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

    char *tot;
    tot = (char*) malloc(8);

    char action = '\0';

    int b_stop = 0;

    int ret = 0;

    int f = 0;

    int c_num = 0;

    for (int i = 0; i < ex_len; i++) {
    	printf("NUM: %c\n", buffer[i]);


    	int exp_len = strlen(expr);
    	for (int e = 0; e < exp_len; e++) {
    	    if (buffer[i] == expr[e]) {
//    	        printf("match\n");
    	        action = expr[e];
    	        strcat(tot, first);

                f = atoi(first);
                c_num = e;

    	        //add_char_to_string(tot, action);
    	        first[0] = '\0';
    	        b_stop = 1;


    	    }
    	    if (b_stop != 0) break;
    	}
    	if (b_stop != 0) {
    	    b_stop = 0;
    	    continue;
    	}

    	add_char_to_string(first, buffer[i]);

    	printf("FIRST: %s\n", first);

    }

    int l = atoi(first);

    if (c_num == 0) {
        ret = f + l;
    } else if (c_num == 1) {
        ret = f - l;
    } else if (c_num == 2) {
        if (f == l) {
            return(0);
        } else {
            return(1);
        }
    } else if (c_num == 3) {
        ret = f * l;
    } else if (c_num == 4) {
        ret = f / l;
    }

    printf("\nfull: %s\n", tot);
    printf("c = %d\n", c_num);
    printf("f = %d\n", f);
    printf("a = %c\n", action);
    printf("l = %d\n", l);
    printf("ret: %d\n", ret);

    return(0);
}

//
// End main-clc.c
//
