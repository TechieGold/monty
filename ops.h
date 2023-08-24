#ifndef OPS_H
#define OPS_H

#include "monty.h"

typedef void (*op_callback)(stack_t **stack, unsigned int line_number);



void ops_add_op(char *code, op_callback callback);

op_node_t *ops_search(const char *opcode);


void op_push(stack_t **stack, unsigned int line_number);

void op_pall(stack_t **stack, unsigned int line_number);


#endif
