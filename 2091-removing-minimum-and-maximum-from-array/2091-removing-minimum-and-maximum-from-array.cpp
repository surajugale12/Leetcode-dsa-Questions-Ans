class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0 ;
        int maxIdx = 0 ;
      int n = nums.size();
            for( int i =0 ; i< n ; i++){
        if( nums[minIdx] > nums[i]){
            minIdx = i ; 
        }
         if( nums[maxIdx] < nums[i]){
            maxIdx = i ; 
        }
            }
    
        
     int left = min(minIdx,maxIdx);
    int right = max(minIdx,maxIdx);

    int front = right + 1;
    int back = n - left ;

    int both = (left + 1 ) + ( n- right );

    int ans = min({front,back,both});
        
        return ans;
    }
};