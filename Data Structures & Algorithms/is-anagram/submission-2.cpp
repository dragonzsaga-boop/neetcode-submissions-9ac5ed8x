class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> us(26,0), ut(26,0);
        for(char c:s) ++us[c-'a'];
        for(char c:t) ++ut[c-'a'];
        return ut == us;
    }
};
