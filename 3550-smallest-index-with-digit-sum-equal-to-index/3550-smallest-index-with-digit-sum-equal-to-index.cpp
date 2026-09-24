class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for( int i =0  ; i<n ; i++){
            if( nums[i] < 10 ){
                if( nums[i] == i){
                    return i ;
                }
            }
            else{
                int sum =0 ;
                int k = nums[i];
                while(k != 0 ){
                int ls = k % 10 ;
                    sum+=ls;
                    k = k / 10 ;
                }
                if( sum == i){
                    return i ;
                }

            }
        }
    return -1 ;
    }
};