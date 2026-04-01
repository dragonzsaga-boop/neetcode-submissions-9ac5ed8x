class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int,int> um;
        for(int i = 0; i < n.size(); ++i) {
            if(um.count(t - n[i])) {
                return {um[t-n[i]], i};
            }
            if(!um.count(n[i])) {
                um[n[i]] = i;
            }
        }
        return {-1,-1};
    }
};
