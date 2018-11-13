#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// complete this header file

typedef struct Type{
	char* opcode;
	
}Type;

int instr_trans(char *op, char *args, char* mcode);
char* examine(char* t);
int is_valid(char *op, char *args);
