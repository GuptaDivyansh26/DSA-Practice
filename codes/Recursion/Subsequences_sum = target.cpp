// Printing all subsets whose sum = target

#include <iostream>
#include <vector>
using namespace std;

void subsequence(int idx, int n, vector<int>& arr, vector<int> curr, int target, int sum)
{
    if(idx >= n)
    {
        if(sum == target)
        {
            cout << '{';
            for(auto it: curr)  cout << ' ' << it << ' ';
            cout << '}';
        
            cout << "  ";
        }
        return;
    }
    
    subsequence(idx + 1, n, arr, curr, target, sum);
    
    curr.push_back(arr[idx]);
    sum += arr[idx];
    subsequence(idx + 1, n, arr, curr, target, sum);
    
    curr.erase(curr.end() - 1);
}

int main()
{
    int n, target;
    
    cout << "Enter length of array & target: ";
    cin >> n >> target;
    
    vector<int> arr(n, 0);
    
    cout << "Enter elements: ";
    
    for(int idx = 0; idx < n; idx++)
    {
        cin >> arr[idx];
    }
    
    vector<int> curr = {};
    
    subsequence(0, n, arr, curr, target, 0);

    return 0;
}