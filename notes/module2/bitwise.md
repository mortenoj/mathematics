## Logic


### Bitwise logic


*AND operator*

And operator need both bits to be 1 to get 1

Example

1100
1010
----
1000


*OR operator*

Or operator needs one or more "1" to get "1"

1100
1010
----
1110

*XOR (exclusive or) operator*

XOR operator needs 1 and only 1 to get 1

1100
1010
----
0110


Can be used to swap variables:

int a = 4 // 0000 0100
int b = 3 // 0000 0011

    a = a^b // 0000 0111
    b = a^b // 0000 0100
    a = a^b // 0000 0011

Now b = a, and a = b

*NOT operator*

Works only one segment of bits, reverses order (1=0 and 0=1)

1010
----
0101


*Shift operators*


-Left shift

shiftes a string of bits to the left

1110010101
1100101010 first shift
1001010100 second shift
0010101000 third shift
0101010000 fourth shift

Left shifting is the same as multiplying 2^rightOperand

var = 3      (0000 0011)
var << 1 = 6 (0000 0110)

(left operand * 2^rightoperand)
(3 << 1 = 6)
3 * 2^1 = 6

var << 4 = 48
3 << 4 = (3 * 2^4 = 48)

-Right shift

shiftes a string of bits to the right

1110010101
0111001010 first shift
0011100101 second shift
0001110010 third shift
0000111001 fourth shift

Right shifting is the same as dividing by 2^rightOperand

var = 3      (0000 0011)
var >> 1 = 1 (0000 0001)

(left operand / 2^rightoperand)
(3 << 1 = 1)
3 / 2^1 = 1

var = 32
var << 2 = 0
32 << 4 = (32 / 2^4 = 2)



-Circular left shift

instead of replacing bits with 0 they get wrapped around to the back of the string

1110010101
1100101011 first shift
1001010111 second shift
0010101111 third shift
0101011110 fourth shift


-Circular right shift

1110010101
1111001010 first shift
0111100101 second shift
1011110010 third shift
0101111001 fourth shift




#### Bitwise operators in C


& - and
| - or
~ - not
<< - left shift
>> - rigth shift
^ - xor











