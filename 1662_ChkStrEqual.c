#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool arrayStringsAreEqual(char (*word1)[10], int word1Size, char (*word2)[10], int word2Size) 
{
    char str1[100] = {};
    char str2[100] = {};
    int size1 = 0,size2 = 0;

    for(int i = 0; i < word1Size; i++) {

    
        for(int j = 0; word1[i][j] != '\0'; j++) {
            str1[size1++] = word1[i][j];
        }
    }
    for(int i = 0; i < word2Size; i++) {
        for(int j = 0; word2[i][j] != '\0'; j++) {
            str2[size2++] = word2[i][j];
        }
    }
    if(size1 != size2) return false;

    for(int i = 0; i < size1; i++)
    {
        if(str1[i] != str2[i]) return false;
    }

    return true;
}

bool arrayStringsAreEqual1(char** word1, int word1Size, char** word2, int word2Size) 
{
    char *Str1 = calloc(1001,sizeof(char));
    char *Str2 = calloc(1001,sizeof(char));

    for ( int i = 0; i < word1Size; i++ )
    strcat(Str1,word1[i]);

    for ( int i = 0; i < word2Size; i++ )
    strcat(Str2,word2[i]);

    bool Res = !strcmp(Str1,Str2) ? true : false;
     
    free(Str1);
    free(Str2);
    return Res;
}

int main()
{


    char word1[][10] = {"abc", "d", "defg"}, word2[][10]  = {"abcddefg"};

    bool bRet = arrayStringsAreEqual(word1,3,word2,1);
    if(bRet == true) {
        printf("Equal");
    } else {
        printf("NOT Equal");
    }

    return 0;
}