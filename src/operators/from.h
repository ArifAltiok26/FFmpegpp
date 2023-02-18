#pragma once
#include "tags/from_execution.h"
namespace ygv
{

template <typename Object, typename... Args> auto from(Object &&object, Args &&...args)
{
    return object(FromExecutionTag, std::forward<Args>(args)...);
};

} // namespace ygv