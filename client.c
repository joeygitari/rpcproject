// RPC tool project in C
// P15/139992/2020 GITARI JOAN WANJIRU
// P15/140890/2020 NJIHIA MAUREEN WANJIKU

// client side

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

// functions for the remote procedures.

int *proc_1_1(int, CLIENT *);
float *proc_2_1(int, char *, CLIENT *);
char **proc_3_1(int, CLIENT *);

int main(int argc, char *argv[])
{
    printf("Client started\n");
    CLIENT *cl;
    int param1 = 10;
    int param2 = 20;
    char *param2_string = "2.5";
    int param3 = 30;

    // client handle for the server 
    cl = clnt_create(argv[1], ADD_PROG, ADD_VERS, "tcp");
    if (cl == NULL)
    {
        printf("error: could not connect to server.\n");
        exit(1);
    }

    // call procedure 1
    int procOneResult = *proc_1_1(param1, cl);
    printf("Result from procedure 1: %d\n", procOneResult);

    // call procedure 2 
    float procTwoResult = *proc_2_1(param2, param2_string, cl);
    printf("Result from procedure 2: %f\n", procTwoResult);

    // call procedure 3 
    char *result_string = *proc_3_1(param3, cl);
    printf("Result from procedure 3: %s\n", result_string);

    // clean up and exit 
    clnt_destroy(cl);
    return 0;
}