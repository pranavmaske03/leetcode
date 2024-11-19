#include<stdio.h>
#include<stdlib.h>

struct People 
{
    char *name;
    int age;
};

int compare_age(const void* age_x,const void* age_y)
{
    return((struct People *)age_x)->age - ((struct People *)age_y)->age;
}

char** sortPeople(char (*names)[10] ,int namesSize, int* heights, int heightsSize) 
{
    struct People *people = malloc(sizeof(struct People) * namesSize);
    for(int i = 0; i < numsSize; i++)
    {
        people[i].name = names[i];
        people[i].age = heights[i];
    }
    qsort(people,namesSize,sizeof(struct People),compare_age);
    char **ret = (char **)malloc(namesSize * sizeof(char*));
    for(int i = namesSize-1,j = 0; i >= 0; i--,j++)
    {   
        ret[j] = people[i].name;
    }
    free(people);
    return ret;
}

int main()
{
    char arr[10][10] = {"Mary","John","Emma"};
    int brr[10 ] = {180,165,170};
    char **ptr = sortPeople(arr,3,brr,3);

    for(int i = 0; i < 3; i++)
    {
        printf("%s\t",ptr[i]);
    }

    return 0;
}