#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"


static char S[8][64] = {{
    /* S1 */
    14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7, 
     0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8, 
     4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0, 
    15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
},{
    /* S2 */
    15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10, 
     3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5, 
     0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15, 
    13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
},{
    /* S3 */
    10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8, 
    13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1, 
    13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
     1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
},{
    /* S4 */
     7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15, 
    13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9, 
    10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
     3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
},{
    /* S5 */
     2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9, 
    14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6, 
     4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14, 
    11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
},{
    /* S6 */
    12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
    10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
     9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
     4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
},{
    /* S7 */
     4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
    13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
     1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
     6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
},{
    /* S8 */
    13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
     1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
     7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
     2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11

}};


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
	printf("RETURN VALUE \n");
	ret_val = bit_addition(ret_val, key);
	bit_disp(ret_val,64);	
	//Spliting Added Value

	uint8_t bitz[8]= {0,0};
	uint16_t i = 0, b = 0;
	for (uint16_t j = 0; j < 48; j++, b++){
	    if ((j % 6) == 0){
	        ++i;
	        b = 0;
	    }

	    if ((1L << j)&ret_val){
	        bitz[i-1] |= 1L << b; 
	    }
	}

	printf("6Bits Seperation\n");

	for (uint8_t j = 0; j < 8; j++){
		printf("%d-- ", j+1);
		bit_disp(bitz[j],6);
	}

	

	//S Permutation into 4 bits

	uint16_t first = 0;

	uint16_t second = 0;

	for (uint16_t j = 0; j < 8; j++){
	    //For the First index
	    if (1L & (bitz[j])){
	        first |= 1L;
	    }
	    if ((1L << 5) & (bitz[j])){
	        first |= 1L << 1;
	    }
	    //For the second index
	    uint8_t c = 1;

	    while (c < 5){
	        if ((1L<<c) & bitz[j]){
	            second |= 1L << (c-1);
	        }
	        ++c;
	    }

		printf("%d-- \n", j+1);

	    bit_disp(first, 2);
	    bit_disp(second, 4);
	    bitz[j] = S[j][(first * 15)+(second)];	
	    first = 0;
	    second = 0;
	    }

	printf("Permetued blocks\n");
	for (uint8_t j = 0; j < 8; j++){
		printf("%d-- ",j+1);
		bit_disp(bitz[j],4);
	}

	//Combining everything back again

	uint32_t value = 0;
	uint16_t arr = 0, count = 0;
	for (uint16_t j = 0; j < 32; j++, count++){
		if (((j % 4) == 0) & (j > 0)){
			++arr;
			count = 0;
		}

		if ((1L << count) & bitz[arr]){
			value |= 1L << j;
		}
	}	
	bit_disp(value, 32);

	//Permutate the output

	uint16_t pc[32] = {16,7, 20, 21,
			29, 12, 28, 17,
			1, 15, 23, 26,
			5, 18, 31, 10,
			2, 8, 24, 14,
			32, 27, 3, 9,
			19, 13, 30, 6,
			22, 11, 4, 25};

	uint32_t rvalue = 0;

	for ( uint16_t j  = 0; j < 32; j++){

		if (value & (1L << (pc[j]-1))){

			rvalue |= 1L << j;

		}
	}
	bit_disp(rvalue,32);
	return rvalue;
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
