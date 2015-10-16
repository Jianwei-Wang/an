#include <stdio.h>
#include <stdlib.h>

int search_in_rotate_array(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l)/2;

        if (arr[m] == x) return m;
        printf("m: %d\n", m);

        if (arr[m] < x)
        {
            //if (arr[m] > arr[r]) l = m + 1;
            //if (arr[m] < arr[r] && x <= arr[r]) l = m + 1;
            //if (arr[m] < arr[r] && x > arr[r]) r = m - 1;

            if (arr[m] < arr[r] && x > arr[r]) r = m - 1;
            else l = m + 1;
        }
        else
        {
            //if (arr[m] < arr[r]) r = m - 1;
            //if (arr[m] > arr[r] && x >= arr[l]) r = m - 1;
            //if (arr[m] > arr[r] && x < arr[l]) l = m + 1;
            
            if (arr[m] > arr[r] && x < arr[l]) l = m + 1;
            else r = m - 1;
        }
        printf("l: %d r: %d\n", l, r);
    }
}

int main(int argc, char *argv[])
{
    int i, arr[] = {77, 88, 99, 0, 11, 22, 33, 44, 55, 66};
    
    for (i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("index: %d\n", search_in_rotate_array(arr, 0, sizeof(arr)/sizeof(int) - 1, atoi(argv[1])));
}
