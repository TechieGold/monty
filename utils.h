#ifndef UTILS_H
#define UTILS_H

#include "monty.h"


char *_strdup(char *str);

void sanitize_input(char *input);

void trim_input(char *input);

char **tokenize_args(char *line, int *num_tokens);

int is_blank_str(const char *string);

int check_digit(const char *number);

void list_push_front(stack_t **stack, int n);

void list_push_back(stack_t **stack, int n);

void list_pop_front(stack_t **stack);

void list_pop_back(stack_t **stack);




#endif
