#include<bits/stdc++.h>
using namespace std;

void fn(int index, vector<int> &a, vector<vector<int>> &v, vector<int> &temp)
{
    if(index == a.size())
    {
        v.push_back(temp);        
        return;
    }
    
    fn(index+1, a, v, temp); // not including
    
    temp.push_back(a[index]); // including
    fn(index+1, a, v, temp);
    temp.pop_back();
}

int main()
{
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;
    cout << "Enter elements: ";
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // vector<int> a = {1, 2, 3};

    vector<vector<int>> v; //vector to contain all subsets
    vector<int>temp; // temporary vector

    fn(0, a, v, temp);

    for(auto i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}

// Time Complexity : O(2^n)
// Space Complexity : O(n*n)