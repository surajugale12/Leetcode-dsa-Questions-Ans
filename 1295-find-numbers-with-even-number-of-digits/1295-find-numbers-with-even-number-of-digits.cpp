class Solution {
public:
    int findNumbers(vector<int>& nums) {
            int ans = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digits = 0 ;
            if (num == 0) {
                digits = 1;
            } else {
                digits = (int)log10(abs(num)) + 1;

                if( digits % 2 == 0 ){
                    ans++;
                }
            }
        }
        return ans ;
    }
};