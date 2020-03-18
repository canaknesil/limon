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

apply(env::Environment, var) =
    if haskey(env.bindings, var)
        env.bindings[var]
    else
        apply(env.next, var)
    end

apply(env::Nothing, var) = nothing

extend(env::Environment, var, value) = env.bindings[var] = value


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

execute(executable::Evaluate) =
    evaluate(executable.ast,
             executable.state,
             executable.continuation)

execute(executable::ApplyContinuation) =
    applyContinuation(executable.continuation,
                      executable.value)

function print_execution(exe::Evaluate)
    t = typeof(exe.ast)
    println("Evaluate: $t")
end

function print_execution(exe::ApplyContinuation)
    t = typeof(exe.continuation)
    println("ApplyContinuation: $t")
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


evaluate(node::AST{:program}, state, cont) =
    Evaluate(node["exp_list"], state, cont)


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


#--------------

function applyContinuation(cont::MakeArrayExpContinuation, value)
    if !isa(value, Limon_Value.IntegerValue)
        error("Array size is not IntegerValue.")
    end
    ApplyContinuation(cont.next, Limon_Value.ArrayValue(value.n))
end

evaluate(node::AST{:make_array_exp}, state, cont) =
    Evaluate(node["exp"], state,
             MakeArrayExpContinuation(state, cont))

#------------

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

#------------

evaluate(node::AST{:int_exp}, state, cont) =
    ApplyContinuation(cont,
                      Limon_Value.IntegerValue(node["int_str"]))

evaluate(node::AST{:bool_exp}, state, cont) =
    ApplyContinuation(cont, Limon_Value.BoolValue(node["bool"]))

#------------

evaluate(node::AST{:empty_param_list}) = ()
evaluate(node::AST{:one_var_param_list}) = (node["var"],)
evaluate(node::AST{:mul_var_param_list}) =
    (node["var"], evaluate(node["non_empty_param_list"])...)

end # module limon_interpreter

