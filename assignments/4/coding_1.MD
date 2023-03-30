# Coding 1 - Rewind or not

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

A game has N levels, and you are currently on the K-th level. Unfortunately, you just realized that to beat the boss
at the final level, you will need a special sword, which can be picked up at level S. You have already completed that
level, but you forgot to pick up the sword at that level.

Now you want to pick up the sword and finish the game in the least amount of time possible, and for that you have two
options:

1. Restart the game and complete all levels again, starting from level 1.
2. Move to previous levels until you reach level S, pick up the sword and complete all the remaining levels, starting
   from level S.

Every time you enter a level you have to exit it, either by completing it and going to the next level or by moving to a
previous level or by finishing / exiting the game. Exiting any level takes 1 minute. That means, for example, that it
took you L minutes to complete the first L levels.

Your task is to discover which option would result in the least amount of total time to finish the game (including the
time you have already spent).

### Input

The first line of the input gives the number of test cases, T. T test cases follow.

The first (and only) line of each test case contains three integers N, K and S: the number of levels in the game, the
current level you are in, and the level where you have to pick up the sword, respectively.

### Output

For each test case, output one line containing`Case #x: y`, where`x`is the test case number (starting from 1) and`y`is
the least amount of total time to finish the game.

### Limits

Time limit: 60 seconds.\

1 ≤ T ≤ 100.\
1 ≤ S<K<N.

#### Test Set 1

N ≤ 1000.

#### Test Set 2

N ≤ 10<sup>9<sup>.

## Sample

```c
Sample input:
2
10 5 2
10 7 6

Sample output:
Case #1: 15
Case #2: 12
```

In Sample Case #1, it took you 4 minutes to complete the first 4 levels and enter 5-th level. Restarting the game and
completing all levels again would take 11 more minutes (1 minute to restart and 10 to complete 10 levels), which adds up
to 15 minutes. The other option would be to move backwards until you reach level 2 (which would take 3 minutes), and
then complete all the remaining levels (taking 9 more minutes), which would result in a total of 16 minutes.

In Sample Case #2, it took you 6 minutes to complete the first 6 levels and enter 7-th level. Moving backwards until
reaching level 6 (one minute), and then completing all the remaining levels (5 minutes), would take a total of 12
minutes to finish the game.

## Analysis

There are 2 possible options to complete all the N levels. Let answer1 and answer2 be the time taken to complete all
levels for each of the options respectively. Initialize answer1 and answer2 as 0.

### Test set 1

We have already reached level K. In order to calculate time taken to reach level K, start iterating from level 1 till
level K and increment answer1 and answer2 on each step as we take 1 unit time to complete each level.

- One of the options to complete all levels is to restart the game and complete all the levels again, starting from
  level 1. We can calculate the time taken for this option by iterating from level 1 till level N and incrementing
  answer1.
- The second possible option is to go back to level S and then complete remaining levels after picking up the
  sword at level S. We can calculate the time taken for this option by iterating from level K to level S and
  incrementing answer2 at each step. Now, start iterating from level S till level N and increment answer2 at each
  step.The minimum time taken to complete all of the levels is the minimum value among answer1 and answer2. As we
  iterate each level at most twice in each possible option, the complexity of the solution is O(N).

### Test set 2

An observation here is that instead of simulating the levels and calculating the time taken, we can compute it in O(1)
time. Initially, we are at level K. This means that we took K time units to reach level K as completing each level takes
1 unit of time. Hence, we can increment answer1 and answer2 by K directly.

- For the first option, we restart the game and complete all levels again. It would take N time units to complete all
  the levels again as total number of levels are N. Hence, answer1 = N + K.

- For the second option, we go back to level
  S. This would take K - S time units as there are K - S levels between level K and level S. Then we complete remaining
  levels after picking up sword at level S. This would take N - S time units. Hence answer2 = K + K - S + N - S.The
  minimum time required to complete all levels is the minimum value among answer1 and answer2. Note that answer2 can
  overflow the range of range of 32-bit signed integers. For example, in C answer2 may overflow the range of INT
  datatype. Although the minimum answer would fit in the range of INT but overflowing of answer2 can cause unexpected
  output. Computing both answer1 and answer2 can be done in constant time. Hence, time complexity of the solution is O(
  1).