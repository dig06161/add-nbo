#include <stdio.h>
#include <stdint.h>
#include <cstring>

int main(int argc, char* argv[]) {
    uint32_t agm1=1, agm2=1, agm3=1;
	unsigned char buf[4] = {0};

	if (argc != 3) {printf("please, check file!");	return 1;}

	FILE* fp = fopen(argv[1], "rb");	

	if (fp == NULL) {printf("please, cheack file!");  return 1;}

	fread(buf, 4, 1, fp);
	agm1 = ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | (buf[3]));

	fp = fopen(argv[2], "rb");
	memset(buf, 0, 4);

	if (fp == NULL) {printf("please, cheack file!");return 1;}
	fread(buf, 4, 1, fp);
	agm2 = ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | (buf[3]));

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", agm1,agm1,agm2,agm2,agm1+agm2,agm1+agm2);

	return 0;
}