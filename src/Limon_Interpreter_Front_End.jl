module Limon_Interpreter_Front_End

import ..Limon_Interpreter
import ..Limon_Parser
import ..LimonREPL

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
    ast = Limon_Parser.parse_limon_str(limon_str, new_filename="REPL")
    run_limon_ast(ast, state, cont, debugExecution=debugExecution)
end

function initialize_limon(conf)
    if conf.limon_file == nothing
        run_dir = pwd()
    else
        run_dir = dirname(conf.limon_file)
    end
    state = Limon_Interpreter.State(run_dir)
    cont =  Limon_Interpreter.EndContinuation()

    if conf.base_library
        base_lib_file = joinpath(dirname(@__FILE__) *
                                 "/../base/base.lmn")
        newState = Limon_Interpreter.State(state.environment, dirname(base_lib_file))
        value = run_limon_file(base_lib_file, newState, cont)
        if value == nothing
            return (nothing, nothing)
        end
    end

    (state, cont)
end

function start_limon(conf::LimonConfiguration)
    try
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
        print_unexpected_str()
        throw(e)
    end
end

function print_unexpected(e)
    print_unexpected_str()
    println(e)
    #print_unexpected_str()
end

function print_unexpected_str()
    println("\n")
    println("#######################################################################")
    println("#                                                                     #")
    println("#  Unexpected error. DON'T MOVE AND REPORT THIS TO THE DEVELOPER !!!  #")
    println("#                                                                     #")
    println("#######################################################################")
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


function limon_on_enter(str)
    try
        #println("\n----- LIMON ON ENTER -----")
        str = lstrip(str) # Remove space at left
        if length(str) == 0 # No need to parse empty line
            return true
        end
        
        #error("adsf")
        ast = Limon_Parser.parse_limon_str(str, no_error_print=true)
        
        if ast == nothing # TODO Display the syntax error if not possible to complete.
            return false
        else
            return true
        end
    catch e
        print_unexpected(e)
        #exit()
        throw(e)
    end
end

function limon_repl(state, cont, conf)

    # The returned value is printed by Julia.
    function limon_on_done(str)
        try
            #println("\n----- LIMON ON DONE -----")
            str = lstrip(str) # remove space at left
            if length(str) == 0
                return nothing
            end

            #throw(:dummy_exception_on_done)
            value = run_limon_str(str, state, cont)
            
            if value == nothing
                println("\nError while running command.")
                return nothing
            end
            show(value)
            println("")
            return nothing
        catch e
            print_unexpected(e)
            #exit()
            throw(e)
        end
    end
        
    LimonREPL.run_limon_repl(limon_on_enter, limon_on_done)
end


end # module Limon_Interpreter_Front_End
