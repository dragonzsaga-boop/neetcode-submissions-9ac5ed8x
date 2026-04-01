class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        // for(auto i : nums) cout<<i<<" "; cout<<endl;
        for(int i = 0; i < nums.size()-2; ++i) {
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                // while((j < k) && (nums[j] == nums[j+1])) ++j;
                while((j < k) && (nums[k] == nums[k-1])) --k;
                cout<<i<<" ["<<nums[i]<<"], " <<j<<" ["<<nums[j]<<"], "<<k<<" ["<<nums[k]<<"] = "<<nums[i] + nums[j] + nums[k]<<endl;
                if(nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                }
                else {//if(nums[i] + nums[j] + nums[k] == 0) {
                    ret.emplace_back(vector<int> {nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                }
            }
            // bool swapped = false;
            while(i < nums.size()-2 && nums[i] == nums[i+1])  {
                ++i;
                // swapped = true;
            }
            // if(swapped) --i;

        }
        return ret;
    }
};
