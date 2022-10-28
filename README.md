## This is a <font color = "FF0000">IBAN code generator</font> used to study the Luhn's formula

To check the "*arithmetic*" correctness of the credit card code we use *Luhn's formula*, which is as follows:

- Assume that the 16 digits are the following (in groups of 4): ($a_1 b_1 a_2 b_2$), (a_3 b_3 a_4 b_4), (a_5 b_5 a_6 b_6), (a_7 b_7 a_8 b_8);

- You multiply the digits a1, a_2, . . . , a_7, a_8 by 2 thus obtaining 2a1, 2a_2, . . . , 2a_7, 2a_8;

- If any of these 8 numbers should be greater than 9 (and thus is a 2-digit number) you replace it with the sum of its digits;

- The sum of the results obtained is to be compared with the sum of the even-place cirphas.

- If the two sums are equal, then the credit card code is correct, otherwise it is incorrect.
