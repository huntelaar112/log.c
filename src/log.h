/**
 * Copyright (c) 2020 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#define LOG_VERSION "0.1.0"

typedef struct {
	va_list ap;
	const char *tag;
	const char *fmt;
	const char *file;
	struct tm *time;
	void *outfile;
	int line;
	int level;
} log_Event;

typedef void (*log_LogFn)(log_Event *ev);
typedef void (*log_LockFn)(bool lock, void *outfile);

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#define log_trace(tag, ...) log_log(tag, LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
/*
#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...)  log_log(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...)  log_log(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)
*/
#define log_debug(tag, ...) log_log(tag, LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(tag, ...)  log_log(tag, LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(tag, ...)  log_log(tag, LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define log_error(tag, ...) log_log(tag, LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(tag, ...) log_log(tag, LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)


const char* log_level_string(int level);
void log_set_lock(log_LockFn fn, void *outfile);
void log_set_level(int level);
void log_set_quiet(bool enable);
int log_add_callback(log_LogFn fn, void *outfile, int level);
int log_add_fp(FILE *fp, int level);

void log_log(const char *tag, int level,  const char *file, int line, const char *fmt, ...);

#endif
