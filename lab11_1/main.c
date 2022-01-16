#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *p1;
	int a;
	p1 = fopen("data11.txt", "r");
	int i = 0;
	int lst[20];
	int sum = 0;
	while (fscanf(p1, "%d ", &a) > 0 && i < 20){
		lst[i] = a;
		sum += a;
		i++;
	}
	
	for (i = 0; i < 20; i++){
		printf("%i\n", lst[i]);
	}
	printf("%i", sum);
	fclose(p1);
	return 0;
}