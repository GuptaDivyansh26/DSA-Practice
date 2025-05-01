#include<iostream>
using namespace std;

// Without backtracking
/*
void func(int n, int i)
{
    if(i > n)    return;

    cout << i << ' ';
    func(n, i + 1);
}
int main(){
    int n;
    cin >> n;
    func(n, 1);
    return 0;
}
*/

// With backtracking
/*
void func(int n)
{
    if(n <= 0)  return;

    func(n - 1);
    cout << n << ' ';
}
int main(){
    int n;
    cin >> n;
    func(n);
    return 0;
}
*/