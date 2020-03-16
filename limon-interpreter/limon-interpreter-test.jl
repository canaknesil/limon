include("limon-include.jl")

import .Limon_Interpreter
import .Limon_Parser

function run_limon_file(filename)
    ast = Limon_Parser.parse_limon(filename)
    value = Limon_Interpreter.trampoline(ast,
                                         Limon_Interpreter.State(),
                                         Limon_Interpreter.EndContinuation(),
                                         debugExecution = true)

    println(value)
end

#run_limon_file(Limon_Parser.empty_program_lmn)
run_limon_file(Limon_Parser.all_nodes_lmn)
