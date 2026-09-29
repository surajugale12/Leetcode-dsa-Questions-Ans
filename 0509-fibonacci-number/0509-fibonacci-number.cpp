class Solution {
public:
 int solveusingmemo( int n , vector<int>& dp){
    if( n == 0 || n== 1){
        return n  ;
    }
    if( dp[n] != -1){
        return dp[n];
    }

        int ans = solveusingmemo(n-1,dp) + solveusingmemo(n-2, dp);
        dp[n] = ans ;
        return dp[n];

 }
    int fib(int n) {
        vector<int> dp(n+1,-1);
      return solveusingmemo(n,dp);
    }
};