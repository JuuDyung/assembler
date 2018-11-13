#include "myas.h"

char* examine(char* t){
	char *temp=NULL;
	
	if(t[0]=='%')
		temp="reg";
	else if(t[0]=='$')
		temp="imm";
	else if((t[0]=='0') && (t[1]=='x'))
		temp="mem";
	else if((t[0]=='(') && (t[1]=='%') && (t[strlen(temp)-1]==')'))
		temp="mem";
	else if((t[0]=='-') && (t[1]=='0')&& (t[2]=='x'))
		temp="mem";
	else
		temp="error";
	return temp;
}
int is_valid(char *op, char *args)
{

	char tmp[256];

	strcpy(tmp,args);

	Type src;
	Type dst;
	Type src_;
	Type dst_;

	//if opcode is not ""
	if(strcmp(op,"mov")!=0)
		return 0;

	//token
	src.opcode=strtok(tmp,",");
	dst.opcode=strtok(NULL,"\n");
	
	//if NULL
	if((src.opcode==NULL)||(dst.opcode==NULL))
		return 0;
	
	//examine
	src_.opcode=examine(src.opcode);
	dst_.opcode=examine(dst.opcode);
	
	//filtering
	if((strcmp(src_.opcode,"error")==0)&&(strcmp(dst_.opcode,"error")==0))
		return 0;

	if((strcmp(src_.opcode,"mem")==0)&&(strcmp(dst_.opcode,"mem")==0))
		return 0;
	else if((strcmp(src_.opcode,"imm")==0)&&(strcmp(dst_.opcode,"imm")==0))
		return 0;
	else if(strcmp(dst_.opcode,"imm")==0)
		return 0;
	
	return 1;
}
