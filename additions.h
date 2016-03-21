#ifndef ADDITIONS_H
#define ADDITIONS_H

/* Simulate FILE* and missing stdio things -- begin */
/* TODO: actually implement stuff! */
typedef void FILE;
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
int fflush(FILE *);
int fprintf(FILE *stream, const char *format, ...);
/* Simulate FILE* and missing stdio things -- end */

/* string.h additions */
char* strdup(const char* s);
int strcasecmp(const char* s1, const char* s2);
int strncasecmp(const char* s1, const char* s2, size_t n);
int snprintf(char* s, size_t n, const char* format, ...);

/* math.h additions -- from https://github.com/sj26/ruby-1.9.3-p0/blob/master/missing/tgamma.c */
static double loggamma(double x);
double tgamma(double x);

int isnan(double n);
int isinf(double n);
int finite(double n);

int isascii(int c);

#endif