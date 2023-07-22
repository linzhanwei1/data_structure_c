#ifndef _STATIC_LIST_H_
#define _STATIC_LIST_H_
#include "SeqList.h"

namespace DTLib {
template <typename T, int N> class StaticList : public SeqList<T> {
protected:
    T m_space[ N ];

public:
    StaticList() {
        this->m_array  = m_space;
        this->m_length = 0;
    }
    int capacity() const {
        return N;
    }
};
} // namespace DTLib

#endif /* _STATIC_LIST_H_ */
