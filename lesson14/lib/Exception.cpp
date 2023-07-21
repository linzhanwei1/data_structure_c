#include "Exception.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

namespace DTLib {

void Exception::init(char const *message, char const *file, int line) {
    m_message = (message ? strdup(message) : NULL);

    if (file != NULL) {
        char s1[ 16 ] = {0};

        snprintf(s1, sizeof(s1), "%d", line);
        m_location = static_cast<char *>(malloc(strlen(file) + strlen(s1) + 2));

        if (m_location != NULL) {
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, s1);
        }
    } else {
        m_location = NULL;
    }
}

Exception::Exception(char const *message) {
    init(message, NULL, 0);
}

Exception::Exception(char const *file, int line) {
    init(NULL, file, line);
}

Exception::Exception(char const *message, char const *file, int line) {
    init(message, file, line);
}

Exception::Exception(const Exception &e) {
    m_message  = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception &Exception::operator=(const Exception &e) {
    if (this != &e) {
        free(m_message);
        free(m_location);

        m_message  = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    return *this;
}

char const *Exception::message() const {
    return m_message;
}

char const *Exception::location() const {
    return m_location;
}

Exception::~Exception() {
    free(m_message);
    free(m_location);
}

} // namespace DTLib
