#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>

#include "additions.h"

FILE* stdin;
FILE* stdout;
FILE* stderr;
int fflush(FILE * f) { return 0; }
int fprintf(FILE *stream, const char *format, ...) { return 0; }


char* strdup(const char* s)
{
    char* d = malloc(strlen(s) + 1);
    if (d != NULL)
        strcpy(d, s);
    return d;
}

int strcasecmp(const char* s1, const char* s2)
{
    const unsigned char* us1 = (const unsigned char*)s1;
    const unsigned char* us2 = (const unsigned char*)s2;

    while (tolower(*us1) == tolower(*us2)) {
        if (*us1++ == '\0')
            return (0);
        us2++;
    }
    return (tolower(*us1) - tolower(*us2));
}

int strncasecmp(const char* s1, const char* s2, size_t n)
{
    if (n != 0) {
        const unsigned char* us1 = (const unsigned char*)s1;
        const unsigned char* us2 = (const unsigned char*)s2;

        do {
            if (tolower(*us1) != tolower(*us2))
                return (tolower(*us1) - tolower(*us2));
            if (*us1++ == '\0')
                break;
            us2++;
        } while (--n != 0);
    }
    return (0);
}

int snprintf(char* s, size_t n, const char* format, ...)
{
    va_list args;
    char* buffer;
    int n_ret = 0;

    buffer = (char*)malloc(n);
    if (!buffer)
        return 0;

    va_start(args, format);
    n_ret = vsprintf(buffer, format, args);
    va_end(args);

    free(buffer);

    return n_ret;
}


#define PI      3.14159265358979324  /* $\pi$ */
#define LOG_2PI 1.83787706640934548  /* $\log 2\pi$ */
#define N       8

#define B0  1                 /* Bernoulli numbers */
#define B1  (-1.0 / 2.0)
#define B2  ( 1.0 / 6.0)
#define B4  (-1.0 / 30.0)
#define B6  ( 1.0 / 42.0)
#define B8  (-1.0 / 30.0)
#define B10 ( 5.0 / 66.0)
#define B12 (-691.0 / 2730.0)
#define B14 ( 7.0 / 6.0)
#define B16 (-3617.0 / 510.0)

static double loggamma(double x)  /* the natural logarithm of the Gamma function. */
{
    double v, w;

    v = 1;
    while (x < N) {  v *= x;  x++;  }
    w = 1 / (x * x);
    return ((((((((B16 / (16 * 15))  * w + (B14 / (14 * 13))) * w
                + (B12 / (12 * 11))) * w + (B10 / (10 *  9))) * w
                + (B8  / ( 8 *  7))) * w + (B6  / ( 6 *  5))) * w
                + (B4  / ( 4 *  3))) * w + (B2  / ( 2 *  1))) / x
                + 0.5 * LOG_2PI - log(v) - x + (x - 0.5) * log(x);
}

double tgamma(double x)  /* Gamma function */
{
    if (x == 0.0) { /* Pole Error */
        errno = ERANGE;
        return 1/x < 0 ? -HUGE_VAL : HUGE_VAL;
    }
    if (x < 0) {
        int sign;
        static double zero = 0.0;
        double i, f;
        f = modf(-x, &i);
        if (f == 0.0) { /* Domain Error */
            errno = EDOM;
            return zero/zero;
        }
        sign = (fmod(i, 2.0) != 0.0) ? 1 : -1;
        return sign * PI / (sin(PI * f) * exp(loggamma(1 - x)));
    }
    return exp(loggamma(x));
}



static double zero(void) { return 0.0; }
static double one (void) { return 1.0; }
static double inf (void) { return one() / zero(); }

int isinf(double n)
{
    static double pinf = 0.0;
    static double ninf = 0.0;

    if (pinf == 0.0) {
        pinf = inf();
        ninf = -pinf;
    }
    return memcmp(&n, &pinf, sizeof n) == 0
        || memcmp(&n, &ninf, sizeof n) == 0;
}

int finite(double n)
{
    return !isnan(n) && !isinf(n);
}

int isascii(int c)
{
	return c >= 0 && c< 128;
}

static int double_ne(double n1, double n2);

int isnan(double n)
{
    return double_ne(n, n);
}

static int double_ne(double n1, double n2)
{
    return n1 != n2;
}