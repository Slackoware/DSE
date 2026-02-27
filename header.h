#ifndef guard
#define guard
#include <stdint.h>
void bit_disp(uint64_t arg, uint8_t size);
uint64_t keyshed(uint64_t key1, uint64_t keys[6]);
uint64_t pc_2(uint32_t c, uint32_t d, uint32_t pc2[46]);
uint32_t function(uint32_t r, uint64_t key);
uint64_t bit_addition(uint64_t a, uint64_t b);
uint64_t des1(uint64_t text, uint64_t keys[6]);
uint64_t des(uint64_t text, uint64_t keys[6]);

#endif
