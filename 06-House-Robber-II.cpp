class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev12 = 0, prev1 = nums[0], prev22 = 0, prev2 = nums[1];
        for(int i = 1; i < n-1; i++){
            int take1 = nums[i] + prev12;
            int notTake1 = prev1;
            int maxSum1 = max(take1, notTake1);
            prev12 = prev1;
            prev1 = maxSum1;

            int take2 = nums[i+1] + prev22;
            int notTake2 = prev2;
            int maxSum2 = max(take2, notTake2);
            prev22 = prev2;
            prev2 = maxSum2;
        }
        return max(prev1, prev2);
    }
};
