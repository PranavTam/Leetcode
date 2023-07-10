class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        int count = n - 2;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (isPrime[j]) {
                        count--;
                        isPrime[j] = false;
                    }
                }
            }
        }
        return count;
    }
};