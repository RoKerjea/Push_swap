
#include <stdio.h>

typedef struct s_median
{
	int a;
	int b;
}		t_median;
 
// Utility function to swapping of element
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 /*
// Returns the correct position of
// pivot element
int Partition(int arr[], int l, int r)
{
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 
// Picks a random pivot element between
// l and r and partitions arr[l..r]
// around the randomly picked element
// using partition()
int randomPartition(int arr[], int l,
                    int r)
{
    int n = r - l + 1;
    int pivot = n / 2;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}*/

void	printtab(int *tab)
{
	int i = 0;

	while(i < 12)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

int	getpivotindexafterpart(int *tab, unsigned int starti, unsigned int endi)
{
	/*printtab(tab);
	printf("starti = %d, endi = %d\n", starti, endi);*/
	int	pivoti;
	int	n;

	n = endi - starti + 1;
    pivoti = n / 2;
    swap(&tab[starti + pivoti], &tab[endi]);
    int lst = tab[endi];
	unsigned int i = starti, j = starti;
    while (j < endi)
	{
        if (tab[j] < lst)
		{
            swap(&tab[i], &tab[j]);
            i++;
        }
        j++;
    }
    swap(&tab[i], &tab[endi]);
	printf("pivoti = %d\n", i);
    return (i);
}
 
// Utility function to find median
void MedianUtil(int arr[], int l, int r,
                int k, t_median *res)
{
 
    // if l < r
    if (l <= r) {
 
        // Find the partition index
        int partitionIndex
            = getpivotindexafterpart(arr, l, r);
		printf("pivoti = %d\n", partitionIndex);

        // If partition index = k, then
        // we found the median of odd
        // number element in arr[]
        if (partitionIndex == k) {
            res->b = arr[partitionIndex];
    		printf("b = %d\n", res->b);
            if (res->a != -1)
                return;
        }
 
        // If index = k - 1, then we get
        // a & b as middle element of
        // arr[]
        else if (partitionIndex == k - 1) {
            res->a = arr[partitionIndex];
   			printf("a = %d\n", res->a);
            if (res->b != -1)
                return;
        }
 
        // If partitionIndex >= k then
        // find the index in first half
        // of the arr[]
        if (partitionIndex >= k)
            return MedianUtil(arr, l,
                              partitionIndex - 1,
                              k, res);
 
        // If partitionIndex <= k then
        // find the index in second half
        // of the arr[]
        else
            return MedianUtil(arr,
                              partitionIndex + 1,
                              r, k, res);
    }
 
    return;
}
 
// Function to find Median
int findMedian(int arr[], int n)
{
    t_median res;

	res.a = -1;
	res.b = -1;
 
    // If n is odd
    if (n % 2 == 1) {

    	printf("gate odd\n");
        MedianUtil(arr, 0, n - 1,
                   n / 2, &res);
		printf("res should be %d\n", res.b);
		return (res.b);
    }
 
    // If n is even
    else {

    	printf("gate even\n");
        MedianUtil(arr, 0, n - 1,
                   n / 2, &res);
		int med = (res.b + res.a) / 2;
		printf("res should be %d\n", med);
		return ((res.b + res.a) / 2);
    }
 
    // Print the Median of arr[]
}
 
// Driver program to test above methods
int main()
{
   // int arr[] = {12, 0, 11, 1, 10, 2, 9, 3, 8, 4, 7, 6, 5};
	int arr[] = {9145, 9281, 9442, 9354, 9337};

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("median final is %d", findMedian(arr, n));
    return 0;
}