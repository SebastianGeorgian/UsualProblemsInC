/*
 * problems.h - classic beginner programming problems, solved as pure functions.
 *
 * None of these functions read input or print output; the interactive menu
 * lives in main.c and the unit tests in tests/test_problems.c.
 */
#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <stdbool.h>
#include <stddef.h>

/* ---- Topic 1: sums -------------------------------------------------- */

/* 1^2 - 2^2 + 3^2 - 4^2 + ... +/- n^2 (0 for n < 1). */
long long alternating_square_sum(int n);

/* Sum of the natural numbers strictly below n that are divisible by 3. */
long long sum_multiples_of_3_below(long long n);

/* 1/2 + 2/3 + ... + n/(n+1) (0 for n < 1). */
double ratio_sum(int n);

/* ---- Topic 2: digits of an integer (the sign is ignored) ------------- */

int digit_sum(long long n);
int digit_occurrences(long long n, int digit);
int max_digit(long long n);
bool is_palindrome(long long n);

/* ---- Topic 3: divisors ---------------------------------------------- */

/*
 * Writes the positive divisors of |n| in increasing order to out (at most
 * cap of them) and returns how many divisors exist in total. Returns 0 for n = 0.
 */
size_t divisors(long long n, long long *out, size_t cap);

/* A perfect number equals the sum of its proper divisors (6, 28, 496, ...). */
bool is_perfect(long long n);

bool is_prime(long long n);

/*
 * Multiplicity of the prime p in n: the largest k such that p^k divides n.
 * Returns -1 when the question has no answer (n = 0 or p is not prime).
 */
int prime_multiplicity(long long n, long long p);

/* Greatest common divisor (always >= 0; gcd(0, 0) = 0). */
long long gcd(long long a, long long b);

/* ---- Topic 4: arrays ------------------------------------------------ */

/* Values that differ by less than this (relative to their size) are equal. */
#define PROBLEMS_EPSILON 1e-9

bool is_arithmetic_progression(const double *v, size_t n);
bool is_geometric_progression(const double *v, size_t n);
double dot_product(const double *a, const double *b, size_t n);

/* Mean of the non-zero elements; returns false if every element is zero. */
bool mean_of_nonzero(const double *v, size_t n, double *mean);

/* How many times the maximum value occurs (0 for an empty array). */
size_t count_of_maximum(const double *v, size_t n);

/* Index of the last element equal to x, or -1 if x is not present. */
long last_index_of(const double *v, size_t n, double x);

#endif
