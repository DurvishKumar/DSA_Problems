class Solution {
public:
    long long fact(int n){
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i=2;i<=n;i++)
            ans = (ans * i) % mod;
        return ans;
    }
    int numPrimeArrangements(int n) {
        int mod = 1e9 + 7;
        if(n < 2) return 1;
        vector<bool>prime(n+1,true);
        prime[0] = prime[1] = false;
        int NoOfPrimes = 0;
        for(int i = 2; i*i <= n; i++){
            if(prime[i]){
                for(int j = i*i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
        for(int i = 2; i <= n; i++){
            if(prime[i]) NoOfPrimes++;
        }
        int NonPrimes = n - NoOfPrimes;
        long long factOfNonPrimes = (fact(NonPrimes)) % mod;;
        long long factOfPrimes = (fact(NoOfPrimes)) % mod;;
        long long ans = (1LL * factOfNonPrimes * factOfPrimes) % mod;
        return ans;
    }
};