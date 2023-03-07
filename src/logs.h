#ifndef LOGS_H
#define LOGS_H

#define TRACE  0U
#define DEBUG  1U
#define INFO   2U
#define WARN   3U
#define ERROR  4U
#define SILENT 5U

void log_trace(const char* format, ...);
void log_debug(const char* format, ...);
void log_info(const char* format, ...);
void log_warn(const char* format, ...);
void log_error(const char* format, ...);

#ifndef TRACE_TAG
#define TRACE_TAG "[Trace]"
#endif /* TRACE_TAGs */

#ifndef DEBUG_TAG
#define DEBUG_TAG "[Debug]"
#endif /* DEBUG_TAG */

#ifndef INFO_TAG
#define INFO_TAG "[Info]"
#endif /* INFO_TAG */

#ifndef WARN_TAG
#define WARN_TAG "[Warning]"
#endif /* WARN_TAG */

#ifndef ERROR_TAG
#define ERROR_TAG "[Error]"
#endif /* ERROR_TAG */

#ifndef LOG_LEVEL
#define LOG_LEVEL INFO
#endif /* LOG_LEVEL */

#define MAX_OUTPUT_BUFFER_SIZE 256UL

#endif /* LOGS_H */