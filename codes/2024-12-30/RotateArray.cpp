// Rotating Array Problem

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
    
    int times;
    cout << "Enter no. of times array has to be rotated: ";
    cin >> times;
    times %= arr.size();
    
    
    // Brute Force- Using temp array
    // Time Complexity --> O(N) 
    // Space Complexity --> O(N)
    
    /*
    vector<int> temp(arr.size(), 0);
    for(int i = times; i < temp.size(); i++){
        
        temp[i] = arr[i - times];
    }
    for(int i = 0; i < times; i++){
        
        temp[i] = arr[i + times + 1];
    }
    arr = temp;
	*/
	
	
    // Optimised- In built Reversal Functions
    // Time Complexity --> 2 * O(N)  
    // Space Complexity --> O(1)
    
    /*
    reverse(arr.begin(), arr.end() - times);
    reverse(arr.end() - times, arr.end());
    reverse(arr.begin(), arr.end());
	*/
    
    
    // Printing Array
    cout << "Rotated Array: ";
    printArray(arr);
    
    return 0;
}