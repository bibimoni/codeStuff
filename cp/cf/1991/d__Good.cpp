#include <bits/stdc++.h>

const int MAX_SIEVE = 4e5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::vector<bool> isPrime(MAX_SIEVE + 5, true);
    isPrime[0] = isPrime[1] = false;
    for (int index1 = 2; index1 <= MAX_SIEVE / index1; index1++) {
        if (isPrime[index1]) {
            for (int index2 = 1ll * index1 * index1; index2 <= MAX_SIEVE; index2 += index1) {
                isPrime[index2] = false;
            }
        }
    }
    int numTestCase;
    std::cin >> numTestCase;
    while (numTestCase--) {
        int numVertex;
        std::cin >> numVertex;
        std::vector<int> result(numVertex);
        result[0] = 1;
        for (int index = 1; index < numVertex; index++) {
            for (int prev = 1; prev <= std::min(index, 50); prev++) {
                if (isPrime[(index + 1) ^ (index - prev + 1)]) {
                    result[index] = std::max(result[index], result[index - prev] + 1);
                }
            }
        }
        std::cout << result.back() << '\n';
        for (int res : result) {
            std::cout << res << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}