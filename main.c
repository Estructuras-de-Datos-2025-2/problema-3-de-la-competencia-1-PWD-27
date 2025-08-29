#include <stdio.h>
#include <stdlib.h>
static int cmp_int(const void *a, const void *b) {
    int x=*(const int*)a, y=*(const int*)b; 
    return (x>y)-(x<y); 
}

int main(void){
    int n;
    if (scanf("%d",&n)!=1) 
    return 0;

    int *a = (int*)malloc((size_t)n*sizeof(int));
    if(!a){ 
    return 0;
    }
    for (int i = 0;i<n;++i){
        if (scanf("%d",&a[i])!=1){
            free(a);
            return 0;
        }
    }
    qsort(a,(size_t)n,sizeof(int),cmp_int);
    int k=0;
    for (int i = 0;i<n;++i){
        if (k ==0 || a[i]!=a[k-1]){
            a[k++]=a[i];
        }
    }

    int*tmp=(int*)realloc(a,(size_t)k*sizeof(int));
    if(tmp) a = tmp;

    printf("%d\n", k);
    for (int i = 0;i<k;++i){
        if (i) putchar(' ');
        printf("%d",a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}
