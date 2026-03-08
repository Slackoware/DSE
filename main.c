#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"


int main(){
	uint64_t num1 = 257777774545444555;
	uint32_t pc1[] = {57,49,41,33,25,17,9,
                        1,58,50,42,34,26,18,
                        10,2,59,51,43,35,27,
                        19,11,3,60,52,44,36,
                        63,55,47,39,31,23,15,
                        7,62,54,46,38,30,22,
                        14,6,61,53,45,37,29,
                        21,13,5,28,20,12,4};

	//Key Schedule
	uint64_t keys[16];
	key_sched(num1, keys);

	//F Function
	uint64_t r_keys[16];
	for (uint16_t j = 0, i = 15; j < 16; i--, j++){
		r_keys[j] = keys[i];
	}
	

	char z = 'z';
	uint64_t cipher1 = des((uint64_t)z, keys);
	uint64_t cipher2 = des(cipher1, r_keys);

	printf("Cipher Test\n");
	printf("%c \n",z);
	printf("%c\n",cipher1);
	printf("%c\n",cipher2);
	
//    printf("\n\nKeys \n");
//	for (uint8_t j = 0; j < 16; j++){
//		printf("%d-- ", j+1);
//		bit_disp(keys[j],48);
//	}

//	printf("\n\nReverse Keys \n");
//	for (uint8_t j = 0; j < 16; j++){
//		printf("%d-- ", j+1);
//		bit_disp(r_keys[j],48);
//	}

	return 0;
}

