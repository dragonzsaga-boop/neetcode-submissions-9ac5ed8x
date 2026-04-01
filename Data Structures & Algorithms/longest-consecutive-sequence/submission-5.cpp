class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> us;
        for(int i : nums) us.insert(i);
        int nextElem = nums[0];
        int maxRes = 0;
        for(int i : nums) {
            // if(i < nextElem && maxRes) continue;
            
            int res = 1, currVal = i;
            while(us.count(++currVal)) {
                ++res;
            }
            nextElem = currVal;
            maxRes = max(maxRes, res);
        }
        return maxRes;
    }
};
