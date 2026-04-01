class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ts) {
        stack<pair<int,int>> st;
        vector<int> res(ts.size());
        for(int i = 0; i < ts.size(); ++i) {
            while(st.size() && (st.top().first < ts[i] ) ) {
                auto pr = st.top(); st.pop();
                res[pr.second] = i - pr.second;
            }
            st.push({ts[i],i});
        }
        return res;
    }
};
