class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        st.empty();
        minSt.empty();
    }
    
    void push(int val) {
        st.push(val);
        if(!minSt.size() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if(!st.size()) return;
        int val = st.top(); st.pop();
        if(val == minSt.top()) {
            minSt.pop();
        }
    }
    
    int top() {
        if(!st.size()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(!minSt.size()) return -1;
        return minSt.top();
    }
};
