class Solution {
    struct comp{
    bool operator()(const pair<int,int> &lhs, const pair<int,int> &rhs) {
            return lhs.first < rhs.first;
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        // for(int i = 0; i < k; ++i) {
        //     pq.push({nums[i],i});
        // }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            while(pq.size() && (pq.top().second < i+1 - k )) {
                pq.pop();
            }
            pq.push({nums[i],i});
            if(pq.size() >= k)
                res.push_back(pq.top().first);
        }
        return res;
    }
};
