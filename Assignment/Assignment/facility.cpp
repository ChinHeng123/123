#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#pragma warning (disable:4996)

typedef struct {
	char facID[6], factype[30], facvenue[30], facdes[20];
	int maxmem;

}Facility;

Facility facility;
int menu();
void addFacility();
void displayFacility();
void searchFacility();
void modifyFacility();
void deleteFacility();

void facilityMenu() {
	char c;

	do {
		switch (menu()) {
		case 1:
			addFacility();
			break;
		case 2:
			displayFacility();
			break;
		case 3:
			searchFacility();
			break;
		case 4:
			modifyFacility();
			break;
		case 5:
			deleteFacility();
			break;
		default:
			printf("ERROR.Please reenter ur option\n");
			break;
		}
		printf("Back to Menu ? \n");
		printf("Yes or No (Y / N)  >> ");
		rewind(stdin);
		scanf("%c", &c);
	} while (toupper(c) == 'Y');

}
int menu() {
	int option;

	printf("|X==============================================X|\n");
	printf("|X                Facility Module               X|\n");
	printf("|X==============================================X|\n");
	printf("|X                Select an option              X|\n");
	printf("|X==============================================X|\n");
	printf("|X         1.Chooose to add facility            X|\n");
	printf("|X         2.Choose to display facility         X|\n");
	printf("|X         3.Search facility                    X|\n");
	printf("|X         4.Modify facility                    X|\n");
	printf("|X         5.Delete facility                    X|\n");
	printf("|X==============================================X|\n");

	printf("Choose ur option  >> ");
	rewind(stdin);
	scanf("%d", &option);

	return option;
}

void addFacility() {
	FILE* fptr;
	Facility facility;

	fptr = fopen("addFacility.txt", "a");
	char c;
	int option;

	if (fptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}

	else {
		do {
			printf("Enter facilityID  >> ");
			rewind(stdin);
			scanf("%s", &facility.facID);


			printf("Enter facility types  >> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.factype);


			printf("Enter facility description  >> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.facdes);

			printf("Enter facility venue  >> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.facvenue);

			printf("Enter facility max member  >> ");
			rewind(stdin);
			scanf("%d", &facility.maxmem);

			printf("Do you want to continue (Y = yes, N = no)  >> ");
			rewind(stdin);
			scanf("%c", &c);

			fprintf(fptr, "%s %s %s %s %d\n", facility.facID, facility.factype, facility.facdes, facility.facvenue, facility.maxmem);
			rewind(stdin);
		} while (toupper(c) == 'Y');


	}

	fclose(fptr);
}

void displayFacility() {
	FILE* fptr;
	Facility facility[100];
	int option, i = 0, record;
	fptr = fopen("addFacility.txt", "r");

	if (fptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(fptr, "%s %s %s %s %d\n", &facility[i].facID, &facility[i].factype, &facility[i].facdes, &facility[i].facvenue, &facility[i].maxmem) != EOF)
		{
			i++;	//increase the array index, then continue read
		}
		record = i;
		printf("----------------------------------------------------------------------------------------------\n");
		printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
		printf("----------------------------------------------------------------------------------------------\n");
		for (i = 0; i < record; i++) {
			printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
			printf("----------------------------------------------------------------------------------------------\n");
		}
		printf("\n\t\t|X===============================================================X|\n");
		printf("\t\t|X===============   Display %d records !!!   ====================X|\n", record);
		printf("\t\t|X===============================================================X|\n\n");
	}

	fclose(fptr);
}
void searchFacility() {
	FILE* fptr;

	Facility facility[100];

	fptr = fopen("addFacility.txt", "r");
	int option2;
	char a, facID[6], facvenue[10];
	int i = 0;
	int record = 0;

	if (fptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(fptr, "%s %s %s %s %d\n", &facility[i].facID, &facility[i].factype, &facility[i].facdes, &facility[i].facvenue, &facility[i].maxmem) != EOF)
		{
			i++;	//increase the array index, then continue read
		}
		record = i;
		fclose(fptr);
		printf("|X====================================================X|\n");
		printf("|X        Select which facility u want to search      X|\n");
		printf("|X====================================================X|\n");
		printf("|X            1. Search FacilityID                    X|\n");
		printf("|X            2. Search Facilityvenue                 X|\n");
		printf("|X====================================================X|\n");
		printf("Enter option (only 1 or 2) >> ");
		scanf("%d", &option2);

		if (option2 == 1) {
			printf("\nEnter ur facility ID  >> ");
			scanf("%s", &facID);

			for (i = 0; i < record; i++) {
				//compare facility ID entered with array code
				if (strcmp(facility[i].facID, facID) == 0) {
					//display found record on screen
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
					printf("----------------------------------------------------------------------------------------------\n");
				}
			}
		}
		else if (option2 == 2) {
			printf("Enter ur facility venue");
			scanf("%s", &facvenue);

			for (i = 0; i < record; i++) {
				//compare facility venue entered with array code
				if (strcmp(facility[i].facvenue, facvenue) == 0) {
					//display found record on screen
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
					printf("----------------------------------------------------------------------------------------------\n");
				}
			}
		}	
	}
	fclose(fptr);
}

void modifyFacility() {

	FILE* fptr;
	Facility facility[100];


	fptr = fopen("addFacility.txt", "r");
	int option3;
	char a, updfacID[6], updfacvenue[10], ans, facID[20], facvenue[20];
	int i = 0;
	int record = 0, modiCount = 0;


	if (fptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(fptr, "%s %s %s %s %d\n", &facility[i].facID, &facility[i].factype, &facility[i].facdes, &facility[i].facvenue, &facility[i].maxmem) != EOF)
		{
			i++;
		}
		record = i;
		fclose(fptr);
		printf("|X====================================================X|\n");
		printf("|X       Select which facility u want to modify       X|\n");
		printf("|X====================================================X|\n");
		printf("|X              1. Modify FacilityID                  X|\n");
		printf("|X              2. Modify Facilityvenue               X|\n");
		printf("|X====================================================X|\n");
		printf("Enter option (only 1 or 2)  >> ");
		rewind(stdin);
		scanf("%d", &option3);
		if (option3 == 1) {
			printf("\nEnter ur facility ID  >> ");
			rewind(stdin);
			scanf("%s", &facID);

			for (i = 0; i < record; i++) {
				//compare facility ID entered with array code
				if (strcmp(facility[i].facID, facID) == 0) {
					//display found record on screen
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
					printf("----------------------------------------------------------------------------------------------\n");
					printf("\nConfirm to Modify (Y=yes)? ");
					rewind(stdin);
					scanf("%c", &ans);
					printf("New facility ID to be modified>>\n");
					rewind(stdin);
					scanf("%s", &updfacID);
					//if ans = Y/y 
					if (toupper(ans) == 'Y') {
						//update facility ID into array element 
						strcpy(facility[i].facID, updfacID);
						modiCount++;
						printf("\nUpdated record:\n");
					}
				}
			}
		}
		else if (option3 == 2) {
			printf("Enter ur facility venue>>\n");
			rewind(stdin);
			scanf("%s", &facvenue);
			for (i = 0; i < record; i++) {
				//compare facility venue entered with array code
				if (strcmp(facility[i].facvenue, facvenue) == 0) {
					//display found record on screen
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
					printf("----------------------------------------------------------------------------------------------\n");
					printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
					printf("----------------------------------------------------------------------------------------------\n");
					
					printf("New facility venue to be modified>>\n");
					rewind(stdin);
					scanf("%s", &updfacvenue);
					
					printf("\nConfirm to Modify (Y=yes)? ");
					rewind(stdin);
					scanf("%c", &ans);

					if (toupper(ans) == 'Y') {//if ans = Y/y 
						//update new facility venue into array element 
						strcpy(facility[i].facvenue, updfacvenue);
						modiCount++;
						printf("\nUpdated record: %\n", i);
					}
					else {
						printf("\nrecord:\n");
					}
				}
			}
		}
	}
	fclose(fptr);
}
							
void deleteFacility() {
	FILE* fptr;

	Facility facility[100];
	int  i = 0, record = 0, found = 0, move;
	char facID[6], ans = 'N';
	fptr = fopen("addFacility.txt", "r");

	if (fptr == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	else {
		while (fscanf(fptr, "%s %s %s %s %d\n", &facility[i].facID, &facility[i].factype, &facility[i].facdes, &facility[i].facvenue, &facility[i].maxmem) != EOF)
		{
			i++;
		}
		record = i;

		printf("Enter which facilityID u want to delete\n");
		rewind(stdin);
		scanf("%s", &facID);

		for (i = 0; i < record; i++) {
			if (strcmp(facility[i].facID, facID) == 0) {

				printf("\n----------------------------------------------------------------------------------------------\n");
				printf("\t\t=============    Record Found   ===========\n");
				printf("----------------------------------------------------------------------------------------------\n");
				printf("|Facility ID\tFacility Type\tFacility Description\tFacility Venue\t\tMaximum People|\n");
				printf("----------------------------------------------------------------------------------------------\n");
				printf("|%-10s\t%-10s\t%-20s\t%-20s\t%-14d|\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
				printf("----------------------------------------------------------------------------------------------\n");
				found = 1;

				printf("\nConfirm to DELETE (Y=yes)? ");
				rewind(stdin);
				scanf("%c", &ans);
			}
		}

			if (toupper(ans) == 'Y') {
				record--;

				for (move = i; move < record; move++) {
					strcpy(facility[move].facID, facility[move + 1].facID);
					strcpy(facility[move].factype, facility[move + 1].factype);
					strcpy(facility[move].facdes, facility[move + 1].facdes);
					strcpy(facility[move].facvenue, facility[move + 1].facvenue);
					facility[move].maxmem = facility[move + 1].maxmem;
				}
				printf("\nRecord Deleted\n");

				fptr = fopen("addFacility.txt", "w");
				for (i = 0; i < record; i++) {
					fprintf(fptr, "%s %s %s %s %d\n", facility[i].facID, facility[i].factype, facility[i].facdes, facility[i].facvenue, facility[i].maxmem);
				}
				fclose(fptr);
			}
			else {
				printf("\nRecord remain \n");
			}
		if (found == 0) {
			printf(" Not Record found by Facility ID : %s\n", facID);
		}
	}
}



