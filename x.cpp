#include <iostream>
#include <vector>

int countPrimes(int N) {
    if (N <= 2) return 0;

    std::vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int primeCount = 0;
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) {
            primeCount++;
        }
    }

    return primeCount;
}

int main() {
    int N;
    std::cout << "Enter a number: ";
    std::cin >> N;

    int result = countPrimes(N);
    std::cout << "Number of primes less than " << N << ": " << result << std::endl;

    return 0;
}