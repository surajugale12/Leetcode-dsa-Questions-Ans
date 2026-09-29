class Solution {
public:
    //  int solveusingmemo( int n , vector<int>& dp){
    //     if( n == 0 || n== 1){
    //         return n  ;
    //     }
    //     if( dp[n] != -1){
    //         return dp[n];
    //     }

    //         int ans = solveusingmemo(n-1,dp) + solveusingmemo(n-2, dp);
    //         dp[n] = ans ;
    //         return dp[n];

    //  }
    int solveusingtabulation(int n) {
        vector<int> dp(n + 1, -1);

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int ans = dp[i - 1] + dp[i - 2];
            dp[i] = ans;
        }
        return dp[n];
    }
    int fib(int n) {
        // vector<int> dp(n+1,-1);
        return solveusingtabulation(n);
    }
};