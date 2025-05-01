// Minimise the Heights- I

// Optimised Approach- sort, modify, check for min and max, find min difference by changing the position of cut

int getMinDiff(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    int diff = arr.back() - arr[0];

    int idx = 0;

    while (idx < arr.size() - 1)
    {
        int grow = max(arr[idx] + k, arr.back() - k);

        int shrink = min(arr[idx + 1] - k, arr[0] + k);

        diff = min(diff, grow - shrink);

        idx++;
    }

    return diff;
}