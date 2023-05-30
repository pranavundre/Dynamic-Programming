class Solution {
public:
    int robHouse(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];
        for(int i = 1; i < n; i++){
            int take = nums[i] + prev2;
            int notTake = prev;
            int maxSum = max(take, notTake);
            prev2 = prev;
            prev = maxSum;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        return nums.size() == 1 ? nums[0] : max(robHouse(nums1), robHouse(nums2));
    }
};
