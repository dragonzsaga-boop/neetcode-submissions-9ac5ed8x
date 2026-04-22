class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charMap;
        int res = 0, startIdx = 0;
        for(int endIdx = 0; endIdx < s.size(); ++endIdx) {
            // cout<<"\t"<<s[endIdx]<<endl;
            if(charMap.count(s[endIdx]) && charMap[s[endIdx]] >= startIdx) {
                // cout<<startIdx<<" : "<<endIdx<<" : "<<s[endIdx]<<" : updated start : "<<charMap[ s[endIdx] ]+1<<endl;
                startIdx = charMap[ s[endIdx] ] + 1;
            }
            charMap[ s[endIdx] ] = endIdx;
            // cout<<res<<" : "<<endIdx-startIdx+1<<endl;
            res = max(res, endIdx - startIdx + 1);
        }
        return res;
    }
};
