class Solution {
public:
    int dp[301][301];
    int MOD = 1e9 + 7;
    long long findPower(int a, int b){
        if(b == 0){
            return 1;
        }
        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;
        if(b % 2 != 0){
            result = (result * a) % MOD;
        }
        return result;
    }

    int solve(int n, int x, int st){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n][st] != -1){
            return dp[n][st];
        }
        int ways = 0;
        for(int i = st; i <= n; i++){
            int power = findPower(i, x);
            if(power > n){
                break;
            }
            ways = (ways + solve(n - power, x, i+1)) % MOD;
        }
        return dp[n][st] = ways;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, 1);
    }
};
