#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct robot_info
{
    int position;
    int health;
    char direction;
    int index;
};

struct robot_stack
{
    int health;
    int index;
};

int compare_robots(const void* robot_x,const void* robot_y)
{
    return((struct robot_info *)robot_x)->position - ((struct robot_info *)robot_y)->position;
}

int compare_stack(const void* stack_x,const void* stack_y)
{
    return((struct robot_stack *)stack_x)->index - ((struct robot_stack *)stack_y)->index;
}

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char * directions, int* returnSize)
{
    int i = 0;
    struct robot_info* robot = malloc(sizeof(struct robot_info)*positionsSize);

    struct robot_stack* stack = malloc(sizeof(struct robot_stack)*positionsSize);
    int top = 0;
    int L_in_stack = 0;

    for(i = 0;i < positionsSize;i++)
    {
        robot[i].position = positions[i];
        robot[i].health = healths[i];
        robot[i].direction = directions[i];
        robot[i].index = i;
    }
    qsort(robot,positionsSize,sizeof(struct robot_info),compare_robots);

    for(i = 0;i < positionsSize;i++)
    {
        if(robot[i].direction == 'R')
        {

            stack[top].health =  robot[i].health;
            stack[top++].index =  robot[i].index;

        }
        else
        {
            while(top > L_in_stack)
            {
                if(robot[i].health < stack[top - 1].health)
                {
                    stack[top - 1].health--;
                    robot[i].health = 0;
                    break;
                }
                else if(robot[i].health == stack[top - 1].health)
                {
                    top--;
                    robot[i].health = 0;
                    break;
                }
                else
                {
                    top--;
                    robot[i].health--;
                }
            }

            if(robot[i].health > 0)
            {
                stack[top].health = robot[i].health;
                stack[top++].index = robot[i].index;
                L_in_stack++;
            }
        }
    }
    free(robot);

    qsort(stack,top,sizeof(struct robot_stack),compare_stack);

    int *ret = (int*)malloc(sizeof(int)*top);
    for(i = 0;i < top;i++)
    {
        ret[i] = stack[i].health;
    }

    free(stack);

    *returnSize = top;
    return ret;
}
int main()
{   
    int arr[10] = {5,4,3,2,1};
    int brr[10] = {11,21,10,23,15};
    char crr[10] = {'R','R','R','R','R'};

    //sorting(arr,brr,crr,4);
    //int *ret = survivedRobotsHealths(arr,brr,crr,5);

    for(int i = 0; i < 5; i++)
    {
       // printf("%d\n",ret[i]);
       // printf("%d\t%d\t%c\n",arr[i],brr[i],crr[i]);
    }

    return 0;
}