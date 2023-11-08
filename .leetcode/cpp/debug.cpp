

#ifdef DEBUG_L

#include <cstdio>

using PrintLevel = enum PrintLevel {
    L_NOTICE = 1, //一般输出
    L_WARNING = 2, //告警输出
    L_TRACE = 3, //追踪调试
    L_DEBUG = 4, //软件bug
    L_FATAL = 5 //致命错误
};
#define Log(level, log_fmt, ...)                                                                                \
    do {                                                                                                        \
        switch (level) {                                                                                        \
        case L_FATAL:                                                                                           \
            printf("L(5,FATAL)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);   \
            break;                                                                                              \
        case L_DEBUG:                                                                                           \
            printf("L(4,DEBUG)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);   \
            break;                                                                                              \
        case L_TRACE:                                                                                           \
            printf("L(3,TRACE)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);   \
            break;                                                                                              \
        case L_WARNING:                                                                                         \
            printf("L(2,WARNING)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            break;                                                                                              \
        case L_NOTICE:                                                                                          \
            printf("L(1,NOTICE)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);  \
            break;                                                                                              \
        default:                                                                                                \
            printf("L(-1,UNKOWN)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            break;                                                                                              \
        }                                                                                                       \
    } while (0)
#else

#define MyPrint(level, log_fmt, ...)

#endif

#ifdef DEBUG_L

#define log(log_fmt, ...) \
    fprintf(stderr, "L(3,TRACE)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);

#define msg(log_fmt) \
    fprintf(stderr, "L(3,TRACE)[%s:%d][%s] \n" log_fmt "\n", __FILE__, __LINE__, __FUNCTION__);

#endif

#undef DEBUG_L

#ifdef TEST_LOG
auto main() -> int
{
    log("hello world ");
    msg("hello world");
}
#endif

#undef TEST_LOG