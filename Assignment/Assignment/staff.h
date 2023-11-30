#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

typedef struct {
	char address[50], city[20];
	int postCode;
}Address;

typedef struct {
	int day, month, year;
}Date;

typedef struct {
	char id[15], name[50], phone[15], department[30], position[30], gender;
	Address add;
	Date DOB;
}Staff;