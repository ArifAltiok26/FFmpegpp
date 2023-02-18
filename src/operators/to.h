#pragma once
#include "tags/to_execution.h"
namespace ygv
{

template <typename Object, typename... Args> auto to(Object &&object, Args &&...args)
{
    return object(ToExecutionTag, std::forward<Args>(args)...);
}

} // namespace ygv