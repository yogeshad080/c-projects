#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>

struct contact {
	char name[50];
	char phone_no[11];
	int age;
};

int add_contact(struct contact *arr, int count);
int view_contact(struct contact *arr, int count);
int search_contact(struct contact *arr, int count);
int dlt_contact(struct contact *arr, int count);
int edit_contact(struct contact *arr, int count);
int data_fetch(struct contact *arr, int data_no);
int contact_no();
int check_phone_no(char np[]);

int contact_no() {
	FILE *fp = fopen("contact.txt", "r");
	if (fp == NULL) {
		return 0;
	}
	int count = 0;
	char line[200];
	while (fgets(line, sizeof(line), fp) != NULL) {
		count++;
	}
	fclose(fp);
	return count;
}

int data_fetch(struct contact *arr, int data_no) {
	FILE *fp = fopen("contact.txt", "r");
	if (fp == NULL) {
		return 0;
	}
	for (int i = 0; i < data_no; i++) {
		fscanf(fp, "%s %s %d\n", arr[i].name, arr[i].phone_no, &arr[i].age);
	}
	fclose(fp);
	return 1;
}

int check_phone_no(char np[]) {
	FILE *fp = fopen("contact.txt", "r");
	struct contact temp;
	if (fp == NULL) {
		return 0;
	}
	while (fscanf(fp, "%s %s %d\n", temp.name, temp.phone_no, &temp.age) != EOF) {
		if (strcmp(temp.phone_no, np) == 0) {
			printf("Same phone number cannot be added.\n");
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

int add_contact(struct contact *arr, int count) {
	char ch = 'y';
	FILE *fp = fopen("contact.txt", "a");
	while (ch == 'y' || ch == 'Y') {

		printf("Enter the name: ");
		scanf("%s", arr[count].name);

		printf("Enter the phone number: ");
		scanf("%s", arr[count].phone_no);

		printf("Enter the age: ");
		scanf("%d", &arr[count].age);

		if (check_phone_no(arr[count].phone_no) == 1) {
			fprintf(fp, "%s %s %d\n", arr[count].name,arr[count].phone_no,arr[count].age);
			count++;
		} else {
			printf("Please enter a different phone number.\n");
		}

		sleep(3);
		system("cls");
		printf("Do you want to add another one (y=yes & n=no)? ");
		scanf(" %c", &ch);
	}
	fclose(fp);
	return count;
}

int view_contact(struct contact *arr, int count) {
	int i,j;
	struct contact temp;
	for(i=0; i<count; i++) {
		for(j=i+1; j<count; j++) {
			if(strcmp(arr[i].name,arr[j].name) > 0) {
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("----------- People ------------\n");
	printf("S.N.\tName\tAge\tPhone_no\n\n");
	for(i=0; i<count; i++) {
		printf("%d.\t%s\t%d\t%s\n", i+1, arr[i].name, arr[i].age, arr[i].phone_no);
	}
	printf("---- The END !!! ------\n\n");
}

int search_contact(struct contact *arr, int count) {
	int i,found;
	char sphone_no[11];
	printf("Type the phone_no of the user:");
	scanf("%s",sphone_no);
	for(i=0; i<count; i++) {
		if(strcmp(sphone_no,arr[i].phone_no) == 0) {
			found++;
			printf("----------- People ------------\n");
			printf("Name\tAge\tPhone_no\n\n");
			printf("%s\t%d\t%s\n", arr[i].name, arr[i].age, arr[i].phone_no);
			return 0;
		}
	}
	if(!found) {
		printf("Given phone_no is not in the data.");
		return count;
	}

}

int dlt_contact(struct contact *arr, int count) {
	int i,temp,found=0;
	char sphone_no[11];
	printf("Type the phone_no of the user:");
	scanf("%s",sphone_no);
	for(i=0; i<count; i++) {
		if(strcmp(sphone_no,arr[i].phone_no) == 0) {
			found++;
			for(temp=i; temp<count; temp++) {
				arr[temp]=arr[temp+1];
			}
			count--;
			break;
		}
	}
	if(!found) {
		printf("Given phone_no is not in the data.");
		sleep(3);
		system("cls");
		return count;
	}
	FILE *fp = fopen("contact.txt", "w");
	if (fp == NULL) {
		printf("Error on opening the file\n");
		return 0;
	}

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %d\n", arr[i].name, arr[i].phone_no, arr[i].age);
	}
	fclose(fp);
	printf("User data has been deleted");
	sleep(3);
	system("cls");
	return count;
}

int edit_contact(struct contact *arr, int count) {
	int i,temp,ch,found=0;
	char sphone_no[11];
	printf("Type the phone_no of the user:");
	scanf("%s",sphone_no);
	
	for(i=0; i<count; i++) {
		if(strcmp(sphone_no,arr[i].phone_no) == 0) {
			found++;
			while(1) {
				printf("What do you want to edit:\n");
				printf("1:Name 2:Phone_no 3:Age 4:Exit\n");
				scanf(" %d",&ch);
				switch(ch) {
					case 1:
						printf("Enter the new name:");
						scanf("%s",arr[i].name);
						break;

					case 2:
						printf("Enter the new phone_no:");
						scanf("%s",arr[i].phone_no);
						break;

					case 3:
						printf("Enter the new age:");
						scanf("%d",&arr[i].age);
						break;

					case 4:
						 goto WRITE_FILE;

					default:
						printf("Not a option.");
				}
			}
		}
		}
		if(!found) {
		printf("Given phone_no is not in the data.");
		sleep(3);
		system("cls");
		return count;
	}
	WRITE_FILE:{
		FILE *fp = fopen("contact.txt", "w");
		if (fp == NULL) {
			printf("Error on opening the file\n");
			return 0;
		}

		for (int i = 0; i < count; i++) {
			fprintf(fp, "%s %s %d\n", arr[i].name, arr[i].phone_no, arr[i].age);
		}
		fclose(fp);

		printf("User data has been edited");
		sleep(3);
		system("cls");
		return count;
}
}

int main() {
	int n, a;
	a = contact_no();
	printf("Total contact data: %d\n\n", a);
	struct contact *per = malloc((a + 100) * sizeof(struct contact));
	data_fetch(per, a);
	while(1) {
		printf("What do you want to do?\n");
		printf("1: Add  2: View  3: Search  4: Delete  5: Edit 6:Exit\n\n");
		scanf("%d", &n);
		switch (n) {
			case 1:
				a = add_contact(per,a);

			case 2:
				a= view_contact(per,a);
				break;

			case 3:
				a=search_contact(per,a);
				break;

			case 4:
				a=dlt_contact(per,a);
				break;

			case 5:
				a=edit_contact(per,a);
				break;

			case 6:
				return 0;

			default:
				printf("Not a option.\n");
				break;
		}
	}
}
