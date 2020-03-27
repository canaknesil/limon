module LimonREPL

export run_limon_repl

using Limon_Parser
using Limon_Interpreter_Front_End

include("REPL/src/REPL.jl")
using .REPL


function limon_on_enter(str)
    #println("\n----- LIMON ON ENTER -----")
    str = lstrip(str) # Remove space at left
    if length(str) == 0 # No need to parse empty line
        return true
    end
    ast = Limon_Parser.parse_limon_str(str, no_error_print=true)
    if ast == nothing # TODO Display the syntax error if not possible to complete.
        return false
    else
        return true
    end
end


function run_limon_repl(state, cont, conf)

    # The returned value is printed by Julia.
    function limon_on_done(str)
        #println("\n----- LIMON ON DONE -----")
        str = lstrip(str) # remove space at left
        if length(str) == 0
            return nothing
        end
        value = Limon_Interpreter_Front_End.run_limon_str(str,
                                                          state,
                                                          cont)
        if value == nothing
            println("\nError while running command.")
            return nothing
        end
        show(value)
        println("")
        return nothing
    end
    
    println("") # Prompt replaces the last printed line.
    term_env = ENV["TERM"]
    term = REPL.Terminals.TTYTerminal(term_env, stdin, stdout, stderr)
    have_color = true
    repl = REPL.LineEditREPL(term, have_color)
    REPL.run_repl(repl, limon_on_enter, limon_on_done)
end

end # module LimonREPL
