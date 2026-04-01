class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        unordered_set<int> us;
        for(int i : n) us.insert(i);

        int retVal = 0;
        for(int i : n) {
            //only start checking for incremental values
            //if this value has not already been considered
            //in its previous value (if x-1 exists, it'll count x in its computation)
            if(us.count(i-1)) {
                continue;
            }
            int currV = i, res = 0;
            while(us.count(currV)) {
                currV += 1;
                res += 1;
            }
            retVal = max(retVal, res);
        }
        return retVal;
    }
};
