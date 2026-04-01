class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        for(int i : nums) ++um[i];
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto &pr : um) {
            // cout<<pr.first<< " : "<<pr.second<<endl;
            pq.push({pr.second,pr.first});
            while(pq.size() > k) {
                pq.pop();
            }
        }
        // auto tr = pq;
        // while(tr.size()) {cout<<tr.top().first<<" : "<<tr.top().second<<endl; tr.pop();}
        vector<int> retv;
        while(pq.size()) {
            retv.push_back(pq.top().second);
            pq.pop();
        }
        return retv;
    }
};
