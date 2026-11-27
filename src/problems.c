#include "problems.h"

#include <math.h>

static unsigned long long magnitude(long long n)
{
    /* Safe for LLONG_MIN, whose negation does not fit in a long long. */
    return n < 0 ? 0ULL - (unsigned long long)n : (unsigned long long)n;
}

static bool nearly_equal(double a, double b)
{
    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));
    return fabs(a - b) <= PROBLEMS_EPSILON * scale;
}

/* ---- Topic 1: sums -------------------------------------------------- */

long long alternating_square_sum(int n)
{
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
        sum += (i % 2 ? 1 : -1) * i * i;
    return sum;
}

long long sum_multiples_of_3_below(long long n)
{
    if (n <= 3)
        return 0;
    long long k = (n - 1) / 3; /* 3 + 6 + ... + 3k */
    return 3 * k * (k + 1) / 2;
}

double ratio_sum(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
        sum += (double)i / (i + 1);
    return sum;
}

/* ---- Topic 2: digits ------------------------------------------------ */

int digit_sum(long long n)
{
    int sum = 0;
    for (unsigned long long m = magnitude(n); m; m /= 10)
        sum += (int)(m % 10);
    return sum;
}

int digit_occurrences(long long n, int digit)
{
    if (digit < 0 || digit > 9)
        return 0;
    unsigned long long m = magnitude(n);
    if (m == 0)
        return digit == 0; /* the number 0 is written with one digit 0 */
    int count = 0;
    for (; m; m /= 10)
        count += (int)(m % 10) == digit;
    return count;
}

int max_digit(long long n)
{
    int best = 0;
    for (unsigned long long m = magnitude(n); m; m /= 10)
        if ((int)(m % 10) > best)
            best = (int)(m % 10);
    return best;
}

bool is_palindrome(long long n)
{
    unsigned long long m = magnitude(n), reversed = 0;
    for (unsigned long long t = m; t; t /= 10) {
        if (reversed > (~0ULL - t % 10) / 10)
            return false; /* the reverse would overflow, so it cannot equal m */
        reversed = reversed * 10 + t % 10;
    }
    return reversed == m;
}

/* ---- Topic 3: divisors ---------------------------------------------- */

size_t divisors(long long n, long long *out, size_t cap)
{
    unsigned long long m = magnitude(n), root = 0;
    size_t count = 0;

    if (m == 0)
        return 0;
    while ((root + 1) <= m / (root + 1))
        root++; /* root = floor(sqrt(m)) without floating point */

    for (unsigned long long d = 1; d <= root; d++) /* small divisors, ascending */
        if (m % d == 0) {
            if (count < cap)
                out[count] = (long long)d;
            count++;
        }
    for (unsigned long long d = root; d >= 1; d--) /* their partners, ascending */
        if (m % d == 0 && d != m / d) {
            if (count < cap)
                out[count] = (long long)(m / d);
            count++;
        }
    return count;
}

bool is_perfect(long long n)
{
    if (n < 2)
        return false;
    long long sum = 1; /* 1 is a proper divisor of every n >= 2 */
    for (long long d = 2; d <= n / d; d++) {
        if (n % d)
            continue;
        sum += d;
        if (d != n / d)
            sum += n / d;
        if (sum > n)
            return false;
    }
    return sum == n;
}

bool is_prime(long long n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;
    for (long long d = 3; d <= n / d; d += 2)
        if (n % d == 0)
            return false;
    return true;
}

int prime_multiplicity(long long n, long long p)
{
    if (n == 0 || !is_prime(p))
        return -1;
    unsigned long long m = magnitude(n), q = (unsigned long long)p;
    int k = 0;
    for (; m % q == 0; m /= q)
        k++;
    return k;
}

long long gcd(long long a, long long b)
{
    unsigned long long x = magnitude(a), y = magnitude(b);
    while (y) {
        unsigned long long r = x % y;
        x = y;
        y = r;
    }
    return (long long)x;
}

/* ---- Topic 4: arrays ------------------------------------------------ */

bool is_arithmetic_progression(const double *v, size_t n)
{
    for (size_t i = 2; i < n; i++)
        if (!nearly_equal(v[i] - v[i - 1], v[1] - v[0]))
            return false;
    return true;
}

bool is_geometric_progression(const double *v, size_t n)
{
    if (n >= 2 && v[0] == 0.0) {
        /* 0, 0, 0, ... is the only progression that can start with 0 */
        for (size_t i = 1; i < n; i++)
            if (v[i] != 0.0)
                return false;
        return true;
    }
    /* b^2 = a*c avoids dividing by zero and also works for negative ratios */
    for (size_t i = 2; i < n; i++)
        if (!nearly_equal(v[i - 1] * v[i - 1], v[i - 2] * v[i]))
            return false;
    return true;
}

double dot_product(const double *a, const double *b, size_t n)
{
    double sum = 0.0;
    for (size_t i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

bool mean_of_nonzero(const double *v, size_t n, double *mean)
{
    double sum = 0.0;
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
        if (v[i] != 0.0) {
            sum += v[i];
            count++;
        }
    if (count == 0)
        return false;
    *mean = sum / (double)count;
    return true;
}

size_t count_of_maximum(const double *v, size_t n)
{
    if (n == 0)
        return 0;
    double max = v[0];
    for (size_t i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
        count += v[i] == max;
    return count;
}

long last_index_of(const double *v, size_t n, double x)
{
    for (size_t i = n; i-- > 0;)
        if (nearly_equal(v[i], x))
            return (long)i;
    return -1;
}
