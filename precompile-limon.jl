println("Precompilation script started ...")

#push!(ARGS, "--repl")
push!(ARGS, "test/all-features.lmn")

using Limon
limon_main()

println("Precompilation script done.")
