# Coding 2- Good Subarrays

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

## Problem

Let us define F(B,L,R) as the sum of a subarray of an array B bounded by
indices L and R (both inclusive). Formally, $F(B, L, R) = B_L + B_{L+1} + \cdots + B_R$.

An array C of length K is called a good array if all the prefix sums of C are non-negative.
Formally, the terms $F(C, 1, 1), F(C, 1, 2), \dots, F(C, 1, K)$ are all non-negative.

Given an array A of N integers, find the result of adding the sums of all the good subarrays in the array A.

## Input

The first line of the input gives the number of test cases T. T test cases follow.

Each test case begins with one line consisting an integer N denoting the number
of integers in the input array A. Then the next line contains N integers
$\mathbf{A_1}, \mathbf{A_2}, \dots, \mathbf{A_N}$ representing the integers in given
input array A.

## Output

For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1) and y is the result of adding the sums of all good
subarrays in the given input array A.

## Limits for each test set

Time limit: 60 seconds on the Gradescope for each test set.

1 ≤ T ≤ 100.

$-800 \le \mathbf{A_i} \le 800$, for all i.

### Test Set 1

1 ≤ N ≤ 200.

### Test Set 2

1 ≤ N ≤ 4 * 10<sup>5</sup> for at most 30 test cases.

For the remaining cases, 1 ≤ N ≤ 200

## Sample

```c
Sample input:
2
5
1 -2 3 -2 4
3
1 0 3

Sample output:
Case #1: 14
Case #2: 12

```

In Sample Case #1, the good subarrays are [1],[3],[3,−2],[3,−2,4], and [4]
with their respective sums 1,3,1,5, and 4. After adding the sums obtained,
the result is 14.

In Sample Case #2, the good subarrays are [1],[1,0],[1,0,3],[0],[0,3],
and [3] with their respective sums 1,1,4,0,3, and 3.
After adding the sums obtained, the result is 12.

#### Analysis

For simplicity, let us denote subarray of array A starting from index i and ending at index
$j, (j >= i)$ as $A(i, j)$.

### Test Set 1

A(i,j) is a good subarray iff all of its prefix sums are non-negative, i.e.

$$
\begin{align*}
\mathbf{A_{i}} &\ge 0 \\
\mathbf{A_{i}} + \mathbf{A_{i + 1}} &\ge 0 \\
\mathbf{A_{i}} + \mathbf{A_{i + 1}} + \mathbf{A_{i + 2}} &\ge 0 \\
&\vdots\\
\mathbf{A_{i}} + \mathbf{A_{i + 1}} + \mathbf{A_{i + 2}} + \cdots + \mathbf{A_{j}} &\ge 0
\end{align*}
$$

We can observe that:

- Observation 1: If A(i, j) is a good subarray then all its prefix arrays A(i,k), such that i≤k≤j are also good subarray.
- Observation 2: If A(i,j) is not a good subarray then all subarrays A(i,k), such that k≥j are also not good subarray.

We can iterate over all subarrays with a left index i. For a fixed left index i, we can iterate over the right index
j such that the subarray sum is non-negative. As soon as we find an index j such that subarray sum of A(i,j) is
less than 0, we can stop and increase the left index.

The overall time complexity of the above solution would be O(N^2), which is fast enough for test set 1.

### Test Set 2

Let us denote subarray sum of A(i,j) as S(i,j) and prefix sum of array A till i-th index as P(i),

$$
\begin{align*}
S(i, j) &= \mathbf{A_{i}} + \mathbf{A_{i + 1}} + \mathbf{A_{i + 2}} + \cdots +\mathbf{A_{j}} \\
P(i) &= \mathbf{A_{1}} + \mathbf{A_{2}} + \mathbf{A_{3}} + \cdots + \mathbf{A_{i}}
\end{align*}
$$

The prefix sum array P of array A can be computed in O(N) by iterating over the array from left to right:

$$
\begin{align*}
P(i) =
\begin{cases}
0 & i = 0\\
P(i -1) + \mathbf{A_i} & i > 0
\end{cases}
\end{align*}
$$

By the definition of a prefix array, we can easily note that S(i,j)=P(j)-P(i-1)

For every index i, let us compute nsv(i)(nearest smaller value), the smallest index j such that j≥i and
subarray sum of A(i,j) is less than 0. If there is no such index we can simply set nsv(i)=N+1. Finding
smallest index j on right of i, such that the subarray sum A(i,j) is less than 0

$$
\begin{align*}
\mathbf{A_{i}} + \mathbf{A_{i + 1}} + \mathbf{A_{i + 2}} + \cdots + \mathbf{A_{j}} &\lt 0 \\
S(i, j) &\lt 0 \\
P(j) - P(i - 1) &\lt 0 \\
P(j) &\lt P(i - 1) \\
\end{align*}
$$

is same as finding the smallest index j, j≥i and P(j)<P(i-1). This can be done using small modification
in[All nearest smaller values algorithm](https://en.wikipedia.org/wiki/All_nearest_smaller_values)in O(N).

All subarrays which starts at index l and end at index j,
such that l≤j<nsv(l) would have non-negative sum.
Sum of all such subarrays starting at index l and extending at max to index r,
r=nsv(l)−1 is same as the sum of below expressions:

$$
\begin{align*}
\mathbf{A_{l}} &= P(l) - P(l - 1) \\
\mathbf{A_{l}} + \mathbf{A_{l + 1}} &= P(l + 1) - P(l - 1) \\
\mathbf{A_{l}} + \mathbf{A_{l + 1}} + \mathbf{A_{l + 2}} &= P(l + 2) - P(l - 1) \\
&\vdots\\
\mathbf{A_{l}} + \mathbf{A_{l + 1}} + \mathbf{A_{l + 2}} + \cdots + \mathbf{A_{r}} &= P(r) - P(l -1)
\end{align*}
$$

On simplification, sum of all subarray A(i,j) such that i=l and i≤j≤r

$$
\begin{align*}
  sum(l) = (P(l) + P(l + 1) + P(l + 2) + \cdots + P(r)) - (r - l + 1) \times P(l - 1)
\end{align*}
$$

The first term P(l)+P(l+1)+P(l+2)+⋯+P(r) can be computed by pre-calculating the prefix sum array
of P.

Let us denote prefix sum of P as PP, i.e. PP(i)=P(1)+P(2)+⋯+P(i). The above sum can be
simplified as:

$$
\begin{align*}
sum(l) &= PP(r) - PP(l - 1) - (r - l + 1) \times P(l - 1) \\
ans &= \sum\limits_{l=1}^{N} sum(l) \\
ans &= \sum\limits_{l=1}^{N} PP(r) - PP(l - 1) - (r - l + 1) \times P(l - 1)
\end{align*}
$$

Nearest smaller value on right for each index in prefix array nsv(i) can be computed in O(N). Sum of all
subarrays with fixed left index and moving right index can be computed in O(1), if we have pre computed prefix sum
array of A i.e. P and prefix sum array of P i.e. PP. Precomputation of prefix sum arrays can be done in O(N).
The overall time complexity of the above solution would be O(N)
