module Limon

include("limon-include.jl")
using .Limon_Interpreter_Front_End

using ArgParse

export limon_main

function parse_commandline()
    s = ArgParseSettings()
    
    @add_arg_table! s begin
        "--no-base"
        help = "Do not run base library."
        action = :store_true
        
        "--repl", "-r"
        help = "Run <file>, if exists, and start REPL."
        action = :store_true
        
        "--no-end-val"
        help = "Do not display end value."
        action = :store_true

        "--print-ast"
        help = "Print AST after parsing."
        action = :store_true

        "--print-debug"
        help = "Print execution info while running."
        action = :store_true

        "file"
        help = "File to be run. If not provided, REPL starts."
    end
    
    return parse_args(s)
end

function limon_main()

    #
    # Parse command line arguments
    #

    # default values
    no_base = false
    repl = false
    no_end_val = false
    print_ast = false
    print_debug = false
    file = nothing
    
    parsed_args = parse_commandline()
    for (arg, val) in parsed_args
        if (arg == "no-base") & (val == true)
            no_base = true
        elseif (arg == "repl") & (val == true)
            repl = true
        elseif (arg == "no-end-val") & (val == true)
            no_end_val = true
        elseif (arg == "print-ast") & (val == true)
            print_ast = true
        elseif (arg == "print-debug") & (val == true)
            print_debug = true
        elseif (arg == "file") & (val != nothing)
            file = val
        end
    end

    print_args = false
    if print_args
        println("no-base     => $no_base")
        println("repl        => $repl")
        println("no-end-val  => $no_end_val")
        println("print-ast   => $print_ast")
        println("print-debug => $print_debug")
        file_arg = file == nothing ? "nothing" : file
        println("file       => $file_arg")
    end

    #
    # Create configuration
    #

    conf = LimonConfiguration(!no_base,
                              !no_end_val,
                              (file == nothing) | repl ? true : false,
                              print_debug,
                              file,
                              nothing,
                              nothing)

    #
    # Run Limon
    #
    
    if print_ast
        start_limon_ast(conf)
        return
    end
    start_limon(conf)
end

end # module Limon

