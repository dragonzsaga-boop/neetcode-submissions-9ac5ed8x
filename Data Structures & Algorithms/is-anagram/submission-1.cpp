class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc(26,0), st(26,0);
        for(auto ch : s) {
            ++sc[ch-'a'];
        }
        for(auto ch : t) {
            ++st[ch-'a'];
        }
        return sc == st;
    }
};
