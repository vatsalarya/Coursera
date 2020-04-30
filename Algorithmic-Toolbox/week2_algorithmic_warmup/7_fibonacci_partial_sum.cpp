#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to);
long long Pisano_period(int m);
long long get_fibonacci_huge(long long n, long long m);

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    long long sum_upto_from = get_fibonacci_huge(from +1 , 10) -1;
    long long sum_upto_to = get_fibonacci_huge(to + 2 , 10) - 1;
    return ((sum_upto_to + 10 - sum_upto_from) % 10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }
    return sum % 10;
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
