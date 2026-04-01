class Solution {
    //()()()()
    void genPar(string str, int numPar, unordered_set<string> &res, int n, int pos = 0) {
        if(numPar > n) return;
        for(int i = 0; i < str.size(); ++i) {
            string newRefL = str.substr(0, str.size()-i) + "()" + str.substr(str.size()-i);
            // string newRefL = str.substr(i, str.size()-i) + "()";
            // cout<<i<<" : "<<pos<<" : "<<newRefL<<" |||\n\t\t "<<str.substr(0, str.size()-i) <<" <---> "<<str.substr(str.size()-i)<<endl;
            if(numPar == n-1)
                res.insert(newRefL);

            genPar(newRefL, numPar+1, res, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n < 1 || n > 7) return {};
        if(n == 1) return {"()"};
        unordered_set<string> res;
        string start = "()";
        genPar(start, 1, res, n);

        vector<string> ret;
        for(const auto &str : res) {
            ret.emplace_back(move(str));
        }
        return ret;
    }
};

// ()
// (()) | ()()
// ()()() | ()(()) | ()()() | (())() | ((())) | (()())