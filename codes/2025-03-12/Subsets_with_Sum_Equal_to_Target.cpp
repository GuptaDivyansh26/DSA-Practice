// All subsets having sum equal to target

// First we input array and target and pass them to recursive function.
// idx to keep record of index traversed, sum to carry sum, and temp is array tohold subset.
// Base condition- if sun = target, print subsequence. Else if unsatisfying conditions, return. else, recursive call.
// We apply pick/non-pick method at every index.

// TC- 2^n --> n is size of array
// SC- k * x --> x is no. of combinations, k is avg length of subsequence

#include<bits/stdc++.h>
using namespace std;

void func(int idx, int& sum, int& target, vector<int>& arr, vector<int> temp)
{
    
    if(sum == target)
    {
        cout << '{';
        
        for(auto it: temp)  cout << it << ' ';
        
        cout << '}';
        
        return;
    }

    if(sum > target || idx >= arr.size())   return;
    
    temp.push_back(arr[idx]);
    sum +=arr[idx];
    
    func(idx + 1, sum, target, arr, temp);

    temp.erase(temp.end() - 1);
    sum -= arr[idx];
    
    func(idx + 1, sum, target, arr, temp);
}

int main(){
    
    int n;
    
    cout << "Enter length of array: ";
    cin >> n;
    
    vector<int> candidates(n, 0);
    
    cout << "Enter elements: ";
    
    for(auto& it : candidates)
    {
        cin >> it;
    }
    
    int target;
    
    cout << "Enter target: ";
    cin >> target;
    
    vector<vector<int>> res;

    vector<int> temp;
    
    int sum = 0;

    func(0, sum, target, candidates, temp);

}