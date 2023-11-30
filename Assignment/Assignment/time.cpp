#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

int todayDate() { 
    SYSTEMTIME time;

    GetLocalTime(&time); //to get UTC time 

    printf("\n\t----------------------------------------------------\n");
    printf("\t\t\tToday is %d / %d / %d\n", time.wDay, time.wMonth, time.wYear); // Return year, month, day
    printf("\t----------------------------------------------------\n");

    return 0;
}