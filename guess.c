#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

	int max=100, min=50,n,i;
	char ch ='y';
	srand(time(NULL));
	while(ch == 'y') {
		int rd_num=rand() % (max - min +1) +min;
		for(i=1; i<=5; i++) {
			while(1) {
				printf("enter your guess number from 50 to 100:");
				if(scanf("%d",&n)!=1) {
					printf("\nCheck Your Mind\n");
					i--;
					while(getchar() !='\n')
						continue;

				}
				break;
			}
			if(n<=max && n>=min) {
				if(n>rd_num) {
					printf("\nguess little lower.(guess:%d)\n",i);
				} else if(n<rd_num) {
					printf("\nguess little higher.(guess:%d)\n",i);
				} else {
					printf("\nyour guess is correct.\n");
					break;

				}
			} else {
				printf("Practice English More\n");
				i--;
			}
		}

		printf("\n\tGAME OVER\t");
		printf("ans:%d",rd_num);

		printf("\nDo you want to restart the game(y=yes&n=no):");
		scanf(" %c",&ch);

		if(ch != 'y') {
			printf("\n\tthanks for playing.");
		}
	}


}