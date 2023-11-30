#include "staff.h"

void addStaff() {
	char choice, aID[15], valid;
	int found;
	Staff S;

	FILE* fp1, * fp2;
	do {
		fp1 = fopen("staffInformation.txt", "r");
		if (fp1 == NULL)
		{
			printf("\t\tUnable to open the file\n");
			exit(-1);
		}
		printf("\t\t      ________________________________");
		printf("\n\t\t           Add new Staff Record\n");
		printf("\t\t      ________________________________\n");
		printf("\n\t\tPlease enter the following staff informations\n");

		do
		{
			printf("\n\t\t-> Staff ID      => ");
			rewind(stdin);
			scanf("%s", &aID);
			found = 0;
			while (fscanf(fp1, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", S.id, S.name, &S.gender, S.phone, S.add.address, &S.add.postCode, S.add.city, &S.DOB.day, &S.DOB.month, &S.DOB.year, S.department, S.position) != EOF)
			{
				if (strcmp(aID, S.id) == 0) {
					found = 1;
					printf("\t\t ***This Member ID Already Existed \n");
				}
			}
			if (!found) { strcpy(S.id, aID); }
		} while (found == 1);
		fclose(fp1);

		printf("\t\t-> Name          => ");
		rewind(stdin);
		scanf("%[^\n]", &S.name);

		do {
			printf("\t\t-> Gender[M/F]   => ");
			rewind(stdin);
			scanf("%c", &S.gender);
			if (toupper(S.gender) != 'M' && toupper(S.gender) != 'F')
			{
				printf("\t\tCharacter Incorrect Please Re-enter\n");
			}
		} while (toupper(S.gender) != 'M' && toupper(S.gender) != 'F');

		printf("\t\t-> Phone         => ");
		rewind(stdin);
		scanf("%s", &S.phone);

		printf("\t\t-> Address       => ");
		rewind(stdin);
		scanf("%[^\n]", &S.add.address);

		do {
			printf("\t\t-> Postcode      => ");
			rewind(stdin);
			scanf("%d", &S.add.postCode);
			if (S.add.postCode > 99999 || S.add.postCode < 10000)
			{
				printf("\t\tInvalid Postcode, Please Re-enter\n");
			}
		} while (S.add.postCode > 99999 || S.add.postCode < 10000);

		printf("\t\t-> City          => ");
		rewind(stdin);
		scanf("%[^\n]", &S.add.city);

		do
		{
			printf("\t\t-> Day of Birth  => ");
			rewind(stdin);
			scanf("%d", &S.DOB.day);
			printf("\t\t-> Month of Birth=> ");
			rewind(stdin);
			scanf("%d", &S.DOB.month);
			printf("\t\t-> Year of Birth => ");
			rewind(stdin);
			scanf("%d", &S.DOB.year);
			//DOB validation
			switch (S.DOB.month)
			{
			case 1: if (S.DOB.day > 31) { valid = 1; }
				  else { valid = 0; } break;
			case 2: if (S.DOB.year % 4 == 0) { if (S.DOB.day > 29) { valid = 1; } else { valid = 0; } }
				  else { if (S.DOB.day > 28) { valid = 1; } else { valid = 0; } } break;
			case 3: if (S.DOB.day > 31) { valid = 1; }
				  else { valid = 0; } break;
			case 4: if (S.DOB.day > 30) { valid = 1; }
				  else { valid = 0; } break;
			case 5: if (S.DOB.day > 31) { valid = 1; }
				  else { valid = 0; } break;
			case 6: if (S.DOB.day > 30) { valid = 1; }
				  else { valid = 0; } break;
			case 7: if (S.DOB.day > 31) { valid = 1; }
				  else { valid = 0; } break;
			case 8: if (S.DOB.day > 31) { valid = 1; }
				  else { valid = 0; } break;
			case 9: if (S.DOB.day > 30) { valid = 1; }
				  else { valid = 0; } break;
			case 10: if (S.DOB.day > 31) { valid = 1; }
				   else { valid = 0; } break;
			case 11: if (S.DOB.day > 30) { valid = 1; }
				   else { valid = 0; } break;
			case 12: if (S.DOB.day > 31) { valid = 1; }
				   else { valid = 0; } break;
			default: valid = 1; break;
			}
			if (S.DOB.year < 1800 || S.DOB.year  > 2022) { valid = 1; }
			if (valid == 1)
			{
				printf("\n\t\t***Invalid Date!!! \n");
			}
		} while (valid == 1);

		printf("\t\t-> Department    => ");
		rewind(stdin);
		scanf("%[^\n]", &S.department);

		printf("\t\t-> Position      => ");
		rewind(stdin);
		scanf("%[^\n]", &S.position);

		fp2 = fopen("staffInformation.txt", "a");
		if (fp2 == NULL)
		{
			printf("\t\tUnable to open the file\n");
			exit(-1);
		}
		fprintf(fp2, "%s:%s:%c:%s:%s:%d:%s:%d:%d:%d:%s:%s\n", S.id, S.name, S.gender, S.phone, S.add.address, S.add.postCode, S.add.city, S.DOB.day, S.DOB.month, S.DOB.year, S.department, S.position);

		printf("\n\t\t|| SYSTEM : New Staff Record is Added Successfully ||\n");

		printf("\n\t\tDo You Want To Continue To Add Record?[Y/N]\n\t\t");
		rewind(stdin);
		scanf("%c", &choice);

		system("cls");
		printf("\n");
		fclose(fp2);
	} while (toupper(choice) == 'Y');
}


void searchRCD() {
	Staff a, b[50];
	char searchID[10], searchName[50], con;
	int  choose, countId, countName, bCount = 0;

	system("cls");

	FILE* readStaff;
	readStaff = fopen("staffInformation.txt", "r");
	if (readStaff == NULL)
	{
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}

	while (fscanf(readStaff, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", a.id, a.name, &a.gender, a.phone, a.add.address, &a.add.postCode, a.add.city, &a.DOB.day, &a.DOB.month, &a.DOB.year, a.department, a.position) != EOF) {
		b[bCount] = a;
		bCount++;
	}
	fclose(readStaff);
	do {
		countId = 0;
		countName = 0;

		do {
			printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\t\t||                   Search Menu                        ||\n");
			printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\t\t||               1.Search Staff With ID                 ||\n");
			printf("\t\t||               2.Search Staff With Name               ||\n");
			printf("\t\t||               3.Exit                                 ||\n");
			printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\n\t\tPlease enter your choice =>:");
			rewind(stdin);
			scanf("%d", &choose);
			printf("\n");
		} while (choose != 1 && choose != 2 && choose != 3);
		switch (choose) {
		case 1: {
			printf("\t\tSearch Staff with ID =>:");
			rewind(stdin);
			scanf("%s", &searchID);
			printf("\n\t\t---------------------------\n");

			for (int z = 0; z < bCount; z++) {
				if (strcmp(searchID, b[z].id) == 0) {
					printf("\t\tNAME           =>%s\n", b[z].name);
					printf("\t\tGENDER         =>%c\n", b[z].gender);
					printf("\t\tPHONE          =>%s\n", b[z].phone);
					printf("\t\tADDRESS        =>%s%d%s\n", b[z].add.address, b[z].add.postCode, b[z].add.city);
					printf("\t\tDOB            =>%d%d%d\n", b[z].DOB.day, b[z].DOB.month, b[z].DOB.year);
					printf("\t\tDEPARTMENT     =>%s\n", b[z].department);
					printf("\t\tPOSITION       =>%s\n", b[z].position);
					countId++;
				}
			}
			break;
		}
		case 2: {
			printf("\t\tSearch Staff with Name =>:");
			rewind(stdin);
			scanf("%[^\n]", &searchName);
			printf("\n\t\t---------------------------\n");

			for (int y = 0; y < bCount; y++) {
				if (strcmp(searchName, b[y].name) == 0) {
					printf("\t\tID             =>%s\n", b[y].id);
					printf("\t\tGENDER         =>%c\n", b[y].gender);
					printf("\t\tPHONE          =>%s\n", b[y].phone);
					printf("\t\tADDRESS        =>%s%d%s\n", b[y].add.address, b[y].add.postCode, b[y].add.city);
					printf("\t\tDOB            =>%d%d%d\n", b[y].DOB.day, b[y].DOB.month, b[y].DOB.year);
					printf("\t\tDEPARTMENT     =>%s\n", b[y].department);
					printf("\t\tPOSITION       =>%s\n", b[y].position);
					countName++;
				}

			}
			break;
		}
		default:
			printf("\n\t\t|| SYSTEM : INVALID INPUT! PLEASE RE-ENTER... ||");
		}

		printf("\n\t\tDo You Want To Continue To Search Record?[Y/N]\n\t\t");
		rewind(stdin);
		scanf("%c", &con);
		rewind(stdin);
		system("cls");
	} while (toupper(con) != 'N');
}



void modifyRCD() {
	int i, search, option, dob, count = 0, pos, modCount = 0;
	char modifyID[20], choice = 'n';
	Staff S, staff[50];

	system("cls");

	FILE* fp, * fEdit;
	fp = fopen("staffInformation.txt", "r");
	if (fp == NULL)
	{
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}

	while (fscanf(fp, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", staff[count].id, staff[count].name, &staff[count].gender, &staff[count].phone, staff[count].add.address, &staff[count].add.postCode, staff[count].add.city, &staff[count].DOB.day, &staff[count].DOB.month, &staff[count].DOB.year, staff[count].department, staff[count].position) != EOF)
	{
		count++;
	}
	fclose(fp);

	fEdit = fopen("staffinformation.txt", "w");
	if (fEdit == NULL)
	{
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}

	do {
		printf("\n\t\tPlease Enter Staff Id To Be Modified :");
		rewind(stdin);
		scanf("%s", &modifyID);
		printf("\n");
		for (int i = 0; i < count; i++)
		{
			if (strcmp(modifyID, staff[i].id) == 0)
			{
				search = 1;
				pos = 1;
				modCount++;

				do {
					printf("\n\t\t__________________________________________________________\n");
					printf("\t\t|                   Modify Menu                        |\n");
					printf("\t\t--------------------------------------------------------\n");
					printf("\t\t|        Please select 1 field to be modify            |\n");
					printf("\t\t|        1.Name                                        |\n");
					printf("\t\t|        2.Gender                                      |\n");
					printf("\t\t|        3.Phone                                       |\n");
					printf("\t\t|        4.Address                                     |\n");
					printf("\t\t|        5.Date Of Birth                               |\n");
					printf("\t\t|        6.Department                                  |\n");
					printf("\t\t|        7.Position                                    |\n");
					printf("\t\t|        8.Exit                                        |\n");
					printf("\t\t__________________________________________________________\n");
					printf("\n\t\tPlease enter your choice =>:");
					rewind(stdin);
					scanf("%d", &option);
					printf("\n");
					if (option == 1) {
						printf("\t\tEnter new name:");
						rewind(stdin);
						scanf("%[^\n]", S.name);
						strcpy(staff[i].name, S.name);
						printf("\n");
					}
					else if (option == 2) {
						printf("\t\tEnter new gender:");
						rewind(stdin);
						scanf("%c", &S.gender);
						staff[i].gender = S.gender;
						printf("\n");
					}
					else if (option == 3) {
						printf("\t\tEnter new phone:");
						rewind(stdin);
						scanf("%s", &S.phone);
						strcpy(staff[i].phone, S.phone);
						printf("\n");
					}

					else if (option == 4) {
						char add2;
						do {
							printf("\t\tWhich part do you want to modify\n");
							printf("\t\tA.Address\n");
							printf("\t\tB.Postcode\n");
							printf("\t\tC.City\n");
							rewind(stdin);
							scanf("%c", &add2);

							if (add2 == 'A') {
								printf("\t\tEnter new address:");
								rewind(stdin);
								scanf("%[^\n]", S.add.address);
								strcpy(staff[i].add.address, S.add.address);
								printf("\n");
							}
							else if (add2 == 'B') {
								printf("\t\tEnter new postcode:");
								rewind(stdin);
								scanf("%d", &S.add.postCode);
								staff[i].add.postCode = S.add.postCode;
								printf("\n");
							}
							else if (add2 == 'C') {
								printf("\t\tEnter new city:");
								rewind(stdin);
								scanf("%[^\n]", &S.add.city);
								strcpy(staff[i].add.city, S.add.city);
								printf("\n");
							}
							else {
								printf("\n");
								printf("\t\tInvalid Input, Please Re-enter");
							}
						} while (add2 != 'A' && add2 != 'B' && add2 != 'C');
					}
					else if (option == 5) {
						char dob;
						do {
							printf("\t\tWhich part do you want to modify\n");
							printf("\t\ta.Date\n");
							printf("\t\tb.Month\n");
							printf("\t\tc.Year\n");
							rewind(stdin);
							scanf("%c", &dob);
							if (dob == 'a') {
								printf("\t\tEnter new date:");
								scanf("%d", &S.DOB.day);
								staff[i].DOB.day = S.DOB.day;
								printf("\n");
							}
							else if (dob == 'b') {
								printf("\t\tEnter new month:");
								scanf("%d", &S.DOB.month);
								staff[i].DOB.month = S.DOB.month;
								printf("\n");
							}
							else if (dob == 'c') {
								printf("\t\tEnter new year:");
								scanf("%d", &S.DOB.year);
								staff[i].DOB.year = S.DOB.year;
								printf("\n");
							}
							else {
								printf("\t\tInvalid Input, Please Re-enter");
							}
						} while (dob != 'a' && dob != 'b' && dob != 'c');
					}

					else if (option == 6) {
						printf("\t\tEnter new department:");
						rewind(stdin);
						scanf("%[^\n]", &S.department);
						strcpy(staff[i].department, S.department);
						printf("\n");
					}

					else if (option == 7) {
						printf("\t\tEnter new position:");
						rewind(stdin);
						scanf("%[^\n]", &S.position);
						strcpy(staff[i].position, S.position);
						printf("\n");
					}

					else if (option == 8) {
						printf("\n\t\tDo You Want To Exit?[Y/N]\n\t\t");
						rewind(stdin);
						scanf("%c", &choice);
					}
					else {
						printf("\t\tInvalid number Please enter number from 1-8");
					}

				} while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8);
			}

			fprintf(fEdit, "%s:%s:%c:%s:%s:%d:%s:%d:%d:%d:%s:%s\n", staff[i].id, staff[i].name, staff[i].gender, staff[i].phone, staff[i].add.address, staff[i].add.postCode, staff[i].add.city, staff[i].DOB.day, staff[i].DOB.month, staff[i].DOB.year, staff[i].department, staff[i].position);
		}
		fclose(fEdit);

		system("cls");

		printf("\t\t\nDo You Want To Continue To Modify Record?[Y/N]\n\t\t");
		rewind(stdin);
		scanf("%c", &choice);
	} while (choice != 'n' && choice != 'N');
}

void displayRCD() {
	Staff S;
	int count = 0;

	system("cls");

	FILE* readStaff;
	readStaff = fopen("staffInformation.txt", "r");
	if (readStaff == NULL) {
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}

	system("cls");

	printf("\n\n\t\t\t\t                                    ==========================================================");
	printf("\n\n\t\t\t\t                                                         Staff Details\n\n");
	printf("\t\t =================================================================================================================================================================\n");
	printf("\t\tID          NAME         GENDER   PHONE                              ADDRESS                    DATE OF BIRTH   DEPARTMENT                              POSITION\n");
	printf("\t\t =================================================================================================================================================================\n");
	while (fscanf(readStaff, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", S.id, S.name, &S.gender, S.phone, S.add.address, &S.add.postCode, S.add.city, &S.DOB.day, &S.DOB.month, &S.DOB.year, S.department, S.position) != EOF) {
		printf("\t\t%-3s\t: %-8s\t: %c\t: %-10s\t: %25s%d,%-10s\t: %5d/%d/%d\t: %-30s\t: %-10s\n\n", S.id, S.name, S.gender, S.phone, S.add.address, S.add.postCode, S.add.city, S.DOB.day, S.DOB.month, S.DOB.year, S.department, S.position);
		count++;
	}
	printf("\n\n\t\t\t|| SYSTEM : %d record has been listed  ||\n\n", count);
	fclose(readStaff);
}

void deleteRCD() {
	Staff a, b[50];
	int bCount = 0, found = 0;
	char staffId[10], con;

	system("cls");

	FILE* readStaff;
	readStaff = fopen("staffInformation.txt", "r");
	if (readStaff == NULL) {
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}

	while (fscanf(readStaff, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", a.id, a.name, &a.gender, a.phone, a.add.address, &a.add.postCode, a.add.city, &a.DOB.day, &a.DOB.month, &a.DOB.year, a.department, a.position) != EOF) {
		b[bCount] = a;
		bCount++;
	}

	fclose(readStaff);

	system("cls");

	do {
		printf("\n\t\tDelete Staff's Record\n");
		printf("\n\t\tPlease Enter The Staff ID You Want To Delete: ");
		rewind(stdin);
		scanf("%s", &staffId);

		for (int z = 0; z < bCount; z++) {
			if (strcmp(staffId, b[z].id) == 0) {
				found++;
				for (int y = z; y < bCount - 1; y++) {
					b[y] = b[y + 1];
				}
			}
		}
		if (found == 0) {
			printf("\n\t\tNo Match Found! Please Re-Enter\n");
		}
		printf("\t\tDo You Want To Continue To Delete ? (Y=Yes) ");
		scanf("%c", &con);
		rewind(stdin);

	} while (toupper(con) != 'Y');

	FILE* writeStaff;
	writeStaff = fopen("staffInformation.txt", "w");
	if (writeStaff == NULL) {
		printf("\t\tUnable to open the file\n");
		exit(-1);
	}
	for (int pos = 0; pos < bCount - found; pos++) {
		fprintf(writeStaff, "%s:%s:%c:%s:%s:%d:%s:%d:%d:%d:%s:%s\n", b[pos].id, b[pos].name, b[pos].gender, b[pos].phone, b[pos].add.address, b[pos].add.postCode, b[pos].add.city, b[pos].DOB.day, b[pos].DOB.month, b[pos].DOB.year, b[pos].department, b[pos].position);
	}
	fclose(writeStaff);

	printf("\t\t|| SYSTEM : The Staff Record Has Been Deleted ! ||\n");
}

void viewRCD() {
	char searchID[20], choice, record;
	Staff S;

	system("cls");

	FILE* fp;

	do {
		fp = fopen("staffinformation.txt", "r");
		if (fp == NULL)
		{
			printf("\t\tUnable to open the file\n");
			exit(-1);
		}
		record = 0;
		printf("\t\tView Staff ID:");
		rewind(stdin);
		scanf("%s", &searchID);

		while (fscanf(fp, "%[^:]:%[^:]:%c:%[^:]:%[^:]:%d:%[^:]:%d:%d:%d:%[^:]:%[^\n]\n", S.id, S.name, &S.gender, S.phone, S.add.address, &S.add.postCode, S.add.city, &S.DOB.day, &S.DOB.month, &S.DOB.year, S.department, S.position) != EOF) {

			if (strcmp(searchID, S.id) == 0) {
				record = 1;
				printf("\t\tNAME           =>%s\n", S.name);
				printf("\t\tGENDER         =>%c\n", S.gender);
				printf("\t\tPHONE          =>%s\n", S.phone);
				printf("\t\tADDRESS        =>%s%d%s\n", S.add.address, S.add.postCode, S.add.city);
				printf("\t\tDOB            =>%d%d%d\n", S.DOB.day, S.DOB.month, S.DOB.year);
				printf("\t\tDEPARTMENT     =>%s\n", S.department);
				printf("\t\tPOSITION       =>%s\n", S.position);

			}
		}
		if (record) {
			printf("\n\t\tStaff Record Is Found\n");
		}
		else {
			printf("\n\t\tStaff Record Not Found\n");
		}
		printf("\n\t\tDo You Want To Continue To View Record?[Y/N]\n\t\t");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\n");
		fclose(fp);

		system("cls");

	} while (choice != 'n' && choice != 'N');
}

void staff()
{
	system("cls");
	system("color f0");
	int choice = 0;
	do {
		printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t||                   Staff Main Menu                    ||\n");
		printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t||               1.Add Staff Record                     ||\n");
		printf("\t\t||               2.Search Staff Record                  ||\n");
		printf("\t\t||               3.Modify Staff Record                  ||\n");
		printf("\t\t||               4.Display Staff Record                 ||\n");
		printf("\t\t||               5.Delete Staff Record                  ||\n");
		printf("\t\t||               6.View Staff Record                    ||\n");
		printf("\t\t||               0.Exit                                 ||\n");
		printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n\t\tPlease enter your choice => ");
		rewind(stdin);
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addStaff();
			break;
		case 2:
			searchRCD();
			break;
		case 3:
			modifyRCD();
			break;
		case 4:
			displayRCD();
			break;
		case 5:
			deleteRCD();
			break;
		case 6:
			viewRCD();
			break;
		case 0:
			printf("\n\n\t\t\t\t^_^ Thank You And Good Bye ^_^\n\n\n\n\n");

			exit(1);
			break;
		default:
			printf("\t\t|| SYSTEM : INVALID INPUT! PLEASE TRY AGAIN... ||");
		}
	} while (choice != 0);
}