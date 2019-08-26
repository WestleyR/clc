// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/clc
// date: Aug 25, 2019
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

char expr[] = {'+', '-', '=', '*', '/'};

void add_char_to_string(char* s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

int calc_num(int action, int first, int second) {
    int ret = -1;

    if (action == 0) {
        ret = first + second;
    } else if (action == 1) {
        ret = first - second;
    } else if (action == 2) {
        // invalid action
        return(ret);
    } else if (action == 3) {
        ret = first * second;
    } else if (action == 4) {
        ret = first / second;
    }

    return(ret);
}

int main() {
    char *buffer;

    size_t n = 1024;

    buffer = malloc(n);

    size_t cr = getline(&buffer, &n, stdin);
    if ((buffer)[cr - 1] == '\n') {
        //(buffer)[cr - 1] = '\0';
        buffer[cr - 1] = '\0';
        cr--;
    }

    set_debug(0);
    print_debugf("stdin: %s\n", buffer);

    printf("OUT: %s\n", buffer);

    int ex_len = strlen(buffer);


    char *first;
    first = (char*) malloc(4);


    char action = '\0';


    int ret = 0;

    int ss = 0;

    int f = -1;

    int c_num = -1;
    int l_num = 10;

    int l = -1;

    for (int i = 0; i < ex_len; i++) {
        //    	printf("NUM: %c\n", buffer[i]);

        int exp_len = strlen(expr);
        for (int e = 0; e < exp_len; e++) {
            if (buffer[i] == expr[e]) {
                //    	        printf("match\n");
                action = expr[e];
                //    	        strcat(tot, first);

                c_num = e;

                if (l_num == 10) l_num = e;

                printf("EEENUM: %d\n", c_num);
                printf("EEELLL: %d\n", l_num);

                ss = 1;

                if (f == -1) {
                    f = atoi(first);
                    first[0] = '\0';
                } else {
                    l = atoi(first);
                    first[0] = '\0';
                }

                if ((f != -1) && (l != -1)) {
                    ret = calc_num(l_num, f, l);
//                    printf("FIRd: %d\n", f);
//                    printf("FIRl: %d\n", l);
                    f = ret;
                    l = -1;
//                    printf("CCC: %d\n", l_num);
                    first[0] = '\0';
                    l_num = 10;
//                    printf("RET: %d\n", ret);
                }
                ss = 1;
            }
        }


        if (ss != 0) {
            ss = 0;
            continue;
        }


        add_char_to_string(first, buffer[i]);


        //    	printf("FIRST: %s\n", first);

    }

    if (f != -1) ret = f;
    l = atoi(first);

    printf("first: %s\n", first);
    printf("fidddlll: %d\n", l);
    printf("fidddfff: %d\n", f);


    if (c_num == 0) {
        ret = ret + l;
    } else if (c_num == 1) {
        ret = ret - l;
    } else if (c_num == 2) {
        if (ret == l) {
            return(0);
        } else {
            return(1);
        }
    } else if (c_num == 3) {
        ret = ret * l;
    } else if (c_num == 4) {
        ret = ret / l;
    }

    printf("\n\n");

    printf("c = %d\n", c_num);
    printf("f = %d\n", f);
    printf("r = %d\n", ret);
    printf("a = %c\n", action);
    printf("l = %d\n", l);

    printf("ret: %d\n", ret);

    return(0);
}

//
// End main-clc.c
//
