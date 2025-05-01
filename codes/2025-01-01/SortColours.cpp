// Sort Colour Problem

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
    
    
    // Brute Force- Sorting
    // Time Complexity --> O(N log N)  
    // Space Complexity --> O(1)  
    
    /*
    sort(arr.begin(), arr.end());
    */
    
    
    
    // Better - Using frequency
    // Time Complexity --> O(N) + O(N)  [Traversing both arrays]
    // Space Complexity --> 3 * O(1)  [Resultant Array]
    
    /*
    unordered_map<int, int> mpp;
    for(int i = 0; i < arr; i++){
        
        mpp[arr[i]]++;
    }
    for(int i = 0; i < mpp[0]; i++){
        
        arr[i] = 0;
    }
    for(int i = mpp[0]; i < mpp[0]+mpp[1]; i++){
        
        arr[i] = 1;
    }
    for(int i = mpp[0]+mpp[1]; i < mpp[0]+mpp[1]+mpp[2]; i++){
        
        arr[i] = 2;
    }
    */
    
    // Optimised - (Dutch national Flag Algorithm) Using 2 pointers
    // Time Complexity --> O(M + N)  [Traversing both arrays]
    // Space Complexity --> O(M + N)  [Resultant Array]
    
    /*
    int i = 0, j = 0, k = arr.size()-1;
    while (j <= k) {
        
        if(arr[j] == 0){
            
          swap(arr[i], arr[j]);
          i++;
          j++;
        }
        else if(arr[j] == 2){
            
          swap(arr[k], arr[j]);
          k--;
        }
        else{
            
          j++;
        }
    }
    */
    
    // Printing Array
    cout << "Sorted Array: ";
    printArray(arr);
    
    return 0;
}