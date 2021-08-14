#include <cstdio>
#include "flsinfo.h"

FLSInfo & FLSInfo::getInstance() {
    static FLSInfo __info(FLS_LOG_LEVEL_INFO);
    return __info;
}

FLSInfo::FLSInfo(enum FLS_LOG_LEVEL level): __level(level) {
    __dest = stderr;
}

enum FLS_LOG_LEVEL FLSInfo::level() const {
    return __level;
}


FILE *FLSInfo::destination() const {
    return __dest;
}

void FLSInfo::setLevel(enum FLS_LOG_LEVEL level) {
    __level = level;
}

void FLSInfo::setDestination(const char *destination) {
    FILE *file = fopen(destination, "w");
    if(file != nullptr) {
        if(__dest != stdin || __dest != stdout || __dest != stderr) {
            fclose(__dest);
        }
        __dest = file;
    }
}
