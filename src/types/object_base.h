#pragma once
#include <utility>
namespace ygv
{
template <typename DataType, typename Allocator> class ObjectBase
{
  public:
    template <typename... Args> ObjectBase(Args &&...args) : m_data(Allocator::allocate(std::forward<Args>(args)...))
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

    operator DataType *()
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
            Allocator::destroy(m_data);
        }
    }

  private:
    DataType *m_data;
};
} // namespace ygv