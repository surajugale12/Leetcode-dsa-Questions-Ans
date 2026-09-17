class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        if (stones.size() == 1) {
            return 1;
        }

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(x- y);
            }
            cout<<x<<endl;
            cout<<y<<endl;
        }
          if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};