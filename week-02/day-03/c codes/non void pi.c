
#include <stdio.h>
#include <stdio.h>

/* Write a non void function which returns the value of PI, so the following number:
3.14159
Try it out in the main function by printing out the result of the pi generator function!
*/
float PI ();
int main(){

    float Pi= PI();

    printf("The value of Pi is %f",Pi);
    return 0;
}

float PI ()
{
        float value = 3.14159;

    return value;
}
