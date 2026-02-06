/* begin of file log_utils.c */
/* glibc headers */
#include <stdio.h>
#include <string.h>
#include <time.h>

/* own headers */
#include "log_utils.h"

/* log_file global definition */
char log_file[64];

void get_log_filename(char *buffer, size_t size) 
{
        /* get current time as Unix timestamp */
        time_t now = time(NULL);
        /* convert timestamp to local time structure */
        struct tm *t = localtime(&now);
        
        /** 
         * format and write filename to buffer for safety,
         * %02d ensures numbers are padded with zeros to 2 digits,
         * tm_mon is 0-based, so add 1 for human-readable month,
         * tm_year is years since 1900, so add 1900 for current year
         */
        snprintf(buffer, size, "log_%02d-%02d-%04d_%02d-%02d.txt",
                t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
                t->tm_hour, t->tm_min);
}

/* Function to log a message with module information */
void log_message(const char *module, const char *message) 
{
        /** 
         * open file in append mode ("a"),
         * creates the file if it doesn't exist
         */
        FILE *fp = fopen(log_file, "a");
        if (!fp) return;  /* return silently if file can't be opened */

        /* get current time for the log entry */
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        /**
         * write timestamped message to file,
         * format: [HH:MM:SS] module_name message
         */
        fprintf(fp, "[%02d:%02d:%02d] %s %s\n",
                t->tm_hour, t->tm_min, t->tm_sec, 
                module ? module : "", message);

        /* close file to save changes and free resources */
        fclose(fp);
}

/* function to log a separator line with section and subsection */
void log_separator(const char* section, const char* subsection) 
{
        /**
         * open file in append mode ("a"),
         * this creates the file if it doesn't exist
         */
        FILE *fp = fopen(log_file, "a");
        if (!fp) return;  /* Return silently if file can't be opened */

        /* write separator lines and section/subsection information */
        fprintf(fp, "\n%s\n", "===========================================");

        if (section && subsection) {
                /* if both section and subsection are provided, print them */
                fprintf(fp, "    %s - %s\n", section, subsection);
        } else if (section) {
                /* if only section is provided, print it */
                fprintf(fp, "            %s\n", section);
        }
        
        fprintf(fp, "%s\n\n", "===========================================");

        /* close file to save changes and free resources */
        fclose(fp);
}

/* function to log an error message (backward compatibility) */
void log_error(const char *filename __attribute__((unused)), const char *message) 
{
        /* call log_message with NULL module */
        log_message(NULL, message);
}
/* end of file log_utils.c */
