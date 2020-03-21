module Limon_Interpreter_Front_End

import ..Limon_Interpreter
import ..Limon_Parser

export
    LimonConfiguration,
    start_limon,
    start_limon_ast

struct LimonConfiguration
    base_library::Bool
    end_value::Bool
    repl::Bool
    print_debug::Bool
    limon_file::Union{AbstractString, Nothing}
    limon_argc::Union{Int, Nothing}
    limon_argv::Union{Array{AbstractString, 1}, Nothing}
end


function run_limon_file(filename, state, cont, debugExecution=false)
    ast = Limon_Parser.parse_limon(filename)
    value = Limon_Interpreter.trampoline(ast, state, cont,
                                         debugExecution = debugExecution)
    value
end

function initialize_limon(conf)
    (Limon_Interpreter.State(),
     Limon_Interpreter.EndContinuation())
end

function start_limon(conf::LimonConfiguration)
    (state, cont) = initialize_limon(conf)
    if conf.limon_file != nothing
        value = run_limon_file(conf.limon_file, state, cont,
                               conf.print_debug)
    end
    if conf.repl
        value = limon_repl(state, cont, conf)
    end
    if conf.end_value & (value != nothing)
        println("\nEnd value: $value")
    end
end

function start_limon_ast(conf)
    if conf.limon_file != nothing
        ast = Limon_Parser.parse_limon(conf.limon_file, print_json=true)
    end
    if conf.repl
        value = limon_repl_ast(conf)
    end
end

function limon_repl_ast(conf)
    println("REPL-AST not implemented !")
end

function limon_repl(state, cont, conf)
    println("REPL not implemented !")
end


end # module Limon_Interpreter_Front_End
