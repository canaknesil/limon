module Limon_Parser

import JSON

export
    parse_limon,
    example_limon_file,
    AST

limon_parser_executable = "../limon-parser/limon-parser"
all_nodes_lmn = "../limon-parser/all-nodes.lmn"
empty_program_lmn = "../limon-parser/empty-program.lmn"

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
                         length(node) == 3 ? node[3] : nothing)

Base.getindex(node::AST, key) = node.branches[key]


function parse_limon(limon_file::AbstractString; print_json=false)
    program_json_str = read(`$limon_parser_executable $limon_file`,
                            String)
    program_json = JSON.parse(program_json_str)
    if print_json
        JSON.print(program_json)
    end
    ast = make_AST(program_json)
    return ast
end
    
end # module Limon_Parser
