#include<stdio.h>

void merge(int arr1[], int arr2[], int m, int n) 
{
  int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0) 
    {
        if(arr1[i] > arr2[j]) 
        {
            arr1[k--] = arr1[i--];
        }
        else 
        {
            arr1[k--] = arr2[j--];
        }
    }
    while(j >= 0) 
    {
        arr1[k--] = arr2[j--];
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d\t",arr1[i]);
    }
}

void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1;
    int j = n - 1;
    int last = nums1Size - 1;

    while (last >= 0)
    {
        if(i < 0)
        {
            nums1[last--] = nums2[j--];
        }
        else if(j<0)
        {
            nums1[last--] = nums1[i--];
        }
        else if(nums1[i] > nums2[j])
        {
            nums1[last--] = nums1[i--];
        }
        else
        {
            nums1[last--] = nums2[j--];
        }
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d\t",nums1[i]);
    }
}

int main()
{
    int Arr[10] = {2,2,5,6,7};
    int Brr[10] = {1,1,5,7,8};

    merge1(Arr,10,5,Brr,5,5);

    return 0;
}
