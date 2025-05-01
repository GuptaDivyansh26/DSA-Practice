// Sum of Two Arrays Problem

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
    vector<int> a = createArray();
    vector<int> b = createArray();
    
    
    // Brute Force- Pushing posiitve elements to Temp1 Array, Negative to Temp2, Array = Temp1 + Temp2
    // Time Complexity --> O(N)  
    // Space Complexity --> O(N)

    int n = a.size(), m = a.size();
    vector<int> res;
	int minn = min(n, m), carry = 0, maxx= max(n, m);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int k = 0; k < minn; k++){

		res.push_back((carry + a[k] + b[k]) % 10);
		carry = (carry + a[k] + b[k]) / 10;
	}
	if (minn == maxx && carry != 0) {
		res.push_back(carry);
	}
    if(minn == m && minn != maxx){

		for(int k = minn; k < maxx; k++){

			res.push_back((carry + a[k]) % 10);
			carry = (carry + a[k]) / 10;
		}
	}
	if(minn == n && minn != maxx){

		for(int k = minn; k < maxx; k++){

			res.push_back((carry + b[k]) % 10);
			carry = (carry + b[k]) / 10;
		}
	}
	reverse(res.begin(), res.end());
    
    
    // Printing Array
    cout << "Summed Array: ";
    printArray(res);
    
    return 0;
}