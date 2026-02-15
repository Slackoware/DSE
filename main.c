#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
int main(){
	uint64_t num1 = 257;
	keyshed(1,num1);
	uint32_t pc1[] = {57,49,41,33,25,17,9,
                        1,58,50,42,34,26,18,
                        10,2,59,51,43,35,27,
                        19,11,3,60,52,44,36,
                        63,55,47,39,31,23,15,
                        7,62,54,46,38,30,22,
                        14,6,61,53,45,37,29,
                        21,13,5,28,20,12,4};
	uint64_t key = 0;
	
	//Algo Test	
	for ( uint16_t j  = 0; j < 56; j++){
                        if (num1 & (1L << (pc1[j]-1))){
                                key |= 1L << j;
                        }
                }
	bit_disp(num1);
	bit_disp(key);
	return 0;
}
