#ifndef STROPS_H
#define STROPS_H

#include <ctype.h>
#include <stdbool.h>

bool starts_with(const char* str, const char* pre);

bool starts_with_ci(const char* str, const char* pre);

const char* skip_str(const char* str, const char* pre);

const char* skip_str_ci(const char* str, const char* pre);

const char* skip_lws(const char* str);

#endif /* STROPS_H */
