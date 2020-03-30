using Documenter

pages = [
    "Home" => "index.md",
    "Variables and Scope" => "variables-and-scope.md",
    "Built-in Values" => "values.md",
    "Math and Operators" => "math-and-operators.md",
    "Control Flow" => "control-flow.md",
    "Procedures" => "procedures.md",
    "Multi-File Programs" => "multi-file-programs.md",

    "Base Library" => [
        "Strings" => "strings.md"
    ],
    
    "Core (draft)" => "core.md",
    "Base (draft)" => "base.md",
    "Index" => "index-page.md"
    # "Subsection" => [
    #     ...
    # ]
]

format =  Documenter.HTML(
    #collapselevel = 1,
    sidebar_sitename = false,
)

makedocs(
    sitename="Limon Documentation",
    pages=pages,
    format=format
)


