class Solution {
public:
    vector<int> twoSum(vector<int>& nm, int target) {
        int l = 0, r = nm.size()-1;
        while(l < r) {
            if(nm[l] + nm[r] > target) {
                --r;
            }
            else if(nm[l] + nm[r] < target) {
                ++l;
            }
            else {//if(nm[l] + nm[r] == target) {
                return {l+1, r+1};
            }
            
        }
        return {-1,-1};
    }
};
