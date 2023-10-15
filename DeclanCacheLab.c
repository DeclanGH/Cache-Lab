#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	unsigned long tag;
	int valid;
	int count;
} cache_line;

int main(){

	printf("\nCACHE SIMULATOR.\n");

	int S,E,B,m,h,p; // integer values for the fundamental parameters of cache
	char policy[4]; // either LFU or LRU

	scanf("%d %d %d %d %s %d %d", &S, &E, &B, &m, policy, &h, &p);
    printf("\n");

	int s = log2(S);
	int b = log2(B);
    int t = m-s-b;

	cache_line **cache = (cache_line **) malloc(S * sizeof(cache_line *));
	for(int i = 0; i < S; i++){
		cache[i] = (cache_line *) malloc(E * sizeof(cache_line));
		for(int j = 0; j < E; j++){
			cache[i][j].tag = -1;
			cache[i][j].valid = 0;
			cache[i][j].count = 0;
		}
	}

	// initializing counters to zero. Address would be given by the user.
	int hitCount = 0;
	int missCount = 0;
	int cycle = 0;
	unsigned long long int address; // I used 'long long' here to fix input4, but it did not work, so I gave up

	while(1){
		scanf("%llx", &address); // read a hexadecimal from user assumed to be a memory address
		if (address == -1){
			break;
		}
		long long int setIndex = (address >> b) & ((1 << s) - 1);
		long long int tag = (address >> (s + b)) & ((1 << t) - 1) ;
		int hit = 0;
		int maxCount = -1; 
		int maxCountIndex = -1; // to avoid errors
		for(int i = 0; i < E; i++){
			if (cache[setIndex][i].valid && cache[setIndex][i].tag == tag){
				hit = 1;
				hitCount++;
				cache[setIndex][i].count++;
                cycle += h;
				printf("%llx H\n", address);
				break;
			}
		}
		if (!hit){
			missCount++;
			int emptyIndex = -1;
			for(int i = 0; i < E; i++){
				if (!cache[setIndex][i].valid){
					emptyIndex = i;
					break;
				}
			}
			if (emptyIndex == -1){
				if (strcmp(policy, "LRU") == 0){
					int minCount = -1;
					int minCountIndex = -1;
				 	for (int i = 0; i < E; i++) {
                    				if (cache[setIndex][i].count < minCount) {
                        				minCount = cache[setIndex][i].count;
                        				minCountIndex = i;
                    				}
                			}	
					cache[setIndex][minCountIndex].tag = tag;
					cache[setIndex][minCountIndex].count = 0;
                    for (int i = 0; i < E; i++) {
                        if (i != minCountIndex) {
                            cache[setIndex][i].count++;
                        }
                    }
					} else if (strcmp(policy, "LFU") == 0){
						for(int i = 0; i < E; i++){
							if (cache[setIndex][i].count > maxCount){
								maxCount = cache[setIndex][i].count;
								maxCountIndex = i;
							}
						}
						cache[setIndex][maxCountIndex].tag = tag;		
						cache[setIndex][maxCountIndex].count = 1;
					}
				}else {
                        cache[setIndex][emptyIndex].valid = 1;
                        cache[setIndex][emptyIndex].tag = tag;
                        cache[setIndex][emptyIndex].count = 0;
                for (int i = 0; i < E; i++) {
                    if (i != emptyIndex && cache[setIndex][i].valid) {
                        cache[setIndex][i].count++;
                    }
                }
				}
                cycle += h + p;
				printf("%llx M\n", address);
			}
		}
			double  missRate = (double) missCount / (hitCount + missCount) * 100;
            printf("%.f %d\n",  missRate, cycle);

			for (int i = 0; i < S; i++){
        		free(cache[i]);
    			}
			free(cache);

	return 0;
}
