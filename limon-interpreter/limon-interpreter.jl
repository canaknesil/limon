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
struct DefExpContinuation
    var
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

function applyContinuation(cont::DefExpContinuation, value)
    extend(cont.state.environment, cont.var, value)
    ApplyContinuation(cont.next, value)
end

evaluate(node::AST{:assign_exp}, state, cont) =
    Evaluate(node["exp"], state,
             DefExpContinuation(node["var"], state, cont))







evaluate(node::AST{:int_exp}, state, cont) =
    ApplyContinuation(cont,
                      Limon_Value.IntegerValue(node["int_str"]))


end # module limon_interpreter

