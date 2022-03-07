#include <stdio.h>

// Functions use a copy of the variable that is passed in the function and
// not the original.. So that temporary var is only in scope of that function
// If you want to access the original variable, the caller must provide the
// variables address (a pointer to the var) More in chapter 5 about pointers

// The story is different for arrays. When the name of an array is used
// as an arg, the val passed to the fun is the location or address of the
// beginning of the array. There is no copying of array elements.
// More in next section 1.9