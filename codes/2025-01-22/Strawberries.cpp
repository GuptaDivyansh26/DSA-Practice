// Strawberries

// My Approach- W/O using sliding window..counting conesecutive no.s of 'O'. if equal to k, ans++;
// TC- O(n) [as high from 0 to n]
// SC- O(1) [constant space]

#include <iostream>
using namespace std;

int main()
{
    int n , k, cnt = 0, ans=0;
    string S;
    
    cin >> n >> k;
    cin >> S;
    
    for(auto it: S)
    {
        if(it == 'O'){
            cnt++;
            if(cnt == k){
                ans++;
                cnt = 0;
            }
        }
        else cnt = 0;
    }
    
    cout << ans;

    return 0;
}


// Using sliding window
// TC- O(n) [as high from 0 to n]
// SC- O(1) [constant space]

#include <iostream>
using namespace std;

int main()
{
    int n , k, ans=0;
    string S;
    
    cin >> n >> k;
    cin >> S;
    
    int low = 0, high = 0, cntO = 0, sz = 1;
    
    if(S[0] == 'O') cntO++;
    
    while(high < n)
    {
        if(sz < k)
        {
            high ++;
            sz ++ ;
            if(high == n)   break;
            
            if(S[high] == 'O')  cntO++ ;
        }
        else
        {
            if(sz == cntO)
            {
                ans++;
                
                low = high + 1;
                high = high + 1;
                sz = 1;
                
                if(low == n) break;
                
                if(S[high] == 'O')  cntO = 1;
                else cntO = 0;
            }
            else
            {
                low++;
                high++;
                if(high == n)   break;
                
                if(S[low - 1] == 'O')   cntO--;
                if(S[high] == 'O')  cntO++;
            }
        }
    }
    
    cout << ans;

    return 0;
}