class Solution {
    using POS_TIME = pair<int,float>;
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<POS_TIME> posTime(pos.size());
        for(int i = 0; i < pos.size(); ++i) {
            posTime[i] = make_pair(pos[i], (static_cast<float>(target-pos[i]))/sp[i]);
        }
        sort(posTime.begin(), posTime.end(), [](const POS_TIME &l, const POS_TIME &r) {
            return(l.first > r.first);
        });
        stack<POS_TIME> st;
        for(auto car : posTime) {
            // cout<<car.first<<" : "<<car.second<<endl;
            if(!st.size() || (st.top().second < car.second)) 
                st.push(car);

        }
        int ret = st.size();
        // cout<<endl<<endl;
        // while(st.size()) { cout<<st.top().first<<" : "<<st.top().second<<endl; st.pop();}
        return ret;
    }
};
