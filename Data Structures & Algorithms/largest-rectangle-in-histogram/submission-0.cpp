class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
/*
7 1 7 2 2 4
1 2 1 2 3 1        L width
1 5 1 3 2 1        R width
1 6 1 4 4 1        L + R combined width
7 6 7 8 8 4        area (combined width * height)

7 1 1 1 7 1 1 1

-1,-1,-1,-1,-1,-1,-1,-1
,8,8,8


 L width
 R width
L+R width
area
*/
        const int &n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> st;

        for(int i = 0; i < n; ++i) {
            while(st.size() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) {
                leftMost[i] = st.top();
            }
            st.push(i);
        }
        st = {};
        for(int i = n-1; i >= 0; --i) {
            while(st.size() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) {
                rightMost[i] = st.top();
            }
            st.push(i);
        }
        int retVal = 0;
        for(int i = 0; i < n; ++i) {
            leftMost[i] += 1;
            rightMost[i] -= 1;
            retVal = max(retVal, 
                        (rightMost[i] - leftMost[i] + 1)*heights[i]);
        }
        return retVal;
    }
};