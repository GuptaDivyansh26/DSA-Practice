#include <iostream>
using namespace std;

// Using iterative approach- Adding two digits, printing, updating till n - 2 times
// TC- O(n - 2) [as iteration runs from i= 2 to n]
// SC- O(1) [No extra space used]

/*
int main()
{
    int n;
    
    cout << "Enter no. of terms: ";
    cin >> n;
    
    if(n == 1)  cout << "0 ";
    else if(n == 2)  cout << "0 1 " ;
    else{
        cout << "0 1 " ;
        int a = 0;
        int b = 1;
        for(int i = 2; i < n; i++)
        {
            int c = a + b;
            
            cout << c << ' ';
            
            a = b, b = c;
        }
    }

    return 0;
}
*/

// Using recursive approach- Adding two digits, printing, passing updated variables in function calls till n - 2 times
// TC- O(n - 2) [as recursion is called from i = 2 to n times]
// SC- O(1) [No extra space used (if not considering the function call stack)]

/*
void fib(int n, int a, int b, int i)
{
    if(i == n) return;
    
    cout << a + b << ' ';
    
    fib(n, b, a + b, i + 1);
}

int main()
{
    int n;
    
    cout << "Enter no. of terms: ";
    cin >> n;
    
    if(n == 1)  cout << "0 ";
    else if(n == 2)  cout << "0 1 " ;
    else{
        cout << "0 1 " ;
        fib(n, 0, 1, 2);
    }

    return 0;
}
*/