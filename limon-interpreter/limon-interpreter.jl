module Limon_Interpreter

using ..Limon_Parser
using ..Limon_Value


struct Environment
    # TODO
end


abstract type EndContinuation end

struct Continuation{T}
    next
end

Continuation() = Continuation{EndContinuation}(nothing)


struct State
    environment
    State() = new(Environment())
end

struct Evaluate
    ast
    state
    continuation
end

struct ApplyContinuation
    continuation
    value
    state
end

execute(executable::Evaluate) =
    evaluate(executable.ast,
             executable.state,
             executable.continuation)

execute(executable::ApplyContinuation) =
    applyContinuation(executable.continuation,
                      executable.value,
                      executable.state)

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


function applyContinuation(cont::Continuation{EndContinuation}, value, state)
    value
end


evaluate(item, state, cont) =
    throw(ArgumentException("Argument should be an AST node to be evaluated."))

evaluate(node::AST{Val{:program}}, state, cont) =
    Evaluate(node["exp_list"], state, cont)

evaluate(node::AST{Val{:one_exp_exp_list}}, state, cont) =
    Evaluate(node["exp"], state, cont)

evaluate(node::AST{Val{:int_exp}}, state, cont) =
    ApplyContinuation(cont,
                      Limon_Value.IntegerValue(node["int_str"]),
                      state)

# function evaluate(node::AST{Val{:program}}, state::State)
#     evaluate(node["assignments"], state)
#     result = evaluate(node["exp"], state)
#     println("Result: $result")
# end

# function evaluate(node::AST{Val{:empty_assignments}}, state::State)
# end

# function evaluate(node::AST{Val{:non_empty_assignments}}, state::State)
#     evaluate(node["assignments"], state)
#     evaluate(node["assignment"], state)
# end

# function evaluate(node::AST{Val{:assignment}}, state::State)
#     value = evaluate(node["exp"], state)
#     #value = 0
#     var = node["identifier"]
#     state.environment[var] = value
#     println("Defining $var as $value.")
# end

# function evaluate(node::AST{Val{:number}}, state::State)
#     parse(Int, node["number_str"])
# end

# function evaluate(node::AST{Val{:variable_ref}}, state::State)
#     state.environment[node["variable"]]
# end

# function evaluate_op(op, exp1::AST, exp2::AST, state::State)
#     value1 = evaluate(exp1, state)
#     value2 = evaluate(exp2, state)
#     op(value1, value2)
# end

# evaluate(node::AST{Val{:addition}}, state::State) =
#     evaluate_op(+, node["exp1"], node["exp2"], state)

# evaluate(node::AST{Val{:substraction}}, state::State) =
#     evaluate_op(-, node["exp1"], node["exp2"], state)

# evaluate(node::AST{Val{:multiplication}}, state::State) =
#     evaluate_op(*, node["exp1"], node["exp2"], state)

# evaluate(node::AST{Val{:division}}, state::State) =
#     evaluate_op(/, node["exp1"], node["exp2"], state)

# evaluate(node::AST{Val{:precedence}}, state::State) =
#     evaluate(node["exp"], state)    


end # module limon_interpreter
