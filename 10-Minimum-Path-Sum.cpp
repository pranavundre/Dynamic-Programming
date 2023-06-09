// Memoization
class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c){
        if(r == 0 && c == 0) return dp[0][0] = grid[0][0];
        if(dp[r][c] != -1) return dp[r][c];

        int up = r == 0 ? INT_MAX : solve(grid, dp, r-1, c);
        int left = c == 0 ? INT_MAX : solve(grid, dp, r, c-1);

        return dp[r][c] = grid[r][c] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return solve(grid, dp, m-1, n-1);
    }
};


// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i==0 && j==0) continue;
                int up = i==0 ? INT_MAX : grid[i-1][j];
                int left = j==0 ? INT_MAX : grid[i][j-1];
                grid[i][j] += min(up, left);
            }
        }
        return grid[m-1][n-1];
    }
};


// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0){
                    dp[j] = j==0 ? grid[j][0] : grid[j][0] + dp[j-1];
                    continue;
                }
                int up = j==0 ? INT_MAX : dp[j-1];
                int left = dp[j];
                dp[j] = grid[j][i] + min(up, left);
            }
        }

        return dp[m-1];
    }
};
