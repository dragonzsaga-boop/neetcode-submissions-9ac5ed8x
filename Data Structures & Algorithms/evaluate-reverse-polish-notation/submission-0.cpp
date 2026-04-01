class Solution {
    bool isOperator(const string &tok) {
        if(tok == "+" || tok == "*" || tok == "/" || tok == "-")
            return true;
        return false;
    }
    int applyOperator(int l, int r, const string &tok) {
        switch (tok.c_str()[0]) {
            case '+' : {
                return l + r;
            } break;
            case '-' : {
                return l - r;
            } break;
            case '*' : {
                return l * r;
            } break;
            case '/' : {
                return l / r;
            } break;
            default : return -1;    
        }
        //return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto & tok : tokens) {
            if(isOperator(tok)) {
                if(st.size() < 2) return -1;
                int r = st.top(); st.pop();
                int l = st.top(); st.pop();
                st.push(applyOperator(l,r,tok));
            }
            else {
                st.push(stoi(tok));
            }
        }
        if(st.size() != 1) return -1;
        return st.top();
    }
};
