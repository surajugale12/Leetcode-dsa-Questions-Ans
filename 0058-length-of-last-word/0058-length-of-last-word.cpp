class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        int i = n - 1;

        // Skip spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count last word
        while (i >= 0 && s[i] != ' ') {
            cnt++;
            i--;
        }

        return cnt;
    }
};