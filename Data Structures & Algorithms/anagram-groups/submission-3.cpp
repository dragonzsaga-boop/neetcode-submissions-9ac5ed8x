class Solution {
    string serializer(const string &str) {
        vector<int> vec(26,0);
        for(auto ch : str) ++vec[ch-'a'];
        string ret = "";
        for(int i = 0; i < 26; ++i) {
            ret += ('a'+i);
            ret += to_string(vec[i]);
        }
        return ret;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mapOfVecOfStrings;
        for(const auto &str : strs) {
            const auto &serializedStr = serializer(str);
            mapOfVecOfStrings[serializedStr].push_back(str);
        }

        vector<vector<string>> ret(mapOfVecOfStrings.size());
        int idx = 0;
        for(const auto &prStringVecStrings : mapOfVecOfStrings) {
            for(const auto & str : prStringVecStrings.second) {
                ret[idx].push_back(str);
            }
            ++idx;
        }
        return ret;
    }
};
