// Subset Sum - 1
Brute Force - Generating all the subsets (Power Set) (TC- 2^N * N)
Optimised - Pick/Non-Pick (Recursion) (TC- 2^n * 2^n log 2^n) (SC- 2^n)

// Subset Sum - 2
Brute Force - Pick/Non-Pick (Recursion) (TC- 2^n * 2^n log 2^n)
Optimised - Only Pick Cases (Sort original array, do not pick duplicate elements during recursion) (TC- 2^n * n * n log n) (SC- 2^n * k (avg. length))

// Print all permutation of a string/array - For codes, check next lexographic arrangement in arrays
Brute Force - Marked/Unmarked (Recursion) (TC- n! * n) (SC- n + n)
Optimised - Swapping elements of original array (Recursion) (TC- n! * n) (SC- 1) [Only auxilliary space for returning ans and recursion stack]