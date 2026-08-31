/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }
        vector<int> ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int> localMinima;

        int cnt = 2;
        while (curr->next != NULL) {

            if (prev->val > curr->val && curr->val < curr->next->val) {

                localMinima.push_back(cnt);
            }
            if (prev->val < curr->val && curr->val > curr->next->val) {

                localMinima.push_back(cnt);
            }

            prev = curr;
            curr = curr->next;
            cnt++;
        }
            if(localMinima.size() == 0 || localMinima.size() == 1){
                return {-1,-1};
            }
        int minDistance = INT_MAX;
        int maxDistance = localMinima[localMinima.size() - 1] - localMinima[0];
        int j = 0;
        for (int i = 1; i < localMinima.size(); i++) {
            int dist = localMinima[i] - localMinima[j];
            minDistance = min(minDistance, dist);

            j++;
        }

        ans.push_back(minDistance);
        ans.push_back(maxDistance);
        return ans;
    }
};