# Coding 1

## Problem

To feed the cats and dogs in a park, you prepared D portions of dog
food and C portions of cat food.

There are a total of N animals waiting in a line, some of which are dogs and others are cats. It might be possible that
all the animals in the line are dogs or all the animals are cats. A string S of N characters C and D represents the
order of cats and dogs in the line. The i-th character is equal to C if the i-th animal in the line is a cat. Similarly,
the i-th character is equal to D if the i-th animal in the line is a dog.

The animals are fed in the order they stay in the line. Each dog eats exactly 1 portion of dog food and similarly each
cat eats exactly 1 portion of cat food. Moreover, you have extra portions of cat food. Every time a dog eats food, you
bring M extra portions of cat food for cats.

Animals have to be fed in the order they wait in line and an animal can only eat if the animal before it has already
eaten. That means that if you run out of dog (or cat) food portions and a dog (or a cat) is about to get fed, the line
will not move, as all the animals will wait patiently.

You need to determine if in this scenario all the dogs in the line will be fed. Note that this means that some cats
might remain in the line, but worry not, you will eventually feed them later!

## Function

```C
char * solution(int D, int C, int M, char *S){
    
    
}
```

### Arguments

Given a function solution which receives arguments as three integers D, C, M and one string S:
the initial number of dog food portions, the initial number of cat food portions,
and the additional portions of cat food that we add after a dog eats a portion of dog food,
and the arrangement of animals, respectively.

**Attention: the output arguments on the Gradescope:**

1. s1: [length of the string S] [D] [C] [M]
2. s2: [S]

****

### Output

Return string "YES" if all the dogs will be fed and string "NO" otherwise.

## Sample

| Case Index | Arguments       | Output |
|------------|-----------------|--------|
| 1          | 10 4 0 "CCDCDD" | "YES"  |
| 2          | 1 2 0 "CCCC"    | "YES"  |
| 3          | 2 1 0 "DCCD"    | "NO"   |

In Sample Case #1, there are 10 portions of dog food and 4 portions of cat food.

1. The first two animals are cats, so after they eat, 2 portions of cat food remain.

2. Then a dog eats one portion of dog food. Now, there are 9 portions of dog food left.

3. Next, a cat eats a portion of cat food, reducing the number of portions of cat food to 1.

4. The last two animals are dogs and they each eat one portion of dog food.

So in this case, all the dogs are able to eat.

In Sample Case #2, there are no dogs. Hence, all (zero) dogs will be able to eat trivially.

In Sample Case #3, the cat before the second dog will not be able to eat because there will not be enough portions of
cat food. Hence, the second dog will also not eat.

## Additional Sample

| Case Index | Arguments            | Output |
|------------|----------------------|--------|
| 1          | 4 2 2 "CDCCCDCCDCDC" | "YES"  |
| 2          | 2 1 3 "DCCCCCDC"     | "NO"   |

In Sample Case #1, 2 portions of cat food appear whenever a dog eats a portion of dog food.

1. After the first cat eats, there is 1 portion of cat food left.

2. Then a dog eats, leaving 3 portions of dog food and 3 portions of cat food.

3. After the next 3 cats eat, there are 3 portions of dog food and 0 portions of cat food remaining.

4. Then a dog eats, leaving 2 portions of dog food and 2 portions of cat food.

5. After the next 2 cats eat food, there are 2 portions of dog food and 0 portions of cat food left.

6. Now a dog eats, leaving 1 portion of dog food and 2 portions of cat food.

7. Next a cat eats, leaving 1 portion of dog food and 1 portion of cat food.

8. The last dog eats the remaining portion of dog food.

So in this case, all the dogs are able to eat.

In Sample Case #2, the cat before the second dog will not be able to eat because there will not be enough portions of
cat food.






