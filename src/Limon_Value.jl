module Limon_Value

import
    Base.length

abstract type Value end

# IntegerValue
# FloatValue
# CharValue
# BoolValue
# SymbolValue
# NullValue
# ArrayValue
# ProcValue

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

typeString(::Type{IntegerValue}) = "integer"

limon_plus(v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n + v2.n)
limon_min( v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n - v2.n)
limon_mul( v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n * v2.n)
limon_div( v1::IntegerValue, v2::IntegerValue) = IntegerValue(floor(v1.n / v2.n))
limon_rem( v1::IntegerValue, v2::IntegerValue) = IntegerValue(v1.n % v2.n)
limon_eq(  v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n == v2.n)
limon_neq( v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n != v2.n)
limon_lot( v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n < v2.n)
limon_grt( v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n > v2.n)
limon_leq( v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n <= v2.n)
limon_geq( v1::IntegerValue, v2::IntegerValue) = BoolValue(v1.n >= v2.n)

limon_umin(val::IntegerValue) = IntegerValue(-val.n)

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
    if !haskey(juliaFloatTypes, precision)
        return nothing
    end
    ftype = juliaFloatTypes[precision]
    FloatValue{ftype}(parse(ftype, str))
end

precision(floatval::FloatValue{T}) where T =
    juliaFloatPrecision[T]

Base.show(io::IO, floatval::FloatValue) =
    show(io, Float64(floatval.f))

typeString(::Type{FloatValue}) = "float"
typeString(::Type{FloatValue{T}}) where T = "float"

limon_plus(v1::FloatValue, v2::FloatValue) = FloatValue(v1.f + v2.f)
limon_min( v1::FloatValue, v2::FloatValue) = FloatValue(v1.f - v2.f)
limon_mul( v1::FloatValue, v2::FloatValue) = FloatValue(v1.f * v2.f)
limon_div( v1::FloatValue, v2::FloatValue) = FloatValue(v1.f / v2.f)
limon_rem( v1::FloatValue, v2::FloatValue) = FloatValue(v1.f % v2.f)
limon_eq(  v1::FloatValue, v2::FloatValue) = BoolValue(v1.f == v2.f)
limon_neq( v1::FloatValue, v2::FloatValue) = BoolValue(v1.f != v2.f)
limon_lot( v1::FloatValue, v2::FloatValue) = BoolValue(v1.f <  v2.f)
limon_grt( v1::FloatValue, v2::FloatValue) = BoolValue(v1.f >  v2.f)
limon_leq( v1::FloatValue, v2::FloatValue) = BoolValue(v1.f <= v2.f)
limon_geq( v1::FloatValue, v2::FloatValue) = BoolValue(v1.f >= v2.f)

limon_umin(val::FloatValue) = FloatValue(-val.f)

#
# CharValue
#

struct CharValue <: Value
    c::Char
end

function CharValue(str::AbstractString)
    CharValue(str[1])
end

# Prints for example '\n', not the new line itself.
Base.show(io::IO, charval::CharValue) =
    show(io, charval.c)

Base.print(io::IO, charval::CharValue) =
    print(io, charval.c)

typeString(::Type{CharValue}) = "char"

limon_eq( v1::CharValue, v2::CharValue) = BoolValue(v1.c == v2.c)
limon_neq(v1::CharValue, v2::CharValue) = BoolValue(v1.c != v2.c)

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

typeString(::Type{BoolValue}) = "bool"

limon_and(v1::BoolValue, v2::BoolValue) = BoolValue(v1.b & v2.b)
limon_or( v1::BoolValue, v2::BoolValue) = BoolValue(v1.b | v2.b)
limon_eq( v1::BoolValue, v2::BoolValue) = BoolValue(v1.b == v2.b)
limon_neq(v1::BoolValue, v2::BoolValue) = BoolValue(v1.b != v2.b)


limon_not(val::BoolValue) = BoolValue(!val.b)

#
# SymbolValue
#

struct SymbolValue <: Value
    str::AbstractString
end

SymbolValue(sym::Symbol) = SymbolValue(Base.String(sym))

Base.show(io::IO, symbolval::SymbolValue) =
    print(":" * symbolval.str)

typeString(::Type{SymbolValue}) = "symbol"

limon_eq( v1::SymbolValue, v2::SymbolValue) = BoolValue(v1.str == v2.str)
limon_neq(v1::SymbolValue, v2::SymbolValue) = BoolValue(v1.str != v2.str)


#
# NullValue
#

struct NullValue <: Value
end

Base.show(io::IO, nullval::NullValue) =
    print(io, "#<null>")

typeString(::Type{NullValue}) = "null"

limon_eq( v1::NullValue, v2::NullValue) = BoolValue(true)
limon_neq(v1::NullValue, v2::NullValue) = BoolValue(false)



#
# ArrayValue
#

struct ArrayValue <: Value
    array::Array{Value, 1}
end

ArrayValue(str::AbstractString) =
    ArrayValue(map(c -> CharValue(c),
                   collect(str)))

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
        print(io, " ")
        show(io, val)
    end
    print(io, "]")
end

function print_str(arrayval::ArrayValue)
    for c in arrayval
        c::CharValue
    end
    print(Base.String(map(cval -> cval.c, arrayval)))
end

Base.iterate(arrayval::ArrayValue, state=1) =
    if state > length(arrayval.array)
        nothing
    else
        (arrayval.array[state], state+1)
    end

typeString(::Type{ArrayValue}) = "array"

String(arrayval::ArrayValue) =
    Base.String(map(charval -> charval.c, arrayval))

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

typeString(::Type{ProcValue}) = "procedure"

#
# Convertions
#

convert_limon_value(::Type{IntegerValue}, val::FloatValue) =
    IntegerValue(floor(val.f))
convert_limon_value(::Type{IntegerValue}, val::CharValue) =
    IntegerValue(val.c)

convert_limon_value(::Type{CharValue}, val::IntegerValue) =
    CharValue(val.n)

convert_limon_value(::Type{FloatValue}, val::IntegerValue) =
    FloatValue{Float64}(floor(val.n))


end # module value
