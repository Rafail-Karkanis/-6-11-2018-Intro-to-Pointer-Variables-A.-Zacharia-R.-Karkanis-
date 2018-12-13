/*
 * Program semp1p1.c from the seminar of the 6th of November, 2018.
 *
 * A similar exercise was presented by Athena Zacharia.
 *
 * Programming Language: ISO/IEC 9899:1990
 *
 * Author: Rafail Karkanis
 * e-mail: rkarkanis@uth.gr
 */

#include <stdio.h>

/*
 * main: Prints the store location, and value of the pointer p
 *       which points to i.
 *       Then the value of the variable that the pointer p points to.
 *
 *       Prints the store location, and value of i.
 *
 *       Prints *&p, &*p, *&i to show that the address
 *       and indirection operator cancel each other in pointer variables.
 */
int main(void)
{
    int i = 5;     /* Initializing i with 5 */
    int *p;        /* Declaring pointer variable p. */

    p = &i;        /* p now points to i */

    /* 
     * Had I skipped p = &i;
     * The pointer p would point nowhere in particular
     *
     * A latter indirection of such a pointer (an uninitialized one)
     * would cause undefined behavior.
     */

    printf("\n%-5s%8X\t%s", "&p:", &p, "store location of p");
    printf("\n%-5s%8X\t%s", " p:", p, "value of p");  
    printf("\n%-5s%8d\t%s", "*p: ", *p,
                           "value of the (integer) variable pointed to by p");

    printf("\n%-5s%8X\t%s", "&i: ", &i, "store location of i");
    printf("\n%-5s%8d\t%s", " i: ", i, "value of i");


    /* 
     * Note that I am using:
     *
     * %X    (x or X: lower or capital hexadecimal value)
     *
     * to print the address locations.
     * You could have also used:
     *
     * %p    (p: pointer)
     *
     * To do the same.
     */


    printf(                                                           "\n\n\n"
           "Notice the similarities."                                     "\n"
           "*i would be an illegal indirection."
    );

    printf(                                                           "\n\n\n"
           "For the mathematically inclined:"                             "\n"
    );

    printf("\n%-5s%8X\t%s", "*&p:", *&p, "value of p");
    printf("\n%-5s%8d\t%s", "*&i: ", *&i, "value of i");
    printf("\n%-5s%8X\t%s", "&*p:", &*p, "value of p");   /* This is tricky */

    printf(                                                             "\n\n"
           "- Why is &*p legal? "                                         "\n"
           "- Why would &*i be illegal?"                                  "\n"
    );

    /* 
     * &*p == &(*p)
     * 
     * since the address operator (&) and the indirection operator (*)
     * have the same precedence, but right associativity.
     * 
     * &(*p) == &i
     * 
     * since p points to i.
     * 
     * This was the tricky part.
     * You could have thought that since printf("%d", *p) produces  5
     * which is the value of i,
     * &(*p) == &5
     * which would be an " '&' on constant " error.
     * 
     * *p serves as an alias of i!
     * When we printed *p, it printed the rvalue of i,
     * whilst when the compiler tried to assess the value of the expression
     * &(*p) it used the lvalue of i!
     * 
     * Consider reading the «A TUTORIAL ON POINTERS AND ARRAYS IN C»
     * by Ted Jensen which is included in the material posted here
     * for an explanation of lvalues and rvalues.
     * 
     * So:
     * &*p == &(*p) == &i == p
     * 
     * The address (&) and indirection operator (*) do cancel each other
     * when used on a pointer variables.
     */


    return 0;
}

