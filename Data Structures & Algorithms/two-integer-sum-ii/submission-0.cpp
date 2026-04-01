class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int l = 0, r = n.size()-1;
        while( l < r ) {
            const auto &currSum = n[l] + n[r];
            if(currSum == t) {
                return {l+1, r+1};
            }
            else if (currSum < t) {
                ++l;
            }
            else {
                --r;
            }
        }
        return {0,0};
    }
};
