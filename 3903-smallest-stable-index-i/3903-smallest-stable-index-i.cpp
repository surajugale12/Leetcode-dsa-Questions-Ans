#include <algorithm>
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int maxi = INT_MIN;
        int mini =INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        int mini = *min_element(nums.begin() + i, nums.end());
            cout<<maxi<<endl;
            cout<<mini<<endl;
            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};