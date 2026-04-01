class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    /*{
        vector<bool> vec(INT_MAX/4, false);
        // cout<<vec.size()<<endl;
        for(int i : nums) {
            // cout<<i <<endl;
            if(vec[i]) return true;
            vec[i] = true;
        }
        return false;
    }*/
    
    {
        unordered_set<int> us;
        for(int i : nums) {
            if(us.count(i))
                return true;
            us.insert(i);
        }
        return false;
    }
    
    /*{
        for(int i = 0; i < nums.size()-1; ++i) {
            int curr = nums[i];
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[j] == curr) {
                    // cout<<nums[j]<<" "<<curr<<endl;
                    return true;
                }
            }
        }
        return false;
    }*/
};
/*
2,497,000,900

9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
10 + 10 + 10 + 10 + 5
45 = (9 * 10)/2
res = (n * [n+1])/2
(n2 + n)/2

0 1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9 
2 3 4 5 6 7 8 9
3 4 5 6 7 8 9
4 5 6 7 8 9
5 6 7 8 9
6 7 8 9
7 8 9
8 9
9
*/