class Solution {
public:
    int reverseDegree(string s) {
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {

            int value = 'z' - s[i] + 1;

            cnt += value * (i + 1);
        }

        return cnt;
    }
};