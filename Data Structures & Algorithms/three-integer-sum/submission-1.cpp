class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        int target = 0;
        
        sort(n.begin(), n.end());
        unordered_map<int,int> umNumCount;

        for(int i = 0; i < n.size(); ++i) {
            //umNumVecIndex[n[i]].push_back(i);
            ++umNumCount[n[i]];
        }
        set<vector<int>> resSet;
        vector<vector<int>> resVec;
        for(int l = 0; l < n.size()-2; ++l) {
            int m = l+1, r = n.size()-1;
            const int &currTarg = target - n[l];
            while(m < r) {
                int currMid = n[m], currRight = n[r];
                const int &currSum = currMid + currRight;
                if(currSum == currTarg) {
                    resSet.insert({n[l], currMid, currRight});
                    while(n[m] == currMid) ++m;
                    while(n[r] == currRight) --r;
                }
                else if(currSum < currTarg) {
                    while(n[m] == currMid) ++m;
                }
                else {
                    while(n[r] == currRight) --r;
                }
            }
        }

        for(auto &iter : resSet) {
            resVec.emplace_back(iter);
        }

        return resVec;
    }
};
