// Second Largest Problem

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
    
    
    // Brute Force- Sort and Searching in Reversed Order
    // Time Complexity --> O(N log N) + O(N) 
    // Space Complexity --> O(1)
    
    /*
    sort(arr.begin(), arr.end());
    int secondLargest;
	for(int k = arr.size()-2; k >= 0; k--){

		if (arr[k] != arr[arr.size()-1]) {
	        secondLargest = arr[k];
	        break;
		}
	}
	*/
	
	
    // Better- Double Traversal
    // Time Complexity --> 2 * O(N)  
    // Space Complexity --> O(1)
    
    /*
    int Largest = INT_MIN;
    int secondLargest = INT_MIN;
	for(int k = 0; k < arr.size(); k++){

		if (arr[k] > Largest) {
	        Largest = arr[k];
		}
	}
	for(int k = 0; k < arr.size(); k++){

		if (arr[k] > secondLargest && arr[k] != Largest) {
	        secondLargest = arr[k];
		}
	}
	*/
	
	
    // Optimised- Single Traversal
    // Time Complexity --> O(N)  
    // Space Complexity --> O(1)
    
    /*
    int Largest = INT_MIN;
    int secondLargest = INT_MIN;
	for(int k = 0; k < arr.size(); k++){

		if (arr[k] > Largest) {
	        secondLargest = Largest;
	        Largest = arr[k];
		}
		else if (arr[k] > secondLargest && arr[k] != Largest) {
	        secondLargest = arr[k];
		}
	}
	*/
    
    
    // Printing Array
    cout << "Second Largest Element: " << secondLargest;
    // printArray(res);
    
    return 0;
}