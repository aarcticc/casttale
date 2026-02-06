/* begin of file log_utils.h */
#ifndef LOG_UTILS_H
#define LOG_UTILS_H

/* glibc headers */
#include <stddef.h>


/* module identifiers for logging */
#define LOG_MODULE_SYSTEM    "[System]"
#define LOG_MODULE_SDL       "[SDL]"
#define LOG_MODULE_GRAPHICS  "[Graphics]"
#define LOG_MODULE_TEXTURE   "[Texture]"
#define LOG_MODULE_MAP       "[Map]"
#define LOG_MODULE_PLAYER    "[Player]"
#define LOG_MODULE_INPUT     "[Input]"
#define LOG_MODULE_CONFIG    "[Config]"
#define LOG_MODULE_RENDER    "[Render]"
#define LOG_MODULE_ASSET     "[Asset]"
#define LOG_MODULE_RESOURCE  "[Resource]"

/* log sections for better organization */
#define LOG_SECTION_INIT     "INITIALIZATION"
#define LOG_SECTION_GAME     "GAME LOOP"
#define LOG_SECTION_SHUTDOWN "SHUTDOWN SEQUENCE"
#define LOG_SECTION_ERROR    "ERROR"

/**
 * global array to store the log file name,
 * size of 64 characters allows for reasonable file path length,
 * 'extern' keyword makes this variable accessible from other source files
 */
extern char log_file[64];

/**
 * function to generate a log filename based on current date/time,
 * parameters:
 *   buffer - destination where the generated filename will be stored
 *   size   - size of the buffer to prevent buffer overflow
 */
void get_log_filename(char *buffer, size_t size);

/**
 * function to write error messages to the log file,
 * parameters:
 *   filename - name of the file where the error occurred
 *   message  - the error message to be logged
 */
 void log_error(const char *filename, const char *message);

/**
 * Function to write a separator line to the log file,
 * Parameters:
 *   filename - name of the file where the separator is logged
 *   phase    - the game phase to be logged
 */
void log_separator(const char* section, const char* subsection);

/**
 * function to log messages with module identifier,
 * parameters:
 *   module  - the module identifier for the log message
 *   message  - the message to be logged
 */
void log_message(const char *module, const char *message);

#endif