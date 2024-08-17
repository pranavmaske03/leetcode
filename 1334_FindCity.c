#include<stdio.h>
#include<stdlib.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int **dup = (int**)malloc(n*sizeof(int*));
    int INF = INT_MAX;

    for(int i=0; i<n; i++){
        dup[i] = (int*)malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            dup[i][j] = (i==j)?0:INF; 
        }
    }

    for(int i=0; i<edgesSize; i++){
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];

        dup[from][to] = weight;
        dup[to][from] = weight;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dup[i][k] != INF && dup[k][j] != INF && dup[i][k]+dup[k][j] < dup[i][j]){
                    dup[i][j] = dup[i][k]+dup[k][j];
                }
            }
        }
    }

    int cityCount =INF;
    int ans=-1;

    for(int i=0; i<n; i++){
        int count =0;
        for(int j=0; j<n; j++){
            if(i!=j && dup[i][j]<= distanceThreshold){
                count++;
            }
        }
        
        if(count < cityCount){
            ans=i;
            cityCount = count;            
        }
        else if(count == cityCount ){
            if(i>ans)
                ans=i;
        }

        printf(" city count = %d, count =  %d, i = %d, ans = %d \n",cityCount,count,i,ans);

    }

    for(int i=0; i<n; i++){
        free(dup[i]);
    }
    free(dup);
    return ans;
}

int main()
{


    return 0;
}