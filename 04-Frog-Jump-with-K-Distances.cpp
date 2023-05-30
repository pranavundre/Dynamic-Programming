#include <bits/stdc++.h>

using namespace std;

int frogJump(vector<int> jump, int n, int k){
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        int minCost = INT_MAX, cnt = 1;
        while(i-cnt >= 0 && cnt <= k){
            int cost = dp[i-cnt] + abs(jump[i-cnt] - jump[i]);
            minCost = min(cost, minCost);
            cnt++;
        }
        dp[i] = minCost;
    }
    return dp[n-1];
}

int main(){
    vector<int> vec = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    cout<<frogJump(vec, 10, 4);
}
