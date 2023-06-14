// Memoization
bool func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = func(ind - 1, target, arr, dp);
    bool take = false;
    if(arr[ind] <= target) take = func(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return func(n-1, k, arr, dp);
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= k; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(target - arr[ind] >= 0) take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}

// Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = 1;
    if(arr[0] <= k) prev[arr[0]] = 1;
    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(target - arr[ind] >= 0) take = prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return curr[k];
}
