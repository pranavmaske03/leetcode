#include<stdio.h>
#include<stdlib.h>

double averageWaitingTime(int** customers, int customersSize, int* customersColSize) 
{
    if(customersSize == 1)
    {
        return customers[0][1];
    }
    else 
    {
        long int sum = 0;
        long int chef_ends = 0,wait_time = 0;

        for(int i = 0; i < customersSize; i++)
        {
            wait_time = ((chef_ends + customers[i][1]) - *customers[i]);
            if(wait_time < 0)
            {
                wait_time = customers[i][1];
            }
            if(chef_ends < *customers[i])
            {
                chef_ends = *customers[i];
                wait_time = customers[i][1];
            }
            sum = sum + wait_time;
            chef_ends = chef_ends + customers[i][1];
        }
        return (double)sum/customersSize;
    }
}

int main()
{
    int **array;
    int SIZE = 0,no = 0;
    int size = 0;
    
    printf("Enter the number of rows \n");
    scanf("%d",&SIZE);

    printf("Enter the number of columns \n");
    scanf("%d",&size);

    array = (int **) malloc(SIZE * sizeof(int*));

    printf("Enter the elements of array \n");
    for (int row = 0; row < SIZE; row++) 
    {
        array[row] = (int *) malloc(SIZE * sizeof(int));
        for (int col = 0; col < size; col++)
        {
            scanf("%d",&no);
            array[row][col] = no;  // or whatever value you want
        }
    }
    double ret = averageWaitingTime(array,6,&size);
    printf("%f\n",ret);

    return 0;
}

//[2,3],[6,3],[7,5],[11,3],[15,2],[18,1]