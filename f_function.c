#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
uint32_t function(uint32_t r, uint64_t key){

	uint16_t e[48] = {3,1,2,3,4,5,
			4,5,6,7,8,9,
			8,9,10,11,12,13,
			12,13,14,15,16,17,
			16,17,18,19,20,21,
			20,21,22,23,24,25,
			24,25,26,27,28,29,
			28,29,30,31,32,1};

	uint64_t ret_val = 0;
	for (uint16_t j = 0; j < 48; j++){
		if ((1L << (e[j]-0)) & r){
			ret_val |= 1l<<j;
		} 
	}
	printf("E Test\n");
	bit_disp(r,32);
	bit_disp(ret_val, 64);
	printf("\n\n");
	printf("\n Bitwise Addition\n");
	bit_disp(ret_val,64);
	bit_disp(key,64);
	bit_disp(bit_addition(ret_val, key),64);	
	
	return 0;
}

uint64_t bit_addition(uint64_t a, uint64_t b){
	uint64_t carry;
	while (b != 0){
		carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
	
}
