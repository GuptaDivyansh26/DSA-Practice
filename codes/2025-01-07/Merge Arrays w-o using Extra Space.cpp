// Merge Arrays w/o using extra space

// Optimised Approach- 2 pointers (1 from back of arr1, 2nd from start of arr2)

void mergeArrays(vector<int>& a, vector<int>& b) {
        
    int idx = a.size() - 1, jdx = 0;
    
    while(idx >= 0 && jdx < b.size())
    {
        if(a[idx] > b[jdx])
        {
            swap(a[idx], b[jdx]);
            idx -- ;
            jdx ++ ;
        }
        else
        {
            break;
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}