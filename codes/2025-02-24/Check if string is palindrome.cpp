#include<iostream>
#include<string>
using namespace std;

bool palindrome(string s, int low, int high)
{
    if(low >= high)  return true;

    if(s[low] != s[high])   return false;
    return palindrome(s, low + 1, high - 1);
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    if(palindrome(s, 0, s.size() - 1))   cout << "\nGiven string is a palindrome";
    else    cout << "\nGiven string is not a palindrome";


    return 0;
}