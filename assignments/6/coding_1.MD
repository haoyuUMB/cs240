# Coding 1 - Peaks

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

Given an array A of length N, for each item A_i is a *peak* if:

- It is not the 1st item or the N-th item, and
- The value of the item is *strictly greater than* the item immediately before it and the item
  immediately after it.

Please find out the number of peaks.

### Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line
containing the integer N. The second line contains N integers. The i-th integer is A_i.

### Output

For each test case, output one line containing`Case #x: y`, where`x`is the test case number (starting from 1) and`y`is
the number of peaks.

### Limits

Time limit: 60 seconds.\
1 ≤ T ≤ 100.\
1 ≤ A_i ≤ 100.

#### Test Set 1

3 ≤ N ≤ 5.

#### Test Set 2

3 ≤ N ≤ 100.

### Sample

```c
Sample input:
4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10


Sample output:
Case #1: 1
Case #2: 0
Case #3: 2
Case #4: 0


```

- In sample case #1, the 2nd item is a peak.
- In sample case #2, there are no peaks.
- In sample case #3, the 2nd and 4th item are peaks.
- In sample case #4, there are no peaks.

