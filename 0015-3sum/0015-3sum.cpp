class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum < 0) lo++;
                else if (sum > 0) hi--;
                else {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++; hi--;
                }
            }
        }
        return res;
    }
};