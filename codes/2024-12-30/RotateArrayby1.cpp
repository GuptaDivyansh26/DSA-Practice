// Rotating Array by 1 Problem

#include <bits/stdc++.h>
using namespace std;


// Creating Array
vector<int> createArray(){
    
    cout << "Enter no. of array elements: ";
    int n;
    cin >> n;
    
    vector<int> v;
    cout << "Enter elements: ";
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
    
    
    // Brute Force- Using temp array
    // Time Complexity --> O(N) 
    // Space Complexity --> O(N)
    
    /*
    vector<int> temp(arr.size(), 0);
    for(int i = 1; i < arr.size(); i++){
        
        temp[i] = arr[i -1];
    }
    temp[0] = arr[arr.size()-1];
    arr = temp;
    */
	
	
	
    // Optimised- Using Temp Variable
    // Time Complexity --> O(N)  
    // Space Complexity --> O(1)
    
    /*
    int temp = arr[arr.size() - 1];
    for(int i = arr.size()-1; i > 0; i--){
        
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
	*/
    
    
    // Printing Array
    cout << "Rotated Array: ";
    printArray(arr);
    
    return 0;
}