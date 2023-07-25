#ifndef _SMART_POINTER_H_
#define _SMART_POINTER_H_

/*
 * 当代C++软件平台中的只能指针
 * 1.指针生命周期结束时主动释放空间
 * 2.一片堆空间最多只能由一个指针标识
 * 3.杜绝指针运算和指针比较
 */
#include "Object.h"

namespace DTLib {
template <typename T> class SmartPointer : public Object {
protected:
    T *m_pointer;

public:
    SmartPointer(T *p = 0) {
        m_pointer = p;
    }
    SmartPointer(const SmartPointer<T> &obj) {
        m_pointer                                    = obj.m_pointer;
        const_cast<SmartPointer<T> &>(obj).m_pointer = 0;
    }
    SmartPointer<T> &operator=(const SmartPointer<T> &obj) {
        if (this != &obj) {
            delete m_pointer;
            m_pointer                                    = obj.m_pointer;
            const_cast<SmartPointer<T> &>(obj).m_pointer = 0;
        }

        return *this;
    }
    T *operator->() {
        return m_pointer;
    }
    T &operator*() {
        return *m_pointer;
    }
    bool isNull() {
        return (m_pointer == 0);
    }
    T *get() {
        return m_pointer;
    }
    ~SmartPointer() {
        delete m_pointer;
    }
};
} // namespace DTLib

#endif /* _SMART_POINTER_H_ */
