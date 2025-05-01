// Union of Two Sorted Arrays Problem

#include <bits/stdc++.h>
using namespace std;


// Creating Array
vector<int> createArray(){
    
    cout << "Enter no. of array elements: ";
    int n;
    cin >> n;
    
    vector<int> v;
    cout << "Enter elements (in sorted manner): ";
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
    vector<int> arr1 = createArray();
    vector<int> arr2 = createArray();
    
    
    // Brute Force- Using map / set
    // Time Complexity --> O((M log(k) + N log(k))  [All distinct elements, k--> no. of elements present in set]
    // Space Complexity --> O(M + N) + O(M + N)  [All distinct elements]
    
    /*
    set<int> st;
    
    for(auto it : arr1){
        
        st.insert(it);
    }
    for(auto it : arr2){
        
        st.insert(it);
    }
    
    vector<int> ans(st.begin(), st.end());
    */
    
    
    
    // Optimised - Using 2 pointers
    // Time Complexity --> O(M + N)  [Traversing both arrays]
    // Space Complexity --> O(M + N)  [Resultant Array]
    
    /*
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        
        if(arr1[i] <= arr2[j]){
            
          if (ans.size() == 0 || ans.back() != arr1[i])     ans.push_back(arr1[i]);
          i++;
        }
        else{
            
          if (ans.size() == 0 || ans.back() != arr2[j])     ans.push_back(arr2[j]);
          j++;
        }
    }
      
    while (i < arr1.size()){
        
        if (ans.back() != arr1[i])    ans.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()){
      
        if (ans.back() != arr2[j])    ans.push_back(arr2[j]);
        j++;
    }
    */
    
    // Printing Array
    cout << "Values in their Union: ";
    printArray(ans);
    
    return 0;
}