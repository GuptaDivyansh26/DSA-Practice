// Reverse Array after 'm' index Problem

#include <bits/stdc++.h>
using namespace std;

// Creating Array
vector<int> createArray()
{

    cout << "Enter no. of array elements: ";
    int n;
    cin >> n;

    vector<int> v;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {

        int num;
        cin >> num;
        v.push_back(num);
    }

    return v;
}

// Printing Array
void printArray(vector<int> arr)
{

    for (auto it : arr)
    {

        cout << it << ' ';
    }
}

// reversing by Recursion
void rev(vector<int> &arr, int i, int j)
{

    if (i >= j)
        return;
    swap(arr[i], arr[j]);
    rev(arr, i + 1, j - 1);
}

int main()
{
    // Creating Array
    vector<int> arr = createArray();

    // Brute Force- Using temp array
    // Time Complexity --> O(N)
    // Space Complexity --> O(N)

    /*
    vector<int> temp(arr.size(), 0);
    for(int i = 0; i < arr.size(); i++){

        temp[arr.size() - 1 - i] = arr[i];
    }
    arr = temp;
    */

    // Better- Swapping
    // Time Complexity --> O(N)
    // Space Complexity --> O(1)

    /*
    int i = 0, j = arr.size() - 1;
    while(i < j){

        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    */

    // Better- Recursion
    // Time Complexity --> O(N)
    // Space Complexity --> O(1)

    /*
    rev(arr, 0, arr.size() - 1);
    */

    // Optimised- Using In-built Function
    // Time Complexity --> O(N)
    // Space Complexity --> O(1)

    /*
    reverse(arr.begin(), arr.end());
    */

    // Printing Array
    cout << "Reversed Array: ";
    printArray(arr);

    return 0;
}