class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> elems;
        for(int i = 0; i < nums.size(); ++i) {
            if(elems.count(target - nums[i])) {
                return {elems[target - nums[i]], i};
            }
            if(!elems.count(nums[i])) {
                elems[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};
