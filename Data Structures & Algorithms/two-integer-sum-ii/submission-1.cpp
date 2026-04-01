class Solution {
public:
    vector<int> twoSum(vector<int>& nm, int target) {
        unordered_map<int, int> um;
        for(int i = 0; i < nm.size(); ++i) {
            if(um.count(target-nm[i])) {
                return {um[target-nm[i]]+1, i+1};
            }
            else um[nm[i]] = i;
        }
        return {-1,-1};
    }
};
