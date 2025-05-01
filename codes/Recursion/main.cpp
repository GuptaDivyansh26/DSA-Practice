// Recursion

// Recursive funtion

// 1 - 5 MB memory of stack

// Types of recursion-
// 1. Linear
// 2. Multiple
// 3. Tail --> upar code, neeche resursive func. call
// 4. Head --> neeche code, upar recursive func. call

// Stack frame --> No of function calls in Stack

// n hello times
// 1 --> n
// n --> 1  1. both parameters, 2. single parameter

#include<bits/stdc++.h>
using namespace std;

void func(int n, int i)
{
    if(i >= n) return;
    
    cout << n - i<< '\n';
        
    func(n , ++i);
}

int main()
{
    int n;
    
    cin >> n;
    
    func(n, 1);
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void func(int n)
{
    if(n <= 0) return;
    
    cout << n << '\n';
        
    func(n - 1);
}

int main()
{
    int n;
    
    cin >> n;
    
    func(n);
    
    return 0;
}

// Compliler optimises tail recursive code and it runs like normal iteration.   -LearnCPP

// Syntactic Sugar

// off by one error

// directly passing by reference using const keyword is allowed in c++

func(vector arr, int idx, v<v<int>> out, vector curr)
// base condition
// multiple recursion
// select, deselect

10-03-25
// In ques. "all subsets", we can take temp parameter as default as "{}" but only w/o reference.
/*
Since default arguments in C++ are evaluated once, if we define temp as a reference (e.g., vector<int>& temp = {}), it results in an invalid initialization error.
The compiler doesn't allow a non-const reference to be initialized with a temporary object ({}), as it needs an lvalue, but {} is an rvalue.

1. Default Arguments in C++ Are Evaluated Once
    In C++, default arguments are evaluated at the time of function declaration and not at each function call.
    This means that when a function is called without an explicit argument for a parameter that has a default value, the default value is not re-created each time. Instead, the compiler uses the same default value that was set at function definition.
2. Reference Variables Require an Lvalue
    A non-const reference (&) must always refer to a valid lvalue (a named object in memory).
    {} (an empty initializer list) is an rvalue (a temporary object) and does not exist beyond the statement in which it is used.
3. Why Does vector<int>& temp = {} Fail?
    Consider this function definition:
        void generateSubsets(std::vector<int>& arr, int index, std::vector<int>& temp = {}) {
            // Function body
        }
    Here, temp is declared as a reference to a vector<int>.
    The default value {} is an rvalue, meaning it is a temporary object.
    A non-const reference cannot bind to an rvalue because rvalues do not persist beyond the current expression.
    Since {} does not have a valid memory location after initialization, the compiler throws an invalid initialization error.
*/

(&& pe chal jayega)
/*
In C++, using an rvalue reference (&&) instead of a lvalue reference (&) allows the function parameter to bind to temporary (rvalue) objects, like {}. When a function parameter is declared as an rvalue reference (&&), it can bind to temporary (rvalue) objects, unlike a normal reference (&), which requires a persistent (lvalue) object.
*/

(r-value and l-value)
/*
    In C++, every expression or object falls into one of two categories:
    ✅ Lvalue (Left-hand value) → Something that has a memory address (can be assigned to).
    ✅ Rvalue (Right-hand value) → A temporary value that does not persist beyond the expression.

    Feature	                                    Lvalue	                        Rvalue
Has a memory address	                        ✅ Yes	                        ❌ No (temporary)
Can appear on the left-hand side of =	        ✅ Yes	                        ❌ No
Can bind to an & (Lvalue Reference)	            ✅ Yes	                        ❌ No
Can bind to an && (Rvalue Reference)	        ❌ No	                        ✅ Yes
Example	                                        int x = 5;	                      int y = x + 2;
*/