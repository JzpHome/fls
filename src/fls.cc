#include <cstdarg>
#include <cstdio>

#include "fls.h"
#include "flsinfo.h"

extern "C" enum FLS_LOG_LEVEL fls_get_log_level() {
    return FLSInfo::getInstance().level();
}

extern "C" void fls_set_log_level(enum FLS_LOG_LEVEL level) {
    FLSInfo::getInstance().setLevel(level);
}

extern "C" void fls_set_log_destination(const char *destination) {
    FLSInfo::getInstance().setDestination(destination);
}

extern "C" void __fls_inner_log(const char *fmt, ...) {
    va_list list;
    va_start(list, fmt);

    FILE *file = FLSInfo::getInstance().destination();
    vfprintf(file, fmt, list);
    fflush(file);

    va_end(list);
}
