class Solution {
public:
    void bubblesort(vector<int>& nums) {

    for(int i = 1; i < nums.size(); i++) {

        for(int j = 0; j < nums.size() - i; j++) {

            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
    for( int i = 0 ; i< nums.size() ; i++){
        cout<<nums[i]<<" ";
    }
    }
    void sortColors(vector<int>& nums) {
      bubblesort(nums);
    }
    
};