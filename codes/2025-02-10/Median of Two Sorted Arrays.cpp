// Median of two sorted arrays

// TC- O(n1 + n2) --> n1 = nums1.size(), n2 = nums2.size()
// SC- O(n1 + n2) --> n1 = nums1.size(), n2 = nums2.size()

//We create a sorted temp array and then find median

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> temp;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] <= nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size())
        {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size())
        {
            temp.push_back(nums2[j]);
            j++;
        }
        for(auto it : temp)
        {
            cout << it << ' ';
        }

        int idx = nums1.size() + nums2.size();
        if(idx % 2 == 1)    return (double)temp[idx / 2];
        else    return (double)(temp[idx / 2] + temp[idx / 2 - 1]) / 2;
    }
};

// or

// TC- O(log(min(n1, n2))) --> n1 = nums1.size(), n2 = nums2.size()
// SC- O(1) [No extra space needed]

//We first take a line of symmetry for the median and find out no of elements to left of it. Then we take our range from 0 to min(n1, n2) to pick that no. of elements from array with less elements and rest from other. we take 4 variables: l1, l2, r1, r2. To satisfy our condition, l1 <= r2 and l2 <= r1 always. If satisfied, we return median depending on no. of toal elements as even or odd. Else, we reduce the search space.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while(low <= high)
        {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1)   r1 = nums1[mid1];
            if(mid2 < n2)   r2 = nums2[mid2];

            if(mid1 - 1 >= 0)   l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0)   l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1)
            {
                if(n % 2 == 1)  return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if(l1 > r2)    high = mid1 - 1;
            else    low = mid1 + 1;
        } 

        return 0;
    }
};