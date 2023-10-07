#include <stdio.h>

int main() {
    int Local_u8KeyArray[4][3]={ {1,2,3},
	{4,5,6},
	{7,8,9},
	{12,0,13} };

    // Create a pointer to an array of integers
    int(* ptr)[3];

    // Point the pointer to the array
    ptr = Local_u8KeyArray;

    // Access elements of the array using the pointer
    printf("Element 3: %d\n", ptr[2][1]); // Output: Element 3: 3

    return 0;
}