#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable : 4996)

int todayDate();
void addBooking();
void searchBooking();
void modifyBooking();
void displayBooking();
void cancleBooking();
void sumBooking();
void Register();

struct bookDate {
	int year, month, day;
};

typedef struct {
	char memberID[10], bookID[6], facilityID[6], name[30], timeStr[10], timeEnd[10];
	double costBook, sum;
	struct bookDate date;
}Booking;

typedef struct {
	char memberID[10];
	char memberName[20];
	int age;
	char gender[10];
	char phone[11];
	char email[100];
}Member;

void bookingMenu() {
	Booking book;
	int choice;

	system("cls");
	todayDate();
	printf("\n|X============================================================X|\n");
	printf("|X                       Booking System                       X|\n");
	printf("|X============================================================X|\n");
	printf("|X                    What can I help you?                    X|\n");
	printf("|X============================================================X|\n");
	printf("|X                      1. Create Booking                     X|\n");
	printf("|X                      2. Check Booking                      X|\n");
	printf("|X                      3. Edit Booking                       X|\n");
	printf("|X                      4. Display Booking                    X|\n");
	printf("|X                      5. Cancle Booking                     X|\n");
	printf("|X                      6. Booking Summary                    X|\n");
	printf("|X============================================================X|\n");

	do {
		printf("|X   Enter your choice, only 1 - 6 (Enter 0 to exit) >> ");
		scanf("%d", &choice);
		rewind(stdin);

		switch (choice) {
			case 1: addBooking(); break;
			case 2: searchBooking(); break;
			case 3: modifyBooking(); break;
			case 4: displayBooking(); break;
			case 5: cancleBooking(); break;
			case 6: sumBooking(); break;
			case 0: printf("End the program.\n"); break;
			default: printf("Invalid input, please enter only (0 - 6) \n"); break;
		}
	}while(choice < 0 || choice > 6 );
	
}

void addBooking() {
	FILE* fbook,* fpmb;

	int record = 0;
	char cfMember, cfbook;
	int displayCount = 0;
	int cFacility, ktv, gym, swim, spa, snk, bk, bt, tt, ft;
	int i = 0, mbr = 0;
	char cfmember = 'N', memberID[10], back = 'N', contin = 'N';
	
	Booking book; //declare prod structure variable
	Member member[30];
	
	fbook = fopen("booking.bin", "ab");//open file pointer for add data into booking.bin
	fpmb = fopen("member.txt", "r"); //open file pointer for read data from member.txt

	if (!fbook || !fpmb) 
		printf("FIle Openning Error \n\n");
	else
	{
		printf("|X============================================================X|\n");
		printf("|X   Did you have MemberID (Y = Sign In, N = Register)  >> ");
		rewind(stdin);
		scanf("%c", &cfMember);
		

		if (toupper(cfMember) == 'Y') {
			//signIn function
			while (fscanf(fpmb, "%s %s %d %s %s %s\n", &member[i].memberID, &member[i].memberName, &member[i].age, &member[i].gender, &member[i].phone, &member[i].email) != EOF) {
				i++;	//increase the array index, then continue read
			}
			mbr = i;
			fclose(fpmb);

			printf("|X============================================================X|\n");
			printf("|X   Enter your Member ID >>>");
			rewind(stdin);
			scanf("%s", &memberID);

			for (i = 0; i < mbr; i++) {
				//compare Member ID entered with array code
				if (strcmp(member[i].memberID, memberID) == 0) {
					//display found record on screen
					printf("=================================================\n");
					printf("|Member ID\tName\tAge\tGender\tPhone\tEmail|\n");
					printf("=================================================\n");
					printf("|%s\t%s\t%d\t%s\t%s\t%s|\n", member[i].memberID, member[i].memberName, member[i].age, member[i].gender, member[i].phone, member[i].email);
					printf("=================================================\n");

					printf("It's that you? (Y/N) : ");
					rewind(stdin);
					scanf("%c", &cfmember);

					if (toupper(cfmember) == 'Y') {
						strcpy(book.memberID, member[i].memberID);
						strcpy(book.name, member[i].memberName);
					}
					else {
						printf("Back to Menu!!!\n");
						bookingMenu();
					}

				}
			}
			
			printf("|X============================================================X|\n");
			printf("|X   Enter Book ID (B0000) (XXX to exit)  >>>");
			rewind(stdin);
			scanf("%s", &book.bookID);
			while(strcmp(book.bookID, "XXX") != 0){
				//enter booking information
				printf("|X===========================================X|\n");
				printf("|X         Enter booking information :       X|\n");
				printf("|X===========================================X|\n");
				
				do {
					printf("|X    Which facility you want to booking?    X|\n");
					printf("|X===========================================X|\n");
					printf("|X	     1. Karaoke                      X|\n");
					printf("|X	     2. Gym                          X|\n");
					printf("|X	     3. Swimming pool                X|\n");
					printf("|X	     4. Spa                          X|\n");
					printf("|X	     5. Snooker                      X|\n");
					printf("|X	     6. Basketball court             X|\n");
					printf("|X	     7. Badminton court              X|\n");
					printf("|X	     8. Tennis court                 X|\n");
					printf("|X	     9. Football field               X|\n");
					printf("|X==========================================X|\n");

					printf("|X   Enter number of facility you want to book(only 1-9) : ");
					rewind(stdin);
					scanf("%d", &cFacility);

					printf("================================================\n");
					switch (cFacility) {
					case 1:
						printf("|X   Which Karaoke room you like to book? (only 1-5) >> ");
						scanf("%d", &ktv);
						if (ktv == 1)
							strcpy(book.facilityID, "KA1");
						else if (ktv == 2)
							strcpy(book.facilityID, "KA2");
						else if (ktv == 3)
							strcpy(book.facilityID, "KA3");
						else if (ktv == 4)
							strcpy(book.facilityID, "KA4");
						else if (ktv == 5)
							strcpy(book.facilityID, "KA5");
						else
							printf("Invalid Input!!! Enter again (only 1 - 5)\n");
						break;

					case 2:
						printf("|X   Which Gym room you like to book? (only 1 or 2) >> ");
						scanf("%d", &gym);
						if (gym == 1)
							strcpy(book.facilityID, "G1");
						else if (gym == 2)
							strcpy(book.facilityID, "G2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 3:
						printf("|X   Which Swimming pool you like to book? (only 1 or 2) >> ");
						scanf("%d", &swim);
						if (swim == 1)
							strcpy(book.facilityID, "SP1");
						else if (swim == 2)
							strcpy(book.facilityID, "SP2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 4:
						printf("|X   Which SPA room you like to book? (only 1 or 2) >> ");
						scanf("%d", &spa);
						if (spa == 1)
							strcpy(book.facilityID, "SA1");
						else if (spa == 2)
							strcpy(book.facilityID, "SA2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 5:
						printf("|X   Which Snooker room you like to book? (only 1 or 2) >> ");
						scanf("%d", &snk);
						if (snk == 1)
							strcpy(book.facilityID, "S1");
						else if (snk == 2)
							strcpy(book.facilityID, "S2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 6:
						printf("|X   Which Basketball court you like to book? (only 1 or 2) >> ");
						scanf("%d", &bk);
						if (bk == 1)
							strcpy(book.facilityID, "BK1");
						else if (bk == 2)
							strcpy(book.facilityID, "BK2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 7:
						printf("|X   Which room you like to book? (only 1 or 2) >> ");
						scanf("%d", &bt);
						if (bt == 1)
							strcpy(book.facilityID, "BC1");
						else if (bt == 2)
							strcpy(book.facilityID, "BC2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;
						
					case 8:
						printf("|X   Which Tennis court you like to book? (only 1 or 2) >> ");
						scanf("%d", &tt);
						if (tt == 1)
							strcpy(book.facilityID, "T1");
						else if (tt == 2)
							strcpy(book.facilityID, "T2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					case 9:
						printf("|X   Which Football field you like to book? (only 1 or 2) >> ");
						scanf("%d", &ft);
						if (ft == 1)
							strcpy(book.facilityID, "FT1");
						else if (ft == 2)
							strcpy(book.facilityID, "FT2");
						else
							printf("Invalid Input!!! Enter again (only 1 - 2)\n");
						break;

					default: printf("Invalid Input!!! Enter again (only 1 - 9)\n"); break;
					}
				} while (cFacility < 1 || cFacility > 9);

				todayDate();// display today date for user

				printf("|X   Enter booking date (dd/mm/yyyy)  >> ");
				rewind(stdin);
				scanf("%d/%d/%d", &book.date.day, &book.date.month, &book.date.year);

				printf("|X   Enter your booking start time (hour:min am/pm) >> ");
				rewind(stdin);
				scanf("%[^\n]", &book.timeStr);

				printf("|X   Enter your booking end time (hour:min am/pm) >> ");
				rewind(stdin);
				scanf("%[^\n]", &book.timeEnd);


				printf("|X   Confirm booking or not (Y = Yes, N = No) : ");
				rewind(stdin);
				scanf("%c", &cfbook);;

				if (toupper(cfbook) == 'Y') {//write data into booking.bin binary file
					fwrite(&book, sizeof(Booking), 1, fbook);
					printf("\nBooking have been successful entered !!! \n\n"); record++;
				}
				else if (toupper(cfbook) == 'N') {
					printf("Booking record not confirm!!!\n");
				}
				else {
					printf("Invalid input");
					bookingMenu();
				}
				printf("Enter Book ID (B0000) (XXX to exit)  >>>");
				rewind(stdin);
				scanf("%s", &book.bookID);
			}

			printf("  %d Booking have been sucessful !!!\n\n", record);
			
		}

		else if (toupper(cfMember) == 'N') {
			//register member
			Register();
			printf("Register successful !!!\n");

			printf("Back to booking menu?\n");
			rewind(stdin);
			scanf("%c", &back);
			if (toupper(back) == 'Y') {
				bookingMenu();
			}
			else {
				printf("\n\|X============================================================X|\n");
				printf("|X                     End the program.                       X|\n");
				printf("|X============================================================X|\n\n");
				exit(-1);
			}

		}

		else {
			printf("Invalid input, return to menu");
			bookingMenu();
		}
	}fclose(fbook);//close file pointer

	printf("Have any booking system continue? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &contin);
	if (toupper(contin) == 'Y') {
		bookingMenu();
	}
	else {
		printf("\n\|X============================================================X|\n");
		printf("|X                     End the program.                       X|\n");
		printf("|X============================================================X|\n\n");
		exit(-1);
	}
	
}

void searchBooking() {
	Booking bk[30];
	int i = 0, bCount, found = 0, tStartHour, tStartMin, tEndHour, tEndMin;
	double bookTime;
	char search, schbookID[6], schmemberID[10], contin = 'N';

	FILE* fbook;
	fbook = fopen("booking.bin", "rb");
	if (fbook == NULL) {
		printf("File openning error\n\n");
		exit(-1);
	}

	// read into structure array element until EOF
	while (fread(&bk[i], sizeof(Booking), 1, fbook) != 0) {
		i++;	//increase the array index, then continue read
	}
	//use bCount to keep the number of record read 
	bCount = i;


	printf("Search for Booking ID or Member ID? ( B / M ) >> ");
	rewind(stdin);
	scanf("%c", &search);

	
	if (toupper(search) == 'B') {
		printf("Enter Booking ID, format (B1000) >> ");
		rewind(stdin);
		scanf("%s", &schbookID);

		for (i = 0; i < bCount; i++) {
			//compare Book ID entered with array code
			if (strcmp(bk[i].bookID, schbookID) == 0) {
				//record found
				found = 1;
				//display found record on screen
				printf("--------------------------------------------------------------------------\n");
				printf("BookingID: %s\t\tFacilityID: %s\nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", bk[i].bookID, bk[i].facilityID, bk[i].date.day, bk[i].date.month, bk[i].date.year,bk[i].timeStr, bk[i].timeEnd);
				printf("--------------------------------------------------------------------------\n");
			}
		}


	}
	else if (toupper(search) == 'M') {
		printf("Enter Member ID, format (M1000) >> ");
		rewind(stdin);
		scanf("%s", &schmemberID);
		for (i = 0; i < bCount; i++) {
			//compare member ID entered with array code
			if (strcmp(bk[i].memberID, schmemberID) == 0) {
				//record found
				found = 1;
				//display found record on screen
				printf("--------------------------------------------------------------------------\n");
				printf("Member ID: %s\t\tFacilityID: %s\nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", bk[i].memberID, bk[i].facilityID, bk[i].date.day, bk[i].date.month, bk[i].date.year, bk[i].timeStr, bk[i].timeEnd);
				printf("--------------------------------------------------------------------------\n");
			}
		}
	}
	//end search

	fclose(fbook);
	if (found == 0) {
		printf("Record not found!!!\n");
	}

	printf("Have any booking system continue? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &contin);
	if (toupper(contin) == 'Y') {
		bookingMenu();
	}
	else {
		printf("\n\|X============================================================X|\n");
		printf("|X                     End the program.                       X|\n");
		printf("|X============================================================X|\n\n");
		exit(-1);
	}

}


void modifyBooking() {
	char ans, cont, bookID[6], newBookID[6], updStr[10], updEnd[10], contin = 'N';
	int i = 0, bCount, modiCount = 0, found, updDay, updMonth, updYear;

	FILE* fbook;

	Booking book[30];

	// Open booking.bin file for reading
	fbook = fopen("booking.bin", "rb");
	if (fbook == NULL) {
		printf("File openning error\n\n");
		exit(-1);
	}

	// read into structure array element until EOF
	while (fread(&book[i], sizeof(Booking), 1, fbook) != 0) {
		i++;	//increase the array index, then continue read
	}
	
	bCount = i;//use bCount to keep the number of record read 

	//close file pointer
	fclose(fbook);

	do {
		printf("\nEnter Book ID of the booking to be modified : ");
		rewind(stdin);
		scanf("%s", &bookID);
		
		found = 0;//set found record to 0

		//search Book ID from array until pCount
		for (i = 0; i < bCount; i++) {
			//compare Book ID entered with array code
			if (strcmp(book[i].bookID, bookID) == 0) {
				found = 1;//record found
				//display found record on screen
				printf("--------------------------------------------------------------------------\n");
				printf("Member ID: %s\t\tBooking ID: %s\tFacilityID: %s\nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", book[i].memberID, book[i].bookID, book[i].facilityID, book[i].date.day, book[i].date.month, book[i].date.year, book[i].timeStr, book[i].timeEnd);
				printf("--------------------------------------------------------------------------\n");

				//prompt user enter updated data
				printf("Enter new booking date (dd/mm/yyyy)  >> ");
				rewind(stdin);
				scanf("%d %d %d", &updDay, &updMonth, &updYear);

				printf("Enter your new booking time (Start time-> hour min) >> ");
				rewind(stdin);
				scanf("%[^\n]", &updStr);
				printf("Enter your booking time (End time-> hour min) >> ");
				rewind(stdin);
				scanf("%[^\n]", &updEnd);

				printf("\nConfirm to Modify (Y=yes)? ");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y') {//if ans = Y/y
					//update time into array element
					book[i].date.day = updDay;
					book[i].date.month = updMonth;
					book[i].date.year = updYear;
					strcpy(book[i].timeStr, updStr);
					strcpy(book[i].timeEnd, updEnd);
					modiCount++;
					printf("\nUpdated record: %d\n");
				}
				else
					printf("\n No Changes Made !!! \n");

				//display record after changes made 
				printf("--------------------------------------------------------------------------\n");
				printf("Member ID: %s\t\tBooking ID: %s\tFacilityID: %s\nName: %-15s\tBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", book[i].memberID, book[i].bookID, book[i].facilityID, book[i].name, book[i].date.day, book[i].date.month, book[i].date.year, book[i].timeStr, book[i].timeEnd);
				printf("--------------------------------------------------------------------------\n");

				break; //stop the looping

			}
		}

		if (!found) //if(found == 0)
			printf("\nNo Booking found with Book ID : %s\n", bookID);

		printf("\nAny more record to modify (Y=yes)? ");
		rewind(stdin);
		scanf("%c", &cont);

	} while (toupper(cont) == 'Y'); //loop while cont = Y/y

	// write array of records to file
	//open file pointer for writing
	fbook = fopen("booking.bin", "wb");
	//use for loop to copy record by record into binary file
	for (i = 0; i < bCount; i++);
	fwrite(&book[i], sizeof(Booking), 1, fbook);
	fclose(fbook);

	printf("\n\t%d Record(s) modified.\n\n", modiCount);

	printf("Have any booking system continue? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &contin);
	if (toupper(contin) == 'Y') {
		bookingMenu();
	}
	else {
		printf("\n\|X============================================================X|\n");
		printf("|X                     End the program.                       X|\n");
		printf("|X============================================================X|\n\n");
		exit(-1);
	}

}

void displayBooking() {
	Booking book;
	FILE* fbook;
	int displayCount = 0;
	char contin = 'N';

	fbook = fopen("booking.bin", "rb");

	//display time
	todayDate();
	printf("--------------------------------------------------------------------------\n");
	//Continue read record from booking.bin while !=0
	//if read record successfully will return TRUE
	while (fread(&book, sizeof(Booking), 1, fbook) != 0)
	{	//display on srceen record by record
		printf("Member ID: %-8s\t", book.memberID);
		printf("BookingID: %-7s\t\t", book.bookID);
		printf("FacilityID: %-5s\n", book.facilityID);
		printf("Name: %-15s\t", book.name);
		printf("Booking Date: %02d/%02d/%04d\t", book.date.day, book.date.month, book.date.year);
		printf("From: %s to %s\n", book.timeStr, book.timeEnd);
		printf("--------------------------------------------------------------------------\n");
		

		displayCount++;//accumulate count

	}
	printf("\n %d records listed !! \n\n", displayCount);
	
	fclose(fbook);//close file pointer
	printf("Have any booking system continue? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &contin);
	if (toupper(contin) == 'Y') {
		bookingMenu();
	}
	else {
		printf("\n\|X============================================================X|\n");
		printf("|X                     End the program.                       X|\n");
		printf("|X============================================================X|\n\n");
		exit(-1);
	}
}


void cancleBooking() {
	char ans = 'N', bookID[6], contin = 'N';
	int i = 0, bCount = 0, move, found;

	FILE* fbook;

	Booking book[30];//Create Booking structure variable with 30 elements

	// read booking.bin file into array of records
	fbook = fopen("booking.bin", "rb");
	if (!fbook)
	{
		printf("File open error!!!\n\n");
		return;
	}
	// read into Structure array until EOF
	while (fread(&book[i], sizeof(Booking), 1, fbook) != 0){
		i++;
	}
	bCount = i;
	fclose(fbook);

	printf("\nEnter Book ID of the Booking to be delected : ");
	rewind(stdin);
	scanf("%s", &bookID);
	//set found record to 0
	found = 0;

	//search Book ID from array until bCount
	for (i = 0; i < bCount; i++) {
		if (strcmp(book[i].bookID, bookID) == 0) {//compare Book ID entered with array code

			printf("\n\t\t=============    Record Found   ===========\n");
			printf("--------------------------------------------------------------------------\n");
			printf("Member ID: %-8s\t", book[i].memberID);
			printf("BookingID: %-7s\t\t", book[i].bookID);
			printf("FacilityID: %-5s\n", book[i].facilityID);
			printf("Name: %-15s\t", book[i].name);
			printf("Booking Date: %02d/%02d/%04d\t", book[i].date.day, book[i].date.month, book[i].date.year);
			printf("From: %s to %s\n", book[i].timeStr, book[i].timeEnd);
			printf("--------------------------------------------------------------------------\n");
			found = 1;//record found
		}

			printf("\nConfirm to DELETE (Y=yes)? ");
			rewind(stdin);
			scanf("%c", &ans);
			//if ans = Y/y
			if (toupper(ans) == 'Y') {
				bCount--;//reduce one record

				//assign i to move variable, move following record to move position
				for (move = i; move < bCount; move++) {
					strcpy(book[move].memberID, book[move + 1].memberID);
					strcpy(book[move].bookID, book[move + 1].bookID);
					strcpy(book[move].name, book[move + 1].name);
					book[move].date.day = book[move + 1].date.day;
					book[move].date.month = book[move + 1].date.month;
					book[move].date.year = book[move + 1].date.year;
					strcpy(book[move].timeStr, book[move + 1].timeStr);
					strcpy(book[move].timeEnd, book[move + 1].timeEnd);

					printf("\n=\t===   Record Deleted   ====\n");
					//open file pointer for writing
					fbook = fopen("booking.bin", "wb");
					//use for loop to copy structure array into binary file
					for (i = 0; i < bCount; i++) {
						fwrite(&book[i], sizeof(Booking), 1, fbook);
					}
					fclose(fbook);
				}
			}
			else {
				printf("\t\t====   Record Remain!!!   ====\n");
			}

	}
		
	
	if (found == 0){
		printf("\nNo Booking found with Book ID : %s\n", bookID);
	}
	printf("Have any booking system continue? (Y/N)  : ");
	rewind(stdin);
	scanf("%c", &contin);
	if (toupper(contin) == 'Y') {
		bookingMenu();
	}
	else {
		printf("\n\|X============================================================X|\n");
		printf("|X                     End the program.                       X|\n");
		printf("|X============================================================X|\n\n");
		exit(-1);
	}
}

void sumBooking() {
	Booking book[30];
	FILE* fbook;

	// Open booking.bin file for reading
	fbook = fopen("booking.bin", "rb");

	int option, i = 0, record, found = 0;
	int sumYear, sumMonth, sumDay;
	char contin = 'N';

	if (fbook == NULL) {
		printf("File openning error\n\n");
		exit(-1);
	}
	else {
		while (fread(&book[i], sizeof(Booking), 1, fbook) != 0) {
			i++;	//increase the array index, then continue read
		}
		record = i;

		printf("|X===============================================X|\n");
		printf("|X==========   Booking Summary System   =========X|\n");
		printf("|X===============================================X|\n");
		printf("|X         1. Summary by booking | Year  |       X|\n");
		printf("|X         2. Summary by booking | Month |       X|\n");
		printf("|X         3. Summary by booking | Day   |       X|\n");
		printf("|X===============================================X|\n");

		do {
			printf("|X  Enter which one summary number (1 - 3)  :");
			rewind(stdin);
			scanf("%d", &option);
			printf("|X===============================================X|\n");

			switch (option) {
			case 1:
				printf("Enter year to summary (2000 until 2022) >> ");
				rewind(stdin);
				scanf("%d", &sumYear);

				for (i = 0; i < record; i++) {
					//compare Book ID entered with array code
					if (book[i].date.year == sumYear) {
						found = 1;//record found
						//display found record on screen
						printf("\nBookingID: %s\t\tName: %s \nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", book[i].bookID, book[i].name, book[i].date.day, book[i].date.month, book[i].date.year, book[i].timeStr, book[i].timeEnd);
					}
				}
				printf("Year :%d have %d records found!!!\n", sumYear, record);
				break;

			case 2:
				printf("Enter month to summary (1 - 12) >> ");
				rewind(stdin);
				scanf("%d", &sumMonth);

				for (i = 0; i < record; i++) {
					//compare Book ID entered with array code
					if (book[i].date.month == sumMonth) {
						found = 1;//record found
						//display found record on screen
						printf("\nBookingID: %s\tName: %s \nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", book[i].bookID, book[i].name, book[i].date.day, book[i].date.month, book[i].date.year, book[i].timeStr, book[i].timeEnd);
					}
				}
				printf("Month :%d have %d records found!!!\n", sumMonth, record);
				break;

			case 3:
				printf("Enter day to summary (1 - 30) >> ");
				rewind(stdin);
				scanf("%d", &sumDay);

				for (i = 0; i < record; i++) {
					//compare Book ID entered with array code
					if (book[i].date.day == sumDay) {
						found = 1;//record found
						//display found record on screen
						printf("\nBookingID: %s\tName: %s \nBooking Date: %02d/%02d/%04d\tFrom: %s to %s\n", book[i].bookID, book[i].name, book[i].date.day, book[i].date.month, book[i].date.year, book[i].timeStr, book[i].timeEnd);
					}
				}
				printf("Day :%d have %d records found!!!\n", sumDay, record);
				break;

			default:
				printf("Invalid input, please enter again!!!\n");
				break;
			}
		} while (option < 1 || option > 3);
		if (found == 0) {
			printf("Input not found record!!!\n");
		}
		printf("Have any booking system continue? (Y/N)  : ");
		rewind(stdin);
		scanf("%c", &contin);
		if (toupper(contin) == 'Y') {
			bookingMenu();
		}
		else {
			printf("\n\|X============================================================X|\n");
			printf("|X                     End the program.                       X|\n");
			printf("|X============================================================X|\n\n");
			exit(-1);
		}
	}
}

void Register() {
	FILE* fpmb;  //declare file pointer

	Member member;

	//open file pointer for appending (add) data into member.txt
	fpmb = fopen("member.txt", "a");

	//check if the file NOT EXIST, print error message and exit program
	if (fpmb == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}

	//prompt for first time input
	else {
		printf("|X============================================================X|\n");
		printf("|X   Enter Member ID  : ");
		rewind(stdin);
		scanf("%s", &member.memberID);
		printf("|X============================================================X|\n");
		printf("|X   Enter Member's Name : ");
		rewind(stdin);
		scanf("%[^\n]", &member.memberName);
		printf("|X============================================================X|\n");
		printf("|X   Enter Member's Age : ");
		rewind(stdin);
		scanf("%d", &member.age);
		printf("|X============================================================X|\n");
		printf("|X   Enter Member's Gender : ");
		rewind(stdin);
		scanf("%s", &member.gender);
		printf("|X============================================================X|\n");
		printf("|X   Enter Member's Phone : ");
		rewind(stdin);
		scanf("%s", &member.phone);
		printf("|X============================================================X|\n");
		printf("|X   Enter Member's Email : ");
		rewind(stdin);
		scanf("%s", &member.email);
		printf("|X============================================================X|\n");
		fprintf(fpmb, "%s %s %d %s %s %s\n", member.memberID, member.memberName, member.age, member.gender, member.phone, member.email);

	}
	fclose(fpmb);

}

void addUsage() {

	int i = 0;
	FILE* fRead, * fWrite;
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
	Usage usage[30];
	Booking book[30];

	fRead = fopen("booking.bin", "rb");
	fWrite = fopen("bookingUsage.dat", "wb");

	if (!fRead) {
		printf("file opening error \n\n");
	}
	else {
		while (fread(&book[i], sizeof(Booking), 1, fRead) != 0) {
			strcpy(usage[i].usageID, "A00");
			usage[i].date.day = book[i].date.day;
			usage[i].date.month = book[i].date.month;
			usage[i].date.year = book[i].date.year;
			strcpy(usage[i].time.timeStr, book[i].timeStr);
			strcpy(usage[i].time.timeEnd, book[i].timeEnd);
			strcpy(usage[i].facilityID, book[i].facilityID);
			strcpy(usage[i].memberID, book[i].memberID);
			strcpy(usage[i].usageType, "Booked");
			usage[i].ttlPpl = 0;
			fwrite(&usage[i], sizeof(Usage), 1, fWrite);
			i++;
		}

	}
	fclose(fRead);
	fclose(fWrite);
}