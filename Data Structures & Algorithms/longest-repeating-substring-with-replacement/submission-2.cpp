class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0, currMax = 0, result = 0;
        unordered_map<char,int> charMap;
        
        while(end < s.length()) {
            ++charMap[ s[end] ];
            currMax = max(currMax, charMap[ s[end] ]);
            if( ((end-start+1) - currMax) > k ) {
                --charMap[ s[start] ];
                ++start;
            }
            result = max(result, end - start + 1);
            ++end;
        }

        return result;
    }
};
