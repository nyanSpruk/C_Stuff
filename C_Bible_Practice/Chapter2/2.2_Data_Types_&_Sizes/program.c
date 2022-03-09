// There are only a few basic data types in C:
// char - singly byte
// int - an integer
// float - single precision floating point
// double - double precision floating point

// In addition there are a number of qualifiers that can be applied to thse basic types
// short and long apply to integers....
// short int sh;
// long int counter;
// but in this case 'int' can be ommited

// qualifier 'signed' and 'unsigned' may be applied to char or any integer.
// unsigned numbers are 0+ and obey the laws of arithmetic modulo 2^n
// so for instante chars are 8 bits.... unisgned char have values between 0 and 255 (2^8)
// while signed chars have values between -128 and 127 (two's compliment)

// Type long double specifies extended precision floating point.... float, double and long double could repesrent
// one, two or three distinct sizes

// the standard headers <limits.h> and <float.h> contain symbolic constants fro all of thse sizes