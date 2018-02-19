#include <stdio.h>
#include <stdlib.h>

int CalculateAdd(int  *num1, int *num2)
{
    int **a = &num1;
    int **b = &num2;
    return **a + **b;
}
int CalculateSub(int  num1, int num2)
{
   return num1 - num2;
}
int CalculateDiv(int num1, int num2)
{
     if (num2 == 0)
     {
         return -1;
     }
     else
     {
        return num1/num2;
     }
}
int CalculateMul(int  num1, int num2)
{
   return num1*num2;
}


int main()
{
    int num1;
    int num2;
    printf("Please enter number one : ");
    scanf("%d", &num1);
    printf("Please enter number two : ");
    scanf("%d", &num2);

    int * num1p= (int *) malloc(num1 * sizeof(int)); // create malloc to assign the memory space in heap of int size.
    int * num2p = (int *) malloc(num2 * sizeof(int));

   * num1p = num1; // assigned the value of num1 to the pointer of num1p i.e it will have it's value.
   * num2p = num2; // assigned the value of num2 to the pointer of num2p i.e it will have it's value.


    printf("Addition \n");
    int outputAdd = CalculateAdd(*(&num1p), *(&num2p)); // we are dereferencing and sending the address of num1p and num2p
    printf("%d\n", outputAdd);


    printf("Subtraction\n");
    int outputsub = CalculateSub(*num1p, *num2p); // We are sending the dereferenced value to the CalculateSub method.
    printf("%d\n", outputsub);

    int (*CalDiv) (int,int); // Created function pointer
    CalDiv = &CalculateDiv; // Assigning the address of the function CalculateDiv to the pointer CalDiv.

    printf("Division\n");
    int outputDiv = CalDiv(*num1p, *num2p); // Dereferencing the pointer.
    if (outputDiv == -1)
    {
        printf("Denominator cannot be negative \n");
    }
    else
    {
         printf("%d\n", outputDiv);
    }

    int (*CalMul) (int, int); // Created function pointer.
    CalMul = CalculateMul; // This is another way to assign the address of function to the function pointer , no need to put &.

    printf("Multiplication\n");
    int outoutMul = CalMul(*num1p, *num2p);
    printf("%d\n", outoutMul);

    return 0;
}
