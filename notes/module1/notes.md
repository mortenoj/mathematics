# Chapter 1 - probability


Sample space (S) = set of all outcomes of an experiment

Event (E) = set of all outcomes of interest (a subset of S)

P(E) = probability that E (event) happens

If we are repeating the experiement several times:
P(E) = frequency of E happening

e.g Rolling a dice:

`S = {1, 2, 3, 4, 5, 6}`
`E = "rolling a 6"`

`P(E) = 1/6`

Probability of S is always 1

`P(S) = 1 or 100%`

Probability of E or F happening = sum of the probabilities

`P(E u F) = P(E) + P(F)`  if `P(E ^ F) = ø` (P(E) and P(F) are disjoint)

Probability of E not happening

`P(!E) = 1 - P(E)`


If E is an event that is contained in event F, then the probility of E happening is less than or equal to F happening

`E <= F` -> `P(E) <= P(F)`

The probability of the union of E and F and E and F are not disjoint

`P(E u F) = P(E) + P(F) - P(E ^ F)`


*More Examples*

-Dice: 5 six-sided dice

S has 6^5 elements
`|S| = 6^5`

E = rolling at least one six


-Card: hand of 5 cards drawn from a deck of 52 cards

S has 52, choose 5 elements
`|S| = c(52,5)`

E = getting a flush


-Queueing 10 people labeled a..j
`|S| = 10!`

Event = a and b shoulb be placed before f


-Consider n amount of dice

`|S| = 6^n` // S har 6 to the power of n elements

For n = 1 we can list the elements of S as {1, 2, 3, 4, 5, 6}
For n = 2 we can view the sample space as entries of a 6 x 6 matrix:

   1  2  3  4  5  6
1 [x, x, x, x, x, x]
2 [x, x, x, x, x, x]
3 [x, x, x, x, x, x]
4 [x, x, x, x, x, x]
5 [x, x, x, x, x, x]
6 [x, x, x, x, x, x]

For n >= 2 it becomes inconvenient to list the elements of S without a PC



*More sample spaces*

In a simple sample space, the S is finite and ell elements x in S has equal probability

`P({x}) = 1 / |S|`

The probability of an event E is then

`P({x}) = 1 / |S|`

and calculating the probabilities is reduced to a problem of enumeration

How can we count the elements in E and S?

-List elements (with or without a computer)
-Enumeration methods
-Methods based on matrices
-Run simulations

*Enumeration*

The four principles for counting:

When counting you should be really careful and understand why you are using the arithmetic operations +, −, ∗, /. Also, if you are unable to solve the problem, you could always try to translate the problem into a more familiar situation where you are able to count. Finally, there are always more than one way to count, and a different (but correct) approach will also give the correct answer. These principles are summarised as:

-The rule of Sum
-The rule of Product
-The rule of Bijection
-The rule of Counting in Two Ways

Recall also the principle of inclusion-exclusion:

`|A u B| = |A| + |B| - |A ^ B|`

Picking random collections of marbles from a bag. You have a bag of marbles numbered 1 to n and you pick out m of these at randoom. Clearly, you will not encounter many problems which directly deals with picking marbles from a bag, but you may be able to translate your problem into that form. Once you are convinced that your problem is equivalent to picking marbles from a bag, you need to ask yourself the following two questions.

-(order) Does it matter which order the marbles were picked?
-(repetition) Are marbles returned to the bag after being picked?

When you know the answer there are four different formulas:

-Ordered selection, allowing repetition: n^m
-Ordered selection, without repetition: P(n, m)
-Unordered selection, without repetition: C(n, m)
-Unordered selection, allowing repetition: C(n + m - 1, n-1) - will not be used in this course




*More examples*

Dice: We look at example where n dice with 6 sides numbrs 1, 2, 3, 4, 5, 6

*What is the probability of having 2 sixes when rolling 2 dice?*

`|S| = 36` (6x6)

`E = rolling 2 sixes` there is only 1 event where this happens

`P(E) = 1/36 = 0.028`


*What is the probability of having at least one six when rolling 2 dice?*

We can view the sample space as a matrix

   1  2  3  4  5  6 </br>
1 [0, 0, 0, 0, 0, 0]</br>
2 [0, 0, 0, 0, 0, 0]</br>
3 [0, 0, 0, 0, 0, 0]</br>
4 [0, 0, 0, 0, 0, 0]</br>
5 [0, 0, 0, 0, 0, 0]</br>
6 [0, 0, 0, 0, 0, 0]</br>

where 0 is an element of the sample space. Using X to indicate the event space we get:

   1  2  3  4  5  6</br>
1 [0, 0, 0, 0, 0, X]</br>
2 [0, 0, 0, 0, 0, X]</br>
3 [0, 0, 0, 0, 0, X]</br>
4 [0, 0, 0, 0, 0, X]</br>
5 [0, 0, 0, 0, 0, X]</br>
6 [X, X, X, X, X, X]</br>

There are 11 Xs so we get:

`P(E) = 11/36 = 0.306`


We could also have calculated follows. 1. "At least one six" means we either have 1 or 2 sixes. We consider these cases separately. If we have 1 six, then we have 2 choices for determining which dice has a six and 5 possible values on the other dice, giving a total of 2⋅5=10 possibilities. There are 1 possibility of having 2 sixes.

In total the probability is ( (10 + 1) / 36 ) = (11 / 36) ≈ 0.306


*What is the probability of having no sixes when we roll 2 dice?*

Remember probability of E not happening

`P(!E) = 1 - P(E)`

Using the calculation above, we get the answer is:

`1 - (11/36) = 25/36 = 0.694`

Another solution: Each dice can now hace 5 different values (which are not 6) giving us: `5 ⋅ 5 = 25` possibilities. So the probability is `25 / 36`.

*What is the probability that the sum is 6 when we roll 2 dice?*

We have the event space where X = 6:

   1  2  3  4  5  6
1 [0, 0, 0, 0, X, 0]
2 [0, 0, 0, X, 0, 0]
3 [0, 0, X, 0, 0, 0]
4 [0, X, 0, 0, 0, 0]
5 [X, 0, 0, 0, 0, 0]
6 [0, 0, 0, 0, 0, 0]

There are 5 Xs therefor the probability is:

`P(E) = 5/36 = 0.139`


*What is the probability of having 1 six when we roll 4 dice?*

There are 4 choices for determining the dice which shows 6 and 5^3 possible values for the remainding dice. So the probability is:

`(4⋅5^3) / 6^4 = 0.39`

*What is the probability of having 4 6s when we roll 8 dice?*

There are C(8, 4) possibilities for determining the dice which show 6, and 5^4 values for the remaining dice. So the probability is:

`(C(8,4) ⋅ 5^4) / 6^8 = 0.026`



*Other notes*

Examples where you calculate the probability of getting at least one event of a sample space:

Flipping a coin 3 times:

What is the probability of getting at least one heads?

This is the same as the probability of not getting all tails
`P(!E) = 1 - P(E)`

P(at least 1 H) = P(not getting all T) = 1 - P(T T T)

`P( T T T ) = 1/2 * 1/2 * 1/2 = 1/8`

`P(at least 1 H) = 1 - 1/8 = 7/8`

Explanation

These are mutually exclusive so you may add them. And they are essentially all of the events.
`P(not all T) or P(all T) = 1` can be converted to `P(not all T) = 1 - P(all t)`


Flipping a coin 10 times:

The probability of getting at least one head?

Again this is the same as the probability of not getting all tails:

`P(!E) = 1 - P(E)`

`P(at least one H) = 1 - (1/2^10) = 1 - (1/1024) = 1023 / 1024 = 0.999` or a 99.9% chance of getting at least one heads of 10 flips




Examples where you need to find the probability of getting exactly a number of events in a sample space:



Flipping a coin 4 times:

What is the probability of getting exactly 2 heads:

Firstly there are 16 different outcomes: `2 * 2 * 2 * 2 = 16`

Secondly, there are 4 different places: _ _ _ _

The first H can be in either of those places: H _ _ _,  _ H _ _,  _ _ H _ or _ _ _ H 
If the first H has taken one of these places, the second H has only 3 spaces left to occupy.

H1 = 4 possibilities
H2 = 3 possibilities

= 12 different scenerios if we think of these the Hs as unique, but they are not.
We are double counting the Hs since it doesn't matter which one is thrown first.

What we acctually want is to divide this by 2 (all of the possible ways to swap the order of 2 different Hs) or 2!
What we now get are all of the possible potitions of any of the 2 Hs:

There for the probability of getting exactly 2 heads is:

`6 / 16 = 3 / 8`


Now, let's flip the coin 5 times:

What is the probability of getting exactly 3 head:

There are `2 * 2 * 2 * 2 * 2 = 32` different outcomes

There are 5 different places: _ _ _ _ _

The Hs can be at either one of these places:

H1 = 5 different possibilities
H2 = 4 different possibilities
H3 = 3 different possibilities

= 60 different possibilities

Now we divide 60 by how many different ways we can sort 3 different Hs: `3! = 3 * 2 * 1 = 6`

`60 / 6 = 10`

The probability of getting exactly 3 head:

`P(E) = 10 / 32 = 5 / 16`


Generally 

What is the probability of getting k Hs in n Flips

`P(k Hs in n Flips)`

We have 2^n possibilities

How many of these involve k heads

The different places k heads kan be at is: 

-1st flip: n
-2nd flip: n-1
-3rd flip: n-2

-nth flip: n * (n-1) ... (n - (k - 1))

Then we need to divide that by how many ways we can sort k things:

n * (n-1) ... (n - (k - 1))     </br>
---------------------------     </br>
  k * (k-1) * (k-2) ... 1       </br>

We can rewrite this as: 

   n!
-------
k!(n-k)!
    
or `(n! / k! * (n-k)!)`


So what is the possibilities of getting k Heads in n Flips: 
Remember we have 2^n possibilities


   n!
-------
k!(n-k)!
-------
  2^n



or `(n! / k! * (n-k)!) / 2^n`



**Permutations**


Place 7 people in 3 chairs

-1st chair: 7 possibilities
-2nd chair: 6 possibilities
-3rd chair: 5 possibilities

7*6*5 = 210 different possibilities

Formula: 

  n!
------
(n-k)!



**Combinations**


Sort ABC = 3! = 6

Formula:

Permutation / r! where r = is k

nCr (n choose r)


=     n!
    ------
    (n-r)!
    ------
      r! 

or

=      n!
    --------
    r!(n-r)!
      














