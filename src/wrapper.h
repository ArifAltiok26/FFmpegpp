#pragma once
#include "wrapper_base.h"
namespace ygv
{

template <typename DataType, typename Allocator, typename Executor> class Wrapper;

template <typename DataType, typename Allocator>
class Wrapper<DataType, Allocator, void> : public WrapperBase<DataType, Allocator>
{
  public:
    using WrapperBase<DataType, Allocator>::WrapperBase;
};

template <typename DataType, typename Allocator, typename Executor>
class Wrapper : public WrapperBase<DataType, Allocator>
{
  public:
    using WrapperBase<DataType, Allocator>::WrapperBase;

    template <typename... Args> auto operator()(Args &&...args)
    {
        return Executor::execute(*this, std::forward<Args>(args)...);
    }
};

} // namespace ygv