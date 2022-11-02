## This is a Credit Card Number (CCN) generator used to study the Luhn's formula

To check the "*arithmetic*" correctness of the CCN we'll use *Luhn's formula*, which is as follows:

- Assume that the 16 digits are the following (in groups of 4): (a1 b1 a2 b2), (a3 b3 a4 b4), (a5 b5 a6 b6), (a7 b7 a8 b8);

- Multiply the digits a1, a2, . . . , a7, a8 by 2 obtaining 2a1, 2a2, . . . , 2a7, 2a8;

- If any of these 8 numbers should be greater than 9 (so it's a 2-digit number) replace it with the sum of its own digits;

- The sum of the odd-place digits need to be added to the sum of the even-place digits;

- If the result of the operation "addition sums / 10 " has no remainder, then the iban code is correct, otherwise it is incorrect.