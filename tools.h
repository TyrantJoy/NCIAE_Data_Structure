#ifndef _TOOLS_H_ 
#define _TOOLS_H_

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double getAverageSteps(int record[]);
int getMotionDays(int record[]);
const char* getWeek(int flag);
void invertArray(int a[], int num);
void displayMainMenu();
void displayUserMenu();
void displayDeleteUserMenu();
void displayFindUserMenu(); 
void displayRankMenu(); 

#endif
