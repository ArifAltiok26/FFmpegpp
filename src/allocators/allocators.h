#pragma once
namespace ygv
{
template <typename... AllocatorTypes> struct Allocators : public AllocatorTypes...
{
    using AllocatorTypes::allocate...;
    using AllocatorTypes::destroy...;
};
} // namespace ygv