class Solution {
public:
int usingrecursion( int n ){

        if( n==1 || n ==2  ){
            return n;
        }
    int ans = usingrecursion(n-1)+ usingrecursion(n-2);
    return ans ;
}
int usingmomosiation( int n,vector<int>& dp){
        if( n==1 || n ==2  ){
            return n;
        }
        if( dp[n] != -1){
            return dp[n];
        }
    int ans = usingmomosiation(n-1,dp)+ usingmomosiation(n-2,dp);
    dp[n] = ans ;


    return ans ;
}
    int climbStairs(int n) {
        vector<int> dp( n+1 , -1);
      return  usingmomosiation(n,dp);
    }
};