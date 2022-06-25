#include <cstdarg>
#include <cstdio>
#include <ctime>

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
    const char *format = "%F %T";

    // timestamp
    char timestamp[1024] = {'\0'};
    auto now = std::time(nullptr);
    std::strftime(timestamp, sizeof(timestamp), format, std::localtime(&now));
    fprintf(file, "[%s]", timestamp);

    // message
    vfprintf(file, fmt, list);
    fflush(file);

    va_end(list);
}
