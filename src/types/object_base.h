#pragma once
#include <utility>
namespace ygv
{
template <typename DataType, typename Allocator> class ObjectBase : Allocator
{
  private:
    using Allocator::allocate;
    using Allocator::destroy;

  public:
    template <typename... Args> ObjectBase(Args &&...args) : m_data(allocate(std::forward<Args>(args)...))
    {
    }

    ObjectBase(DataType *data) : m_data(data)
    {
    }

    ObjectBase(ObjectBase &&other) : m_data(other.m_data)
    {
        other.m_data = nullptr;
    }

    ObjectBase &operator=(ObjectBase &&other)
    {
        destroy();
        std::swap(m_data, other.m_data);
        return *this;
    }

    ~ObjectBase()
    {
        destroy();
    }

    operator bool() const
    {
        return m_data;
    }

    operator DataType *&()
    {
        return m_data;
    }

    operator DataType *() const
    {
        return m_data;
    }

    DataType *operator->()
    {
        return m_data;
    }

    const DataType *operator->() const
    {
        return m_data;
    }

    DataType **operator&()
    {
        return &m_data;
    }

    const DataType **operator&() const
    {
        return &m_data;
    }

  private:
    void destroy()
    {
        if (m_data)
        {
            destroy(m_data);
            m_data = nullptr;
        }
    }

  private:
    DataType *m_data;
};
} // namespace ygv