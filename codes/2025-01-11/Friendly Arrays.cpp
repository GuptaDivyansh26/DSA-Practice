// Friendly Array
// even ka max nikaalne ke liye b ke har element ka 'or' and then a se 'xor'

// if n is even, where n is no. of elements in 'a', then that bit for which all is '1' will be zero. minimising the value
// can't maxmize in even

// if n is odd, we can maximize but cannot minimize

// TC - O(N + M + N + N) = O(max(M, N)) --> N = a.size(), M = b.size()
// SC- O(1)


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int idx = 0; idx < t; idx++)
    {
        int n, m;
        cin >> n >> m;
        
        vector<int> a;
        vector<int> b;
        
        for(int jdx = 0; jdx < n; jdx++)
        {
            int val;
            cin >> val;
            a.push_back(val);
        }
        
        for(int jdx = 0; jdx < m; jdx++)
        {
            int val;
            cin >> val;
            b.push_back(val);
        }
        
        int minn = 0, maxx = 0, xrr = 0;
        for(auto it : a)
        {
            xrr = it ^ xrr;
        }
        
        int bo = 0;
        for(auto it : b)
        {
            bo = bo | it ;
        }
        
        for(auto& it : a)
        {
            it = it | bo ;
        }
        
        int xr = 0;
        for(auto it : a)
        {
            xr = it ^ xr ;
        }
        
        if(a.size() % 2 == 0)
        {
            minn = xr ;
            maxx = xrr ;
        }
        else{
            minn = xrr ;
            maxx = xr ;
        }
        
        
        cout << minn << ' ' << maxx << "\n";
    
    }

    return 0;
}