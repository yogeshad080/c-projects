#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
//#include <conio.h>
int main() {
	int a,p,cp,n,da,na,wa;
	FILE *fp=fopen("atm.txt","r");
	fscanf(fp,"%d\n%d",&a,&p);
	fclose(fp);


	while(1) {
		printf("enter your password:");
		if(scanf("%d",&cp)!=1) {
			printf("password is in integer only\n\n");
			while(getchar() !='\n')
				continue;


		}
		if(p != cp) {
			printf("incorrect\n\n");
		} else {
			printf("correct\n\n");
			
			
			while(1) {
			printf("Current Amount:%d\n",a);
			printf("What do you want to do?\n");
			printf("1:Deposit\t2:Withdraw\t3:Exit\n");
			
		    if(scanf("%d",&n)!=1) {
			printf("select the number only\n\n");
			while(getchar() !='\n')
				continue;
			}

			switch(n){
				case(1):
					printf("\nHow much do you want to deposite?\n");
					scanf("%d",&da);
					na=a+da;
					a=na;
					printf("Current Amount:%d\n",a);
					printf("pls wait a movement...");
					fopen("atm.txt","w");
					fprintf(fp,"%d\n%d",na,p);
					fclose(fp);
					sleep(5); 
					system("cls");   
					break;
				
				case(2):
					printf("\nHow much do you want to withdraw?\n");
					scanf("%d",&wa);
					if(a<wa)
					{
						printf("are you kidding me?\n\n");
						continue;
					}
					else
					{
						na=a-wa;
						a=na;
					    fopen("atm.txt","w");
					    fprintf(fp,"%d\n%d",na,p);
					    fclose(fp);
					    printf("Current Amount:%d\n",a);
					    printf("pls wait a movement...");
					    sleep(5); 
					    system("cls"); 
					    continue;
					}
	
				case(3):
					return 0;
					break;
					
				default:
					printf("Not a choice\n\n");
					
			}
		}
		}
	}



}