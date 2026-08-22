class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ;
        int pro = 1 ;
        int ans = n ;
        while( ans!= 0){
            int ls = ans % 10 ;
            sum+=ls;
            pro*=ls;
            ans = ans/ 10 ;
        }
        int res = sum + pro ;
        if( n % res == 0){
            return true ;
        }else
        return false;
        
    }
};