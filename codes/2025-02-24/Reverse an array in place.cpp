#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> & v, int low, int high)
{
    if(low >= high)  return;

    int temp = v[low];
    v[low] = v[high];
    v[high] = temp;

    reverse(v, low + 1, high - 1);
}

void print(vector<int> v)
{
    for(auto it : v)
    {
        cout << it << ' ';
    }
}

int main()
{
    int n;
    cout << "Enter length of vector: ";
    cin >> n;

    vector<int> v(n, 0);
    cout << "Enter elements: ";
    for(int idx = 0; idx < n; idx ++)
    {
        cin >> v[idx];
    }

    cout << "Reversed Array is: ";
    reverse(v, 0, n-1);
    
    print(v);

    return 0;
}