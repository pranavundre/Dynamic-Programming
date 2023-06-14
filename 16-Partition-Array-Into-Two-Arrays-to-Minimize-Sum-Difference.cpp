int minSubsetSumDifference(vector<int>& arr, int n){
	int totalSum = accumulate(arr.begin(), arr.end(), 0);
	int sum = (totalSum+1)/2;

	vector<int> prev(sum+1, 0), curr(sum+1, 0);
	prev[0] = curr[0] = 1;

	int diff = INT_MAX;

	if(arr[0] <= sum) prev[arr[0]] = 1;
	
	for(int ind = 1; ind < n; ind++){
		for(int target = 1; target <= sum; target++){
			bool notTake = prev[target];
			bool take = false;
			if(target - arr[ind] >= 0) take = prev[target - arr[ind]];
			curr[target] = take || notTake;
		}
		prev = curr;
	
	}

	for(int i = 0; i < sum+1; i++) if(curr[i]) diff = min(diff, abs(2*i - totalSum));

	return diff;
}
