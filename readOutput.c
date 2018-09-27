#include <stdio.h>
#include <string.h>

int main(){
	FILE *outFile;

	outFile = fopen("output.txt", "rb");
	if(!outFile){
		perror("Error opening output file");
		return -1;
	}

	unsigned char buf[17];

	int read = 0;
	while((read = fread(buf, 1, 16, outFile)) > 0){
		for(int i = 0; i < read; i++){
			printf("%x ", buf[i]);
		}
		printf("\n");
	}

	fclose(outFile);
}