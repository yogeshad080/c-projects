#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char name[50];
	int age;
	int marks;
};

int stuCount();
void fetchStudents(struct student *arr);

char file_path[] = "list.txt";

int stuCount() {
	FILE *fp;
	fp = fopen(file_path, "r");
	if (fp == NULL) {
		return 0;
	}
	char ch;
	int i=0;
	ch = fgetc(fp);
	while(!feof(fp)) {
		ch = fgetc(fp);
		if(ch == '\n') {
			i++;
		}
	}
	fclose(fp);
	return i;
}

void fetchStudents(struct student *arr) {
	int i;
	int data_count = stuCount();
	FILE *fp;
	fp = fopen(file_path, "r");
	if(fp==NULL) {
		printf("Failed to Open File");
		exit(0);
	}
	for(i=0; i<data_count; i++) {
		fscanf(fp, "%s %d %d\n", arr->name, &arr->age, &arr->marks);
		arr++;
	}
	fclose(fp);
}

void sortedStudents(struct student *per, int data_no) {
	int i, j;
	struct student temp;
	for(i=0; i<data_no; i++) {
		for(j=i+1; j<data_no; j++) {
			if(strcmp(per[i].name, per[j].name) > 0) {
				temp = per[j];
				per[j] = per[i];
				per[i] = temp;
			}
		}
	}
}

void printStudents(struct student per[], int data_count){
	int i;
	printf("----------- Students ------------\n");
	printf("S.N.\tName\tAge\tMarks\n");
	for(i=0; i<data_count; i++){
		printf("%d.\t%s\t%d\t%d\n", i+1, per[i].name, per[i].age, per[i].marks);
	}
	printf("---- The END !!! ------\n\n");
}

void main() {
	printf("Total Students: %d\n\n", stuCount());
	
	int data_count = stuCount();
	struct student *studs = malloc(data_count * sizeof(struct student));
//	struct student studs[data_count];
	fetchStudents(studs);
	printStudents(studs, data_count);
	
	printf("\n------------> Sorting Existing Students <---------------\n\n");
	sortedStudents(studs, data_count);
	printStudents(studs, data_count);
}