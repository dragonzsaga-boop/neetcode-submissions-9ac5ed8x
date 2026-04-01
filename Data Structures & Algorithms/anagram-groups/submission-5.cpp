class Solution {
    string convertToCode(const string &str) {
        // cout<<"Converting : "<<str;
        vector<int> retVal(26,0);
        for(char ch : str) {
            ++retVal[ch-'a'];
            // cout<<"\n ..... "<<ch<<" "<<retVal[ch-'a']<<endl;
        }
        string ret = "";
        for(int i : retVal) {
            ret += 'a'+i;
            ret += to_string(i);
        }
        // cout<<" : to "<<ret<<endl;
        return ret;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> returnMap;
        for(const auto &str : strs) {
            returnMap[convertToCode(str)].push_back(str);
        }
        // for(const auto &vecStrPair : returnMap) {
        //     cout<<vecStrPair.first<<" : ";
        //     for(const auto &str : vecStrPair.second) {
        //         cout<<str<<" ; ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<string>> retVec;
        for(const auto &vecStrPair : returnMap) {
            retVec.emplace_back((vecStrPair.second));
        }
        return retVec;
    }
};
