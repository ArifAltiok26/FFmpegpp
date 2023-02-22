#pragma once
namespace ygv::allocators
{
template <typename DataType> struct Default_w
{
    static DataType *allocate()
    {
        return new DataType();
    }

    template <typename... Args> DataType *allocate(Args &&...args)
    {
        return new DataType(args...);
    }

    static void destroy(DataType *data)
    {
        delete data;
    }
};
}; // namespace ygv::allocators