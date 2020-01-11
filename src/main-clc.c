// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/clc
// date: Jan 7, 2019
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019-2020 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

//              0    1    2    3    4
char expr[] = {'+', '-', '=', '*', '/'};

void add_char_to_string(char* s, char c) {
  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';
}

int is_int(int num) {
  if (num >= 0 && num <= 9) {
    return(0);
  }

  return(1);
}

int is_expr(char in) {
  int match = 1;

  for (int e = 0; e < 4; e++) {
    if (in == expr[e]) {
      match = 0;
    }
  }

  return(match);
}

int is_vallid_input(char in) {
  if (is_expr(in) == 0) {
    return(0);
  }

  if (is_int(in - '0') == 0) {
    return(0);
  }

  return(1);
}

int calc_num(int action, int first, int second) {
  int ret = -1;

//  if (first == 0) return(0);
  if (first == 0) return(second);

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

int main(int argc, char** argv) {
  char *buffer;

  size_t n = 1024;

  buffer = malloc(n);

  size_t cr = getline(&buffer, &n, stdin);
  if ((buffer)[cr - 1] == '\n') {
    buffer[cr - 1] = '\0';
  }

  set_debug(0);
  print_debugf("stdin: %s\n", buffer);

  int action = 0;
  int match = 0;
  int full_ex = 0;

  int s = 0;
  int ret = 0;

  for (int i = 0; i < cr-1; i++) {
    if (buffer[i] == ' ') continue;
    if (is_vallid_input(buffer[i]) != 0) {
      fprintf(stderr, "%s: %c: Invalid input\n", argv[0], buffer[i]);
      return(1);
    }
    for (int e = 0; e < 4; e++) {
      if (buffer[i] == expr[e]) {
        action = e;
        match = 1;
      }
    }

    if (match == 1) {
      print_debugf("Action: %c\n", expr[action]);
      match = 0;
      full_ex++;
      s = 0;
    } else {
      s *= 10;
      s += buffer[i] - '0';
      print_debugf("NUM: %d\n", s);
      int jump_c = 1;
      if (buffer[i+1] == ' ') jump_c = 2;
      if (is_expr(buffer[i+jump_c]) == 0 || buffer[i+jump_c] == '\0') {
        print_debugf("Calcing: %d %c %d\n", ret, expr[action], s);
        ret = calc_num(action, ret, s);
      }
    }
  }

  printf("%d\n", ret);

  return(0);
}

// vim: tabstop=2 shiftwidth=2 expandtab autoindent softtabstop=0
