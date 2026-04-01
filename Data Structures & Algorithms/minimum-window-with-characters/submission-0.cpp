class Solution {
    bool compareMaps(unordered_map<char,int> &sCount,
                        unordered_map<char,int> &tCount) {
        for(const auto &pr : tCount) {
            if(!sCount.count(pr.first) || sCount[pr.first] < pr.second)
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tCount, sCount;
        for(auto ch : t) ++tCount[ch];

        string res = "";
        int start = 0, end = 0;
        for(end = 0; end < s.size(); ++end) {
            ++sCount[ s[end] ];
            while(compareMaps(sCount, tCount)) {
                // cout<<res<<"\t"<<s.substr(start, end-start+1)<<endl;
                if(end-start+1 <= res.size() || res == "") {
                    res = s.substr(start, end-start+1);
                }
                --sCount[s[start]];
                ++start;
            }
        }

        return res;
    }
};
