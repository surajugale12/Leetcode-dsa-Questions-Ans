class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        vector<int>prefix(nums.size());
        vector<int>sufix(nums.size());

        
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(  int i =0; i< nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            prefix[i] = maxi ;
             
        }
         for(  int i =nums.size() -1 ;i>=0; i--){
            mini = min(mini , nums[i]);
            sufix[i] = mini ;
             
        }
        
        
        for( int i =0 ; i< nums.size()  ; i++){
            if( prefix[i] - sufix[i] <= k){
                return i ;
            }
        }
        return -1 ;
    }
};