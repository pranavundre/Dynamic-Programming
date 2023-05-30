// Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size(), res = -1;
    if(n==1) return nums[0];
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = nums[1];
    res = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        int maxSum = 0;
        for(int j = 0; j < i-1; j++){
            int sum = dp[j] + nums[i];
            maxSum = max(sum, maxSum);
        }
        dp[i] = maxSum;
        res = max(res, maxSum);
    }
    return res;
}

// Space Optimized
int maximumNonAdjacentSum(vector<int> &nums){
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
