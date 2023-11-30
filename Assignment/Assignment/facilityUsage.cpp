#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#pragma warning(disable:4996)

struct Date {
	int day, month, year;
};

struct Time {
	char timeStr[10], timeEnd[10];
};

typedef struct {
	char usageID[6];
	struct Date date;
	struct Time time;
	char memberID[10];
	char facilityID[6];
	char usageType[11];
	int ttlPpl;

}Usage;

Usage usage;

void usageAdd();
void usageDisplay();
void usageSearch();
void usageModify();
void usageDelete();
void usageSummary();
void usageRead();
void menu();
void header();
void noData();
void ordinal(int a);
void print(int i);


//MAIN
void facilityUsage() {
	char cycle;

	do {
		menu();

		printf("\n\tDo you want to continue (Y = yes) ? ");
		scanf("%c", &cycle);
		system("cls");
	} while (toupper(cycle) == 'Y');
}

//MENU
void menu() {
	int ans;

	printf("\t=========================================\n");
	printf("\t|\t   Facility Usage Module\t|\n");
	printf("\t|\t                 \t   \t|\n");
	printf("\t|\t  Add data       \t= 1\t|\n");
	printf("\t|\t  Display data   \t= 2\t|\n");
	printf("\t|\t  Search data    \t= 3\t|\n");
	printf("\t|\t  Modify data    \t= 4\t|\n");
	printf("\t|\t  Delete data    \t= 5\t|\n");
	printf("\t|\t  Summary Report \t= 6\t|\n");
	printf("\t|\t  Read from BOOKING\t= 7\t|\n");
	printf("\t|\t  Exit           \t= 8\t|\n");
	printf("\t=========================================\n\n");

	do {
		printf("\t\t  Insert your answer : ");
		scanf("%d", &ans);
		rewind(stdin);
		switch (ans) {
		case 1:usageAdd(); break;
		case 2:usageDisplay(); break;
		case 3:usageSearch(); break;
		case 4:usageModify(); break;
		case 5:usageDelete(); break;
		case 6:usageSummary(); break;
		case 7:usageRead(); break;
		case 8:printf("\n\t------------------Exit-----------------\n"); break;
		default:printf("\t\tInvalid answer, Please enter again!\n\n"); break;
		}
	} while (ans > 8 || ans < 1);
}

//read data from other module
void usageRead() {
	//fadd = usage.bat, fbook = booking module
	FILE* fAdd, * fbook;
	fbook = fopen("bookingUsage.dat", "rb");
	fAdd = fopen("usage.dat", "ab");
	int i = 0, arr;
	Usage usage[30];
	if (!fAdd) {
		printf("file opening error \n\n");
	}
	else {
		while (fread(&usage[i], sizeof(Usage), 1, fbook) != 0) {
			i++;
		}

		arr = i;

		for (i = 0; i < arr; i++) {
			fwrite(&usage[i], sizeof(Usage), 1, fAdd);
		}
	}
	fclose(fbook);
	fclose(fAdd);

	printf("\n\n\t--------------Date Loaded--------------\n");

}

//ADD function
void usageAdd() {

	FILE* fAdd;
	int count = 0;
	char choice;
	Usage usage;
	//open in apending
	fAdd = fopen("usage.dat", "ab");
	if (fAdd == NULL) {
		printf("\tfile opening error \n\n");
		exit(-1);
	}
	//scan usage ID and loop
	printf("\t\tEnter Usage ID ,format = A00(XXX to stop) : ");
	scanf("%s", &usage.usageID);
	rewind(stdin);

	while (strcmp(usage.usageID, "XXX") != 0) {

		printf("\t\tEnter the date  (dd/mm/yyyy)            > ");
		scanf("%d/%d/%d", &usage.date.day, &usage.date.month, &usage.date.year);
		rewind(stdin);

		printf("\t\tEnter the Start time (hour:min am/pm)   > ");
		scanf("%[^\n]", &usage.time.timeStr);
		rewind(stdin);

		printf("\t\tEnter the End time (hour:min am/pm)     > ");
		scanf("%[^\n]", &usage.time.timeEnd);
		rewind(stdin);

		printf("\t\tMember ID (M0000)                       > ");
		scanf("%s", &usage.memberID);
		rewind(stdin);

		printf("\t\tFacility ID (XX0)                       > ");
		scanf("%s", &usage.facilityID);
		rewind(stdin);

		printf("\t\tUsage Type                              > ");
		scanf("%s", &usage.usageType);
		rewind(stdin);

		printf("\t\tTotal people                            > ");
		scanf("%d", &usage.ttlPpl);
		rewind(stdin);

		fwrite(&usage, sizeof(Usage), 1, fAdd);

		printf("\n\t\tEnter Usage ID ,format = A00(XXX to stop) :");
		scanf("%s", &usage.usageID);
		rewind(stdin);

	};

	fclose(fAdd);
}

//Display function
void usageDisplay() {
	int i = 0;
	FILE* fDis;
	fDis = fopen("usage.dat", "rb");
	if (fDis == NULL) {
		printf("file opening error \n\n");
		exit(-1);
	}
	//Printf format
	header();

	while (fread(&usage, sizeof(Usage), 1, fDis) != 0)
	{
		printf("\t|    %-4s    |    %02d/%02d/%04d    |    %7s - %7s    |     %5s     |   %5s     | %10s     |      %02d      |\n", usage.usageID, usage.date.day, usage.date.month, usage.date.year, usage.time.timeStr, usage.time.timeEnd, usage.memberID, usage.facilityID, usage.usageType, usage.ttlPpl);
		i++;
	}
	printf("\t|=======================================================================================================================|\n");
	printf("\t|                                                 %2d records listed !!                                                  |\n", i);
	printf("\t=========================================================================================================================\n");


	//close file pointer
	fclose(fDis);
}

//function with parameter to printf data
void print(int i) {
	FILE* fPrint;
	Usage usage[20];
	int k = 0;
	fPrint = fopen("usage.dat", "rb");
	while (fread(&usage[k], sizeof(Usage), 1, fPrint) != 0) {
		k++;
	}
	fclose(fPrint);
	printf("\t|    %-4s    |    %02d/%02d/%04d    |    %7s - %7s    |     %5s     |   %5s     | %10s     |      %02d      |\n", usage[i].usageID, usage[i].date.day, usage[i].date.month, usage[i].date.year, usage[i].time.timeStr, usage[i].time.timeEnd, usage[i].memberID, usage[i].facilityID, usage[i].usageType, usage[i].ttlPpl);

}

//to print header
void header() {
	printf("\n\n\t=========================================================================================================================\n");
	printf("\t|  Usage ID  |       DATE       |          Time           |   Member ID   | Facility ID |   Usage Type   | Total People |\n");
	printf("\t|============|==================|=========================|===============|=============|================|==============|\n");
}

//to print date not found msg
void noData() {
	printf("\t|            |                  |                         |               |             |                |              |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------------------------|\n");
	printf("\t|                                                     No Data Founds !!!!                                               |\n");
	printf("\t=========================================================================================================================\n");
}

//Search
void usageSearch() {
	char choice, usageID[6], memberID[6], facilityID[6];
	int i = 0, uCount, ans, found, f;

	FILE* fSearch;

	Usage usage[30];
	fSearch = fopen("usage.dat", "rb");
	if (fSearch == NULL) {
		printf("file opening error \n\n");
		exit(-1);
	}

	while (fread(&usage[i], sizeof(Usage), 1, fSearch) != 0) {
		i++;
	}
	uCount = i;

	fclose(fSearch);

	do {//choose record to search
		printf("\t=========================================\n");
		printf("\t|   Insert Usage ID you want to Search  |\n");
		printf("\t=========================================\n\n");


		printf("\t\tEnter the Usage ID (A00) : ");
		scanf("%s", &usageID);
		rewind(stdin);

		found = 0;
		//Printf format
		header();

		//compare and scan data
		for (i = 0; i < uCount; i++) {
			if (strcmp(usage[i].usageID, usageID) == 0) {
				found = 1;
				f = i;
			};
		};

		//f = i to define struct array
  //exit if not found
		if (found == 0) {
			noData();
		}

		else {
			//display data found
			print(f);
			ordinal(f + 1);
		}

		printf("\n\tAny more data to search (Y = yes) ? ");
		scanf("%c", &choice);
		rewind(stdin);

	} while (toupper(choice) == 'Y');
};

//MODIFY
void usageModify() {
	usageDisplay();
	char choice, usageID[6], memberID[10], facilityID[6], usageType[11];
	int i = 0, ttlPpl, modiTotal = 0, uCount, ans, found, f;

	FILE* fModi;
	Date date;
	Time time;
	Usage usage[30];

	fModi = fopen("usage.dat", "rb");
	if (fModi == NULL) {
		printf("file opening error \n\n");
		exit(-1);
	}

	while (fread(&usage[i], sizeof(Usage), 1, fModi) != 0) {
		i++;
	}
	uCount = i;

	fclose(fModi);

	do {//choose record to search
		printf("\t=========================================\n");
		printf("\t|   Insert Usage ID you want to Modify  |\n");
		printf("\t=========================================\n\n");


		printf("\t\tEnter the Usage ID (A00) : ");
		scanf("%s", &usageID);
		rewind(stdin);

		found = 0;
		//Printf format
		header();

		//compare and scan data
		for (i = 0; i < uCount; i++) {
			if (strcmp(usage[i].usageID, usageID) == 0) {
				found = 1;
				f = i;
			};
		};

		if (found == 0) {
			noData();
		}

		else {
			//display data found
			print(f);
			ordinal(f + 1);

			printf("\t=========================================\n");
			printf("\t|Which record do you want to modify ?\t|\n");
			printf("\t|\t                 \t   \t|\n");
			printf("\t|\t  Usage ID       \t= 1\t|\n");
			printf("\t|\t  DATE           \t= 2\t|\n");
			printf("\t|\t  Time           \t= 3\t|\n");
			printf("\t|\t  Member ID      \t= 4\t|\n");
			printf("\t|\t  Facility ID    \t= 5\t|\n");
			printf("\t|\t  Usage TYPE     \t= 6\t|\n");
			printf("\t|\t  Total People   \t= 7\t|\n");
			printf("\t|\t                 \t   \t|\n");
			printf("\t=========================================\n\n");

			do {
				printf("\t\t  Insert your choice : ");
				scanf("%d", &ans);
				rewind(stdin);
				switch (ans) {
				case 1:printf("\t\tEnter the New Usage ID (A00) : ");
					scanf("%s", &usageID);
					break;
				case 2:printf("\t\tEnter the New Date (DD/MM/YYYY) : ");
					scanf("%d/%d/%d", &date.day, &date.month, &date.year);
					break;
				case 3:printf("\t\tEnter the Start time (hour:min am/pm) >");
					scanf("%[^\n]", &time.timeStr);
					rewind(stdin);
					printf("\t\tEnter the End time (hour:min am/pm) >");
					scanf("%[^\n]", &time.timeEnd);
					break;
				case 4:printf("\t\tEnter the New Member ID (M0000) : ");
					scanf("%s", &memberID);
					break;
				case 5:printf("\t\tEnter the New Facility ID (XX0) : ");
					scanf("%s", &facilityID);
					break;
				case 6:printf("\t\tEnter the New Usage Type : ");
					scanf("%s", &usageType);
					break;
				case 7:printf("\t\tEnter the Total People : ");
					scanf("%d", &ttlPpl);
					break;
				default:printf("\t\tInvalid answer, Please enter again!\n\n"); break;
				}
				rewind(stdin);
			} while (ans > 7 || ans < 1);

			printf("\n\t\tConfirm to Modify (Y= yes)? ");
			scanf("%c", &choice);
			rewind(stdin);

			if (toupper(choice) == 'Y') {
				switch (ans) {
				case 1:strcpy(usage[f].usageID, usageID);
					printf("\t\tNew Usage ID (A00) : %s\n", usage[f].usageID);
					break;
				case 2:usage[f].date.day = date.day;
					usage[f].date.month = date.month;
					usage[f].date.year = date.year;
					printf("\t\tNew Date (DD/MM/YYYY) : %02d/%02d/%4d \n", usage[f].date.day, usage[f].date.month, usage[f].date.year);
					break;
				case 3:strcpy(usage[f].time.timeStr, time.timeStr);
					strcpy(usage[f].time.timeEnd, time.timeEnd);
					printf("New Time (00:00am - 00:00pm) : %7s - %7s \n", usage[f].time.timeStr, usage[f].time.timeEnd);
					break;
				case 4:strcpy(usage[f].memberID, memberID);
					printf("\t\tNew Member ID (M0000) : %s\n", usage[f].memberID);
					break;
				case 5:strcpy(usage[f].facilityID, facilityID);
					printf("\t\tNew Facility ID (XX0) : %s\n", usage[f].facilityID);
					break;
				case 6:strcpy(usage[f].usageType, usageType);
					printf("\t\tNew Usage Type : %s\n", usage[f].usageType);
					break;
				case 7:usage[f].ttlPpl = ttlPpl;
					break;
				};
				modiTotal++;
			}
			else {
				printf("\n\tNo Changes Made !!\n\n");
			}

			//write in array
			fModi = fopen("usage.dat", "wb");
			for (i = 0; i < uCount; i++) {
				fwrite(&usage[i], sizeof(Usage), 1, fModi);
			}
			fclose(fModi);

			header();
			print(f);
			printf("\t================================================================================================\n");
		}
		printf("\n\tAny more data to modify (Y = yes) ? ");
		scanf("%c", &choice);
		rewind(stdin);

	} while (toupper(choice) == 'Y');

	printf("\n\t\t==================================\n");
	printf("\t\t||\t%d Data(s) modifed\t||\n", modiTotal);
	printf("\t\t==================================\n");
	usageDisplay();
};

//DELETE
void usageDelete() {
	usageDisplay();
	char choice, usageID[6], memberID[6], facilityID[6];
	int i = 0, modiTotal = 0, uCount, ans, found, f, arr;

	FILE* fDel;

	Usage usage[30];
	fDel = fopen("usage.dat", "rb");
	if (fDel == NULL) {
		printf("file opening error \n\n");
		exit(-1);
	}

	while (fread(&usage[i], sizeof(Usage), 1, fDel) != 0) {
		i++;
	}
	uCount = i;

	fclose(fDel);

	do {//choose record to search
		printf("\t=========================================\n");
		printf("\t|   Insert Usage ID you want to Delete  |\n");
		printf("\t=========================================\n\n");


		printf("\t\tEnter the Usage ID (A00) : ");
		scanf("%s", &usageID);
		rewind(stdin);

		found = 0;

		//Print header
		header();

		//compare and scan data
		for (i = 0; i < uCount; i++) {
			if (strcmp(usage[i].usageID, usageID) == 0) {
				found = 1;
				f = i;
			};
		};
		//f = i to define struct array
	  //exit if not found
		if (found == 0) {
			noData();
		}

		else {
			print(f);
			ordinal(f + 1);

			printf("\n\t\tConfirm to Delete the data (Y = yes)? ");
			scanf("%c", &choice);
			rewind(stdin);

			if (toupper(choice) == 'Y') {
				uCount--;
				for (arr = f; arr < uCount; arr++) {
					strcpy(usage[arr].usageID, usage[arr + 1].usageID);
					usage[arr].date.day = usage[arr + 1].date.day;
					usage[arr].date.month = usage[arr + 1].date.month;
					usage[arr].date.year = usage[arr + 1].date.year;
					strcpy(usage[arr].time.timeStr, usage[arr + 1].time.timeStr);
					strcpy(usage[arr].time.timeEnd, usage[arr + 1].time.timeEnd);
					strcpy(usage[arr].memberID, usage[arr + 1].memberID);
					strcpy(usage[arr].facilityID, usage[arr + 1].facilityID);
					strcpy(usage[arr].usageType, usage[arr + 1].usageType);
					usage[arr].ttlPpl = usage[arr + 1].ttlPpl;
				}
				printf("\tData Deleted\n");
				modiTotal++;
			}
			else {
				printf("\n\tData Remains !!\n\n");
			}
		}
		printf("\n\n\tAny more data to Delete (Y = yes) ? ");
		scanf("%c", &choice);
		rewind(stdin);

	} while (toupper(choice) == 'Y');


	//write in array
	fDel = fopen("usage.dat", "wb");
	for (i = 0; i < uCount; i++) {
		fwrite(&usage[i], sizeof(Usage), 1, fDel);
	}
	fclose(fDel);
	printf("\n\t\t============================\n");
	printf("\t\t|| %d Data(s) deleted !!! ||\n", modiTotal);
	printf("\t\t============================\n");
	usageDisplay();
};

//summary
void usageSummary() {
	char choice, facilityID[6], usageType[11];
	int i = 0, uCount, ans, found, f = 0, num, total, sum, n = 0;

	FILE* fSearch;
	Date date;
	Usage usage[30];
	fSearch = fopen("usage.dat", "rb");
	if (fSearch == NULL) {
		printf("file opening error \n\n");
		exit(-1);
	}

	while (fread(&usage[i], sizeof(Usage), 1, fSearch) != 0) {
		i++;
	}
	uCount = i;

	fclose(fSearch);

	do {//choose record to search
		printf("\t=========================================\n");
		printf("\t|  Which summary do you want to look ?  |\n");
		printf("\t|\t                 \t   \t|\n");
		printf("\t|\t  DATE           \t= 1\t|\n");
		printf("\t|\t  Month          \t= 2\t|\n");
		printf("\t|\t  Year           \t= 3\t|\n");
		printf("\t|\t  Usage Type     \t= 4\t|\n");
		printf("\t|\t  Facility ID    \t= 5\t|\n");
		printf("\t|\t                 \t   \t|\n");
		printf("\t=========================================\n\n");

		do {
			printf("\t\t  Insert your answer : ");
			scanf("%d", &ans);
			rewind(stdin);
			switch (ans) {

			case 1:printf("\t\tEnter the Date (DD/MM/YYYY) : ");
				scanf("%d/%d/%d", &date.day, &date.month, &date.year);
				break;
			case 2:printf("\t\tEnter the Month (MM/YYYY) : ");
				scanf("%d/%d", &date.month, &date.year);
				break;
			case 3:printf("\t\tEnter the Year (YYYY) : ");
				scanf("%d", &date.year);
				break;
			case 4:printf("\t\tEnter the Usage Type : ");
				scanf("%s", &usageType);
				break;
			case 5:printf("\t\tEnter the Facility ID (XX0) : ");
				scanf("%s", &facilityID);
				break;
			default:printf("\t\tInvalid answer, Please enter again!\n\n"); break;
			}
			rewind(stdin);
		} while (ans > 5 || ans < 1);

		found = 0;

		header();

		//compare and scan data
		switch (ans) {
		case 1:for (i = 0; i < uCount; i++) {
			if (date.day == usage[i].date.day && date.month == usage[i].date.month && date.year == usage[i].date.year) {
				found = 1;
				print(i);
				num = usage[i].ttlPpl;
				total = n + num;
				n = total;
				f++;
			};
		};
		case 2:for (i = 0; i < uCount; i++) {
			if (date.month == usage[i].date.month && date.year == usage[i].date.year) {
				found = 1;
				print(i);
				num = usage[i].ttlPpl;
				total = n + num;
				n = total;
				f++;
			};
		};
		case 3:for (i = 0; i < uCount; i++) {
			if (date.year == usage[i].date.year) {
				found = 1;
				print(i);
				num = usage[i].ttlPpl;
				total = n + num;
				n = total;
				f++;
			};
		};
		case 4:for (i = 0; i < uCount; i++) {
			if (strcmp(usage[i].usageType, usageType) == 0) {
				found = 1;
				print(i);
				num = usage[i].ttlPpl;
				total = n + num;
				n = total;
				f++;
			};
		};

		case 5:for (i = 0; i < uCount; i++) {
			if (strcmp(usage[i].facilityID, facilityID) == 0) {
				found = 1;
				print(i);
				num = usage[i].ttlPpl;
				total = n + num;
				n = total;
				f++;
			};
		};

		};

		if (found == 0) {
			noData();
		}
		else {
			//display data found
			printf("\t|-----------------------------------------------------------------------------------------------------------------------|\n");
			printf("\t|\t\t\t         %2d record(s) are listed\t\t                |       Total People = %2d\t|\n", f, total);
			printf("\t=========================================================================================================================\n");
		}

		printf("\n\tAny more data to search (Y = yes) ? ");
		scanf("%c", &choice);
		rewind(stdin);

	} while (toupper(choice) == 'Y');
};

//print bottom of ouput with record place
void ordinal(int a) {
	printf("\t|=======================================================================================================================|\n");

	if ((a % 10) == 1 && a != 11 && a != 111) {
		printf("\t|\t\t\t\t\t         %2dst record listed !!               \t\t\t                |\n", a);
	}
	else if ((a % 10) == 2 && a != 12 && a != 112) {
		printf("\t|\t\t\t\t\t        %2dnd record listed !!               \t\t\t                |\n", a);
	}
	else if ((a % 10) == 3 && a != 13 && a != 113) {
		printf("\t|\t\t\t\t\t        %2drd record listed !!               \t\t\t                |\n", a);
	}
	else {
		printf("\t|\t\t\t\t\t        %2dth record listed !!               \t\t\t                |\n", a);
	}
	printf("\t=========================================================================================================================\n");

}
