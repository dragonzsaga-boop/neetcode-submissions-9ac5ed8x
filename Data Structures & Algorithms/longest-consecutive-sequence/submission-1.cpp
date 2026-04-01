class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        unordered_set<int> us;
        for(int i : n) us.insert(i);

        //for(int i = 0; i < n.size(); ++i) {
        int maxVal = 0;
        for(int i : n) {
            if(us.count(i-1)) {
                continue;
            }
            int currV = i, res = 0;
            while(us.count(currV)) {
                currV += 1;
                res += 1;
            }
            maxVal = max(maxVal, res);
        }
        return maxVal;
    }
};
