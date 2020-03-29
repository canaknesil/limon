using Pkg
using PackageCompiler

Pkg.activate(".")

packages = [:Limon,
            :JSON,
            :ArgParse]

sysimage = ARGS[1]
PackageCompiler.create_sysimage(packages; sysimage_path=sysimage,
                                precompile_execution_file="precompile-limon.jl")
