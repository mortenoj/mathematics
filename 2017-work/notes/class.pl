f(a,b).
f(a,c).
f(b,c).

# Terminal in and outputs
#
# , = and
# ; = or
# lower case letters : atoms/relations
# variables: upper case letters

1 ?- [class].
true

2 ?- f(a,d).
false

3 ?- f(a,b).
true

4 ?- f(a,b) , f(b,c).
true

5 ?- f(a,b) ; f(b,a).
true

6 ?- f(a,d).
false // Cannot compute that there is a flight between a and d

7 ?- f(a, Where).
Where = b ;
Where = c.

8 ?- f(H,G).
H = a,
G = b ;
H = a,
G = c ;
H = b,
G = c.

9 ?- f(Where, Where).
false # cant find any instances where this is true
