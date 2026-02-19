#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
void bit_disp(uint64_t arg, uint8_t size){
	uint8_t bit;
	uint16_t i = 1;
	for (uint16_t j = size; j > 0; j--, i++){
		bit = 0;
		if (arg & (1L<<(j-1))){
			bit = 1;
		}
		printf("%d",bit);
		if ((i%8) == 0){
			printf("\t");
		}
		
	} 
	printf("\n");
}

uint64_t keyshed(uint64_t key1, uint64_t keys[6]){
	uint32_t pc1[] = {57,49,41,33,25,17,9,
			1,58,50,42,34,26,18,
			10,2,59,51,43,35,27,
			19,11,3,60,52,44,36,
			63,55,47,39,31,23,15,
			7,62,54,46,38,30,22,
			14,6,61,53,45,37,29,
			21,13,5,28,20,12,4};

	uint32_t pc2[] = {14,17,11,24,1,5,
			3,28,15,6,21,10,
			23,19,12,4,26,8,
			16,7,27,20,13,2,
			41,52,31,37,47,55,
			30,40,51,45,33,48,
			44,49,39,56,34,53,
			46,42,50,36,29,32};
	uint64_t key2 = 0;

	//PC-1
	for ( uint16_t j  = 0; j < 56; j++){
		if (key1 & (1L << (pc1[j]-1))){
			key2 |= 1L << j;
		}
	}
	bit_disp(key1,64);
	bit_disp(key2,64);

	//Initial Seperation //28 each	
	uint32_t C = 0;
	uint32_t D = 0;
	
	for (uint16_t j = 0; j < 28; j++){
		if (key1 & ( 1L << (pc1[j]-1) )){
			C |= 1L << j;
		}
	}
	for (uint16_t j = 0; j < 28; j++) {
		if (key1 & (1L << (pc1[j+28]-1) )){
			D |= 1L << j;
		}
	}
	printf("\n");
	bit_disp(C,32);
	bit_disp(D,32);
	
	//First Iteration
	//1
	C = C << 1;
	D = D << 1;
 	keys[0] = pc_2(C, D, pc2);

	//2
	C = C << 1;
	D = D << 1;
	keys[1] = pc_2(C, D, pc2);

	//3
	C = C << 2;
	D = D << 2;
	keys[2] = pc_2(C, D, pc2);
	
	//4
	C = C << 2;
	D = D << 2;
	keys[3] = pc_2(C, D, pc2);

	//5
	C = C << 2;
	D = D << 2;
	keys[4] = pc_2(C, D, pc2);
		
	
	

	return 0;
}

uint64_t pc_2(uint32_t c, uint32_t d, uint32_t pc2[46]){
	uint64_t key = 0;
	uint64_t ret_key = 0;
	for (uint16_t j = 0; j < 28; j++){
		if (c & (1L << j)){
			key |= 1L << j;
		}
	} 

	for (uint16_t j = 0; j < 28; j++){
		if (d & (1L << j)){
			key |= 1L << (j+28);
		}
	}
	printf("\n\nCombined PC 2\n");
	bit_disp(key, 64); //48 bits
	for (uint16_t j = 0; j < 48; j++){
		if ( key & (1L << (*(pc2 + j)-1))){
			ret_key |= 1L << j;	
		}
	}
	printf("PC_2 Applied \n");
	bit_disp(ret_key,64);
	return ret_key;
}








