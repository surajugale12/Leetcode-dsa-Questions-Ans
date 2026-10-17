class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> arr;

        for (int i = 0; i < n; i++) {
            int k = nums[i];
            int sum = 0;

            while (k != 0) {
                sum += k % 10;
                k /= 10;
            }

            arr.push_back({sum, nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i][2] == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j][2];
                cycle++;
            }

            if (cycle > 1)
                cnt += cycle - 1;
        }

        return cnt;
    }
};