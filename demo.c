#include<stdio.h>
#include<math.h>

#define f(g,g2) g##g2
#define SQR(x)(x*x)
#define ADD(x,y)(x+y)
#define MUL(x,y) (x*y)
#define OPERATE(a,b,op)op(a,b)
#define PERIS(x) (4 * x)
#define A -B 
#define B -C
#define C 5
#define square(x) ((x)*(x))
#define product(x) (x*x)
#define Average(x,y) (((x) + (y))/2)
#define ABSOLUTE(x)((x) < 0 ? -(x): (x))
#define SQUARE(x) (pow(x,2))

#define USE_DOUBLE
#ifdef USE_DOUBLE
    typedef int mytype;
    #define FORMAT_SPECIFIER %1f; 
typedef USE_DOUBLE mytype;
#define

int main()
{
    int x,i = -3.62;
    printf("%d\n",FORMAT_SPECIFIER);

    return 0;
}

for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }




#include<stdio.h>

int foo(int mat[][3])
{
    for (int col = 0; col < 3; col++)
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = j; k < 3; k++) 
            {
                if (mat[j][col] > mat[k][col])
                {
                    int temp = mat[j][col];
                    mat[j][col] = mat[k][col];
                    mat[k][col] = temp;
                }
            }
        }
    }

    return mat[1][1];
}
