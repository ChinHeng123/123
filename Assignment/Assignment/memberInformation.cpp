#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable :4996)

void memberMenu();

typedef struct {
	char memberID[20];
	char memberName[20];
	int age;
	char gender[10];
	char phone[11];
	char email[100];
}Member;


void add() {

	FILE* ptr;  //declare file pointer

	Member member;

	char c, cont = 'N';

	//open file pointer for appending (add) data into member.txt
	ptr = fopen("member.txt", "a");

	//check if the file NOT EXIST, print error message and exit program
	if (ptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}

	//prompt for first time input
	do {
		printf("Enter Member ID  : ");
		rewind(stdin);
		scanf("%s", &member.memberID);

		printf("Enter Member's Name : ");
		rewind(stdin);
		scanf("%[^\n]", &member.memberName);

		printf("Enter Member's Age : ");
		rewind(stdin);
		scanf("%d", &member.age);

		printf("Enter Member's Gender : ");
		rewind(stdin);
		scanf("%s", &member.gender);

		printf("Enter Member's Phone : ");
		rewind(stdin);
		scanf("%s", &member.phone);

		printf("Enter Member's Email : ");
		rewind(stdin);
		scanf("%s", &member.email);

		printf("Continue? (Y /N)  >> ");
		rewind(stdin);
		scanf("%c", &c);

		fprintf(ptr, "%s %s %d %s %s %s\n", member.memberID, member.memberName, member.age, member.gender, member.phone, member.email);

	} while (toupper(c) == 'Y');

	fclose(ptr);
	printf("Continue system? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &cont);
	if (toupper(cont) == 'Y') {
		memberMenu();
	}
	else {
		printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("X                                                         X\n");
		printf("X                  Thanks for using !                     X\n");
		printf("X                      Good Bye !                         X\n");
		printf("X                                                         X\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		exit(-1);
	}
}

void display() {
	FILE* ptr;
	Member member[50];
	int i = 0, record;
	char cont = 'N';
	ptr = fopen("member.txt", "r");

	if (ptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(ptr, "%s %s %d %s %s %s\n", &member[i].memberID, &member[i].memberName, &member[i].age, &member[i].gender, &member[i].phone, &member[i].email) != EOF)
		{
			i++;	//increase the array index, then continue read
		}
		record = i;
		printf("=================================================\n");
		printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
		printf("=================================================\n");
		for (i = 0; i < record; i++) {
			printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
			printf("=================================================\n");
		}

		printf("|X===============   Display %d records !!!   ====================X|\n", record);
	}

	fclose(ptr);
	printf("Continue system? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &cont);
	if (toupper(cont) == 'Y') {
		memberMenu();
	}
	else {
		printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("X                                                         X\n");
		printf("X                  Thanks for using !                     X\n");
		printf("X                      Good Bye !                         X\n");
		printf("X                                                         X\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		exit(-1);
	}
}

void search() {
	FILE* ptr;

	Member member[50];

	ptr = fopen("member.txt", "r");
	char memberID[20], memberName[20], cont = 'N';
	int option, i = 0;
	int record = 0;

	if (ptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(ptr, "%s %s %d %s %s %s\n", &member[i].memberID, &member[i].memberName, &member[i].age, &member[i].gender, &member[i].phone, &member[i].email) != EOF)
		{
			i++;	//increase the array index, then continue read
		}
		record = i;
		fclose(ptr);
		printf("------------------------------------------------------------\n");
		printf("           Search function        \n");
		printf("-----------------------------------------------------------\n");
		printf("           1. Search by Member ID     \n");
		printf("           2. Search by Member Name                       \n");
		printf("-----------------------------------------------------------\n");
		printf("Enter option (1 - 3) >> ");
		scanf("%d", &option);

		if (option == 1) {
			printf("\nEnter your Member ID  : ");
			scanf("%s", &memberID);

			for (i = 0; i < record; i++) {
				//compare Member ID entered with array code
				if (strcmp(member[i].memberID, memberID) == 0) {
					//display found record on screen
					printf("=================================================\n");
					printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
					printf("=================================================\n");
					printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
					printf("=================================================\n");
				}
			}
		}
		else if (option == 2) {
			printf("Enter your Member Name : ");
			scanf("%s", &memberName);

			for (i = 0; i < record; i++) {
				//compare ? entered with array code
				if (strcmp(member[i].memberName, memberName) == 0) {
					//display found record on screen
					printf("=================================================\n");
					printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
					printf("=================================================\n");
					printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
					printf("=================================================\n");
				}
			}
		}
		fclose(ptr);
		printf("Continue system? (Y/N)  : ");
		rewind(stdin);
		scanf("%c", &cont);
		if (toupper(cont) == 'Y') {
			memberMenu();
		}
		else {
			printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			printf("X                                                         X\n");
			printf("X                  Thanks for using !                     X\n");
			printf("X                      Good Bye !                         X\n");
			printf("X                                                         X\n");
			printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			exit(-1);
		}
	}
}

void modify() {

	FILE* ptr;
	Member member[50];

	ptr = fopen("member.txt", "r");
	int option;
	char mdfdMemberID[20], memberID[20], mdfd, mdfdPhone[11], phone[11], cont = 'N';
	int i = 0;
	int record = 0, mdfdCount = 0;

	if (ptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	while (fscanf(ptr, "%s %s %d %s %s %s\n", &member[i].memberID, &member[i].memberName, &member[i].age, &member[i].gender, &member[i].phone, &member[i].email) != EOF) {
		i++;
	}
	record = i;

	fclose(ptr);

	printf("|X==============================================================X|\n");
	printf("|X       Select which member information u want to modify       X|\n");
	printf("|X==============================================================X|\n");
	printf("|X                   1. Modify Member ID                        X|\n");
	printf("|X                   2. Modify Phone                            X|\n");
	printf("|X==============================================================X|\n");
	printf("Enter option (only 1 or 2)  >> ");
	rewind(stdin);
	scanf("%d", &option);
	if (option == 1) {
		printf("\nEnter Member ID  >> ");
		rewind(stdin);
		scanf("%s", &memberID);

		for (i = 0; i < record; i++) {
			//compare member ID entered with array code
			if (strcmp(member[i].memberID, memberID) == 0) {
				//display found record on screen
				printf("=================================================\n");
				printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
				printf("=================================================\n");
				printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
				printf("=================================================\n");
				printf("\nConfirm to Modify (Y=yes)? ");
				rewind(stdin);
				scanf("%c", &mdfd);
				printf("New Member ID to be modified>>\n");
				rewind(stdin);
				scanf("%s", &mdfdMemberID);
				//if ans = Y/y 
				if (toupper(mdfd) == 'Y') {
					//update Member ID into array element 
					strcpy(member[i].memberID, mdfdMemberID);
					mdfdCount++;
					printf("\nUpdated record:\n");
				}
			}
		}
	}
	else if (option == 2) {
		printf("Enter Member's Phone>>\n");
		rewind(stdin);
		scanf("%s", &phone);
		for (i = 0; i < record; i++) {
			//compare facility venue entered with array code
			if (strcmp(member[i].phone, phone) == 0) {
				//display found record on screen
				printf("=================================================\n");
				printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
				printf("=================================================\n");
				printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
				printf("=================================================\n");
				printf("\nConfirm to Modify (Y=yes)? ");
				rewind(stdin);
				scanf("%c", &mdfd);
				printf("New Phone to be modified>>\n");
				rewind(stdin);
				scanf("%s", &mdfdPhone);
				//if ans = Y/y
				if (toupper(mdfd) == 'Y') {
					//update new phone into array element 
					strcpy(member[i].phone, mdfdPhone);
					mdfdCount++;
					printf("\nUpdated record: %\n", i);
				}
				else {
					printf("\nRecord:\n");
				}
			}
		}
	}
	fclose(ptr);
	printf("Continue system? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &cont);
	if (toupper(cont) == 'Y') {
		memberMenu();
	}
	else {
		printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("X                                                         X\n");
		printf("X                  Thanks for using !                     X\n");
		printf("X                      Good Bye !                         X\n");
		printf("X                                                         X\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		exit(-1);
	}
}


void deleteMember() {
	FILE* ptr;

	Member member[100];
	int  i = 0, record = 0, found = 0, dl;
	char memberID[20], ans = 'N', cont = 'N';
	ptr = fopen("member.txt", "r");

	if (ptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(ptr, "%s %s %d %s %s %s\n", &member[i].memberID, &member[i].memberName, &member[i].age, &member[i].gender, &member[i].phone, &member[i].email) != EOF)
		{
			i++;
		}
		record = i;

		printf("Enter which Member ID u want to delete\n");
		rewind(stdin);
		scanf("%s", &memberID);

		for (i = 0; i < record; i++) {
			if (strcmp(member[i].memberID, memberID) == 0) {

				printf("======================================================\n");
				printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
				printf("======================================================\n");
				printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
				printf("======================================================\n");
				found = 1;

				printf("\nConfirm to DELETE (Y=yes)? ");
				rewind(stdin);
				scanf("%c", &ans);
			}
		}

		if (toupper(ans) == 'Y') {
			record--;

			for (dl = i; dl < record; dl++) {
				strcpy(member[dl].memberID, member[dl + 1].memberID);
				strcpy(member[dl].memberName, member[dl + 1].memberName);
				member[dl].age = member[dl + 1].age;
				strcpy(member[dl].gender, member[dl + 1].gender);
				strcpy(member[dl].phone, member[dl + 1].phone);
				strcpy(member[dl].email, member[dl + 1].email);
			}
			printf("\nRecord Deleted\n");

			ptr = fopen("member.txt", "w");
			for (i = 0; i < record; i++) {
				fprintf(ptr, "%s %s %d %s %s %s\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
			}
			fclose(ptr);
		}
		else {
			printf("\nRecord remain \n");
		}
		if (found == 0) {
			printf(" Not Record found by Member ID : %s\n", memberID);
		}
		printf("Continue system? (Y/N)  : ");
		rewind(stdin);
		scanf("%c", &cont);
		if (toupper(cont) == 'Y') {
			memberMenu();
		}
		else {
			printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			printf("X                                                         X\n");
			printf("X                  Thanks for using !                     X\n");
			printf("X                      Good Bye !                         X\n");
			printf("X                                                         X\n");
			printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			exit(-1);
		}
	}
}
//Menu
void memberMenu() {
	system("cls");
	int n;
	printf("\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("X                                                         X\n");
	printf("X    Welcome to Member Information Management System      X\n");
	printf("X                                                         X\n");
	printf("X                        Menu                             X\n");
	printf("X                                                         X\n");
	printf("X                 1. Add Data                             X\n");
	printf("X                 2. Search Data                          X\n");
	printf("X                 3. Modify Data                          X\n");
	printf("X                 4. Display Data                         X\n");
	printf("X                 5. Delete Data                          X\n");
	printf("X                 6. Exit system                          X\n");
	printf("X                                                         X\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
	printf("\n");
	printf("Please enter a selection (1-7):");
	scanf("%d", &n);
	printf("\n");
	if (n >= 0 && n <= 7) {
		switch (n) {
		case 1: add(); break;
		case 2: search(); break;
		case 3: modify(); break;
		case 4: display(); break;
		case 5: deleteMember(); break;
		case 6:
			printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			printf("X                                                         X\n");
			printf("X                  Thanks for using !                     X\n");
			printf("X                      Good Bye !                         X\n");
			printf("X                                                         X\n");
			printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			exit(-1);
		}
	}
	else {
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("X                                                         X\n");
		printf("X                      Input Error !                      X\n");
		printf("X                Logged out of the System !               X\n");
		printf("X                                                         X\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		exit(-1);
	}
}
