// Tabulatiom
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int l = j==0 ? INT_MAX : dp[i-1][j-1];
                int c = dp[i-1][j];
                int r = j==n-1 ? INT_MAX : dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(l, min(c, r));
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};


// Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for(int i = 1; i < n; i++){
            int l = INT_MAX, c = INT_MAX, r = dp[0];
            for(int j = 0; j < n; j++){
                l = c;
                c = r;
                r = j==n-1 ? INT_MAX : dp[j+1];
                dp[j] = matrix[i][j] + min(l, min(c, r));
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};


// Max Path Sum
int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    vector<int> dp = matrix[0];
    for(int i = 1; i < n; i++){
        int l = INT_MIN, c = INT_MIN, r = dp[0];
        for(int j = 0; j < m; j++){
            l = c;
            c = r;
            r = j==m-1 ? INT_MIN : dp[j+1];
            dp[j] = matrix[i][j] + max(l, max(c, r));
        }
    }
    return *max_element(dp.begin(), dp.end());
}
