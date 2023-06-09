// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), res = INT_MAX;
        if(n==1) return triangle[0][0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                int upl = j==0 ? INT_MAX : triangle[i-1][j-1];
                int upr = j==i ? INT_MAX : triangle[i-1][j];
                triangle[i][j] += min(upl, upr);
                if(i == n-1) res = min(res, triangle[i][j]);
            }
        }
        return res;
    }
};


// Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), res = INT_MAX;
        vector<int> vec(n, 0);
        vec[0] = triangle[0][0];
        for(int i = 1; i < n; i++){
            int prev = INT_MAX;
            for(int j = 0; j <= i; j++){
                int upl = prev;
                int upr = j==i ? INT_MAX : vec[j];
                prev = upr;
                vec[j] = triangle[i][j] + min(upl, upr);
            }
        }
        return *min_element(vec.begin(), vec.end());
    }
};
