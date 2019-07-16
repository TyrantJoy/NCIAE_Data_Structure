#ifndef _USER_H_ 
#define _USER_H_

#include "tools.h"
 
typedef struct user
{
	char name[20];
	char phoneNumber[12];
	char sex[2];
	int record[7];
	int age;
	double averageSteps;
	int motionDays;
}user;

int inputUserSteps(int index, user* userList[]);
int inputUserInfo(int index, int userNum, user* userList[]);
int addUser(int* userNum, user* userList[]);
int deleteUserByPhoneNumber(char* phoneNumber, int* userNum, user* userList[]);
int deleteUserByName(char* name, int* userNum, user* userList[]);
int changeUserInfo(char* phoneNumber, int userNum, user* userList[]);
int changeUserSteps(char* phoneNumber, int userNum, user* userList[]);
int findUserByPhoneNumber(char* phoneNumber, int userNum, user* userList[]);
int findUserByName(char* name, int userNum, user* userList[]);
int displayUserList(int userNum, user* userList[]);
int displayUserByIndex(int index, user* userList[]);
int displayUserBySex(char* sex, int userNum, user* userList[]);
int displayUserByPhoneNumber(char* phoneNumber,int userNum, user* userList[]);
int displayUserByMotionDays(int daysNum, int userNum, user* userList[]);

#endif 
