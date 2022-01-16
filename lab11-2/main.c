#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *p1;
	p1 = fopen("data12.txt", "r");
	char c;
	int tlines = 0;
	int a = 0;
	if (p1 == NULL){
		printf("Could not open file");
		return 1;
	}
	while (1){
		c = fgetc(p1);
		if (c == EOF){
			break;
		}
		a++;
		if (c == '\n'){
			tlines++;
		}
	}
	rewind(p1);
	char *stixoi;
	stixoi = (char*) calloc(a, sizeof(char));
	printf("\n");
	int b = 0;
	while (1){
		c = fgetc(p1);
		if (c == EOF){
			break;
		}
		if (b <= a){
			stixoi[b] = c;
			b++;
		}
	}
	fclose(p1);
	
	int endlineind = 0;
	
	int s = -1;
	
	int *p;
	int g = 0;
	while (g <= 0 || g > tlines){
		printf("How many lines of the given text do you want to display? The number should be less or equal to %i\n", tlines);
		scanf(" %i", &g);
	}
	p = (int*) calloc(g, sizeof(int));
	int *pd;
	pd = (int*) calloc(g, sizeof(int));
	for (int i = 0; i < g; i++){
		pd[i] = 0;
	}
	for (int i = 0; i < g; i++){
		printf("Give me the #%i line. Numeration starts from 0:\n", i+1);
		scanf(" %i", &p[i]);
		if (p[i] > tlines){
			while (p[i] > tlines){
				printf("The number should be less or equal to %i, the numerizing starts from 0!\n", tlines);
				scanf(" %i", p[i]);
			}
		}
	}
	printf("The selected lines are:\n");
	for (int i =0; i < g; i++){
		printf("%i ", p[i]);
	}
	b = 0;
	int pind = 0;
	printf("\nText: \n\n\n");
	while (b <= a){
		if (stixoi[b] == '\n'){
			if (p[pind] == endlineind){
				printf("\n");
			}
			endlineind++;
			if (pind < (g-1) && pd[pind] == 1){
				pind++;
			}
		}
		else if (p[pind] == endlineind){
			printf("%c", stixoi[b]);
			pd[pind] = 1;
		}
		b++;
	}
	
	free(p);
	free(pd);
	return 0;
}
