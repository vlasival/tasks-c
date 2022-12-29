#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t A, B, M, R, S;
uint32_t hashFunc(uint32_t x) {
	return (((A * x + B) % M) % R) / S;
}

uint32_t somehash(uint32_t key){
	key *= 0x45D9F3B;
	key = key ^ (key >> 16);
	return key;
}

int main() {
	int arr[32][32] = {0};
	scanf("%lld %lld %lld %lld %lld", &A, &B, &M, &R, &S);
	unsigned key, hash, newhash;
	for (int i = 0; i < 32; i++){
		for (uint32_t k = 0; k < 150000; k++) {
			key = somehash(k);
			hash = hashFunc(key);
			newhash = hashFunc(key ^ (1 << i));
			for (int j = 0; j < 32; j++){
				if ((hash & (1 << j)) != (newhash & (1 << j))){
					arr[i][j]++;
				}
			}
		}
	}

	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 32; j++){
			printf("%d ", (arr[i][j] / 1500));
		}
		printf("\n");
	}
	return 0;
}
