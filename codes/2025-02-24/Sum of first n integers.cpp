#include<iostream>
using namespace std;

int sum(int n)
{
    if(n <= 0)  return 0;

    return n + sum(n - 1);
}

int main()
{
    int n;

    cout << "Enter num: ";
    cin >> n;

    cout << "Sum from 1 to num: " << sum(n);

    return 0;
}