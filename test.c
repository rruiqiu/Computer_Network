#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    srand(600318682); //use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
    printf("%ld\n",time(NULL));
}