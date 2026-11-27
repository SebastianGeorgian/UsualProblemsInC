/* Unit tests for problems.c - run with `make test`. */
#include "../src/problems.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>

static int failures, checks;

#define CHECK(cond)                                                       \
    do {                                                                  \
        checks++;                                                         \
        if (!(cond)) {                                                    \
            failures++;                                                   \
            fprintf(stderr, "%s:%d: check failed: %s\n", __FILE__, __LINE__, #cond); \
        }                                                                 \
    } while (0)

#define CHECK_NEAR(a, b) CHECK(fabs((a) - (b)) < 1e-9)

static void test_sums(void)
{
    CHECK(alternating_square_sum(0) == 0);
    CHECK(alternating_square_sum(1) == 1);
    CHECK(alternating_square_sum(4) == 1 - 4 + 9 - 16);
    CHECK(alternating_square_sum(5) == 15);
    CHECK(sum_multiples_of_3_below(3) == 0);
    CHECK(sum_multiples_of_3_below(10) == 3 + 6 + 9);
    CHECK(sum_multiples_of_3_below(9) == 3 + 6); /* strictly below n */
    CHECK_NEAR(ratio_sum(1), 0.5);
    CHECK_NEAR(ratio_sum(3), 0.5 + 2.0 / 3 + 0.75);
}

static void test_digits(void)
{
    CHECK(digit_sum(0) == 0);
    CHECK(digit_sum(12345) == 15);
    CHECK(digit_sum(-907) == 16);
    CHECK(digit_sum(LLONG_MIN) == 89); /* 9223372036854775808 */
    CHECK(digit_occurrences(1212321, 2) == 3);
    CHECK(digit_occurrences(0, 0) == 1);
    CHECK(digit_occurrences(105, 0) == 1);
    CHECK(digit_occurrences(123, 10) == 0);
    CHECK(max_digit(0) == 0);
    CHECK(max_digit(-3917) == 9);
    CHECK(is_palindrome(0));
    CHECK(is_palindrome(12321));
    CHECK(is_palindrome(-121));
    CHECK(!is_palindrome(123));
    CHECK(!is_palindrome(10));
    CHECK(!is_palindrome(LLONG_MAX));
}

static void test_divisors(void)
{
    long long out[16];
    CHECK(divisors(0, out, 16) == 0);
    CHECK(divisors(1, out, 16) == 1 && out[0] == 1);
    CHECK(divisors(12, out, 16) == 6);
    CHECK(out[0] == 1 && out[1] == 2 && out[2] == 3 && out[3] == 4 && out[4] == 6 && out[5] == 12);
    CHECK(divisors(-36, out, 16) == 9 && out[4] == 6 && out[8] == 36);
    CHECK(divisors(97, out, 16) == 2 && out[1] == 97);
    CHECK(divisors(720720, out, 16) == 240); /* count is exact even when out is too small */

    CHECK(!is_perfect(1));
    CHECK(is_perfect(6) && is_perfect(28) && is_perfect(496) && is_perfect(8128));
    CHECK(!is_perfect(12) && !is_perfect(27));

    CHECK(!is_prime(-7) && !is_prime(0) && !is_prime(1));
    CHECK(is_prime(2) && is_prime(3) && is_prime(97) && is_prime(1000000007));
    CHECK(!is_prime(4) && !is_prime(91) && !is_prime(1000000007LL * 3));

    CHECK(prime_multiplicity(72, 2) == 3);
    CHECK(prime_multiplicity(72, 3) == 2);
    CHECK(prime_multiplicity(-250, 5) == 3);
    CHECK(prime_multiplicity(7, 2) == 0);
    CHECK(prime_multiplicity(0, 2) == -1);
    CHECK(prime_multiplicity(64, 4) == -1);

    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(-12, 18) == 6);
    CHECK(gcd(0, 5) == 5);
    CHECK(gcd(0, 0) == 0);
    CHECK(gcd(17, 5) == 1);
}

static void test_arrays(void)
{
    const double ap[] = {2, 5, 8, 11}, notap[] = {1, 2, 4};
    const double gp[] = {3, -6, 12, -24}, notgp[] = {1, 2, 3}, zeros[] = {0, 0, 0}, zfirst[] = {0, 1, 2};
    const double fractions[] = {0.1, 0.2, 0.3}; /* inexact in binary floating point */
    CHECK(is_arithmetic_progression(ap, 4));
    CHECK(is_arithmetic_progression(fractions, 3));
    CHECK(!is_arithmetic_progression(notap, 3));
    CHECK(is_arithmetic_progression(notap, 2));
    CHECK(is_geometric_progression(gp, 4));
    CHECK(!is_geometric_progression(notgp, 3));
    CHECK(is_geometric_progression(zeros, 3));
    CHECK(!is_geometric_progression(zfirst, 3));

    const double a[] = {1, 2, 3}, b[] = {4, -5, 6.5};
    CHECK_NEAR(dot_product(a, b, 3), 4 - 10 + 19.5);

    const double withzeros[] = {0, 4, 0, -1, 0}, allzero[] = {0, 0};
    double mean = 0;
    CHECK(mean_of_nonzero(withzeros, 5, &mean) && fabs(mean - 1.5) < 1e-9);
    CHECK(!mean_of_nonzero(allzero, 2, &mean));

    const double negatives[] = {-5, -2, -9, -2}, maxes[] = {7, 1, 7, 7, 3};
    CHECK(count_of_maximum(negatives, 4) == 2);
    CHECK(count_of_maximum(maxes, 5) == 3);
    CHECK(count_of_maximum(maxes, 0) == 0);

    const double search[] = {4, 1, 4, 2};
    CHECK(last_index_of(search, 4, 4) == 2);
    CHECK(last_index_of(search, 4, 1) == 1);
    CHECK(last_index_of(search, 1, 4) == 0); /* index 0 is found */
    CHECK(last_index_of(search, 4, 9) == -1);
}

int main(void)
{
    test_sums();
    test_digits();
    test_divisors();
    test_arrays();
    if (failures) {
        fprintf(stderr, "%d of %d checks FAILED\n", failures, checks);
        return 1;
    }
    printf("All %d checks passed\n", checks);
    return 0;
}
