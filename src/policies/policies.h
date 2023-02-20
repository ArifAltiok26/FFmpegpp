#pragma once
namespace ygv
{
template <typename... PolicyTypes> struct Policies : PolicyTypes...
{
    using PolicyTypes::execute...;
};
} // namespace ygv