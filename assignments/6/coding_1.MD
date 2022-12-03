# Coding 1 - Subsequence

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

Irina is given a string I that she is supposed to type out.

While Irina is typing, she may make some mistakes, such as pressing the wrong key. As her typing speed is important to
her, she does not want to spend additional time correcting the mistakes, so she continues to type with the errors until
she finishes the speed test. After she finishes the speed test, she produces a P.

Now she wonders how many extra letters she needs to delete in order to get I from P. It is possible that Irina made
a mistake and P cannot be converted back to I just by deleting some letters. In particular, it is possible that
Irina missed some letters.

Help Irina find out how many extra letters she needs to remove in order to obtain I or if I cannot be obtained from
P by removing letters then output`IMPOSSIBLE`.

### Input

The first line of the input gives the number of test cases, T. T test cases follow.

Each test case has 2 lines. The first line of each test case is an input string I(that denotes the string that the
typing test has provided). The next line is the produced string P(that Irina has entered).

### Output

For each test case, output one line containing`Case #x: y`, where x is the test case number (starting from 1) and y
is the number of extra letters that need to be removed in order to obtain I. If it is not possible to obtain I then
output`IMPOSSIBLE`as y.

### Limits

Memory limit: 1 GB.\
1≤T≤100.\
Both the strings contain letters from`a`-`z`and`A`-`Z`.\
Length of the given strings will be 1≤|I|,|P|≤10^5.

#### Test Set 1

Time limit: 60 seconds.\
All letters in I are the same.

#### Test Set 2

Time limit: 60 seconds.

### Sample

```c
Sample input:
2
aaaa
aaaaa
bbbbb
bbbbc

Sample output:
Case #1: 1
Case #2: IMPOSSIBLE

```

In the first test case, P contains one extra a, so she needs to remove 1 extra letter in order to obtain I.
In the second test case, Irina typed only 4 letters b, while I consists of 5 letters b so the answer is IMPOSSIBLE.

```c
Sample input:
2
Ilovecoding
IIllovecoding
KickstartIsFun
kkickstartiisfun


Sample output:
Case #1: 2
Case #2: IMPOSSIBLE

```

In the first test case, P has 2 extra letters, I and l. The other letters are in the order given in I. So she needs to
remove 2 letters in order to obtain I.
In the second test case, there is no letter K in P so the answer is IMPOSSIBLE.
