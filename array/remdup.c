// C program to remove duplicates
#include <stdio.h>
int removedup(int arr[], int n){
    if(n==0 || n==1){
        return n;
    }
    int temp[n];
    int j=0;
    for(int i=0; i<n-1;i++){
        if(arr[i] != arr[i+1]){
            temp[j++] = arr[i];
        }
    }
        temp[j++] = arr[n-1];
        for(int i=0; i<=j; i++){
            arr[i]=temp[i];

        }
        return j;
}

// for(int k=0; i< n ; i++){
//     if(a[i]>a[i+1]){
//         int temp;
//         temp = arr[i];
//         arr[i+1]=arr[i];
//         arr[i]=temp;

//     }
// }
int removeDuplicates(int arr[], int n)
{
	if (n == 0 || n == 1)
		return n;

	int temp[n];

	// Start traversing elements
	int j = 0;

	// If current element is not equal to next element
	// then store that current element
	for (int i = 0; i < n - 1; i++)
		if (arr[i] != arr[i + 1])
			temp[j++] = arr[i];

	// Store the last element as whether it is unique or
	// repeated, it hasn't stored previously
	temp[j++] = arr[n - 1];

	// Modify original array
	for (int i = 0; i < j; i++)
		if(arr[i] = temp[
        }

	return j;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// removeDuplicates() returns new size of array.
	n = removeDuplicates(arr, n);

	// Print updated array
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
