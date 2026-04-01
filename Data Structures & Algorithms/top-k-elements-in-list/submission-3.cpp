class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> valToFreq;
        map<int, vector<int>> freqToVals;
        // priority_queue<int, deque<int>> pq;

        for(int i : nums) ++valToFreq[i];
        for(const auto &pairValToFreq : valToFreq) {
            freqToVals[pairValToFreq.second].push_back(pairValToFreq.first);
        }

        vector<int> retVal;
        for(auto riter = freqToVals.rbegin(); riter != freqToVals.rend(); ++riter) {
            for(auto i : riter->second) {
                retVal.push_back(i);
                if(!(--k)) return retVal;
            }
        }
        return retVal;
    }
};
