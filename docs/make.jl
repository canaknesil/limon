using Documenter

pages = [
    "Home" => "index.md",
    "Variables and Scope" => "variables-and-scope.md",
    "Built-in Values" => "values.md",
    "Math and Basic Operations" => "math-and-basic-operations.md",
    "Control Flow" => "control-flow.md",
    "Procedures" => "procedures.md",
    "Strings" => "strings.md",
    "Multi-File Programs" => "multi-file-programs.md",
    
    "Core (draft)" => "core.md",
    "Base (draft)" => "base.md",
    "Index" => "index-page.md"
    # "Subsection" => [
    #     ...
    # ]
]

makedocs(sitename="Limon Documentation", pages=pages)


