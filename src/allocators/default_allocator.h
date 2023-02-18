#pragma once
namespace ygv
{
template <typename DataType> struct DefaultAllocator
{
    static DataType *allocate()
    {
        return new DataType();
    }

    static template <typename... Args> DataType *allocate(Args &&...args)
    {
        return new DataType(args...);
    }

    static void destroy(DataType *data)
    {
        delete data;
    }
};
}; // namespace ygv