class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;
        int maxxl = height[0];
        int maxxr = *max_element(height.begin() + 1, height.end());
    
        for(int idx = 1; idx < height.size() - 1; idx++)
        {
            maxxl = max(maxxl, height[idx - 1]);
            
            if(height[idx] == maxxr)    maxxr = *max_element(height.begin() + idx + 1, height.end());
            
            res = res + min(maxxl, maxxr) - min(min(maxxl, maxxr), height[idx]);
        }
        
        return res;

    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;
    
        for(int idx = 1; idx < height.size() - 1; idx++)
        {
            int maxxl = *max_element(height.begin(), height.begin() + idx);
            int maxxr = *max_element(height.begin() + idx + 1, height.end());
            
            res = res + min(maxxl, maxxr) - min(min(maxxl, maxxr), height[idx]);
        }
        
        return res;

    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;
        int maxx = *max_element(height.begin(), height.end());
        int index = find(height.begin(), height.end(), maxx) - height.begin();

        for(int idx = 0; idx < index; idx++)
        {   
            if(height[idx])
            {
                for(int jdx = idx+1; jdx < height.size(); jdx++)
                {
                    if(height[jdx] >= height[idx])
                    {
                        res += min(height[idx], height[jdx])*(jdx-idx);

                        for(int kdx = idx+1; kdx < jdx; kdx++){

                            res -= height[kdx];
                        }

                        idx = jdx - 1;
                    }
                }
            }
        }


        for(int idx = height.size() - 1; idx > index; idx--)
        {   
            if(height[idx])
            {
                for(int jdx = idx-1; jdx >= 0; jdx--)
                {
                    if(height[jdx] >= height[idx])
                    {
                        res += min(height[idx], height[jdx])*(idx - jdx);

                        for(int kdx = idx-1; kdx > jdx; kdx--){

                            res -= height[kdx];
                        }

                        idx = jdx + 1;
                    }
                }
            }
        }

        return res;
    }
};