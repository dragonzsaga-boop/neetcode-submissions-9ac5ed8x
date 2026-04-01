class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        for(int i : nums) ++um[i];
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto &pr : um) {
            pq.push({pr.second,pr.first});
            while(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> retv;
        while(pq.size()) {
            retv.push_back(pq.top().second);
            pq.pop();
        }
        return retv;
    }
};
