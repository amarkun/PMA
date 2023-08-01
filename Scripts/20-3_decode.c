#include <stdio.h>
#include <string.h>

char PLAINTEXT[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char SUBCYPHER[] = "PLMOKNIJBUHVYGTFCRDXESZWAQzaqxswcdevfrbgtnhymjukilop";

int zDecodeDataA(char *data, int nDataLen){
	int i;
	if(data != 0){
		if(nDataLen != 0){
			char *pSC = &SUBCYPHER[0];
			char *pPT = &PLAINTEXT[0];
			char encCh;
			char decCh;
			i = 0;
			while(nDataLen != 0){
				encCh=*(data+i);
				for(int j = 0; j<52; j++){
					if(encCh == *(pSC + j)){
						decCh = *(pPT + j);
						*(data+i) = decCh;
					}
				}
				i++;
				nDataLen--;
			}
		}
		return 1;
	} else {
		return 0;
	}
}

int zDecodeDataB(char *data, int nDataLen){
	int i,j;
	char encCh, decCh;
	int nCypherLen = strlen(SUBCYPHER);
	for(i=0; i<nDataLen; i++){
		encCh = data[i];
		for(j=0; j<nCypherLen; j++){
			if(encCh == SUBCYPHER[j]){
				decCh = PLAINTEXT[j];
				data[i] = decCh;
			}
		}
	}
	return 1;
}

int main(int argc, char** argv) {
	int decoded;
	if (argc == 2) {
		char *data = argv[1];
		printf("Encoded: %s\n", data);
		//decoded = zDecodeDataA(data, strlen(data));
		decoded = zDecodeDataB(data, strlen(data));
		if(decoded){
			printf("Decoded: %s\n", data);
			return 0;
		}
	}
	return 1;
}