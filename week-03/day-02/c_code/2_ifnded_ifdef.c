#include <stdio.h>
#include <stdlib.h>

// Define the TOTORO macro which holds the number of students in our class

   /*  */

int main(){
    // Use the #ifdef and #ifndef macros!



    // If the TOTORO macro is not defined print out 32
#ifndef TOTORO
#define TOTORO 32
#endif // TOTORO


    // If the TOTORO macro is defined print out it's value
#ifdef TOTORO
#endif // TOTORO
printf("Totoro class member count:\t%d", TOTORO);

    return 0;
}
