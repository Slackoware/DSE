#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
void bit_disp(uint64_t bits){
	uint8_t bit;
	for (uint16_t j = 0; j < 64; j++){
		bit = 0;
		if (bits & (1L<<j)){
			bit = 1;
		}
		printf("%d",bit);
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
	printf("%d \n", sizeof(pc1));
	if (n == 1){
		for ( uint16_t j  = 0; j < 56; j++){
			if (key1 & (1L << (pc1[j]-1))){
				key2 |= 1L << j;
			}
		}
	}
	printf("%Lb \n",key1);
	bit_disp(key1);
	printf("%Lb \n",key2);
	bit_disp(key2);

	return 0;
	

}
