class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       int n = nums.size();
        int p = 2;
        int ans = k;
        sort(nums.begin(),nums.end());
        for( int i =0 ; i< n ; i++){
            if(ans == nums[i]){
                ans = k * p;
                p++;
                cout<<ans<<endl;
            }
           
        }
        return ans ;
    }
};