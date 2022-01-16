#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_rand (int l, int num[]){
	srand(time(0));
	for (int i = 0; i < l; i++){
		num[i] = rand()%100;
		printf("%i\n", num[i]);
	}
	
	FILE *p1, *p2;
	p1 = fopen("data3ev.txt", "w+");
	p2 = fopen("data3od.txt", "w+");
	for (int i = 0; i < l; i++){
		if ((num[i]%2) == 0){
			fprintf(p1, "%i\n", num[i]);
		}
		else {
			fprintf (p2, "%i\n", num[i]);
		}
	}
	fclose(p1);
	fclose(p2);
	
}
int main(int argc, char *argv[]) {
	
	int k;
	printf("How big do u want the array?\n");
	scanf(" %i", &k);
	int nums[k];
	
	fill_rand(k, nums);
	return 0;
}