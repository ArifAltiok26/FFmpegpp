#pragma once
#include "allocators/default.h"
#include "object_base.h"
namespace ygv
{

template <typename DataType, typename Allocator = allocators::Default<DataType>, typename OperatorPolicy = void>
class Object;

template <typename DataType, typename Allocator>
class Object<DataType, Allocator, void> : public ObjectBase<DataType, Allocator>
{
  public:
    using ObjectBase<DataType, Allocator>::ObjectBase;
};

template <typename DataType, typename Allocator, typename OperatorPolicy>
class Object : public ObjectBase<DataType, Allocator>
{
  public:
    using ObjectBase<DataType, Allocator>::ObjectBase;

    template <typename... Args> auto operator()(Args &&...args)
    {
        return OperatorPolicy::execute(*this, std::forward<Args>(args)...);
    }
};

} // namespace ygv