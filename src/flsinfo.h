#ifndef __FLS_FLSINFO_H_
#define __FLS_FLSINFO_H_

#include <cstdio>
#include "fls.h"

class FLSInfo {
    public:
        static FLSInfo & getInstance();

        enum FLS_LOG_LEVEL level() const;

        FILE *destination() const;

        void setLevel(enum FLS_LOG_LEVEL level);

        void setDestination(const char *destination);

    private:
        FLSInfo(enum FLS_LOG_LEVEL level);

    private:
        enum FLS_LOG_LEVEL __level;
        FILE *__dest;
};

#endif  // __FLS_FLSINFO_H_
