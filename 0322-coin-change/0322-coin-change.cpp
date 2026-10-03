class Solution {
public:
    int sloveusingrecursion(vector<int>&coins , int amount,vector<int>&dp){

        int mini = INT_MAX;
        if( amount == 0){
            return 0 ;
        }
        if( dp[amount] != -1){
            return dp[amount];
        }

        for( int i =0 ; i< coins.size() ; i++){

            if( coins[i] <= amount){

                int recursion = sloveusingrecursion(coins,amount- coins[i],dp);
                if(recursion != INT_MAX){
                    mini = min(mini,1+recursion);
                }
            }
        }
        dp[amount] = mini;
return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<int>dp(amount+1 , -1);
       int ans = sloveusingrecursion(coins, amount,dp);
       if( ans == INT_MAX){
        return -1 ;
       }
       else{
        return ans;
       }
    }
};