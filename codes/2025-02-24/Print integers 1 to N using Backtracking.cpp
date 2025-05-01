#include<iostream>
using namespace std;

void func(int n)
{
    if(n <= 0)  return;

    func(n-1);

    cout << n << '\n';
}

int main()
{
    int n;

    cout << "Enter num: ";
    cin >> n;

    cout << "Numbers from 1 to num: \n";
    func(n);

    return 0;
}