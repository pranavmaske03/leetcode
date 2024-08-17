#include<stdio.h>

int foo(int arr[], int left, int right) 
{
    int mid = left + (right - left) / 2;

    if ((mid == 0 || arr[mid - 1] >= arr[mid]) && (mid == right || arr[mid + 1] >= arr[mid])) 
    {
        return mid;
    }
    if (mid > 0 && arr[mid - 1] > arr[mid]) 
    {
        return foo(arr, left, mid - 1);
    } else {
        return foo(arr, mid + 1, right);
    }
}





int main()
{
    int arr1[3][3] =  {{3, 8, -2}, {-4, 12, -3}, {6, 1, 9}};
    int arr[] =   {14, 16, 18, 11, 17, 12};
    char str[] = "Hello!1212";
    int size = 6;

    printf("n = %d\n",foo(arr,0,5));
    //printf("n = %d\n",foo(str));
   //printf("n = %d\n",typeofTriangle(3,4,2));

    return 0;
}