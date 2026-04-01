class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> su(26,0), st(26,0);
        for(auto ch : s) {
            ++su[ch-'a'];
        }
        for(auto ch : t) {
            ++st[ch-'a'];
        }
        return su == st;
    }
};
