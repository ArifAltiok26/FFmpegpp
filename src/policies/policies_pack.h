#pragma once
namespace ygv::policies
{
template <typename... Policies> struct PoliciesPack : Policies...
{
    using Policies::execute...;
};
} // namespace ygv::policies