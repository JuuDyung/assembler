#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");

	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	//char tmp[256];
	//char opcode[10];
	//char *src,*des;

	type src_;
	type dst_;

	//src=strtok(tmp,",");
	//des=strtok(NULL,",");
	
	if(strcmp(src_.opcode,"reg")==0){
		//case 1(reg to reg)
		if(strcmp(dst_.opcode,"reg")==0)
			strcpy(mcode,"89");
		//case 5(reg to mem)
		if(strcmp(dst_.opcode,"mem")==0)
			strcpy(mcode,"a3");
	}
	else if(strcmp(src_.opcode,"mem")==0){
		//case 2(mem to reg sib)
		if(src_.opcode[0]=='(') strcpy(mcode,"8b");

		//case 3(mem to reg dis)
		else if((src_.opcode[0]=='-')&&(strchr(src_.opcode,"(")!=NULL)) strcpy(mcode,"8b");

		//case 4(mem to reg eax)
		else if(src_.opcode[0]=='0') strcpy(mcode,"a1);
	}
 
	else if(strcmp(src_.opcode,"imm")==0){
		//case 6(immediate to reg)
		if(strcmp(dst_.opcode,"%eax")==0) strcpy(mcode,"b8");
		else if(strcmp(dst_.opcode,"%ecx")==0) strcpy(mcode,"b9");
		else if(strcmp(dst_.opcode,"%edx")==0) strcpy(mcode,"ba");
		else if(strcmp(dst_.opcode,"%ebx")==0) strcpy(mcode,"bb");
		else if(strcmp(dst_.opcode,"%esp")==0) strcpy(mcode,"bc");
		else if(strcmp(dst_.opcode,"%ebp")==0) strcpy(mcode,"bd");
		else if(strcmp(dst_.opcode,"%esi")==0) strcpy(mcode,"be");
		else if(strcmp(dst_.opcode,"%edi")==0) strcpy(mcode,"bf");
	}

	return 1;	
}
