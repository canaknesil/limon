module Limon_Interpreter_Front_End

import Limon_Interpreter
import Limon_Parser
import LimonREPL

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

function run_limon_ast(ast, state, cont; debugExecution=false)
    if ast == nothing
        return nothing
    else
        Limon_Interpreter.trampoline(ast, state, cont,
                                     debugExecution = debugExecution)
    end
end

function run_limon_file(filename, state, cont; debugExecution=false)
    ast = Limon_Parser.parse_limon(filename)
    run_limon_ast(ast, state, cont, debugExecution=debugExecution)
end

function run_limon_str(limon_str, state, cont; debugExecution=false)
    ast = Limon_Parser.parse_limon_str(limon_str)
    run_limon_ast(ast, state, cont, debugExecution=debugExecution)
end

function initialize_limon(conf)
    (Limon_Interpreter.State(),
     Limon_Interpreter.EndContinuation())
end

function start_limon(conf::LimonConfiguration)
    try
        #throw(:dummy_exception)
        # Initialization
        (state, cont) = initialize_limon(conf)
        if state == nothing
            println("\nLimon initialization error.")
            return
        end

        # Run top file
        if conf.limon_file != nothing
            value = run_limon_file(conf.limon_file, state, cont,
                                   debugExecution=conf.print_debug)
            if value == nothing
                println("\nError while running provided file '$(conf.limon_file)'.")
                return
            end
        end

        # Leave control to REPL, or exit after printing end value
        if conf.repl
            limon_repl(state, cont, conf)
        else
            if conf.end_value & (value != nothing)
                print("End value: ")
                show(value)
                println("")
            end
        end
    catch e
        print_unexpected(e)
    end
end

function print_unexpected(e)
    print_unexpected_str()
    println(e)
    print_unexpected_str()
end

function print_unexpected_str()
    println("\n")
    println("#####################################################################")
    println("# Unexpected error. DON'T MOVE AND REPORT THIS TO THE DEVELOPER !!! #")
    println("#####################################################################")
    println("")
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
    println("REPL for AST mode is not implemented !")
end

function limon_repl(state, cont, conf)
    LimonREPL.run_limon_repl(state, cont, conf)
end


end # module Limon_Interpreter_Front_End
