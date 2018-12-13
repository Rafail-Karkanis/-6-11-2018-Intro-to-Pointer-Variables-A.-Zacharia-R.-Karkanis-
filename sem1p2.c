/*
 * Program semp1p2.c from the seminar of the 6th of November, 2018.
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
 *       which points to k.
 *       Then the value of the variable that pointer p points to.
 *
 *       Prints the store location, and value of k.
 *
 *       Changes the value of *p (an alias for k), and shows its results
 *       by printing the aforementioned information again.
 */
int main(void)
{
    int k = 5;
    int *p = &k;

    printf("\n%-5s%8X\t%s", "&p:", &p, "store location of p");
    printf("\n%-5s%8X\t%s", " p:", p, "value of p");  
    printf("\n%-5s%8d\t%s", "*p: ", *p,
                           "value of the (integer) variable pointed to by p");
    
    printf("\n%-5s%8X\t%s", "&k: ", &k, "store location of k");
    printf("\n%-5s%8d\t%s", " k: ", k, "value of k");


    *p = 28;

    /* 
     * Note that in:
     * 
     * *p = 28;
     * 
     * The asterisk (*) is used as the indirection operator
     * 
     * Yet in:
     * 
     * int *p = &k;
     * 
     * The * is simply part of the declaration.
     * It is punctuation, not an operator.
     * 
     * int *p = &k;
     * 
     * is equivalent to:
     * 
     * int *p;
     * p = &k;
     * 
     */


    printf(                                                             "\n\n"
           "*p = 28;"
                                                                        "\n\n"
    );

    printf("\n%-5s%8X\t%s", "&p:", &p, "store location of p");   
    printf("\n%-5s%8X\t%s", " p:", p, "value of p");  

    printf("\n%-5s%8d\t%s", "*p: ", *p,
                           "value of the (integer) variable pointed to by p");

    printf("\n%-5s%8X\t%s", "&k: ", &k, "store location of k");
    printf("\n%-5s%8d\t%s", " k: ", k, "value of k");

    

    printf(                                                             "\n\n"
           "I have changed (indirectly) the value of k via p."
                                                                          "\n"
    );

    return 0;
}

