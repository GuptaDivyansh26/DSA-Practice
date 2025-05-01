// Move Negative Elements to End Problem

#include <bits/stdc++.h>
using namespace std;


// Creating Array
vector<int> createArray(){
    
    cout << "Enter no. of array elements: ";
    int n;
    cin >> n;
    
    vector<int> v;
    cout << "Enter elements (0s, 1s, 2s): ";
    for(int i = 0; i < n; i++){
        
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    return v;
}

// Printing Array
void printArray(vector<int> arr){
    
    for(auto it : arr){
        
        cout << it << ' ';
    }
}


int main()
{
    // Creating Array
    vector<int> arr = createArray();
    
    
    // Brute Force- Pushing posiitve elements to Temp1 Array, Negative to Temp2, Array = Temp1 + Temp2
    // Time Complexity --> O(N)  
    // Space Complexity --> O(N)

    // This method is used to preserve the order but uses extra space.
    
    // Better - Using 2 Pointers
    // Time Complexity --> O(N)  [Traversing]
    // Space Complexity --> O(1)  [No extra space]
    
    // This method doesn't use ny extra space bu it doesn't preserve the order. Although, it does move negative elements to the end.

    int i = 0, j = 0;
    while(i < arr.size() && j < arr.size()){
        
        while(arr[i] > 0)   i++;
        while(arr[j] < 0)   j++;
        swap(arr[i], arr[j]);
        i++; j++;
    }
    
    
    // Printing Array
    cout << "Sorted Array: ";
    printArray(arr);
    
    return 0;
}