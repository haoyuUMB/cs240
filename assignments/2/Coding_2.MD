# Coding 2

## Problem

You are given two string S and F consisting of lower case English letters.
You are allowed to perform several operations on the string S.
In each operation, you can change one letter of the string
to the one following it or preceding it in the alphabetical order.
For example: for the letter c, you are allowed to
change it to either b or d in an operation.
The letters can be considered in a cyclic order, i.e., the preceding letter
for letter a would be letter z.
Similarly, the following letter for letter z would be letter a.

Your aim is to find the minimum number of operations that are required such that each letter in string S after applying
the operations, is present in string F.

## Function

```C
int solution(char *S, char *F){
    
    
}
```

### Arguments

Two strings S and F and the letters in string F are lexicographically sorted.

### Output

An integer

## Sample

| Case Index | Arguments  | Output |
|------------|------------|--------|
| 1          | "abcd" "a" | 6      |
| 2          | "pppp" "p" | 0      |

In Sample Case #1, all the letters in string S should be converted to letter a. We can keep on changing the letters to
its preceding letter till we reach the letter a. We do not need to change the first letter as it is already a. The
second letter needs 1 operation to change it to a. The third letter needs 2 operations to change it to a. The fourth
letter needs 3 operation to change it to a. Hence, we need a total of 6 operations to change string S such that all
letters are changed to a.

In Sample Case #2, string S already contains only the favorite letter from string F. Hence, we do not require any more
operations.

## Additional Sample

| Case Index | Arguments                 | Output |
|------------|---------------------------|--------|
| 1          | "pqrst" "ou"              | 9      |
| 2          | "abf" "abf"               | 0      |
| 3          | "aaaaaaaaaaaaaaab" "aceg" | 1      |

n Sample Case #1, all the letters in string S should be converted to either the letter o or the letter u. For the first
and second letters it is optimal to change them to preceding letters till they are changed to letter o. The first letter
would take 1 operation to change to letter o. The second letter would take 2 operations to change to letter o. For
fourth and fifth letters it is optimal to change them to following letters till they are changed to letter u. The fourth
letter would take 2 operations to change to letter u. The fifth letter would take 1 operation to change to letter u. We
can change the third letter to either o or u as both of them would require 3 operations. Hence, we need a total of 9
operations to change string S such that all letters are changed to either o or u.

In Sample Case #2, string S already contains only the favorite letters from string F. Hence, we do not require any more
operations.

In Sample Case #3, we only need to change the last letter b to either a or c. Thus, we only need 1 operation.






