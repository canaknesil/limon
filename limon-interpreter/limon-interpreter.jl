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

extend(env::Environment, var, value) = env.bindings[var] = value

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
    state
    next
end
struct MulAssignExpContinuation
    param_list
    state
    next
end
struct MakeArrayExpContinuation
    state
    next
end
struct OneCondCondListContinuation
    exp2
    cond_else
    state
    next
end
struct MulCondCondListContinuation
    exp2
    cond_list
    state
    next
end
struct PrintExpContinuation
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
struct ValtypeExpContinuation
    next
end
struct CallExpOpContinuation
    item_list
    state
    next
end
struct CallExpArgumentContinuation
    proc
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
    state
    next
end
struct ArrayGetExp2Continuation
    array
    next
end
struct ArraySetExp1Continuation
    exp2
    exp3
    state
    next
end
struct ArraySetExp2Continuation
    array
    exp3
    state
    next
end
struct ArraySetExp3Continuation
    array
    index
    next
end
struct SizeOfExpContinuation
    next
end
struct BinaryOpExp1Continuation
    op
    exp2
    state
    next
end
struct BinaryOpExp2Continuation
    op
    val1
    next
end
struct UnaryOpExpContinuation
    op
    next
end
struct RunExpContinuation
    current_file
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
                   executable.continuation)

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
        if isa(executable, Limon_Value.Value)
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
    extend(cont.state.environment, cont.var, value)
    ApplyContinuation(cont.next, value)
end

evaluate(node::AST{:assign_exp}, state, cont) =
    Evaluate(node["exp"], state,
             AssignExpContinuation(node["var"], state, cont))


function applyContinuation(cont::MulAssignExpContinuation, value)
    if !isa(value, Limon_Value.ArrayValue)
        error("Value must be an ArrayValue.")
    end
    map((var, value) -> extend(cont.state.environment, var, value),
        cont.param_list, value)
    ApplyContinuation(cont.next, value)
end

function evaluate(node::AST{:mul_assign_exp}, state, cont)
    param_list = evaluate(node["param_list"])
    Evaluate(node["exp"], state,
             MulAssignExpContinuation(param_list, state, cont))
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


applyContinuation(cont::TryContinuation, value) =
    ApplyContinuation(cont.next, value)

function evaluate(node::AST{:try_catch_exp}, state, cont)
    newState = State(Environment(state.environment))
    Evaluate(node["try_exp_list"], newState,
             TryContinuation(node["catch_var"],
                             node["catch_exp_list"], state, cont))
end


function reportUncaughtException(value)
    print("Uncaught exception: ")
    println(value)
    value
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

applyContinuation(cont::RaiseContinuation, value) =
    applyExceptionHandler(value, cont)

evaluate(node::AST{:raise_exp}, state, cont) =
    Evaluate(node["exp"], state, RaiseContinuation(cont))


applyContinuation(cont::ValtypeExpContinuation, value) =
    ApplyContinuation(cont.next,
                      Limon_Value.SymbolValue(Limon_Value.typeString(value)))

evaluate(node::AST{:valtype_exp}, state, cont) =
    Evaluate(node["exp"], state,
             ValtypeExpContinuation(cont))


evaluate(node::AST{:gensym_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.SymbolValue(String(gensym())))


evaluate(node::AST{:var_exp}, state, cont) =
    ApplyContinuation(cont, apply(state.environment, node["var"]))


function evaluate(node::AST{:proc_exp}, state, cont)
    param_list = evaluate(node["param_list"])
    ApplyContinuation(cont, Limon_Value.ProcValue(param_list,
                                                  node["exp_list"],
                                                  state))
end


function applyProcedure(proc, args, cont)
    newState = State(Environment(proc.state.environment))
    map((var, val) -> extend(newState.environment, var, val),
        proc.param_list, args)
    Evaluate(proc.body, newState, cont)
end

applyContinuation(cont::CallExpArgumentContinuation, value) =
    ApplyProcedure(cont.proc, value, cont.next)

applyContinuation(cont::CallExpOpContinuation, value) =
    Evaluate(cont.item_list, cont.state,
             CallExpArgumentContinuation(value, cont.next))

function evaluate(node::AST{:call_exp}, state, cont)
    Evaluate(node["exp"], state,
             CallExpOpContinuation(node["item_list"], state, cont))
end


evaluate(node::AST{:splice_call_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             CallExpOpContinuation(node["exp2"], state, cont))


evaluate(node::AST{:array_const_exp}, state, cont) =
    Evaluate(node["item_list"], state, cont)


function applyContinuation(cont::MakeArrayExpContinuation, value)
    if !isa(value, Limon_Value.IntegerValue)
        error("Array size is not IntegerValue.")
    end
    ApplyContinuation(cont.next, Limon_Value.ArrayValue(value.n))
end

evaluate(node::AST{:make_array_exp}, state, cont) =
    Evaluate(node["exp"], state,
             MakeArrayExpContinuation(state, cont))


applyContinuation(cont::ArrayGetExp2Continuation, value) =
    ApplyContinuation(cont.next, cont.array[value.n])

applyContinuation(cont::ArrayGetExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             ArrayGetExp2Continuation(value, cont.next))

evaluate(node::AST{:array_get_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             ArrayGetExp1Continuation(node["exp2"], state, cont))


function applyContinuation(cont::ArraySetExp3Continuation, value)
    cont.array[cont.index.n] = value
    ApplyContinuation(cont.next, value)
end

applyContinuation(cont::ArraySetExp2Continuation, value) =
    Evaluate(cont.exp3, cont.state,
             ArraySetExp3Continuation(cont.array, value, cont.next))

applyContinuation(cont::ArraySetExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             ArraySetExp2Continuation(value, cont.exp3, cont.state, cont.next))

evaluate(node::AST{:array_set_exp}, state, cont) =
    Evaluate(node["exp1"], state,
             ArraySetExp1Continuation(node["exp2"],
                                      node["exp3"], state, cont))


applyContinuation(cont::SizeOfExpContinuation, value) =
    ApplyContinuation(cont.next, Limon_Value.IntegerValue(length(value)))

evaluate(node::AST{:size_of_exp}, state, cont) =
    Evaluate(node["exp"], state,
             SizeOfExpContinuation(cont))


applyContinuation(cont::BinaryOpExp2Continuation, value) =
    ApplyContinuation(cont.next, cont.op(cont.val1, value))

applyContinuation(cont::BinaryOpExp1Continuation, value) =
    Evaluate(cont.exp2, cont.state,
             BinaryOpExp2Continuation(cont.op, value, cont.next))

evaluate_binary_op(op, node::AST, state, cont) =
    Evaluate(node["exp1"], state,
             BinaryOpExp1Continuation(op, node["exp2"], state, cont))

macro evaluate_binary_op_macro(node_symbol, op)
    return :( evaluate(node::AST{$node_symbol}, state, cont) =
              evaluate_binary_op($op, node, state, cont) )
end

@evaluate_binary_op_macro(:plus_k, +)
@evaluate_binary_op_macro(:min_k , -)
@evaluate_binary_op_macro(:mul_k , *)
@evaluate_binary_op_macro(:div_k , /)
@evaluate_binary_op_macro(:rem_k , %)
@evaluate_binary_op_macro(:eq_k  , ==)
@evaluate_binary_op_macro(:neq_k , !=)
@evaluate_binary_op_macro(:lot_k , <)
@evaluate_binary_op_macro(:grt_k , >)
@evaluate_binary_op_macro(:leq_k , <=)
@evaluate_binary_op_macro(:geq_k , >=)
@evaluate_binary_op_macro(:and_k , &)
@evaluate_binary_op_macro(:or_k  , |)


applyContinuation(cont::UnaryOpExpContinuation, value) =
    ApplyContinuation(cont.next, cont.op(value))

evaluate_unary_op(op, node::AST, state, cont) =
    Evaluate(node["exp"], state,
             UnaryOpExpContinuation(op, cont))

macro evaluate_unary_op_macro(node_symbol, op)
    return :( evaluate(node::AST{$node_symbol}, state, cont) =
              evaluate_unary_op($op, node, state, cont) )
end

@evaluate_unary_op_macro(:umin_k, -)
@evaluate_unary_op_macro(:not_k , !)


function applyContinuation(cont::RunExpContinuation, value)
    ast = Limon_Parser.parse_limon(joinpath(dirname(cont.current_file),
                                            Limon_Value.String(value)))
    Evaluate(ast, cont.state, cont.next)
end    

function evaluate(node::AST{:run_exp}, state, cont)
    Evaluate(node["exp"], state,
             RunExpContinuation(node.location[1], state, cont))
    #ApplyContinuation(cont, Limon_Value.SymbolValue("run_exp_not_implemented"))
end


function applyContinuation(cont::OneCondCondListContinuation, value)
    if !isa(value, Limon_Value.BoolValue)
        error("Condition must be BoolValue.")
    end
    if value.b
        Evaluate(cont.exp2, cont.state, cont.next)
    else
        Evaluate(cont.cond_else, cont.state, cont.next)
    end
end

evaluate(node::AST{:one_cond_cond_list}, state, cont) =
    Evaluate(node["exp1"], state,
             OneCondCondListContinuation(node["exp2"],
                                         node["cond_else"], state, cont))


function applyContinuation(cont::MulCondCondListContinuation, value)
    if !isa(value, Limon_Value.BoolValue)
        error("Condition must be BoolValue.")
    end
    if value.b
        Evaluate(cont.exp2, cont.state, cont.next)
    else
        Evaluate(cont.cond_list, cont.state, cont.next)
    end
end

evaluate(node::AST{:mul_cond_cond_list}, state, cont) =
    Evaluate(node["exp1"], state,
             MulCondCondListContinuation(node["exp2"],
                                         node["cond_list"],
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

evaluate(node::AST{:float_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.FloatValue(node["float_str"], 64))

function evaluate(node::AST{:floatp_exp}, state, cont)
    str = node["floatp_str"]
    index_of_p = findfirst(c -> isequal(c, 'p') | isequal(c, 'P'),
                           str)
    float_str = str[1:index_of_p - 1]
    precision = parse(Int, str[index_of_p + 1:end])
    ApplyContinuation(cont, Limon_Value.FloatValue(float_str, precision))
end

evaluate(node::AST{:bool_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.BoolValue(node["bool"]))

function evaluate(node::AST{:char_exp}, state, cont)
    str = node["char_str"]
    str = str[2:end - 1]
    ApplyContinuation(cont, Limon_Value.CharValue(unescape_string(str)))
end

function evaluate(node::AST{:string_exp}, state, cont)
    str = node["string_str"]
    str = unescape_string(str[2:end - 1])
    char_arr = map(c -> Limon_Value.CharValue(c),
                   collect(str))
    ApplyContinuation(cont, Limon_Value.ArrayValue(char_arr))
end

function evaluate(node::AST{:symbol_exp}, state, cont)
    str = node["symbol_str"]
    ApplyContinuation(cont, Limon_Value.SymbolValue(str[2:end]))
end



#------------

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

