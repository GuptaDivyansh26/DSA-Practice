// Two majority elements (> N/3)

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
    cout << "Enter elements (Frequency of two elements should be greater than 'N/3'): ";
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
    
    // Brute Force- Traversing the loop twice. One for checking the elements and other for counting their occurences.
    // Time Complexity --> O(N ^ 2)  
    // Space Complexity --> O(2)    [Although we are using a vector, there can be max of 2 elements]
    
    /*
    maxVar = -1;
    vector<int> ans;
    int i = 0 ---> arr.size(){
        int freq = 0;
        int j = 0 ---> arr.size(){
            if(arr[j] == arr[i]){
                
                freq++;
            }
        }
        if(freq > N / 3){
            ans.push_back(arr[i]);
        }
        if(ans.size() == 2) break;
    }
    */
    
    // Better - Using Hashing
    // Time Complexity --> O(N) + O(N)  [Storing ad Fetching]
    // Space Complexity --> O(N) + O(2) [Unordered map--> N * O(1) and vector for returning the answer]

    /*
    unordered_map<int, int> mpp;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        
        if(it.second > arr.size() / 3){
            
            ans.push_back(it.first);
        }
        if(ans.size() == 2) break;
    }
    */
    
    
    // Optimised - Moore's Voting Algorithm (Focuses on chances of winning instead of actual frequency)
    // Time Complexity --> O(N)  [Single Traversal]
    // Space Complexity --> O(2)  [No extra space required]
    
    /*
    int cand1 = -1, cand2 = -1;
    int votes1 = 0, votes2 = 0;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        
        if(arr[i] == cand1){
            
            votes1++;
        }
        else if(arr[i] == cand2){
            
            votes2++;
        }
        else if(cand1 != arr[i] && votes1 == 0){
            
            votes1 = 1;
            cand1 = arr[i];
        }
        else if(cand2 != arr[i] && votes2 == 0){
            
            votes2 = 1;
            cand2 = arr[i];
        }
        else{
            
            votes1--;
            votes2--;
        }
    }
    ans.push_back(cand1);
    ans.push_back(cand2);
    */
    
    // Printing Array
    cout << "Maximum frequency variables: ";
    printArray(ans);
    
    return 0;
}