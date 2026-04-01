class Solution {
public:
    int trap(vector<int>& h) {
/*
        [0,2,0,3,1,0,1,3,2,1]

        [0,0,2,0,2,3,2,0,1,2] water fillable on section due to highest wall on left
        [3,1,3,0,2,3,2,0,0,0] water fillable on section due to highest wall on right
        [0,0,2,0,2,3,2,0,0,0] water fillable finally at the end
*/
        vector<int> l(h.size()), r(h.size());

        for(int currHighest = 0, i = 0; i < h.size(); ++i) {
            l[i] = max((currHighest - h[i]), 0);
            currHighest = max(currHighest, h[i]);
        }
        for(int currHighest = 0, i = h.size()-1; i >= 0; --i) {
            r[i] = max((currHighest - h[i]), 0);
            currHighest = max(currHighest, h[i]);
        }
        int res = 0;
        for(int i = 0; i < h.size(); ++i) {
            res += min(l[i], r[i]);
        }
        return res;
    }
};
