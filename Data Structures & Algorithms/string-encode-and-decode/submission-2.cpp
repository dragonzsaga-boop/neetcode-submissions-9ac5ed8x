class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for(const string &str : strs) {
            stringstream x;
            x<<std::setfill('0') << std::setw(3)<<str.size();
            ret += x.str();
            ret += str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> retV;
        for(int i = 0; i < s.size(); ) {
            int currLen = stoi(s.substr(i,3));
            retV.push_back(std::move(s.substr(i+3, currLen)));
            i += currLen + 3;
        }

        return retV;
    }
};
