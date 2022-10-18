# Coding 2

## Problem

There is one particularly long street with N houses on it. This street has length N, and the N houses are evenly placed
along it, that is, the first house is at position 1, the second house is at position 2, and so on. The distance between
any pair of houses i and j is |i−j|, where |x| denotes the absolute value of x.

Some of these houses have trash bins in front of them. That means that the owners of such houses do not have to walk
when they want to take their trash out. However, for the owners of houses that do not have trash bins in front of them,
they have to walk towards some house that has a trash bin in front of it, either to the left or to the right of their
own house.

To save time, every house owner always takes their trash out to the trash bin that is closest to their houses. If there
are two trash bins that are both the closest to a house, then the house owner can walk to any of them.

Given the number of houses N, and the description of which of these houses have trash bins in front of them, find out
what is the sum of the distances that each house owner has to walk to take their trashes out. You can assume that at
least one house has a trash bin in front of it.

## Function

```C
/* Attention:
 * We are using the long data type for result,
 * as the result could be very large to exceed
 * the limit of int for some test case
 * */
long solution(int l, char *S) {
/*Complete this function*/
}
```

### Arguments

The length of the string [S] and the string [S].

The string representing which houses have trash bins in front of them. If the i-th character in string S is equal to '
1',
then it means that the i-th house has a trash bin in front of it.
Otherwise, if it is equal to '0', then it means that the i-th house does not have a trash bin in front of it.

### Return

An integer

## Sample

| Case Index | Arguments  | Output |
|------------|------------|--------|
| 1          | 3 "111"    | 0      |
| 2          | 6 "100100" | 5      |

For the first test case, every house has a trash bin in front of it, and therefore none of the house owners will have to
walk to take their trashes out.

For the second test case, the first and the fourth house owners have trash bins in front of their houses, and therefore
will not have to walk. The second house owner will walk towards the first house, and the distance will be equal to 1.
The third, fifth, and sixth house owners will walk towards the fourth house, and the distances will be equal to 1, 1,
and 2, respectively.




