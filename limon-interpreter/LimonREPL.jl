module LimonREPL

export run_limon_repl

include("REPL/src/REPL.jl")
using .REPL


function run_limon_repl()
    term_env = ENV["TERM"]
    term = REPL.Terminals.TTYTerminal(term_env, stdin, stdout, stderr)
    have_color = true
    repl = REPL.LineEditREPL(term, have_color)
    REPL.run_repl(repl)
end


end # module LimonREPL
