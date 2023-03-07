#include "logs.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static void log_print(FILE* stream, const char* format, const char* tag, va_list args);

#if (LOG_LEVEL > TRACE)
void log_trace([[maybe_unused]]const char* format, ...) {}
#else 
void log_trace(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_print(stderr, format, TRACE_TAG, args);
    va_end(args);
}
#endif /* LOG_LEVEL > TRACE */

#if (LOG_LEVEL > DEBUG)
void log_debug([[maybe_unused]]const char* format, ...) {}
#else
void log_debug(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_print(stderr, format, DEBUG_TAG, args);
    va_end(args);
}
#endif /* LOG_LEVEL > DEBUG */

#if (LOG_LEVEL > INFO)
void log_info([[maybe_unused]]const char* format, ...) {}
#else
void log_info(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_print(stderr, format, INFO_TAG, args);
    va_end(args);
}
#endif /* LOG_LEVEL > INFO */

#if (LOG_LEVEL > WARN)
void log_warn([[maybe_unused]]const char* format, ...) {}
#else
void log_warn(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_print(stderr, format, WARN_TAG, args);
    va_end(args);
}
#endif /* LOG_LEVEL > WARN */

#if (LOG_LEVEL > ERROR)
void log_error([[maybe_unused]]const char* format, ...) {}
#else
void log_error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_print(stderr, format, ERROR_TAG, args);
    va_end(args);
}

void log_print(FILE* stream, const char* format, const char* tag, va_list args) {
    char format_str_buffer[MAX_OUTPUT_BUFFER_SIZE];
    snprintf(format_str_buffer, MAX_OUTPUT_BUFFER_SIZE, "%s %s \n\r", tag, format);
    
    char output_str_buffer[MAX_OUTPUT_BUFFER_SIZE];
    vsnprintf(output_str_buffer, MAX_OUTPUT_BUFFER_SIZE, (const char*) format_str_buffer, args);    

    fprintf(stream, (const char*)output_str_buffer);
}


#endif /* LOG_LEVEL > ERROR */