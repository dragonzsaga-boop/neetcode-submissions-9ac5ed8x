class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> retL(nums.size()), retR(nums.size());
        retL[0] = retR[nums.size()-1] = 1;

        for(int i = 1; i < nums.size(); ++i) {
            retL[i] = retL[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; --i) {
            retR[i] = retR[i+1] * nums[i+1];
        }

        for(int i = 0; i < nums.size(); ++i) {
            retL[i] *= retR[i];
        }
        
        return retL;
    }
};
