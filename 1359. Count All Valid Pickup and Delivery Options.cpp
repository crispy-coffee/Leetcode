class Solution {
public:
    const int MOD = 1000000007;

    unsigned long long mod_pow(unsigned long long base, int exponent) {
        unsigned long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }

    unsigned long long calculateAN(int n) {
        unsigned long long numerator = 1;
        unsigned long long denominator = 1;

        for (int i = 1; i <= 2 * n; ++i) {
            numerator = (numerator * i) % MOD;
        }

        for (int i = 1; i <= n; ++i) {
            denominator = (denominator * 2) % MOD;
        }

        unsigned long long inverse_denominator = mod_pow(denominator, MOD - 2);

        return (numerator * inverse_denominator) % MOD;
    }

    int countOrders(int n) {
        // using formulat a(n) = (2n)! / (2^n);
        // return calculateAN(n);

        return brute(n);
    }

    int brute(int n){
        unsigned long long prev = 1;
        unsigned long long spaces = 3;
        unsigned long long answer = 1;

        for(int i=2; i<=n; i++, spaces+=2){
            unsigned long long spaces_sum = (spaces * (spaces+1))/2;

            answer = (prev * spaces_sum)%MOD;
            prev = answer;
        }

        return (int)answer;
    }

};