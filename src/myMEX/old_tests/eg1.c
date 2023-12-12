#include <stdio.h>

void func(int* array, int size)
{

	// Print size of array directly by size argument
	printf("Size of array inside func = %d bytes\n", size);
}

int main()
{

	// Create an one dimensional array
	int array[10] = { 0 };
    // array[1];
    // array = malloc(30);
	// Get size of an array (bytes)
	int size = sizeof(array);

	// print size of an array in main method
	printf("Size of array in main function = %d bytes\n",
		size);

	// Call func function
	func(array, size);

	return 0;
}