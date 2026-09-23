class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      
        int total = 0;

        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        int target = total - x;

        // If target is negative
        if(target < 0) {
            return -1;
        }

        int i = 0;
        int sum = 0;
        int maxLength = -1;

        for(int j = 0; j < nums.size(); j++) {

            sum += nums[j];

            while(i <= j && sum > target) {
                sum = sum - nums[i];
                i++;
            }

            if(sum == target) {
                maxLength = max(maxLength, j - i + 1);
            }
        }

        if(maxLength == -1) {
            return -1;
        }

        return nums.size() - maxLength;
    }
};