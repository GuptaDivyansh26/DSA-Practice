#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int ans = 0, sum = 0;
    long long x;
    
    cin >> n;
    cin >> x;
    
    vector<long long> v;
    
    for(int idx = 0; idx < n; idx++)
    {
        cin >> v[i];
    }
    
    int i = 0, j = 0;
    while(j < n)
    {
        sum += v[j];
        j++;
        while(sum > x)
        {
            sum = sum - v[i];
            i++;
        }
        if(sum == x)    ans++;
    }
    
    cout << ans;

    return 0;
}