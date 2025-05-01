// Pow(x, n)- Running this loop for n times can cause TLE for some cases. Hence, if n is divisible by 2, we pass x*x and n%2
// as parameters; otherwise, we take one n out to to make n even. This reduces time complexity by half.

// TC- O(n/2) [Recursion is called n/2 times as we keep dividing n by 2 at every step and no multiple recursions are called]
// SC- O(1) [No extra space used (excep recursion stack)]

class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 0)  return 0;
        if(n == 0)  return 1;

        long long num = n;
        double res;
        if(n % 2 == 0)  res =  myPow(x * x, abs(num) / 2);
        else    res = x * myPow(x * x, (abs(num) - 1) / 2);

        return n < 0 ? 1.0 / res : res;
    }
};