#pragma once
#include "object_base.h"
namespace ygv
{

template <typename DataType, typename Allocator, typename OperatorPolicies> class Object;

template <typename DataType, typename Allocator>
class Object<DataType, Allocator, void> : public ObjectBase<DataType, Allocator>
{
  public:
    using ObjectBase<DataType, Allocator>::ObjectBase;
};

template <typename DataType, typename Allocator, typename OperatorPolicies>
class Object : public ObjectBase<DataType, Allocator>
{
  public:
    using ObjectBase<DataType, Allocator>::ObjectBase;

    template <typename... Args> auto operator()(Args &&...args)
    {
        return OperatorPolicies::execute(*this, std::forward<Args>(args)...);
    }
};

} // namespace ygv