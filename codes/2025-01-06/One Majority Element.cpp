// One majority element (> N/2)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Creating Array
vector<int> createArray(){
    
    cout << "Enter no. of array elements: ";
    int n;
    cin >> n;
    
    vector<int> v;
    cout << "Enter elements (Frequency of one element should be greater than 'N/2'): ";
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
    vector<int> arr = createArray();
    
    // Brute Force- Traversing the loop twice. One for checking the element and other for counting its occurences. Use two variable- cnt, maxi
    // Time Complexity --> O(N ^ 2)  
    // Space Complexity --> O(1)
    
    /*
    maxVar = -1;
    int i = 0 ---> arr.size(){
        int freq = 0;
        int j = 0 ---> arr.size(){
            if(arr[j] == arr[i]){
                
                freq++;
            }
        }
        if(freq > N / 2){
            maxVar = arr[i];
            break;
        }
    }
    */
    
    // Better - Using Hashing
    // Time Complexity --> O(N) + O(N)  [Storing ad Fetching]
    // Space Complexity --> O(N)  [Unordered map--> N * O(1)]

    /*
    unordered_map<int, int> mpp;
    int maxVar = -1, count = 0;
    for(int i = 0; i < arr.size(); i++){
        
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        
        if(it.second > arr.size() / 2){
            
            maxVar = it.first;
            count = it.second;
        }
    }
    */
    
    // Optimised - Moore's Voting Algorithm (Focuses on chances of winning instead of actual frequency)
    // Time Complexity --> O(N)  [Single Traversal]
    // Space Complexity --> O(1)  [No extra space required]
    
    /*
    int maxVar = -1;
    int votes = 0;
    for(int i = 0; i < arr.size(); i++){
        
        if(arr[i] == maxVar){
            
            votes++;
        }else{
            
            if(votes > 0)   votes--;
            else if(votes == 0){
                
                maxVar = arr[i];
                votes++;
            }
        }
    }
    int count = 0;
    for(auto it : arr){
        
        if(it == maxVar)    count++;
    }
    */
    
    // Printing Array
    if(maxVar == -1)    cout << "No maximum element present in array.";
    else    cout << "Maximum frequency variable: " << maxVar << " with frequency: " << count;
    
    return 0;
}