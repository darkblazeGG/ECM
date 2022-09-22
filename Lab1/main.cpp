#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double Result(int N, double x)
{
    double result = 0;
    for (int i = 1, t = 1, p = x; i < N; i++, t *= -1, p *= x)
        result += t * p / i;
    return result;
}

int main(int argc, char **argv)
{
    double result, x = 0.1;
    struct timespec start, end;
    int N = strtol(argv[1], NULL, 10);

    if (N < 0) // Условие чтобы было дано число больше нуля
        return 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    result = Result(N, x);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    printf("Spent %lf sec.\n for get result %lf", end.tv_sec - start.tv_sec + 0.000000001 * (end.tv_nsec - start.tv_nsec), result);

    return 0;
}
