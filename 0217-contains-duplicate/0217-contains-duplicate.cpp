class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m ;

        for( int i =0 ; i <nums.size() ; i++){
            int cnt = nums[i];
            m[cnt]++;
        }

        for( auto i : m){
            cout<<i.second<<endl;
            if(i.second > 1){
                return true;
            };
        }
        return false ;
    }
};