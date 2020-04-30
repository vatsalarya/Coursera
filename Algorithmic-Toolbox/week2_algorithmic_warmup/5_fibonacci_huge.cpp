#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1) return n;
    long long previous = 0 , current  = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current % m;
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
long long get_fibonacci_huge_fast(long long n, long long m) {
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
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << "\n";
}
