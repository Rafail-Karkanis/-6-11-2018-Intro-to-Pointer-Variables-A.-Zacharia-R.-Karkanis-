/*
 * Program semp1p3.c from the seminar of the 6th of November, 2018.
 *
 * A similar exercise was presented by Athena Zacharia.
 *
 * Programming Language: ISO/IEC 9899:1990
 *
 * Author: Rafail Karkanis
 * e-mail: rkarkanis@uth.gr
 */

#include <stdio.h>

/* Function prototypes */
void sad_swap(int a, int b);
void cool_swap(int *a, int *b);
void risky_swap(int *a, int *b);

/*
 * main: Calls sad_swap, cool_swap, risky_swap
 *       and prints their effects to x, y.
 */
int main(void)
{
    int x = 5, y = 2;

    printf("\nSay we have the following point:\n");
    printf("(x, y) = (%d, %d)", x, y);
    
    
    sad_swap(x, y);
    printf("\n\nAfter using sad_swap(x, y): \n");
    printf("(x, y) = (%d, %d)", x, y);

    /* Note I am using the address operator (&) to pass the address of x, y */
    cool_swap(&x, &y);
    printf("\n\nAfter using cool_swap(&x, &y): \n");
    printf("(x, y) = (%d, %d)", x, y);

    printf("\n\nYep, the pointers did it.\nThey swapped the stubborn (x, y)");
    printf("\n\n");
    
    risky_swap(&x, &y);
    printf("\n\nAfter using risky_swap(&x, &y): \n");
    printf("(x, y) = (%d, %d)", x, y);

    printf(                                                             "\n\n"
           "What would happen if x + y"                                   "\n"
           "were more than an int variable can store?"                    "\n"
           "Try it."                                                      "\n"
           "Include the limits.h library and use the macro INT_MAX"       "\n"
    );


    return 0;

}
    
/* 
 * sad_swap: Tries to swap the values of two int variables.
 *
 *           Sadly, a, b, are local int variables
 *           which store the values of x, y.
 *           Not their addresses.
 *           Thus, any change in a, b, doesn't affect x, y.
 */ 
void sad_swap(int a, int b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;
}

/* 
 * cool_swap: Swaps the values of two int variables.
 * 
 *            *a, *b, are also local variables; Local pointer variables.
 * 
 *            By using pointer variables we store the addresses of x, y.
 *            Any change in *a, changes the object a is pointing to.
 *            Any change in *b, changes the object b is pointing to.
 *
 *            No wonder * is the "indirection" operator.
 *            We indirectly (e.g. by using *a, an alias of x)
 *            affect the values of the x, y!
 *            So, their scope means little.
 */
void cool_swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
}

/*
 * risky_swap: Swaps the values of two variables.
 *
 *              Risk of buffer overflow.
 *              How can I fix it?
 */
void risky_swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}
