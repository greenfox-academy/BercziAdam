#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/** TODO:
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */
int *range(int from,int to,int step);
int from=0;
int to=11;
int step=2;
int n;
int i;
int main() {

        if (to%step==0)
    {
    n=(float)to/step-1;
    }else
    {
    n=floor((float)to/step);
    }
    int *prt=range(from , to , step);
    for (i=0; i<n; i++){

    printf("%d\n",*(prt+i));
    }
    free(prt);
    return 0;
}

int *range(int from,int to,int step)
{
int* pointer=NULL;

if (to%step==0)
{
    n=(float)to/step-1;
}else
{
    n=floor((float)to/step);
}
pointer= (int*) calloc((n), sizeof(int));
if(pointer == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
   for (i=0; i<n; i++){
        pointer[i]=step*i;
   }
return (pointer);
free(pointer);
}
