#ifndef _LIST_H_
#define _LIST_H_

#include "Object.h"

namespace DTLib {
template <typename T> class List : public Object {
protected:
    List(const List &);
    List &operator=(const List &);

public:
    List() {
    }
    virtual bool insert(const T &e)        = 0;
    virtual bool insert(int i, const T &e) = 0;
    virtual bool remove(int i)             = 0;
    virtual bool set(int i, const T &e)    = 0;
    virtual bool get(int i, T &e) const    = 0;
    virtual int  find(const T &e) const    = 0;
    virtual int  length() const            = 0;
    virtual void clear()                   = 0;
};

} // namespace DTLib

#endif /* _LIST_H_ */
