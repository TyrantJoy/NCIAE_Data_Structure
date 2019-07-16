#ifndef _INIT_H_ 
#define _INIT_H_ 

#include "rank.h"
#include "map.h"

int initUserInfo(user* userList[]);
Graph* initMapInfo();
int saveData(int userNum, user* userList[]);

#endif
