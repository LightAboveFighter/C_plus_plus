#include <iostream>
#include <cassert>
#include <string> // Решето Эратосфена
#include <vector>
#include <stdexcept>

auto eratosphene_sieve( int max) {
    assert (max > 1); //give an error with (exeption)

    std::vector<bool> sieved(max + 1, false);
    for ( int i = 2; i * i <= max; ++i ) {
        if ( !sieved[i] ) {
            int step = (i != 2) ? 2 * i : i;
            for ( int j = i * i; j <= max; j += step) {
                sieved[j] = true;
            }
        }
    }

    std::vector<int> primes;
    for ( int i = 2; i <= max; ++i ) {
        if (!sieved[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i ) {
        if (x % i == 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

int main() {
    for (int max: {2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 234, 10000 } ) {
                    std::cout << "max = " << max << std::endl;
                    for (auto p: eratosphene_sieve(max) ) {
                        if (!is_prime(p) )
                            throw std::runtime_error(
                                "not a prime (" + std::to_string(p) + ")"
                            );
                        std::cout << p << " ";
                    }
                    std::cout << std::endl;

                   }
}