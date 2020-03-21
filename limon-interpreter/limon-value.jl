module Limon_Value

import
    Base.+,
Base.-,
Base.*, 
Base./, 
Base.%, 
Base.==, 
Base.!=, 
Base.<, 
Base.>, 
Base.<=, 
Base.>=,
Base.&,
Base.|,
Base.!

abstract type Value end

#
# IntegerValue
#

struct IntegerValue <: Value
    n::BigInt
end

IntegerValue(int_str::AbstractString) =
    IntegerValue(parse(BigInt, int_str))

IntegerValue(str::AbstractString, base) =
    IntegerValue(parse(BigInt, str, base=base))


Base.show(io::IO, intval::IntegerValue) =
    show(io, intval.n)

typeString(val::IntegerValue) = "integer"

+(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n + v2.n)
-(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n - v2.n)
*(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n * v2.n)
/(v1::IntegerValue, v2::IntegerValue) = IntegerValue(floor(v1.n + v2.n))
%(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n % v2.n)
==(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n == v2.n)
!=(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n != v2.n)
<(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n < v2.n)
>(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n > v2.n)
<=(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n <= v2.n)
>=(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n >= v2.n)

-(val::IntegerValue) = IntegerValue(-val.n)

#
# FloatValue
#

juliaFloatTypes = Dict{Int, DataType}()
juliaFloatTypes[16] = Float16
juliaFloatTypes[32] = Float32
juliaFloatTypes[64] = Float64

juliaFloatPrecision = Dict{DataType, Int}()
juliaFloatPrecision[Float16] = 16
juliaFloatPrecision[Float32] = 32
juliaFloatPrecision[Float64] = 64

struct FloatValue{T} <: Value
    f::T
end

function FloatValue(str::AbstractString, precision)
    ftype = juliaFloatTypes[precision]
    FloatValue{ftype}(parse(ftype, str))
end

precision(floatval::FloatValue{T}) where T =
    juliaFloatPrecision[T]

Base.show(io::IO, floatval::FloatValue) =
    show(io, Float64(floatval.f))

typeString(val::FloatValue) = "float"

#
# CharValue
#

struct CharValue <: Value
    c
end

function CharValue(str::AbstractString)
    CharValue(str[1])
end

Base.show(io::IO, charval::CharValue) =
    show(io, charval.c)

typeString(val::CharValue) = "char"

#
# BoolValue
#

struct BoolValue <: Value
    b::Bool
end

Base.show(io::IO, boolval::BoolValue) =
    if boolval.b
        print(io, "#<true>")
    else
        print(io, "#<false>")
    end

typeString(val::BoolValue) = "bool"

(&)(v1::BoolValue, v2::BoolValue) = BoolValue(v1.b & v2.b)
(|)(v1::BoolValue, v2::BoolValue) = BoolValue(v1.b | v2.b)

!(val::BoolValue) = BoolValue(!val.b)

#
# SymbolValue
#

struct SymbolValue <: Value
    str::AbstractString
end

Base.show(io::IO, symbolval::SymbolValue) =
    print(":" * symbolval.str)

typeString(val::SymbolValue) = "symbol"

#
# NullValue
#

struct NullValue <: Value
end

Base.show(io::IO, nullval::NullValue) =
    print(io, "#<null>")

typeString(val::NullValue) = "null"

#
# ArrayValue
#

struct ArrayValue <: Value
    array::Array{T, 1} where {T <: Value}
end

ArrayValue(n::Integer) = ArrayValue(fill(NullValue(), n))

Base.getindex(array_value::ArrayValue, key) =
    array_value.array[key + 1]

Base.setindex!(array_value::ArrayValue, value, key) =
    array_value.array[key + 1] = value

Base.length(arrayval::ArrayValue) =
    length(arrayval.array)

function Base.show(io::IO, arrayval::ArrayValue)
    print(io, "[#")
    for val in arrayval.array
        print(io, " $val")
    end
    print(io, "]")
end

Base.iterate(arrayval::ArrayValue, state=1) =
    if state > length(arrayval.array)
        nothing
    else
        (arrayval.array[state], state+1)
    end

Base.length(arrayval::ArrayValue) = length(arrayval.array)

typeString(val::ArrayValue) = "array"

#
# ProcValue
#

struct ProcValue <: Value
    param_list
    body
    state
end

Base.show(io::IO, procval::ProcValue) =
    print("#<procedure>")

typeString(val::ProcValue) = "procedure"

end # module value
