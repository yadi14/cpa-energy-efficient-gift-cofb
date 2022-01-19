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
 uint8_t Q3 = 0x02;
 uint8_t sQ1K = 0x00;
 uint8_t sQ2K = 0x00;
 uint8_t sQ3K = 0x00;

for(uint16_t i = 0; i < 16; i++) {
	Q1 = i;
	for(uint16_t j = i+1; j < 16; j++) {
		Q2 = j;
		for(uint16_t m = j+1; m < 16; m++) {
		Q3 = m;
		FILE *fpM;
		string filename ("Q1Q2Q3_simplfy/"+to_string(Q1) + "_" + to_string(Q2) + "_" + to_string(Q3) +".txt");
		fpM = fopen(filename.c_str(),"w");
		for(uint16_t k = 0; k < 16; k++) {
			key = k;
			sQ1K = sbox[Q1^key];
			sQ2K = sbox[Q2^key];
			sQ3K = sbox[Q3^key];
			fprintf(fpM,"%0*x %0*x\n",1,sQ1K^sQ2K,1,sQ1K^sQ3K);
		}
		fclose(fpM);
	}
	}
  
}
  return 0;
}
