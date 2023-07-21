#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "Object.h"

namespace DTLib {

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception : public Object {
protected:
    char *m_message;
    char *m_location;

    void init(char const *message, char const *file, int line);

public:
    Exception(char const *message);
    Exception(char const *file, int line);
    Exception(char const *message, char const *file, int line);
    Exception(const Exception &e);
    Exception &operator=(const Exception &e);

    virtual char const *message() const;
    virtual char const *location() const;

    virtual ~Exception() = 0;
};

class ArithmeticException : public Exception {
public:
    ArithmeticException()
        : Exception(0) {
    }
    ArithmeticException(char const *message)
        : Exception(message) {
    }
    ArithmeticException(char const *file, int line)
        : Exception(file, line) {
    }
    ArithmeticException(char const *message, char const *file, int line)
        : Exception(message, file, line) {
    }

    ArithmeticException(const ArithmeticException &e)
        : Exception(e) {
    }
    ArithmeticException &operator=(const ArithmeticException &e) {
        Exception::operator=(e);
        return *this;
    }
    char const *message() const {
        return m_message;
    }
    char const *location() const {
        return m_location;
    }
};

class NullPointerException : public Exception {
public:
    NullPointerException()
        : Exception(0) {
    }
    NullPointerException(char const *message)
        : Exception(message) {
    }
    NullPointerException(char const *file, int line)
        : Exception(file, line) {
    }
    NullPointerException(char const *message, char const *file, int line)
        : Exception(message, file, line){};

    NullPointerException(const NullPointerException &e)
        : Exception(e) {
    }
    NullPointerException &operator=(const NullPointerException &e) {
        Exception::operator=(e);
        return *this;
    }
};

class IndexOutOfBoundsException : public Exception {
public:
    IndexOutOfBoundsException()
        : Exception(0) {
    }
    IndexOutOfBoundsException(const char *message)
        : Exception(message) {
    }
    IndexOutOfBoundsException(const char *file, int line)
        : Exception(file, line) {
    }
    IndexOutOfBoundsException(const char *message, const char *file, int line)
        : Exception(message, file, line) {
    }

    IndexOutOfBoundsException(const IndexOutOfBoundsException &e)
        : Exception(e) {
    }

    IndexOutOfBoundsException &operator=(const IndexOutOfBoundsException &e) {
        Exception::operator=(e);

        return *this;
    }
};

class NoEnoughMemoryException : public Exception {
public:
    NoEnoughMemoryException()
        : Exception(0) {
    }
    NoEnoughMemoryException(const char *message)
        : Exception(message) {
    }
    NoEnoughMemoryException(const char *file, int line)
        : Exception(file, line) {
    }
    NoEnoughMemoryException(const char *message, const char *file, int line)
        : Exception(message, file, line) {
    }

    NoEnoughMemoryException(const NoEnoughMemoryException &e)
        : Exception(e) {
    }

    NoEnoughMemoryException &operator=(const NoEnoughMemoryException &e) {
        Exception::operator=(e);

        return *this;
    }
};

class InvalidParameterException : public Exception {
public:
    InvalidParameterException()
        : Exception(0) {
    }
    InvalidParameterException(const char *message)
        : Exception(message) {
    }
    InvalidParameterException(const char *file, int line)
        : Exception(file, line) {
    }
    InvalidParameterException(const char *message, const char *file, int line)
        : Exception(message, file, line) {
    }

    InvalidParameterException(const InvalidParameterException &e)
        : Exception(e) {
    }

    InvalidParameterException &operator=(const InvalidParameterException &e) {
        Exception::operator=(e);

        return *this;
    }
};

class InvalidOperationException : public Exception {
public:
    InvalidOperationException()
        : Exception(0) {
    }
    InvalidOperationException(const char *message)
        : Exception(message) {
    }
    InvalidOperationException(const char *file, int line)
        : Exception(file, line) {
    }
    InvalidOperationException(const char *message, const char *file, int line)
        : Exception(message, file, line) {
    }

    InvalidOperationException(const InvalidOperationException &e)
        : Exception(e) {
    }

    InvalidOperationException &operator=(const InvalidOperationException &e) {
        Exception::operator=(e);

        return *this;
    }
};

} // namespace DTLib

#endif /* _EXCEPTION_H_ */
