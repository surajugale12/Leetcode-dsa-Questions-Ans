class Solution {
public:
int recurisionnusingmemo( vector<int>& nums , int index , vector<int>& dp){
            if( index  >= nums.size()){
                return 0;
            }
            if( dp[index] != -1 ){
                return dp[index];
            }
        int include = nums[index] + recurisionnusingmemo(nums, index + 2 , dp);
        int exclude = 0 + recurisionnusingmemo(nums, index + 1, dp);
        int ans = max( include,exclude);
        dp[index] = ans ;
        return ans ;
}
    int rob(vector<int>& nums) {
        int n = nums.size();
   vector<int> dp( n+1,-1);
  int ans =  recurisionnusingmemo(nums,0,dp);
  return ans ;
    }
};