// Reverse Array after 'm' index Problem

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
    
    int M;
    cout << "Enter 'M': ";
    cin >> M;
    
    
    // Brute Force- Using temp array
    // Time Complexity --> O(N) 
    // Space Complexity --> O(N)
    
    /*
    vector<int> temp(arr.size(), 0);
    for(int i = 0; i <= M; i++){
        
        temp[i] = arr[i];
    }
    for(int i = 0; i < arr.size() - M - 1; i++){
        
        temp[i + M + 1] = arr[arr.size() - i - 1];
    }
    arr = temp;
    */
	
	
    // Better- Swapping
    // Time Complexity --> O(N)  
    // Space Complexity --> O(1)
    
    /*
    int i = M + 1, j = arr.size() - 1;
    while(i < j){
        
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
	*/
	
	
    // Optimised- Using In-built Function
    // Time Complexity --> O(N)  
    // Space Complexity --> O(1)
    
    /*
    reverse(arr.begin() + M + 1, arr.end());
	*/
    
    
    // Printing Array
    cout << "Semi Reversed Array: ";
    printArray(arr);
    
    return 0;
}