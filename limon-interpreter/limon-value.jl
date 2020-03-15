module Limon_Value

abstract type Value end

struct IntegerValue <: Value
    n::BigInt
end

IntegerValue(int_str::AbstractString) =
    IntegerValue(parse(BigInt, int_str))

Base.show(io::IO, intval::IntegerValue) =
    show(io, intval.n)

end # module value
