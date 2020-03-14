module Limon_Interpreter

using ..Limon_Parser

struct State
    environment
    State() = new(Dict{AbstractString, Real}())
end

"""
Evaluates an AST node or applies a continuation. 
This specific method is a catch all method.
"""
evaluate(item, state::State) = throw(ArgumentException("""Argument should be an AST node to be evaluated or a continuation to be applied."""))

function evaluate(node::AST{Val{:program}}, state::State)
    evaluate(node["assignments"], state)
    result = evaluate(node["exp"], state)
    println("Result: $result")
end

function evaluate(node::AST{Val{:empty_assignments}}, state::State)
end

function evaluate(node::AST{Val{:non_empty_assignments}}, state::State)
    evaluate(node["assignments"], state)
    evaluate(node["assignment"], state)
end

function evaluate(node::AST{Val{:assignment}}, state::State)
    value = evaluate(node["exp"], state)
    #value = 0
    var = node["identifier"]
    state.environment[var] = value
    println("Defining $var as $value.")
end

function evaluate(node::AST{Val{:number}}, state::State)
    parse(Int, node["number_str"])
end

function evaluate(node::AST{Val{:variable_ref}}, state::State)
    state.environment[node["variable"]]
end

function evaluate_op(op, exp1::AST, exp2::AST, state::State)
    value1 = evaluate(exp1, state)
    value2 = evaluate(exp2, state)
    op(value1, value2)
end

evaluate(node::AST{Val{:addition}}, state::State) =
    evaluate_op(+, node["exp1"], node["exp2"], state)

evaluate(node::AST{Val{:substraction}}, state::State) =
    evaluate_op(-, node["exp1"], node["exp2"], state)

evaluate(node::AST{Val{:multiplication}}, state::State) =
    evaluate_op(*, node["exp1"], node["exp2"], state)

evaluate(node::AST{Val{:division}}, state::State) =
    evaluate_op(/, node["exp1"], node["exp2"], state)

evaluate(node::AST{Val{:precedence}}, state::State) =
    evaluate(node["exp"], state)    


end # module limon_interpreter
