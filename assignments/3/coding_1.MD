# Coding 1

## Problem

A string *C* of length *L* consisting of uppercase English characters is strictly increasing if, for every pair of
indices
*i* and *j* such that *1 ≤ i < j ≤ L* (1-based), the
character at position *i* is smaller than the character at position *j*.

For example, the strings ABC and ADF are strictly increasing, however the strings ACC and FDA are not.

Question: given a string S of length N, you have to find out, for every position 1≤i≤N, what is the length of the
longest strictly increasing substring that ends at position i.

A substring is a contiguous sequence of characters within a string.

## Function

```C
/* Attention:
 *  For test2 dataset, you can't pass by a quadratic running time solution
 *  
 * Hint1:
 * The longest strictly increasing substring wouldn't exceed 26
 * Hint2:
 * You can recount start from every not strictly increasing position
 * 
 * 
 * */

int *solution(int L, char *S, int *res) {
/*Complete this function*/

return res;
}
```

### Arguments

Given a function solution which receives arguments as [L], [S], [res] the
length of the string [S], the string [S] and the data [res]
to store the results

**Attention: the output arguments on the Gradescope:**

1. s1: [length of the string S]
2. s2: [S]

****

### Results

Return the [res] which contains the length of the longest
strictly increasing substring that ends at position i, from
the first to the last position.

## Sample

| Case Index | Arguments  | Output      |
|------------|------------|-------------|
| 1          | 4 "ABBC"   | 1 2 1 2     |
| 2          | 6 "ABACDA" | 1 2 1 2 3 1 |

In Sample Case #1, the longest strictly increasing substring ending at position 1 is A. The longest strictly increasing
substrings ending at positions 2, 3 and 4 are AB, B and BC, respectively.

In Sample Case #2, the longest strictly increasing substrings for each position are A, AB, A, AC, ACD and A.

