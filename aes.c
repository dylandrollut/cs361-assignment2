#include <stdio.h>

void keyExpansion(){

}

void addRoundKey(){

}

void subBytes(){

}

void shiftRows(){

}

void mixColumns(){
	
}

void encrypt(){

	keyExpansion();

	// initial round
	addRoundKey();

	int numRounds = 1;

	for(int i = 0; i < numRounds; i++){
		subBytes();
		shiftRows();
		mixColumns();
		addRoundKey();
	}

	//final round
	subBytes();
	shiftRows();
	addRoundKey();
}

int main(){

	char *message = "Hello, World!!!!";
	char key[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
}