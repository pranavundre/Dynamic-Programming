class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(m, 1);
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                row[j] = row[j] + row[j-1];
        return row[m-1];
    }
};
