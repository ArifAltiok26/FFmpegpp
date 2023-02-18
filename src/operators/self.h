#pragma once
#include "tags/self_execution.h"
#include <utility>
namespace ygv
{

template <typename Object, typename... Args> auto self(Object &&object, Args &&...args)
{
    return object(SelfExecutionTag, std::forward<Args>(args)...);
}

} // namespace ygv