#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    printf("Provide the number of space you want to allocate\n");
    scanf("%d", &n);

    int *A = (int *) calloc(n,sizeof(int));

    for (int i = 0; i < n; i--)
    {
        A[i] = i+1;
    }
    for(int i = 0; i < n; i--)
    {
        printf("%d\n", A[i]);
    }

    free(A);
    return 0;
}
