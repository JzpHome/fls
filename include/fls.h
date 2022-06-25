#ifndef __FLS_FLS_H_
#define __FLS_FLS_H_

#include <cstdarg>

#ifdef __cplusplus
extern "C" {
#endif

enum FLS_LOG_LEVEL {
    FLS_LOG_LEVEL_REVERSED = 0,
    FLS_LOG_LEVEL_ERR,
    FLS_LOG_LEVEL_WARN,
    FLS_LOG_LEVEL_INFO,
    FLS_LOG_LEVEL_DEBUG,
    FLS_LOG_LEVEL_VERBOSE,
};

/**
 * @brief   get current log level
 * @return  current log level
 */
enum FLS_LOG_LEVEL fls_get_log_level(void);

/**
 * @brief   change log level to special level
 * @param   level   special level
 * @return  none
 */
void fls_set_log_level(enum FLS_LOG_LEVEL level);


/**
 * @brief   set the log storage destination
 * @param   destination     the storage location
 */
void fls_set_log_destination(const char *destination);



/*======================== inner function =========================*/
extern void __fls_inner_log(const char *fmt, ...);



/*=========================== log func ============================*/
#define FLS_ERR(fmt, ...) \
    do { \
        if(fls_get_log_level() < FLS_LOG_LEVEL_ERR) { \
            break; \
        } \
        __fls_inner_log("[%s][Err] " fmt, , __func__, ##__VA_ARGS__); \
    } while(0)


#define FLS_WARN(fmt, ...) \
    do { \
        if(fls_get_log_level() < FLS_LOG_LEVEL_WARN) { \
            break; \
        } \
        __fls_inner_log("[%s][Warn] " fmt, , __func__, ##__VA_ARGS__); \
    } while(0)


#define FLS_INFO(fmt, ...) \
    do { \
        if(fls_get_log_level() < FLS_LOG_LEVEL_INFO) { \
            break; \
        } \
        __fls_inner_log("[%s][Info] " fmt, , __func__, ##__VA_ARGS__); \
    } while(0)


#define FLS_DEBUG(fmt, ...) \
    do { \
        if(fls_get_log_level() < FLS_LOG_LEVEL_DEBUG) { \
            break; \
        } \
        __fls_inner_log("[%s][Debug] " fmt, , __func__, ##__VA_ARGS__); \
    } while(0)


#define FLS_VERBOSE(fmt, ...) \
    do { \
        if(fls_get_log_level() < FLS_LOG_LEVEL_VERBOSE) { \
            break; \
        } \
        __fls_inner_log("[%s][Verbose] " fmt, , __func__, ##__VA_ARGS__); \
    } while(0)

#ifdef __cplusplus
}
#endif

#endif  // __FLS_FLS_H_
