class Solution {
    string convertToString(const vector<int> &vec) {
        string res;
        for(int i = 0; i < vec.size(); ++i) {
            res += ('a'+i);
            res += to_string(vec[i]);
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> resMap;
        for(const auto &str : strs) {
            vector<int> strmap(26,0);
            for(auto ch : str) {
                ++strmap[ch-'a'];
            }
            resMap[convertToString(strmap)].push_back(str);
        }
        cout<<"x"<<endl;
        vector<vector<string>> resv(resMap.size());
        int idx = 0;
        for( auto &strVec : resMap) {
            for(const auto &str : strVec.second) {
                resv[idx].push_back(str);
            }
            ++idx;
        }
        return resv;
    }
};
