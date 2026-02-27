#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint64_t des1(uint64_t text, uint64_t keys[6]){
//Permutation
	uint64_t text2 = 0;
	printf("\nInput Text\n");
	bit_disp(text,64);
	uint16_t iip[64] = {40, 8, 48, 16, 56, 24, 64, 32,
			39, 7, 47, 15, 55, 23, 63, 31,
			38, 6, 46, 14, 54, 22, 62, 30,
			37, 5, 45, 13, 53, 21, 61, 29,
			36, 4, 44, 12, 52, 20, 60, 28,
			35, 3, 43, 11, 51, 19, 59, 27,
			34, 2, 42, 10, 50, 18, 58, 26,
			33, 1, 41, 9, 49, 17, 57, 25};

	uint16_t IP[64] = {58, 50, 42, 34, 26, 18, 10, 2,
			60, 52, 44, 36, 28, 20 ,12, 4,
			62, 54, 46, 38, 30, 22, 14, 6,
			64, 56, 48, 40, 32, 24, 16, 8,
			57, 49, 41, 33, 25, 17, 9, 1,
			59, 51, 43, 35, 27, 19, 11, 3,
			61 ,53, 45, 37, 29, 21, 13, 5,
			63, 55, 47, 39, 31, 23, 15, 7};

	for (uint16_t j = 0; j < 64; j++){
		if ((1L << (iip[j]-1)) & ((uint64_t)text)){
			text2 |= 1L << j;
		}
	}
	bit_disp(text2,64);

	//Splitting
	uint32_t left = 0;
	uint32_t right = 0;
	for (uint16_t j = 0; j < 64; j++){
		if (((1L << j) & text2) && (j < 32)) {
			left |= 1L << j;
		}
		else if ((1L << j) & text2){
			right|= 1L << (j-32);
		}
	}

	printf("\nLeft and Right Seperation Respectively\n ");
	bit_disp(left,32);
	bit_disp(right,32);

	//All Rounds before IIP
	uint32_t tmp = 0;
	for (uint16_t j = 0; j < 6; j++){
		tmp = right;
		right = bit_addition(left,function(right,keys[j]));
		left = tmp;
	}

	//Joining
	text2 = 0;
	for (uint16_t j = 0; j < 64; j++){
		if (((1L << j) & right) && (j < 32)){
			text2 |= 1L << j;
		}

		else if (((1L << (j-32)) & left) && (j >= 32)){
			text2 |= 1L << j;
		}					
	}

	printf("\nRight, Left and text 2 in order of joining\n");
	bit_disp(right, 32);
	bit_disp(left, 32);
	bit_disp(text2, 64);

	//Inverse Permutation
	text = 0;
	for (uint16_t j = 0; j < 64; j++){
		if ((1L << (IP[j]-1)) & text2){
			text |= 1L << j;
		}
	}
	printf("\nInverse Permutation\n");

	bit_disp(text,64);
	return text;
}

uint64_t des(uint64_t text, uint64_t keys[6]){
//Permutation
	uint64_t text2 = 0;
	printf("\nInput Text\n");
	bit_disp(text,64);
	uint16_t IP[64] = {58, 50, 42, 34, 26, 18, 10, 2,
			60, 52, 44, 36, 28, 20 ,12, 4,
			62, 54, 46, 38, 30, 22, 14, 6,
			64, 56, 48, 40, 32, 24, 16, 8,
			57, 49, 41, 33, 25, 17, 9, 1,
			59, 51, 43, 35, 27, 19, 11, 3,
			61 ,53, 45, 37, 29, 21, 13, 5,
			63, 55, 47, 39, 31, 23, 15, 7};

	for (uint16_t j = 0; j < 64; j++){
		if ((1L << (IP[j]-1)) & ((uint64_t)text)){
			text2 |= 1L << j;
		}
	}
	bit_disp(text2,64);

	//Splitting
	uint32_t left = 0;
	uint32_t right = 0;
	for (uint16_t j = 0; j < 64; j++){
		if (((1L << j) & text2) && (j < 32)) {
			left |= 1L << j;
		}
		else if ((1L << j) & text2){
			right|= 1L << (j-32);
		}
	}

	printf("\nLeft and Right Seperation Respectively\n ");
	bit_disp(left,32);
	bit_disp(right,32);

	//All Rounds before IIP
	uint32_t tmp = 0;
	for (uint16_t j = 0; j < 6; j++){
		tmp = right;
		right = bit_addition(left,function(right,keys[j]));
		left = tmp;
	}

	uint16_t iip[64] = {40, 8, 48, 16, 56, 24, 64, 32,
			39, 7, 47, 15, 55, 23, 63, 31,
			38, 6, 46, 14, 54, 22, 62, 30,
			37, 5, 45, 13, 53, 21, 61, 29,
			36, 4, 44, 12, 52, 20, 60, 28,
			35, 3, 43, 11, 51, 19, 59, 27,
			34, 2, 42, 10, 50, 18, 58, 26,
			33, 1, 41, 9, 49, 17, 57, 25};
	//Joining
	text2 = 0;
	for (uint16_t j = 0; j < 64; j++){
		if (((1L << j) & right) && (j < 32)){
			text2 |= 1L << j;
		}
		else if (((1L << (j-32)) & left) && (j >= 32)){
			text2 |= 1L << j;
		}					
	}

	printf("\nRight, Left and text 2 in order of joining\n");
	bit_disp(right, 32);
	bit_disp(left, 32);
	bit_disp(text2, 64);

	//Inverse Permutation
	text = 0;
	for (uint16_t j = 0; j < 64; j++){
		if ((1L << (iip[j]-1)) & text2){
			text |= 1L << j;
		}
	}
	printf("\nInverse Permutation\n");
	
	bit_disp(text,64);
	return text;
}

