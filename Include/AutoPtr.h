#if !defined(_CAutoPtr_H_)
#define _CAutoPtr_H_

#include "com_exception.h"

template<class T>
class CAutoPtr
{
public:
    typedef T _PtrClass;

    explicit CAutoPtr(_PtrClass *_P = 0)
        : m_bOwns(_P != 0),
          m_ptr(_P)
    {
    }

    CAutoPtr(const CAutoPtr<_PtrClass>& _Y)
        : m_bOwns(_Y.m_bOwns),
          m_ptr(_Y.Release())
    {
    }

    CAutoPtr<_PtrClass>& operator=(const CAutoPtr<_PtrClass>& _Y)
    {
        if (this != &_Y)
        {
            if (m_ptr != _Y.Get())
            {
                if (m_bOwns)
                {
                    delete m_ptr;
                }
                m_bOwns = _Y.m_bOwns;
            }
            else if (_Y.m_bOwns)
            {
                m_bOwns = true;
            }
            m_ptr = _Y.Release();
        }
        return (*this);
    }

    ~CAutoPtr()
    {
        if (m_bOwns)
        {
            delete m_ptr;
        }
    }

    _PtrClass& operator*() const
    {
        if (!m_ptr)
        {
#ifdef _AFX
            AfxThrowMemoryException();
#else
            com_exception ce( E_OUTOFMEMORY );
            throw ce;
#endif
        }
        return (*Get());
    }

    _PtrClass *operator->() const
    {
        if (!m_ptr)
        {
#ifdef _AFX
            AfxThrowMemoryException();
#else
            com_exception ce( E_OUTOFMEMORY );
            throw ce;
#endif
        }
        return (Get());
    }

    bool operator!() const
    {
        return (m_ptr == NULL);
    }

    _PtrClass* Get() const
    {
        return (m_ptr);
    }

    _PtrClass* Release() const
    {
        m_bOwns = false;
        _PtrClass* ptr = m_ptr;
        m_ptr = 0;
        return (ptr);
    }

    void Delete()
    {
        if (m_bOwns)
        {
            delete m_ptr;
            m_ptr = 0;
            m_bOwns = false;
        }
    }

private:
    mutable bool m_bOwns;
    mutable _PtrClass* m_ptr;
};

#endif //_CAutoPtr_H_
