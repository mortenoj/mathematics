parent(a,b).
parent(a,c).
parent(b,d).
grandparent(X,Y) :- write("rule 1: "), write(X), write(Y), parent(X,Z), parent(Z,Y).

# Terminal

1 ?- [class].
true.

2 ?- grandparent(a,d).
rule 1: ad
true

3 ?- grandparent(a,X).
rule 1: a_1760
X = d ;
false
