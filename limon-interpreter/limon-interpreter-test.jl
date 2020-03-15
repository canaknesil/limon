include("limon-include.jl")

import .Limon_Interpreter
import .Limon_Parser

ast = Limon_Parser.parse_limon(Limon_Parser.example_limon_file)
value = Limon_Interpreter.trampoline(ast,
                                     Limon_Interpreter.State(),
                                     Limon_Interpreter.Continuation(),
                                     debugExecution = true)

println(value)

