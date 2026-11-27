/*
 * main.c - interactive menu for the problems in problems.c.
 *
 * Pick a topic, then an exercise; enter 0 to go back or quit.
 */
#include "problems.h"

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_DIVISORS 4096

/* ---- input helpers --------------------------------------------------- */

static void end_of_input(void)
{
    puts("\nEnd of input - goodbye.");
    exit(EXIT_SUCCESS);
}

static long long read_integer(const char *prompt, long long min, long long max)
{
    char line[256];
    for (;;) {
        printf("%s", prompt);
        fflush(stdout);
        if (!fgets(line, sizeof line, stdin))
            end_of_input();
        char *end;
        errno = 0;
        long long value = strtoll(line, &end, 10);
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')
            end++;
        if (end != line && *end == '\0' && errno == 0 && value >= min && value <= max)
            return value;
        printf("  Please enter a whole number between %lld and %lld.\n", min, max);
    }
}

static double read_real(const char *prompt)
{
    char line[256];
    for (;;) {
        printf("%s", prompt);
        fflush(stdout);
        if (!fgets(line, sizeof line, stdin))
            end_of_input();
        for (char *c = line; *c; c++)
            if (*c == ',')
                *c = '.'; /* accept 2,5 as well as 2.5 */
        char *end;
        errno = 0;
        double value = strtod(line, &end);
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')
            end++;
        if (end != line && *end == '\0' && errno == 0)
            return value;
        puts("  Please enter a number.");
    }
}

static size_t read_array(double *v, const char *name)
{
    char prompt[64];
    snprintf(prompt, sizeof prompt, "Number of elements in %s (1-%d): ", name, MAX_ELEMENTS);
    size_t n = (size_t)read_integer(prompt, 1, MAX_ELEMENTS);
    for (size_t i = 0; i < n; i++) {
        snprintf(prompt, sizeof prompt, "  %s[%zu] = ", name, i + 1);
        v[i] = read_real(prompt);
    }
    return n;
}

static long long read_any_integer(const char *prompt)
{
    return read_integer(prompt, LLONG_MIN + 1, LLONG_MAX);
}

/* ---- output helpers -------------------------------------------------- */

static void print_list_end(size_t printed)
{
    puts(printed ? "" : "(none)");
}

/* ---- topic 1: sums --------------------------------------------------- */

static void ex_alternating_squares(void)
{
    int n = (int)read_integer("n (1-1000000): ", 1, 1000000);
    printf("1^2 - 2^2 + 3^2 - ... +/- %d^2 = %lld\n", n, alternating_square_sum(n));
}

static void ex_multiples_of_3(void)
{
    long long n = read_integer("n (1-1000000000): ", 1, 1000000000);
    printf("Sum of the multiples of 3 below %lld = %lld\n", n, sum_multiples_of_3_below(n));
}

static void ex_ratio_sum(void)
{
    int n = (int)read_integer("n (1-10000000): ", 1, 10000000);
    printf("1/2 + 2/3 + ... + %d/%d = %.6f\n", n, n + 1, ratio_sum(n));
}

/* ---- topic 2: digits ------------------------------------------------- */

static void ex_digit_sum(void)
{
    long long n = read_any_integer("Number: ");
    printf("The digit sum of %lld is %d\n", n, digit_sum(n));
}

static void ex_digit_occurrences(void)
{
    long long n = read_any_integer("Number: ");
    int d = (int)read_integer("Digit (0-9): ", 0, 9);
    printf("The digit %d appears %d time(s) in %lld\n", d, digit_occurrences(n, d), n);
}

static void ex_max_digit(void)
{
    long long n = read_any_integer("Number: ");
    printf("The largest digit of %lld is %d\n", n, max_digit(n));
}

static void ex_palindrome(void)
{
    long long n = read_any_integer("Number: ");
    printf("%lld %s a palindrome\n", n, is_palindrome(n) ? "is" : "is not");
}

/* ---- topic 3: divisors ----------------------------------------------- */

static void ex_divisors(void)
{
    static long long out[MAX_DIVISORS];
    long long n = read_integer("Number (1-1000000000000): ", 1, 1000000000000LL);
    size_t total = divisors(n, out, MAX_DIVISORS);
    printf("%lld has %zu divisor(s): ", n, total);
    for (size_t i = 0; i < total && i < MAX_DIVISORS; i++)
        printf("%s%lld", i ? ", " : "", out[i]);
    puts("");
}

static void ex_perfect(void)
{
    long long n = read_integer("Number (1-1000000000000): ", 1, 1000000000000LL);
    printf("%lld %s a perfect number\n", n, is_perfect(n) ? "is" : "is not");
}

static void ex_prime(void)
{
    long long n = read_any_integer("Number: ");
    printf("%lld %s prime\n", n, is_prime(n) ? "is" : "is not");
}

static void ex_multiplicity(void)
{
    long long n = read_any_integer("Number n (not 0): ");
    long long p = read_integer("Prime p: ", 2, 1000000000000LL);
    int k = prime_multiplicity(n, p);
    if (k < 0)
        printf("Undefined: %s\n", n == 0 ? "n must not be 0" : "p must be a prime number");
    else
        printf("%lld divides %lld exactly %d time(s) (%lld^%d is the largest such power)\n", p, n, k, p, k);
}

static void ex_gcd(void)
{
    long long a = read_any_integer("a = ");
    long long b = read_any_integer("b = ");
    printf("gcd(%lld, %lld) = %lld\n", a, b, gcd(a, b));
}

/* ---- topic 4: arrays ------------------------------------------------- */

static double va[MAX_ELEMENTS], vb[MAX_ELEMENTS];

static void ex_positive_values(void)
{
    size_t n = read_array(va, "v"), shown = 0;
    printf("Positive values: ");
    for (size_t i = 0; i < n; i++)
        if (va[i] > 0)
            printf("%s%g", shown++ ? ", " : "", va[i]);
    print_list_end(shown);
}

static void ex_positive_positions(void)
{
    size_t n = read_array(va, "v"), shown = 0;
    printf("Positions (1-based) holding positive values: ");
    for (size_t i = 0; i < n; i++)
        if (va[i] > 0)
            printf("%s%zu", shown++ ? ", " : "", i + 1);
    print_list_end(shown);
}

static void ex_odd_positions(void)
{
    size_t n = read_array(va, "v"), shown = 0;
    printf("Values at odd positions (1st, 3rd, 5th, ...): ");
    for (size_t i = 0; i < n; i += 2)
        printf("%s%g", shown++ ? ", " : "", va[i]);
    print_list_end(shown);
}

static void ex_reverse(void)
{
    size_t n = read_array(va, "v");
    printf("Reversed: ");
    for (size_t i = n; i-- > 0;)
        printf("%g%s", va[i], i ? ", " : "\n");
}

static void ex_arithmetic(void)
{
    size_t n = read_array(va, "v");
    printf("The values %s an arithmetic progression\n", is_arithmetic_progression(va, n) ? "form" : "do not form");
}

static void ex_geometric(void)
{
    size_t n = read_array(va, "v");
    printf("The values %s a geometric progression\n", is_geometric_progression(va, n) ? "form" : "do not form");
}

static void ex_dot_product(void)
{
    size_t n = read_array(va, "a");
    printf("Now enter b, with the same %zu elements:\n", n);
    for (size_t i = 0; i < n; i++) {
        char prompt[32];
        snprintf(prompt, sizeof prompt, "  b[%zu] = ", i + 1);
        vb[i] = read_real(prompt);
    }
    printf("a . b = %g\n", dot_product(va, vb, n));
}

static void ex_mean_nonzero(void)
{
    size_t n = read_array(va, "v");
    double mean;
    if (mean_of_nonzero(va, n, &mean))
        printf("Mean of the non-zero values = %g\n", mean);
    else
        puts("Every value is zero, so there is no mean of non-zero values.");
}

static void ex_count_max(void)
{
    size_t n = read_array(va, "v");
    printf("The maximum value occurs %zu time(s)\n", count_of_maximum(va, n));
}

static void ex_last_position(void)
{
    size_t n = read_array(va, "v");
    double x = read_real("Value to look for: ");
    long pos = last_index_of(va, n, x);
    if (pos < 0)
        printf("%g does not occur in the array\n", x);
    else
        printf("The last occurrence of %g is at position %ld (1-based)\n", x, pos + 1);
}

/* ---- menu ------------------------------------------------------------ */

struct exercise {
    const char *title;
    void (*run)(void);
};

struct topic {
    const char *title;
    const struct exercise *exercises;
    size_t count;
};

#define TOPIC(name, list) { name, list, sizeof list / sizeof list[0] }

static const struct exercise sums[] = {
    {"1^2 - 2^2 + 3^2 - ... +/- n^2", ex_alternating_squares},
    {"Sum of the numbers below n divisible by 3", ex_multiples_of_3},
    {"1/2 + 2/3 + ... + n/(n+1)", ex_ratio_sum},
};
static const struct exercise digits[] = {
    {"Sum of the digits of a number", ex_digit_sum},
    {"How many times a digit occurs in a number", ex_digit_occurrences},
    {"Largest digit of a number", ex_max_digit},
    {"Is the number a palindrome?", ex_palindrome},
};
static const struct exercise divisor_problems[] = {
    {"All divisors of a number", ex_divisors},
    {"Is the number perfect?", ex_perfect},
    {"Is the number prime?", ex_prime},
    {"Multiplicity of a prime p in n", ex_multiplicity},
    {"Greatest common divisor of two numbers", ex_gcd},
};
static const struct exercise arrays[] = {
    {"Positive values of an array", ex_positive_values},
    {"Positions of the positive values", ex_positive_positions},
    {"Values at odd positions", ex_odd_positions},
    {"Array in reverse order", ex_reverse},
    {"Is it an arithmetic progression?", ex_arithmetic},
    {"Is it a geometric progression?", ex_geometric},
    {"Dot product of two arrays", ex_dot_product},
    {"Mean of the non-zero values", ex_mean_nonzero},
    {"How many times the maximum occurs", ex_count_max},
    {"Last position of a value", ex_last_position},
};
static const struct topic topics[] = {
    TOPIC("Sums", sums),
    TOPIC("Digits of an integer", digits),
    TOPIC("Divisors", divisor_problems),
    TOPIC("Arrays", arrays),
};

int main(void)
{
    const size_t ntopics = sizeof topics / sizeof topics[0];
    puts("Usual Problems in C - classic beginner exercises");
    for (;;) {
        puts("\n=== Topics ===");
        for (size_t i = 0; i < ntopics; i++)
            printf("  %zu. %s\n", i + 1, topics[i].title);
        puts("  0. Quit");
        long long t = read_integer("Choose a topic: ", 0, (long long)ntopics);
        if (t == 0)
            break;
        const struct topic *topic = &topics[t - 1];
        for (;;) {
            printf("\n=== %s ===\n", topic->title);
            for (size_t i = 0; i < topic->count; i++)
                printf("  %zu. %s\n", i + 1, topic->exercises[i].title);
            puts("  0. Back");
            long long e = read_integer("Choose an exercise: ", 0, (long long)topic->count);
            if (e == 0)
                break;
            printf("\n-- %s --\n", topic->exercises[e - 1].title);
            topic->exercises[e - 1].run();
        }
    }
    puts("Goodbye.");
    return EXIT_SUCCESS;
}
