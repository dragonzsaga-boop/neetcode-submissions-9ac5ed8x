class Solution {
public:
    int search(vector<int>& n, int t) {
        int l = 0, r = n.size()-1;
        while( l < r ) {
            int m = l + (r-l)/2;
            // cout<<l<<", "<<r<<" : "<<m<<endl;
            if(n[m] < t) l = m+1;
            else if(n[m] > t) r = m;
            else return m;
        }
        return (n[l] == t ? l : -1);
    }
};
