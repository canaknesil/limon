include("limon-include.jl")

import .Limon_Interpreter
import .Limon_Parser

ast = Limon_Parser.parse_limon(Limon_Parser.example_limon_file)
Limon_Interpreter.evaluate(ast, Limon_Interpreter.State())

