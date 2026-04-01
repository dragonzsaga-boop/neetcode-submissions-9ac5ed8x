class Solution {
    map<char,char> mp{{')','('},{']','['},{'}','{'}};
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s) {
            switch(ch) {
                case '(':
                case '[':
                case '{': {
                    st.push(ch);
                    break;
                }
                case ']':
                case '}':
                case ')': {
                    if(!mp.count(ch) || st.empty()) return false;
                    if(st.top() != mp[ch]) return false;
                    st.pop();
                    break;
                }
                default: return false;
            }
        }
        return st.empty();
    }
};
