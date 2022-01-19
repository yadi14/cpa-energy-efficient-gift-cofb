#include <iostream>
#include <cstdint>
#include <cstring>
#include <bitset>
// #include <fstream>
#include <cstdio>

using namespace std;
static uint8_t sbox[16]={//FOR Gift
0x01,0x0A,0x04,0x0C,0x06,0x0F,0x03,0x09,0x02,0x0D,0x0B,0x07,0x05,0x00,0x08,0x0E};

int main() {
 uint8_t key = 0x00;
 uint8_t Q1 = 0x00;
 uint8_t Q2 = 0x01;
 uint8_t sQ1K = 0x00;
 uint8_t sQ2K = 0x00;

for(uint16_t i = 0; i < 16; i++) {
	Q1 = i;
	for(uint16_t j = i+1; j < 16; j++) {
		Q2 = j;
		FILE *fpM;
		string filename ("Q1Q2_verbose/"+to_string(Q1) + "_" + to_string(Q2) + ".txt");
		fpM = fopen(filename.c_str(),"w");
		fprintf(fpM,"Q1 = %0*x, Q2 = %0*x\n\n", 1,Q1,1,Q2);
		for(uint16_t k = 0; k < 16; k++) {
			key = k;
			fprintf(fpM,"k = %0*x\t", 1,key);
			sQ1K = sbox[Q1^key];
			sQ2K = sbox[Q2^key];
			fprintf(fpM,"s(Q1^k) = %0*x, s(Q2^k) = %0*x, s(Q1^k)^s(Q2^k) = %0*x\n\n", 1,sQ1K,1,sQ2K, 1, sQ1K^sQ2K);
		}
		fprintf(fpM,"end\n");
		fclose(fpM);
	}
  
}
  return 0;
}
