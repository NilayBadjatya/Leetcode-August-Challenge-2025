class Solution {
public:
    
    double solve(int a, int b,  vector<vector<double>>& dp){
        if(a == 0 && b == 0){
            return 0.5;
        }
        if(a == 0){
            return 1.0;
        }
        if(b == 0){
            return 0.0;
        }
        if(dp[a][b] != -1.0){
            return dp[a][b];
        }
        double x = solve(a - min(a, 100), b, dp);
        double y = solve(a - min(a, 75), b - min(b, 25), dp);
        double w = solve(a - min(a, 50), b - min(b, 50), dp);
        double z = solve(a - min(a, 25), b - min(b, 75), dp);

        return dp[a][b] = 0.25 * (x + y + w + z);
    }

    double soupServings(int n) {
        if(n >= 5000){
            return 1;
        }
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1.0));
        return solve(n, n, dp);
    }
};
