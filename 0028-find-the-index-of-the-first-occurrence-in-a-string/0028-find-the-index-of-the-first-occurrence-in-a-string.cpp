class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0 ;
        if (needle.empty()) return 0;
        for( int i =0 ; i < haystack.length() ; i++){
                if( needle[j] == haystack[i]){
                    if(j == needle.length()-1){ 
                     return i- (needle.length()-1) ;
                    }
                    j++;
                }else{
                i = i - j;
                    j =0  ;
                }
                cout<<i<<endl;
            
        }
        return -1 ;
    }
};