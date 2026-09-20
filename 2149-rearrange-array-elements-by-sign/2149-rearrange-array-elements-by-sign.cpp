class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive ;
        vector<int> negative ;
        vector<int> ans(nums.size(),0) ;

        for( int i =0 ; i< nums.size()  ; i++){
            if(nums[i] >= 0 ){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }  
        int j =0 ; 
        for( int i =0 ; i< nums.size() ; i+=2){
            ans[i] = positive[j];
            j++ ;
        }
        int k =0;
         for( int i =1 ; i< nums.size() ;i+=2){
           ans[i] = negative[k];
           k++ ;
        }
        
        return ans;
    }
};