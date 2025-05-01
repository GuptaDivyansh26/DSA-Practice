// Minimise the Heights- II

// Optimised Approach- sort, modify, check for min and max, find min difference by changing the position of cut. If ele - k goes below 0, skip the iteration.

int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
  
    int res = arr[n - 1] - arr[0];

    for (int idx = 1; idx < arr.size(); idx++) {
      
        if (arr[idx] - k < 0)
            continue;
      
        int shrink = min(arr[0] + k, arr[idx] - k);
      
        int grow = max(arr[idx - 1] + k, arr[n - 1] - k);

        res = min(res, grow - shrink);
    }
    
    return res;
}