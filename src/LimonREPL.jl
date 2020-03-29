module LimonREPL

export run_limon_repl

include("REPL/src/REPL.jl")
using .REPL

function run_limon_repl(on_enter_func, on_done_func)
    println("") # Prompt replaces the last printed line.
    term_env = ENV["TERM"]
    term = REPL.Terminals.TTYTerminal(term_env, stdin, stdout, stderr)
    have_color = true
    repl = REPL.LineEditREPL(term, have_color)
    REPL.run_repl(repl, on_enter_func, on_done_func)
end

end # module LimonREPL
