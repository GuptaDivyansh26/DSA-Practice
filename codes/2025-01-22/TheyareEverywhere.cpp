// They are Everywhere

// Using sliding window- Moving from left to right, we'll check if no. of unique elements in window = no. of total unique elements [therefore, set].
// Once, we got that, we'll note size of window and reduce window by increasing low until low <= high.  Repeating this until full string covered.
// Using map to note last occuring position of a character helping reduce window size

// TC- O(n) [as high from 0 to n, then low from 0 to n]
// SC- O(n) [n -> no. of unique elements in set]

#include <iostream>
#include <set>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
 
    string S;
    cin >> S;
 
    set<char> st;
 
    for(auto i : S)
    {
        st.insert(i);
    }
 
    int cnt = st.size();
 
    unordered_map<char, int> mpp;
 
    int lo = 0;
    int hi = 0;
    int ans = INT_MAX;
    int distinctCount = 1;
    mpp[S[0]] = 0;
 
    while(hi < n)
    {
        if(distinctCount < cnt)
        {
            hi++;
 
            if(hi == n) break;
 
            char ch = S[hi];
 
            if(mpp.count(ch)) // have seen before somewhere
            {
                if(mpp[ch] >= lo) // it already exists in the window
                {
                    // we do nothing
                }
                else // it doesn't exist in the window
                {
                    distinctCount++;
                }
                mpp[ch] = hi;
            }
            else // haven't seen before at all
            {
                mpp[ch] = hi;
                distinctCount++;
            }
        }
        else // distinctCount == cnt
        {
            ans = min(ans, hi - lo + 1);
 
            char ch = S[lo];
 
            lo++;
 
            if(mpp[ch] >= lo) // that means it still exists somewhere in the window
            {
                // we do nothing
            }
            else // we just removed a distinct character from the window
            {
                distinctCount--;
            }
        }
    }
 
    cout << ans;

    return 0;
}