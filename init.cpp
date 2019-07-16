#include "init.h"

int initUserInfo(user* userList[]){
	FILE *userInfo;
	int i = 0;
	if ((userInfo = fopen("userinfo.txt","r")) == NULL)
		return 0;
	while(!feof(userInfo)){
		userList[i] = (user*)malloc(sizeof(user));
		fscanf(userInfo, "%s %s %s %d %d %d %d %d %d %d %d\n",  userList[i]->name, 
										  					    userList[i]->phoneNumber, 
										  						userList[i]->sex, 
										  						&userList[i]->age,
																&userList[i]->record[0], 
												   				&userList[i]->record[1],
												   				&userList[i]->record[2],
												   				&userList[i]->record[3],
												   				&userList[i]->record[4],
												   				&userList[i]->record[5],
												   				&userList[i]->record[6]);
		userList[i]->averageSteps = getAverageSteps(userList[i]->record);
		userList[i]->motionDays = getMotionDays(userList[i]->record);
		i = i + 1;
	}
	fclose(userInfo);
	return i;
} 

Graph* initMapInfo(){
	return createGraph();
}

int saveData(int userNum, user* userList[]){
	FILE *userInfo;
	if((userInfo=fopen("userinfo.txt","w"))==NULL)
		return 0;
	for(int i = 0; i < userNum; i++){
		fprintf(userInfo, "%s %s %s %d %d %d %d %d %d %d %d\n", userList[i]->name, 
										  					    userList[i]->phoneNumber, 
										  						userList[i]->sex, 
										  						userList[i]->age,
																userList[i]->record[0], 
												   				userList[i]->record[1],
												   				userList[i]->record[2],
												   				userList[i]->record[3],
												   				userList[i]->record[4],
												   				userList[i]->record[5],
												   				userList[i]->record[6]);
	}
	fclose(userInfo);
	cout<<"用户信息已经保存!"<<endl; 
	return 0;
}

