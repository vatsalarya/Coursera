#include <iostream>

int fibonacci_sum_naive(long long n) ;
long long Pisano_period(int m);
long long get_fibonacci_huge(long long n, long long m);

// Sum (Fib[0]+Fib[1]+.....+Fib[n]) = Fib[n+2]-Fib[2]
int fibonacci_sum_fast(long long n) {
    if (n <= 2) return n;
    int Last_Digit_Of_nPlus2 = get_fibonacci_huge(n + 2, 10);
	int Last_Digit_Of_2 = get_fibonacci_huge(2, 10);
	return ((Last_Digit_Of_nPlus2 + 10 ) - Last_Digit_Of_2) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}

long long Pisano_period(int m){
    long long previous = 0 , current  = 1;
    for(int i=0; i<m*m; ++i){
        long long tmp_previous = previous % m;
        previous = current % m;
        current = tmp_previous + previous;
        if(previous == 0 && current == 1) return i+1;
    }
    return -1;
}
long long get_fibonacci_huge(long long n, long long m) {
    long long pisano_period = Pisano_period(m);
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

int fibonacci_sum_naive(long long n) {
    if (n <= 1) return n;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    return sum % 10;
}