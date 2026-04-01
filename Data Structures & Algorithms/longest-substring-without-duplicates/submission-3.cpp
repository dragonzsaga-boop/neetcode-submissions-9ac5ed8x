class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_set<char> us;
        int l = 0, res = 0;
        for(int i = 0; i < s.size(); ++i) {
            while(us.find(s[i]) != us.end()) {
                us.erase(s[l]);
                ++l;
            }
            res = max(res, i-l+1);
            us.insert(s[i]);
        }
        return res;
    }
};
