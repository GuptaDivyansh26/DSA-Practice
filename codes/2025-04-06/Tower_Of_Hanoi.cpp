// Tower of Hanoi

// To move 'N' rings from tower A to tower C, consider moving 
// 1. n - 1 rings from tower A to tower B (helper)
// 2. n th ring from tower A to tower C
// 3. n-1 rings from tower B to tower C
// Base case -> 1 ring can be moved in 1 step directly from tower A to tower C

// TC - O(2 ^ N) [For N rings, operation of moving N - 1 rings is being done twice, once from A to B and then from B to C.]
// SC - O(N) [Recusrsion stack space, worst case possibility is N]

class Solution {
  public:

    int towerOfHanoi(int n, int from, int to, int aux)
    {
        int towerOfHanoi(int n, int from, int to, int aux)
        {
            if(n == 0)  return 0;
            if(n == 1)  return 1;
            
            int a = towerOfHanoi(n - 1, 1, 2, 3);
            int b = towerOfHanoi(1, 1, 3, 2);
            int c = towerOfHanoi(n - 1, 2, 3, 1);
            
            return a + b + c;
            
            // or return 2 * towerOfHanoi(n - 1) - 1;
        }
    }
}

// or we could observe the formula 2^N - 1

class Solution {
  public:

    int towerOfHanoi(int n, int from, int to, int aux)
    {
        return pow(2, n) - 1;
        
        // or return (1 << n) - 1;
    }
}