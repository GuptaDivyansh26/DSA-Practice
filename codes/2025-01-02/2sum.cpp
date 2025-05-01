// Two Sum Problem

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
    
    cout << "Enter target value: ";
    int target;
    cin >> target;
    
    // Brute Force- Use 2 loops
    // Time Complexity --> O(N^2)  [Traversing for every 'i']
    // Space Complexity --> O(1)  [No extra space used]
    
    
    // Better Force- Hashing
    // Time Complexity --> N * O(1)  [If no such elements]
    // Space Complexity --> N * O(1) + O(2)  [Map + Resultant Array]
    
    /*
    vector<int> ans;
    unordered_map<int, int> mpp;
    
    for(int i = 0; i < arr.size(); i++){
        
        int rem = target - arr[i];
        if(mpp.find(rem) != mpp.end()){
            
            ans.push_back(mpp[rem]);
            ans.push_back(i);
            break;
        }
        mpp[arr[i]] = i;
    }
    
    if(ans.empty()) ans.push_back(-1);
    */
    
    
    // Optimised - Using 2 pointers
    // Time Complexity --> O(N * log N) + O(N)  [Sorting + Traversing]
    // Space Complexity --> N * O(1) + O(2)  [Map + Resultant Array]
    
    /*
    unordered_map<int, int> mpp;
    for(int i = 0; i < arr.size(); i++){
        
        mpp[arr[i]] = i;
    }
    
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    
    while(i < j){
        
        if(arr[i] + arr[j] < target)    i++;
        else if(arr[i] + arr[j] > target)    j--;
        else{
            
            ans.push_back(mpp[arr[i]]);
            ans.push_back(mpp[arr[j]]);
            break;
        }
    }
    
    if(ans.empty()) ans.push_back(-1);
    */
    
    // Printing Array
    cout << "Values present at index: ";
    printArray(ans);
    
    return 0;
}