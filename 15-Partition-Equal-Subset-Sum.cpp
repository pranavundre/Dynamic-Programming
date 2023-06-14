class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;
        sum = sum>>1;
        int n = nums.size();
        vector<int> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = curr[0] = 1;
        if(nums[0] <= sum) prev[nums[0]] = 1;
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target - nums[ind] >= 0) take = prev[target - nums[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return curr[sum];
    }
};
