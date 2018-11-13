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
	int type;
	char opcode[10];
	swtch(type){
		case 1:{//reg to reg
			strcpy(opcode,"89");
			break;
		}
		case 2:{//mem to reg sib
			strcpy(opcode,"8b");
			break;
		}
		case 3:{//mem to reg dis
			strcpy(opcode,"8b");
			break;
		}
		case 4:{//mem to reg eax
			strcpy(opcode,"a1");
			break;
		}
		case 5:{//reg to mem
			strcpy(opcode,"a3");
			break;
		}
		case 6:{//immediate to reg
			strcpy(opcode,"b8");
			break;
		}
		default:{
			strcpy(opcode,"ERR");
			break;
		}
	return 1;	
}
