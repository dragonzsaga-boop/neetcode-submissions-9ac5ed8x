class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vecPosSpeed(position.size());
        for(int i = 0; i < position.size(); ++i) {
            vecPosSpeed[i].first = position[i];
            vecPosSpeed[i].second = speed[i];
        }
        sort(vecPosSpeed.begin(), vecPosSpeed.end(), greater<pair<int,int>>());

        // need for stack comes, since there's no overtaking possible
        // a fast car (a) stuck behind slow car (b), will join slower car's fleet
        // even if there was another faster car (c) ahead of the slow car, 
        // there will be two fleets, fleet with car (c) and fleet with car (b,a)

        stack<float> stTimeToTarget;
        for(int i = 0; i < vecPosSpeed.size(); ++i) {
            const float &timeToTarget 
                = (static_cast<float>(target-vecPosSpeed[i].first)/vecPosSpeed[i].second);
            if(stTimeToTarget.empty() || timeToTarget > stTimeToTarget.top()) {
                stTimeToTarget.push(timeToTarget);
            }
        }
        return stTimeToTarget.size();
/*
        [2 , 3]
        [4 , 1] time -> [3, 3]
        [6 , 4]
        [8 , 7]
        [10, 10]

        [1, 2, 2, 1]
        [7, 4, 1, 0] time -> [3, 3, 5, 10]
        [8, 6, 3, 1]
        [9, 8, 5, 2]
        [10,10,7, 3]
        [10,10,9, 4]
        [10,10,10,5]
        [__________]        

*/
    }
};
