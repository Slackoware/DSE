#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
void bit_disp(uint64_t arg, uint8_t size){
	uint8_t bit;
	uint16_t i = 1;
	for (uint16_t j = 0; j < (size); j++, i++){
		bit = 0;
		if (arg & (1L<<j)){
			bit = 1;
		}
		printf("%d",bit);
		if ((i%8) == 0){
			printf("\t");
		}
		
	} 
	printf("\n");
}

uint64_t keyshed(uint16_t n, uint64_t key1){
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
	D = D >> 4 ; //Bug of sorts
	printf("\n");
	bit_disp(C,32);
	bit_disp(D,32);


	return 0;
	

}
