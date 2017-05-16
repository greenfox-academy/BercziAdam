#include <stdio.h>
#include <stdint.h>

int main() {

	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".
     int a = 1;
    while(a <= 100) {

        if(a % 3 == 0 && a % 5 == 0) {
            printf("FizzBuzz\n");
        }

        else if(a % 3 == 0) {
            printf("Fizz\n");
        }

        else if(a % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", a);
        }

        a ++;

    }

    return 0;
}
