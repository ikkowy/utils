#include <utils/strops.h>

bool starts_with(const char* str, const char* pre) {
    while (*pre != '\0' && *str != '\0')
        if (*pre++ != *str++)
            return false;
    return *pre == '\0';
}

bool starts_with_ci(const char* str, const char* pre) {
    while (*str != '\0' && *pre != '\0')
        if (tolower(*str++) != tolower(*pre++))
            return false;
    return *pre == '\0';
}

const char* skip_str(const char* str, const char* pre) {
    const char* str_ = str;
    while (*pre != '\0' && *str != '\0')
        if (*pre++ != *str++)
            return str_;
    if (*pre == '\0') return str;
    return str_;
}

const char* skip_str_ci(const char* str, const char* pre) {
    const char* str_ = str;
    while (*pre != '\0' && *str != '\0')
        if (tolower(*pre++) != tolower(*str++))
            return str_;
    if (*pre == '\0') return str;
    return str_;
}

const char* skip_lws(const char* str) {
    while (*str == ' ' || *str == '\t' ) ++str;
    return str;
}
