// Memoization
int recur(vector<int> &jumps, int index, vector<int> &dp){
    if(dp[index] != -1) return dp[index];
    if(index == 0) return 0;
    
    int left = recur(jumps, index-1, dp) + abs(jumps[index]-jumps[index-1]);
    int right = INT_MAX;
    if(index>1) right = recur(jumps, index-2, dp) + abs(jumps[index]-jumps[index-2]);
    
    return dp[index] = min(left, right);
}
int frogJump(int n, vector<int> &jumps){
    vector<int> dp(n, -1);
    return recur(jumps, n-1, dp);
}

// Tabulation
int frogJump(int n, vector<int> &jumps){
    if(n==1) return 0;
    vector<int> dp(n, 0);
    dp[1] = dp[0] + abs(jumps[1] - jumps[0]);
    for(int i = 2; i < n; i++){
        int fs = dp[i-1] + abs(jumps[i] - jumps[i-1]);
        int ss = dp[i-2] + abs(jumps[i] - jumps[i-2]);
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}

// Space Optimization
int frogJump(int n, vector<int> &jumps){
    if(n==1) return 0;
    int a = 0, b = abs(jumps[1] - jumps[0]);
    for(int i = 2; i < n; i++){
        int fs = b + abs(jumps[i] - jumps[i-1]);
        int ss = a + abs(jumps[i] - jumps[i-2]);
        a = b;
        b = min(fs, ss);
    }
    return b;
}
