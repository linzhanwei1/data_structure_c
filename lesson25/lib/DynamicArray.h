#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include "Array.h"
#include "Exception.h"

namespace DTLib {
template <typename T> class DynamicArray : public Array<T> {
protected:
    int m_length;

    T *copy(T *array, int len, int newLen) {
        T *ret = new T[ newLen ];

        if (ret != NULL) {
            int size = (len < newLen) ? len : newLen;

            for (int i = 0; i < size; i++) {
                ret[ i ] = array[ i ];
            }
        }

        return ret;
    }
    void update(T *array, int length) {
        if (array != NULL) {
            T *temp = this->m_array;

            this->m_array  = array;
            this->m_length = length;

            delete[] temp;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update DynamicArray object ...");
        }
    }
    void init(T *array, int length) {
        if (array != NULL) {
            this->m_array  = array;
            this->m_length = length;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
        }
    }

public:
    DynamicArray(int length) {
        init(new T[ length ], length);
    }
    DynamicArray(const DynamicArray<T> &obj) {
        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
    }
    DynamicArray<T> &operator=(const DynamicArray<T> &obj) {
        if (this != &obj) {
            update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
        }
        return *this;
    }
    int length() const {
        return m_length;
    }
    void resize(int length) {
        if (length != m_length) {
            update(copy(this->m_array, m_length, length), length);
        }
    }

    ~DynamicArray() {
        delete[] this->m_array;
    }
};

} // namespace DTLib

#endif /* _DYNAMIC_ARRAY_H__ */
