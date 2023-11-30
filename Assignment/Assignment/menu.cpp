#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

void staff();
void facilityMenu();
void memberMenu();
void bookingMenu();
void facilityUsage();

void main() {
	int choice;

	printf("\n|X============================================================X|\n");
	printf("|X              ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤                                X|\n");
	printf("|X              ©¤©¤¨X¨[©¤©¤©¤©¤©¤©¤¨X¨[©¤©¤                                X|\n");
	printf("|X              ©¤¨X¨a¨^¨[©¤©¤©¤©¤©¤¨U¨U©¤©¤                                X|\n");
	printf("|X              ©¤¨^¨[¨X¨p¨T¨T¨j¨T¨T¨g¨U©¤©¤                                X|\n");
	printf("|X              ©¤©¤¨U¨U¨U¨X¨[¨U¨X¨[¨U¨U©¤©¤                                X|\n");
	printf("|X              ©¤©¤¨U¨^¨g¨^¨a¨U¨^¨a¨U¨^¨[©¤                                X|\n");
	printf("|X              ©¤©¤¨^¨T¨m¨T¨T¨m¨T¨T¨m¨T¨a©¤                                X|\n");
	printf("|X              ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤                                X|\n");
	printf("|X              Welcome to Double Tool CLUB                   X|\n");
	printf("|X============================================================X|\n\n");


	printf("|X============================================================X|\n");
	printf("|X                       Module Choice                        X|\n");
	printf("|X============================================================X|\n");
	printf("|X            1. Staff Information Management System          X|\n");
	printf("|X            2. Facility Management System                   X|\n");
	printf("|X            3. Member Information Management System         X|\n");
	printf("|X            4. Booking System                               X|\n");
	printf("|X            5. Facility Usage Module                        X|\n");
	printf("|X            0. Exit the program                             X|\n");
	printf("|X============================================================X|\n");
	

	do{
		printf("\nEnter number of module (only 1 - 5, 0 = exit) >>> ");
		rewind(stdin);
		scanf("%d", &choice);

		switch (choice) {
		case 1: staff(); break;
		case 2: facilityMenu(); break;
		case 3: memberMenu(); break;
		case 4: bookingMenu(); break;
		case 5: facilityUsage(); break;
		case 0: printf("\n|X============================================================X|\n");
				printf("|X                     End the program.                       X|\n"); 
				printf("|X============================================================X|\n\n"); 
				exit(-1);
		default: printf("\n\tInvalid input, please enter again!!!\n");
		}
	} while (choice < 0 || choice >5);
	printf("\n\t\t|X============================================================X|\n");
	printf("\t\t|X                     End the program.                       X|\n");
	printf("\t\t|X============================================================X|\n\n");
	exit(-1);
}