module Limon_Interpreter

using ..Limon_Parser
using ..Limon_Value


struct Environment
    bindings
    next
    Environment(next) = new(Dict{AbstractString,
                                 Limon_Value.Value}(), next)
end

Environment() = Environment(nothing)

function apply(env::Environment, var)
    #println("Applying environment with $var.")
    #println("Environment: ")
    #println(env)
    if haskey(env.bindings, var)
        env.bindings[var]
    else
        apply(env.next, var)
    end
end

apply(env::Nothing, var) = nothing

function extend(env::Environment, var, value)
    env.bindings[var] = value
end

function setvar(env::Environment, var, value)
    if haskey(env.bindings, var)
        env.bindings[var] = value
        value
    else
        setvar(env.next, var, value)
    end
end

setvar(env::Nothing, var, value) = nothing


function Base.show(io::IO, env::Environment)
    show(env.bindings)
    println("")
    show(env.next)
end


struct EndContinuation end
struct ExpListContinuation
    exp_list
    state
    next
end
struct AssignExpContinuation
    var
    location
    state
    next
end
struct MulAssignExpContinuation
    param_list
    location
    state
    next
end
struct MakeArrayExpContinuation
    location
    next
end
struct OneCondCondListContinuation
    exp2
    cond_else
    location
    state
    next
end
struct MulCondCondListContinuation
    exp2
    cond_list
    location
    state
    next
end
struct PrintExpContinuation
    next
end
struct ShowExpContinuation
    next
end
struct TryContinuation
    catch_var
    catch_exp_list
    state
    next
end
struct RaiseContinuation
    next
end
struct ConvertExp1Continuation
    exp2
    location
    state
    next
end
struct ConvertExp2Continuation
    exp1
    location
    next
end
struct ValtypeExpContinuation
    next
end
struct CallExpOpContinuation
    item_list
    location
    state
    next
end
struct CallExpArgumentContinuation
    proc
    location
    next
end
struct OneExpItemListContinuation
    next
end
struct MulExpItemListContinuation
    non_empty_item_list
    state
    next
end
struct MulExpItemListContinuation2
    first_item
    next
end
struct ArrayGetExp1Continuation
    exp2
    location
    state
    next
end
struct ArrayGetExp2Continuation
    array
    location
    next
end
struct ArraySetExp1Continuation
    exp2
    exp3
    location
    state
    next
end
struct ArraySetExp2Continuation
    array
    exp3
    location
    state
    next
end
struct ArraySetExp3Continuation
    array
    index
    location
    next
end
struct SizeOfExpContinuation
    location
    next
end
struct BinaryOpExp1Continuation
    op
    exp2
    location
    state
    next
end
struct BinaryOpExp2Continuation
    op
    val1
    location
    next
end
struct UnaryOpExpContinuation
    op
    location
    next
end
struct RunExpContinuation
    current_file
    location
    state
    next
end

struct State
    environment
end

State() = State(Environment())

struct Evaluate
    ast
    state
    continuation
end

struct ApplyContinuation
    continuation
    value
end

struct ApplyProcedure
    procedure
    args
    continuation
    location
end

function execute(executable::Evaluate)
    evaluate(executable.ast,
             executable.state,
             executable.continuation)
end

execute(executable::ApplyContinuation) =
    applyContinuation(executable.continuation,
                      executable.value)

execute(executable::ApplyProcedure) =
    applyProcedure(executable.procedure,
                   executable.args,
                   executable.continuation,
                   executable.location)

function print_execution(exe::Evaluate)
    loc = exe.ast.location
    if loc == nothing
        loc_str = "No location"
    else
        loc_str = "$(loc[1]): $(loc[2]) $(loc[3]) $(loc[4]) $(loc[5])"
    end
    t = typeof(exe.ast)
    println("Evaluate: $t $loc_str")
end

function print_execution(exe::ApplyContinuation)
    t = typeof(exe.continuation)
    println("ApplyContinuation: $t")
end

function print_execution(exe::ApplyProcedure)
    println("ApplyProcedure")
end

function trampoline(ast, state, continuation; debugExecution = false)
    executable = Evaluate(ast, state, continuation)
    while true
        if debugExecution
            print_execution(executable)
        end
        executable = execute(executable)
        if isa(executable, Limon_Value.Value) | (executable == nothing)
            break
        end
    end
    executable
end


function applyContinuation(cont::EndContinuation, value)
    value
end


evaluate(node::AST{T}, state, cont) where T =
    throw(ArgumentError("AST parameter type $T is not implemented."))

evaluate(node::AST{:empty_program}, state, cont) =
    ApplyContinuation(cont, Limon_Value.NullValue())


function evaluate(node::AST{:program}, state, cont)
    Evaluate(node["exp_list"], state, cont)
end


evaluate(node::AST{:one_exp_exp_list}, state, cont) =
    Evaluate(node["exp"], state, cont)


applyContinuation(cont::ExpListContinuation, value) =
    Evaluate(cont.exp_list, cont.state, cont.next)

evaluate(node::AST{:mul_exp_exp_list}, state, cont) =
    Evaluate(node["exp"], state,
             ExpListContinuation(node["exp_list"], state, cont))
    
    
evaluate(node::AST{:scope_exp}, state, cont) =
    Evaluate(node["exp_list"],
             State(Environment(state.environment)),
             cont)

function evaluate(node::AST{:def_exp}, state, cont)
    value = Limon_Value.NullValue()
    extend(state.environment, node["var"], value)
    ApplyContinuation(cont, value)
end

function applyContinuation(cont::AssignExpContinuation, value)
    val = setvar(cont.state.environment, cont.var, value)
    if val == nothing
        raiseLimonException("Variable '$(cont.var)' not defined",
                            cont.next, cont.location)
    else
        ApplyContinuation(cont.next, val)
    end
end

evaluate(node::AST{:assign_exp}, state, cont) =
    Evaluate(node["exp"], state,
             AssignExpContinuation(node["var"], node.location, state, cont))


function applyContinuation(cont::MulAssignExpContinuation, value)
    if !isa(value, Limon_Value.ArrayValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Right-hand side of a multi-variable assignment must be of type 'array'. Got '$tstr'.", cont.next, cont.location)
    elseif length(value) != length(cont.param_list)
        raiseLimonException("Number of variable does not match array length in multi-variable assignment. Got $(length(cont.param_list)) variables and array size $(length(value)).", cont.next, cont.location)
    else
        map((var, value) -> extend(cont.state.environment, var, value),
            cont.param_list, value)
        ApplyContinuation(cont.next, value)
    end
end

function evaluate(node::AST{:mul_assign_exp}, state, cont)
    param_list = evaluate(node["param_list"])
    Evaluate(node["exp"], state,
             MulAssignExpContinuation(param_list, node.location, state, cont))
end


evaluate(node::AST{:cond_exp}, state, cont) =
    Evaluate(node["cond_list"], state, cont)


function applyContinuation(cont::PrintExpContinuation, value)
    print(value)
    ApplyContinuation(cont.next, value)
end

evaluate(node::AST{:print_exp}, state, cont) =
    Evaluate(node["exp"], state,
             PrintExpContinuation(cont))


function applyContinuation(cont::ShowExpContinuation, value)
    show(value)
    ApplyContinuation(cont.next, value)
end

evaluate(node::AST{:show_exp}, state, cont) =
    Evaluate(node["exp"], state,
             ShowExpContinuation(cont))


applyContinuation(cont::TryContinuation, value) =
    ApplyContinuation(cont.next, value)

function evaluate(node::AST{:try_catch_exp}, state, cont)
    newState = State(Environment(state.environment))
    Evaluate(node["try_exp_list"], newState,
             TryContinuation(node["catch_var"],
                             node["catch_exp_list"], state, cont))
end


function reportUncaughtException(value)
    if (isa(value, Limon_Value.ArrayValue)
        && (length(value) > 0)
        && isa(value[0], Limon_Value.SymbolValue)
        && (value[0].str == "internal_limon_exception"))
        print("\nInternal Limon Exception: ")
        Limon_Value.print_str(value[1])
        println("")
        print("Location: '")
        Limon_Value.print_str(value[2][0])
        print("'")
        println(" between lines ", value[2][1], "-", value[2][3],
                ", columns ", value[2][2], "-", value[2][4])        
    else    
        print("Uncaught exception: ")
        println(value)
    end
    nothing
end

function applyExceptionHandler(value, cont)
    while true
        if isa(cont, TryContinuation)
            newState = State(Environment(cont.state.environment))
            extend(newState.environment, cont.catch_var, value)
            return Evaluate(cont.catch_exp_list, newState, cont.next)
        elseif isa(cont, EndContinuation)
            return reportUncaughtException(value)
        else
            cont = cont.next
        end
    end
end

function raiseLimonException(what::AbstractString, cont, location)
    exc_sym = Limon_Value.SymbolValue(:internal_limon_exception)
    what = Limon_Value.ArrayValue(what)
    filename = Limon_Value.ArrayValue(location[1]::AbstractString)
    location = map(i -> Limon_Value.IntegerValue(i),
                   location[2:end])
    location = Limon_Value.ArrayValue([filename, location...])
    exc = Limon_Value.ArrayValue([exc_sym, what, location])
    ApplyContinuation(RaiseContinuation(cont), exc)
end

applyContinuation(cont::RaiseContinuation, value) =
    applyExceptionHandler(value, cont)

evaluate(node::AST{:raise_exp}, state, cont) =
    Evaluate(node["exp"], state, RaiseContinuation(cont))


limonTypes = Dict{String, Type}()
limonTypes[Limon_Value.typeString(Limon_Value.IntegerValue)] = Limon_Value.IntegerValue
limonTypes[Limon_Value.typeString(Limon_Value.FloatValue)] = Limon_Value.FloatValue
limonTypes[Limon_Value.typeString(Limon_Value.CharValue)] = Limon_Value.CharValue
limonTypes[Limon_Value.typeString(Limon_Value.BoolValue)] = Limon_Value.BoolValue
limonTypes[Limon_Value.typeString(Limon_Value.SymbolValue)] = Limon_Value.SymbolValue
limonTypes[Limon_Value.typeString(Limon_Value.NullValue)] = Limon_Value.NullValue
limonTypes[Limon_Value.typeString(Limon_Value.ArrayValue)] = Limon_Value.ArrayValue
limonTypes[Limon_Value.typeString(Limon_Value.ProcValue)] = Limon_Value.ProcValue


function applyContinuation(cont::ConvertExp2Continuation, value)
    if !isa(value, Limon_Value.SymbolValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Type in conversion must be of type 'symbol', got '$tstr'.", cont.next, cont.location)
    elseif !(value.str in keys(limonTypes))
        raiseLimonException("'$(value.str)' is not a Limon value type.", cont.next, cont.location)
    elseif length(methods(Limon_Value.convert_limon_value, [typeof(limonTypes[value.str]),
                                                            typeof(cont.exp1)])) == 0
        from = Limon_Value.typeString(typeof(cont.exp1))
        to = value.str
        raiseLimonException("Converting '$from' to '$to' is not defined.", cont.next, cont.location)
    else
        converted = Limon_Value.convert_limon_value(limonTypes[value.str], cont.exp1)
        ApplyContinuation(cont.next, converted)
    end
end   

applyContinuation(cont::ConvertExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             ConvertExp2Continuation(value, cont.location, cont.next))

evaluate(node::AST{:convert_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             ConvertExp1Continuation(node["exp2"], node.location, state, cont))


applyContinuation(cont::ValtypeExpContinuation, value) =
    ApplyContinuation(cont.next,
                      Limon_Value.SymbolValue(Limon_Value.typeString(typeof(value))))

evaluate(node::AST{:valtype_exp}, state, cont) =
    Evaluate(node["exp"], state,
             ValtypeExpContinuation(cont))


evaluate(node::AST{:gensym_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.SymbolValue(String(gensym())))


function evaluate(node::AST{:var_exp}, state, cont)
    var = node["var"]
    val = apply(state.environment, var)
    if val == nothing
        raiseLimonException("Variable '$var' not defined",
                            cont, node.location)
    else
        ApplyContinuation(cont, val)
    end
end


function evaluate(node::AST{:proc_exp}, state, cont)
    param_list = evaluate(node["param_list"])
    if length(Set(param_list)) != length(param_list)
        raiseLimonException("Some of the arguments are identical in procedure value.", cont, node.location)
    else
        ApplyContinuation(cont, Limon_Value.ProcValue(param_list,
                                                      node["exp_list"],
                                                      state))
    end
end


function applyProcedure(proc, args, cont, location)
    if !isa(proc, Limon_Value.ProcValue)
        tstr = Limon_Value.typeString(typeof(proc))
        raiseLimonException("First expression in a procedure call must be of type 'procedure'. Got '$tstr'.", cont, location)
    elseif length(proc.param_list) != length(args)
        raiseLimonException("Number of arguments in procedure call is not correct. Expected $(length(proc.param_list)), got $(length(args)).", cont, location)
    else
        newState = State(Environment(proc.state.environment))
        map((var, val) -> extend(newState.environment, var, val),
            proc.param_list, args)
        Evaluate(proc.body, newState, cont)
    end
end

applyContinuation(cont::CallExpArgumentContinuation, value) =
    ApplyProcedure(cont.proc, value, cont.next, cont.location)

applyContinuation(cont::CallExpOpContinuation, value) =
    Evaluate(cont.item_list, cont.state,
             CallExpArgumentContinuation(value, cont.location, cont.next))

function evaluate(node::AST{:call_exp}, state, cont)
    Evaluate(node["exp"], state,
             CallExpOpContinuation(node["item_list"], node.location, state, cont))
end


evaluate(node::AST{:splice_call_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             CallExpOpContinuation(node["exp2"], node.location, state, cont))


evaluate(node::AST{:array_const_exp}, state, cont) =
    Evaluate(node["item_list"], state, cont)


function applyContinuation(cont::MakeArrayExpContinuation, value)
    if !isa(value, Limon_Value.IntegerValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Size in array construction must be of type 'integer', got '$tstr'.", cont.next, cont.location)
    elseif value.n < 0
        raiseLimonException("Size in array construction must be greater than or equal to zero. Got $(value.n).", cont.next, cont.location)
    else
        ApplyContinuation(cont.next, Limon_Value.ArrayValue(value.n))
    end
end

evaluate(node::AST{:make_array_exp}, state, cont) =
    Evaluate(node["exp"], state,
             MakeArrayExpContinuation(node.location, cont))


function applyContinuation(cont::ArrayGetExp2Continuation, value)
    if !isa(cont.array, Limon_Value.ArrayValue)
        tstr = Limon_Value.typeString(typeof(cont.array))
        raiseLimonException("First expression in array reference must be of type 'array'. Got '$tstr'.", cont.next, cont.location)
    elseif !isa(value, Limon_Value.IntegerValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Second expression in array reference must be of type 'integer'. Got '$tstr'.", cont.next, cont.location)
    elseif !((value.n >= 0) & (value.n < length(cont.array)))
        raiseLimonException("Index in array reference must be in interval [0, $(length(cont.array) - 1)]. Got $(value.n).", cont.next, cont.location)
    else
        ApplyContinuation(cont.next, cont.array[value.n])
    end
end

applyContinuation(cont::ArrayGetExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             ArrayGetExp2Continuation(value, cont.location, cont.next))

evaluate(node::AST{:array_get_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             ArrayGetExp1Continuation(node["exp2"], node.location, state, cont))


function applyContinuation(cont::ArraySetExp3Continuation, value)
    if !isa(cont.array, Limon_Value.ArrayValue)
        tstr = Limon_Value.typeString(typeof(cont.array))
        raiseLimonException("First expression in array reference must be of type 'array'. Got '$tstr'.", cont.next, cont.location)
    elseif !isa(cont.index, Limon_Value.IntegerValue)
        tstr = Limon_Value.typeString(typeof(cont.index))
        raiseLimonException("Second expression in array reference must be of type 'integer'. Got '$tstr'.", cont.next, cont.location)
    elseif !((cont.index.n >= 0) & (cont.index.n < length(cont.array)))
        raiseLimonException("Index in array reference must be in interval [0, $(length(cont.array) - 1)]. Got $(cont.index.n).", cont.next, cont.location)
    else
        cont.array[cont.index.n] = value
        ApplyContinuation(cont.next, value)
    end
end

applyContinuation(cont::ArraySetExp2Continuation, value) =
    Evaluate(cont.exp3, cont.state,
             ArraySetExp3Continuation(cont.array, value, cont.location, cont.next))

applyContinuation(cont::ArraySetExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             ArraySetExp2Continuation(value, cont.exp3, cont.location, cont.state, cont.next))

evaluate(node::AST{:array_set_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             ArraySetExp1Continuation(node["exp2"],
                                      node["exp3"], node.location, state, cont))


function applyContinuation(cont::SizeOfExpContinuation, value)
    if !isa(value, Limon_Value.ArrayValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Sizeof operation expression must be of type 'array'. Got '$tstr'.", cont.next, cont.location)
    else
        ApplyContinuation(cont.next, Limon_Value.IntegerValue(length(value)))
    end
end

evaluate(node::AST{:size_of_exp}, state, cont) =
    Evaluate(node["exp"], state,
             SizeOfExpContinuation(node.location, cont))


function applyContinuation(cont::BinaryOpExp2Continuation, value)
    method_count = length(methods(cont.op, [typeof(cont.val1),
                                            typeof(value)]))
    if method_count == 0
        t1 = Limon_Value.typeString(typeof(cont.val1))
        t2 = Limon_Value.typeString(typeof(value))
        raiseLimonException("Binary hardware operation '$(cont.op)' is not implemented for types '$t1', '$t2'.", cont.next, cont.location)
    else
        result = try
            cont.op(cont.val1, value)
        catch e
            exc_str = "Error while hardware operation '$(cont.op)': " * string(e)
            return raiseLimonException(exc_str, cont.next, cont.location)
        end
        ApplyContinuation(cont.next, cont.op(cont.val1, value))
    end
end

applyContinuation(cont::BinaryOpExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             BinaryOpExp2Continuation(cont.op, value, cont.location, cont.next))

evaluate_binary_op(op, node::AST, state, cont) =
    Evaluate(node["exp1"], state,
             BinaryOpExp1Continuation(op, node["exp2"], node.location, state, cont))

macro evaluate_binary_op_macro(node_symbol, op)
    return :( evaluate(node::AST{$node_symbol}, state, cont) =
              evaluate_binary_op($op, node, state, cont) )
end

@evaluate_binary_op_macro(:plus_k, Limon_Value.limon_plus)
@evaluate_binary_op_macro(:min_k , Limon_Value.limon_min)
@evaluate_binary_op_macro(:mul_k , Limon_Value.limon_mul)
@evaluate_binary_op_macro(:div_k , Limon_Value.limon_div)
@evaluate_binary_op_macro(:rem_k , Limon_Value.limon_rem)
@evaluate_binary_op_macro(:eq_k  , Limon_Value.limon_eq)
@evaluate_binary_op_macro(:neq_k , Limon_Value.limon_neq)
@evaluate_binary_op_macro(:lot_k , Limon_Value.limon_lot)
@evaluate_binary_op_macro(:grt_k , Limon_Value.limon_grt)
@evaluate_binary_op_macro(:leq_k , Limon_Value.limon_leq)
@evaluate_binary_op_macro(:geq_k , Limon_Value.limon_geq)
@evaluate_binary_op_macro(:and_k , Limon_Value.limon_and)
@evaluate_binary_op_macro(:or_k  , Limon_Value.limon_or)


function applyContinuation(cont::UnaryOpExpContinuation, value)
    method_count = length(methods(cont.op, [typeof(value)]))
    if method_count == 0
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Unary hardware operation '$(cont.op)' is not implemented for type '$tstr'.", cont.next, cont.location)
    else
        ApplyContinuation(cont.next, cont.op(value))
    end
end

evaluate_unary_op(op, node::AST, state, cont) =
    Evaluate(node["exp"], state,
             UnaryOpExpContinuation(op, node.location, cont))

macro evaluate_unary_op_macro(node_symbol, op)
    return :( evaluate(node::AST{$node_symbol}, state, cont) =
              evaluate_unary_op($op, node, state, cont) )
end

@evaluate_unary_op_macro(:umin_k, Limon_Value.limon_umin)
@evaluate_unary_op_macro(:not_k , Limon_Value.limon_not)


function applyContinuation(cont::RunExpContinuation, value)
    file_to_be_run = joinpath(dirname(cont.current_file),
                              Limon_Value.String(value))
    ast = Limon_Parser.parse_limon(file_to_be_run)
    if ast == nothing
        raiseLimonException("Parsing error running file '$file_to_be_run'.", cont.next, cont.location)
    else
        Evaluate(ast, cont.state, cont.next)
    end
end    

function evaluate(node::AST{:run_exp}, state, cont)
    Evaluate(node["exp"], state,
             RunExpContinuation(node.location[1], node.location, state, cont))
    #ApplyContinuation(cont, Limon_Value.SymbolValue("run_exp_not_implemented"))
end


function applyContinuation(cont::OneCondCondListContinuation, value)
    if !isa(value, Limon_Value.BoolValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Condition must be of type 'bool'. Got '$tstr'.", cont.next, cont.location)
    elseif value.b
        Evaluate(cont.exp2, cont.state, cont.next)
    else
        Evaluate(cont.cond_else, cont.state, cont.next)
    end
end

evaluate(node::AST{:one_cond_cond_list}, state, cont) =
    Evaluate(node["exp1"], state,
             OneCondCondListContinuation(node["exp2"],
                                         node["cond_else"], node.location, state, cont))


function applyContinuation(cont::MulCondCondListContinuation, value)
    if !isa(value, Limon_Value.BoolValue)
        tstr = Limon_Value.typeString(typeof(value))
        raiseLimonException("Condition must be of type 'bool'. Got '$tstr'.", cont.next, cont.location)
    elseif value.b
        Evaluate(cont.exp2, cont.state, cont.next)
    else
        Evaluate(cont.cond_list, cont.state, cont.next)
    end
end

evaluate(node::AST{:mul_cond_cond_list}, state, cont) =
    Evaluate(node["exp1"], state,
             MulCondCondListContinuation(node["exp2"],
                                         node["cond_list"],
                                         node.location,
                                         state, cont))

evaluate(node::AST{:non_empty_cond_else}, state, cont) =
    Evaluate(node["exp"], state, cont)

evaluate(node::AST{:empty_cond_else}, state, cont) =
    ApplyContinuation(cont, Limon_Value.NullValue())


evaluate(node::AST{:int_exp}, state, cont) =
    ApplyContinuation(cont,
                      Limon_Value.IntegerValue(node["int_str"]))

function evaluate(node::AST{:bin_exp}, state, cont)
    str = node["bin_str"]
    ApplyContinuation(cont, Limon_Value.IntegerValue(str[3:end], 2))
end

function evaluate(node::AST{:hex_exp}, state, cont)
    str = node["hex_str"]
    ApplyContinuation(cont, Limon_Value.IntegerValue(str[3:end], 16))
end

function evaluate(node::AST{:float_exp}, state, cont)
    fvalue = Limon_Value.FloatValue(node["float_str"], 64)
    ApplyContinuation(cont, fvalue)
end

function evaluate(node::AST{:floatp_exp}, state, cont)
    str = node["floatp_str"]
    index_of_p = findfirst(c -> isequal(c, 'p') | isequal(c, 'P'),
                           str)
    float_str = str[1:index_of_p - 1]
    precision = parse(Int, str[index_of_p + 1:end])

    fvalue = Limon_Value.FloatValue(float_str, precision)
    if fvalue == nothing
        raiseLimonException("Floating point precision $precision is not supported.", cont, node.location)
    else
        ApplyContinuation(cont, Limon_Value.FloatValue(float_str, precision))
    end
end

evaluate(node::AST{:bool_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.BoolValue(node["bool"]))

function evaluate(node::AST{:char_exp}, state, cont)
    str = node["char_str"]
    str = str[2:end - 1]
    try
        str = unescape_string(str)
    catch exc
        if isa(exc, ArgumentError)
            error_str = "Error while character unescaping: " * string(exc)
            return raiseLimonException(error_str, cont, node.location)
        else
            throw(exc)
        end
    end
    
    ApplyContinuation(cont, Limon_Value.CharValue(str))
end

function evaluate(node::AST{:string_exp}, state, cont)
    str = node["string_str"]
    try
        str = unescape_string(str[2:end - 1])
    catch exc
        if isa(exc, ArgumentError)
            error_str = "Error while string unescaping: " * string(exc)
            return raiseLimonException(error_str, cont, node.location)
        else
            throw(exc)
        end
    end
    
    char_arr = map(c -> Limon_Value.CharValue(c),
                   collect(str))
    ApplyContinuation(cont, Limon_Value.ArrayValue(char_arr))
end

function evaluate(node::AST{:symbol_exp}, state, cont)
    str = node["symbol_str"]
    ApplyContinuation(cont, Limon_Value.SymbolValue(str[2:end]))
end

evaluate(node::AST{:null_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.NullValue())



evaluate(node::AST{:empty_param_list}) = ()
evaluate(node::AST{:one_var_param_list}) = (node["var"],)
evaluate(node::AST{:mul_var_param_list}) =
    (node["var"], evaluate(node["non_empty_param_list"])...)


evaluate(node::AST{:empty_item_list}, state, cont) =
    ApplyContinuation(cont, Limon_Value.ArrayValue(0))

function applyContinuation(cont::OneExpItemListContinuation, value)
    ApplyContinuation(cont.next, Limon_Value.ArrayValue([value]))
end

evaluate(node::AST{:one_exp_item_list}, state, cont) =
    Evaluate(node["exp"], state,
             OneExpItemListContinuation(cont))

function applyContinuation(cont::MulExpItemListContinuation2, value)
    ApplyContinuation(cont.next,
                      Limon_Value.ArrayValue([cont.first_item, value...]))
end

applyContinuation(cont::MulExpItemListContinuation, value) =
    Evaluate(cont.non_empty_item_list, cont.state,
             MulExpItemListContinuation2(value, cont.next))

evaluate(node::AST{:mul_exp_item_list}, state, cont) =
    Evaluate(node["exp"], state,
             MulExpItemListContinuation(node["non_empty_item_list"], state, cont))


end # module limon_interpreter

