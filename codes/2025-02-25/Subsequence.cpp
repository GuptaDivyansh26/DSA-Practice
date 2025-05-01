// Generating all subsequences of array- We pick up all elements one by one, and apply recursion if that element is picked and once if it is not picked. On doing so, all cases are covered.

// Time Complexity - O(2 ^ n)   where n --> length of array r
// Space Complexity - O(n)  [We are using a  temp array 'curr' whose max. size can be 'n']

#include <iostream>
#include <vector>
using namespace std;

void subsequence(int idx, int n, vector<int>& arr, vector<int> curr)
{
    if(idx >= n)
    {
        cout << '{';
        for(auto it: curr)  cout << ' ' << it << ' ';
        cout << '}';
        
        cout << "  ";
        return;
    }
    
    curr.push_back(arr[idx]);
    subsequence(idx + 1, n, arr, curr);
    
    curr.erase(curr.end() - 1);
    subsequence(idx + 1, n, arr, curr);
}

int main()
{
    int n;
    
    cout << "Enter length of array: ";
    cin >> n;
    
    vector<int> arr(n, 0);
    
    cout << "Enter elements: ";
    
    for(int idx = 0; idx < n; idx++)
    {
        cin >> arr[idx];
    }
    
    vector<int> curr = {};
    
    subsequence(0, n, arr, curr);

    return 0;
}