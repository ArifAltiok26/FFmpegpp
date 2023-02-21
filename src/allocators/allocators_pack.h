#pragma once
namespace ygv::allocators
{
template <typename... Allocators> struct AllocatorsPack : public Allocators...
{
    using Allocators::allocate...;
    using Allocators::destroy...;
};
} // namespace ygv::allocators