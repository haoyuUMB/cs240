# Coding 2- Stopwatch Subarrays

1. All test cases are given and there are no code templates
2. There are solution analysis in the end.
3. There are run time limits
4. Every test set runs 100 cases, avoid allocating
   and freeing memory frequently, since it may cause
   memory allocation issue, especially test set2. Try to use the same
   memory for each test case.
5. You should make sure your code runs on the
   largest case, since if that runs correctly,
   the other cases would be fine in terms of memory issue.

### Problem

Given an array of N positive integers. The i-th integer of the array is A_i.

A contiguous subarray is an *m-stopwatch* if it is of length m and contains the integers m, m-1, m-2, ..., 2, 1 in that
order. For example,`[3, 2, 1]`is a 3-stopwatch.

Can you count the number of K-stopwatchs in the array?

### Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line
containing the integers N and K. The second line contains N integers. The i-th integer is A_i.

### Output

For each test case, output one line containing`Case #x: y`, where`x`is the test case number (starting from 1) and`y`is
the number of K-stopwatchs in the array.

### Limits

Time limit: 60 seconds.\
1 ≤ T ≤ 100.\
2 ≤ K ≤ N.\
1 ≤ A_i ≤ 2 × 10^5, for all i.

#### Test Set 1

2 ≤ N ≤ 1000.

#### Test Set 2

2 ≤ N ≤ 2 × 10^5 for at most 10 test cases.\
For the remaining cases, 2 ≤ N ≤ 1000.

## Sample

```c
Sample input:
3
12 3
1 2 3 7 9 3 2 1 8 3 2 1
4 2
101 100 99 98
9 6
100 7 6 5 4 3 2 1 100


Sample output:
Case #1: 2
Case #2: 0
Case #3: 1


```

In sample case #1, there are two 3-stopwatchs as highlighted below.

- 1 2 3 7 9 `3 2 1` 8 3 2 1
- 1 2 3 7 9 3 2 1 8  `3 2 1`

In sample case #2, there are no 2-stopwatchs.

In sample case #3, there is one 6-stopwatch as highlighted below.

- 100 7 `6 5 4 3 2 1` 100

## Analysis

### Test Set 1

For each element A_i, we can check whether it is a start of a K-stopwatch.
In other words, we check whether A_i + j = K - j for all 0 ≤ j ≤ K. If the element A_i
satisfies the condition, we can increment our answer counter by 1. This
solution runs in O(N × K).

### Test Set 2

To solve this test set, we can loop through the elements and keep track of the number of consecutive elements such that
the next element is one less than the previous element. We can do this by keeping a counter. If the current element is
one less than the previous element, we increment this counter by 1. Otherwise, we reset the counter to 0. If the current
element is 1 and our counter is at least K - 1, we know that the current element is the end of a K-stopwatch. We can
increment our answer counter by 1 in this case.

This approach works since any pair of K-stopwatch subarrays does not overlap. This solution runs in O(N).