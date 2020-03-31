module Limon_Parser

import JSON

export
    parse_limon,
    example_limon_file,
    AST

limon_parser_executable = joinpath(@__DIR__, "../limon-parser/limon-parser")
all_nodes_lmn = "../limon-parser/all-nodes.lmn"
empty_program_lmn = "../limon-parser/empty-program.lmn"

#temp_file_dir = joinpath(dirname(@__FILE__), "limon-repl-tmp")
temp_file_dir = "/tmp/limon-repl-tmp"

struct AST{T}
    branches
    location
end

make_AST(const_node::AbstractString) = const_node
make_AST(const_node::Bool) = const_node

make_AST(node) =
    AST{Symbol(node[1])}(Dict(map((key, value) ->
                                  (key, make_AST(value)),
                                  keys(node[2]), values(node[2]))),
                         node[3])

Base.getindex(node::AST, key) = node.branches[key]

function ast_replace_filename(node::AST{T}, filename) where T
    newLocation = node.location
    newLocation[1] = filename
    newBranches = Dict(map((key, value) -> (key, ast_replace_filename(value, filename)),
                           keys(node.branches), values(node.branches)))
    AST{T}(newBranches, newLocation)
end
    
ast_replace_filename(node, filename) = node

function parse_limon(limon_file::AbstractString; print_json=false, no_error_print=false)
    program_json_str = ""
    try
        #program_json_str = read(`$limon_parser_executable $limon_file`,
        #                       String)
        io = IOBuffer()
        error_direction = no_error_print ? devnull : stdout
        run(pipeline(`$limon_parser_executable $limon_file`,
                     stdout=io, stderr=error_direction))
        program_json_str = String(take!(io))
    catch exc
        program_json_str = nothing
        if !no_error_print
            println("\n... error generated by parser.")
        end
    end
    if program_json_str == nothing
        return nothing
    else
        program_json = JSON.parse(program_json_str)
        if print_json
            #JSON.print(program_json, 3)
            println(program_json_str)
        end
        ast = make_AST(program_json)
        return ast
    end
end

function parse_limon_str(limon_str::AbstractString;
                         print_json=false,
                         no_error_print=false,
                         new_filename=nothing)
    temp_file_name = "repl-$(getpid())-$(Threads.threadid())"
    temp_file_name = joinpath(temp_file_dir, temp_file_name)
    #println(temp_file_name)
    mkpath(dirname(temp_file_name))
    open(temp_file_name, "w") do io
        write(io, limon_str)
        write(io, "\n")
    end
    ast = parse_limon(temp_file_name, print_json=print_json, no_error_print=no_error_print)
    if new_filename != nothing
        ast = ast_replace_filename(ast, new_filename)
    end
    return ast
end
    
end # module Limon_Parser
