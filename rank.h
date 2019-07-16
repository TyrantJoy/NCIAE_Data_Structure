#ifndef _RANK_H_ 
#define _RANK_H_

#include "user.h"

int sortByDay(int userNum, user* userList[], int flag);
int sortByWeek(char* phoneNumber, int userNum, user* userList[]);
int sortByMotionDays(int userNum, user* userList[]);
int displayRankByDay(int userNum, user* userList[]);
int displayRankByWeek(char* phoneNumber, int userNum, user* userList[]);
int displayRankByMotionDays(int userNum, user* userList[]);

#endif
