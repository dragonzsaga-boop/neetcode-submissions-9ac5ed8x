class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for(int i : nums) us.insert(i);
        int maxRes = 0;
        for(int i : nums) {
            if(us.count(i-1)) continue;

            int res = 1, currVal = i;
            while(us.count(++currVal)) {
                ++res;
            }
            maxRes = max(maxRes, res);
        }
        return maxRes;
    }
};
