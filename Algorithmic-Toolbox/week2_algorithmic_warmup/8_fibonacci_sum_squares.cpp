#include <iostream>

int fibonacci_sum_squares_naive(long long n);
long long get_fibonacci_huge(long long n, long long m = 10);
int fibonacci_sum_squares_fast(long long n) {
    return ((get_fibonacci_huge(n+1) * get_fibonacci_huge(n)) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}


long long get_fibonacci_huge(long long n, long long m) {
    //Pisano period for 10 is 60
    long long pisano_period = 60;
    n %= pisano_period;
    if (n <= 1) return n;
    long long previous = 0 , current  = 1;

    for (long long i = 0; i < n-1; ++i) {
        long long tmp_previous = previous % m;
        previous = current % m;
        current = tmp_previous + previous;
    }
    return current % m;
}
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
