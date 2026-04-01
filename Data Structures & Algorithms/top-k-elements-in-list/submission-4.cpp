class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> valToFreq;
        priority_queue<pair<int,int>, deque<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i : nums) ++valToFreq[i];

        for(const auto &prVtoF : valToFreq) {
            pq.push({prVtoF.second, prVtoF.first});
            while(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> retVal;
        while(pq.size()) {
            retVal.emplace_back(move(pq.top().second)); pq.pop();
        }
        return retVal;
    }
};
