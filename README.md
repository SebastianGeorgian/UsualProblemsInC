# Usual Problems in C

A collection of 22 classic beginner programming exercises in C: sums, digits,
divisors and arrays. You reach them through an interactive menu, and unit tests
cover every solution.

It started as a university programming assignment and has since been cleaned up:
the solutions are pure functions separated from the input/output code, and
edge cases such as 0, 1, negative numbers and empty input are handled properly.

## Exercises

| Topic | Exercises |
|---|---|
| **1. Sums** | 1² − 2² + 3² − … ± n² · sum of the numbers below *n* divisible by 3 · 1/2 + 2/3 + … + n/(n+1) |
| **2. Digits** | digit sum · occurrences of a digit · largest digit · palindrome check |
| **3. Divisors** | all divisors · perfect number · prime check · multiplicity of a prime *p* in *n* · greatest common divisor |
| **4. Arrays** | positive values · positions of positive values · values at odd positions · reverse order · arithmetic progression · geometric progression · dot product · mean of non-zero values · occurrences of the maximum · last position of a value |

## Build and run

You need a C11 compiler (gcc or clang) and `make`.

```sh
make          # builds ./usual-problems
make run      # builds and starts the menu
make test     # builds and runs the unit tests
make clean
```

Choose a topic, then an exercise; `0` goes back or quits. Invalid input is
rejected with a message instead of crashing the program, and decimal numbers
can be typed with either `.` or `,`.

```
=== Divisors ===
  1. All divisors of a number
  ...
Choose an exercise: 1
Number (1-1000000000000): 360
360 has 24 divisor(s): 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 18, 20, 24, 30, 36, 40, 45, 60, 72, 90, 120, 180, 360
```

## Project layout

```
src/problems.h        function declarations and their contracts
src/problems.c        the solutions (no input or output)
src/main.c            interactive menu and input validation
tests/test_problems.c unit tests, including edge cases
Makefile
```

## Notes on the solutions

- Primality and divisor checks only test candidates up to √n, so they are fast even for 12-digit numbers.
- The greatest common divisor uses Euclid's algorithm with remainders, so `gcd(0, n)` works too.
- Digit functions handle negative numbers, including `LLONG_MIN`.
- Floating-point comparisons (progressions, searching) allow a small relative tolerance, so `0.1, 0.2, 0.3` counts as an arithmetic progression.
- The geometric progression check uses b² = a·c, which also works for negative ratios and avoids dividing by zero.

## License

[MIT](LICENSE)
