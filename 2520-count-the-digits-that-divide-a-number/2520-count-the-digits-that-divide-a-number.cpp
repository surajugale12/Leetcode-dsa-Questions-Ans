class Solution {
public:
    int countDigits(int num) {
        if( num < 10){
            return 1 ;
        }
        int cnt =0 ; 
        int duplicate = num ;
            while( duplicate !=  0 ){
            int ld = duplicate % 10 ; 
            if( num % ld == 0 ){
                cnt++;
            }
            duplicate = duplicate / 10 ;
        }
       return cnt;
    }
};