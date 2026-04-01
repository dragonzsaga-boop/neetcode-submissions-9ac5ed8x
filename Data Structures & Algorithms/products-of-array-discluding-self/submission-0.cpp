class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> l (n.size(),1), r(n.size(),1);
        
        for(int i = 1; i < n.size(); ++i) {
            l[i] = l[i-1] * n[i-1];
        }

        for(int j = n.size()-2; j >= 0; --j) {
            r[j] = r[j+1] * n[j+1];
        }

        for(int i = 0; i < n.size(); ++i) {
            l[i] *= r[i];
        }

        return l;
    }
};
