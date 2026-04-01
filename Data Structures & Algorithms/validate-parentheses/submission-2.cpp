class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> vset = {'[',']','(',')','{','}'};
        unordered_map<char,char> pmap = {{'}','{'},{')','('},{']','['}};
        stack<char> st;
        for(int i = 0; i < s.size(); ++i) {
            if(!vset.count(s[i])) { 
                return false;
            }
            if(!pmap.count(s[i])) {
                st.push(s[i]);
            }
            else {
                if(!st.size() || st.top() != pmap[s[i]]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
