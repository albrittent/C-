#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,D;
    scanf("%d %d %d",&N,&M,&D);
    char nums[M][10000];
    for(int i=0;i<M;i++){
        scanf("%s",nums[i]);
    }
    int pre_hash[N][D];
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            scanf("%d",&pre_hash[i][j]);
        }
    }
    int post_hash[M][D];
    for(int i=0;i<M;i++){
        for(int j=0;j<D;j++){
            char c = nums[i][j];
            int number = atoi(&c);
            int j4 = j*j*j*j;
            int dj = (D-j);
            int dj4 = dj*dj*dj*dj;
            post_hash[i][j] = ((number+j4+dj4)*D*D)/((D-3)*(D-3));
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int ok = 1;
            for(int k=0;k<D;k++){
                if(post_hash[j][k] != pre_hash[i][k]){
                    ok = 0;
                }
            }    
            if(ok==1){
                    printf("%s\n",nums[j]);
            }
        }
    }
    return 0;
}