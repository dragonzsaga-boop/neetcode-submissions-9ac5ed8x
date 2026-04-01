class Solution {
    //aaababb
    //bbabaaa
    //aaabababaaaaa
public:
//3
    int characterReplacement(string s, int k) {
        vector<int> chars(26,0);
        int start = 0, end = 0;
        int res = 0, currMax = 0 ;
        while(end < s.size()) {
            ++chars[s[end] - 'A'];
            currMax = max(currMax, chars[s[end] - 'A']);
            while((( end - start + 1 ) - currMax) > k) {
                --chars[s[start]-'A'];
                ++start;
            }
            res = max(res, end - start + 1);
            ++end;
        }
        return res;
    }
};
