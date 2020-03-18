module Limon_Value

abstract type Value end

struct IntegerValue <: Value
    n::BigInt
end

IntegerValue(int_str::AbstractString) =
    IntegerValue(parse(BigInt, int_str))

Base.show(io::IO, intval::IntegerValue) =
    show(io, intval.n)


struct BoolValue <: Value
    b::Bool
end

Base.show(io::IO, boolval::BoolValue) =
    if boolval.b
        print(io, "#<true>")
    else
        print(io, "#<false>")
    end


struct NullValue <: Value
end

Base.show(io::IO, nullval::NullValue) =
    print(io, "#<null>")


struct ArrayValue <: Value
    array::Array{Value, 1}
    ArrayValue(value_array::Array{T, 1}) where {T <: Value} =
        new(value_array)
end

ArrayValue(n::Integer) = ArrayValue(fill(NullValue(), n))

Base.getindex(array_value::ArrayValue, key) =
    array_value.array[key]

Base.setindex!(array_value::ArrayValue, value, key) =
    array_value.array[key = value]

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

end # module value
