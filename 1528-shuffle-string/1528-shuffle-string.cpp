class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string ans = s ; 

        for( int i =0 ; i< s.size() ; i++){
            char ch = s[i];
            ans[indices[i]] = ch ;
        }
        return ans;
    }
};