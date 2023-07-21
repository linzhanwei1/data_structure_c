#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cstddef>
#include <cstdlib>

namespace DTLib {
class Object {
public:
    void *operator new(size_t size) throw();
    void  operator delete(void *p);
    void *operator new[](size_t size) throw();
    void  operator delete[](void *p);
    bool  operator==(const Object &obj);
    bool  operator!=(const Object &obj);
    virtual ~Object() = 0;
};
} // namespace DTLib

#endif /* _OBJECT_H_ */
