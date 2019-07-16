#include "user.h"

int inputUserInfo(int index, int userNum, user* userList[]){
	
	cout<<"请输入姓名: ";
	scanf("%s", userList[index]->name);
	while(1){
		char phoneNumber[12];
		cout<<"请输入电话号码: ";
		scanf("%s", phoneNumber);
		if(findUserByPhoneNumber(phoneNumber, userNum, userList) == -1 &&
		   strlen(phoneNumber) == 11){
			strcpy(userList[index]->phoneNumber, phoneNumber);
			break;	
		}
		else
			cout<<"用户号已经存在或小于11位,请重新输入!"<<endl; 
	} 
	
	while(1){
		char sex[2];
		cout<<"请输入性别: ";
		scanf("%s", sex);
		if(strcmp(sex, "男") == 0 || strcmp(sex, "女") == 0){
			strcpy(userList[index]->sex, sex);
			break;
		}
		else
			cout<<"输入非法,请重新输入!"<<endl; 
	}
	
	while(1){
		cout<<"请输入年龄: ";
		if(scanf("%d", &userList[index]->age) == 1){
			fflush(stdin);
			break;
		}
		else{
			cout<<"输入非法,请重新输入!"<<endl;
			fflush(stdin);
		}
	}
}

int inputUserSteps(int index, user* userList[]){
	
	for(int i = 0; i < 7; i++){
		while(1){
			cout<<"请输入第"<<i+1<<"天的步数: ";
			if(scanf("%d", &userList[index]->record[i]) == 1){
				fflush(stdin);
				break;
			}
			else{
				cout<<"输入非法,请重新输入!"<<endl;
				fflush(stdin);
			}
		}
	}
	userList[index]->averageSteps = getAverageSteps(userList[index]->record);
	userList[index]->motionDays = getMotionDays(userList[index]->record);	
}

int addUser(int* userNum, user* userList[]){
	printf("*****************************************\n");
	printf("**              增加用户               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	userList[*userNum] = (user*)malloc(sizeof(user));	
	inputUserInfo(*userNum, *userNum, userList);
	inputUserSteps(*userNum, userList);
	*userNum = *userNum + 1;
	return *userNum;
}

int displayUserList(int userNum, user* userList[]){
	cout<<endl;
	printf("用户号\t\t姓名\t\t性别\t年龄\t周一\t周二\t周三\t周四\t周五\t周六\t周日\t平均步\t连续天\n"); 
	for(int i = 0; i < userNum; i++){		
		printf("%d. %s\t%-8s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\t%d\n",
				i + 1,
				userList[i]->phoneNumber,
				userList[i]->name,
				userList[i]->sex,
				userList[i]->age,
				userList[i]->record[0],
				userList[i]->record[1],
				userList[i]->record[2],
				userList[i]->record[3],
				userList[i]->record[4],
				userList[i]->record[5],
				userList[i]->record[6],
				userList[i]->averageSteps,
				userList[i]->motionDays);
	}
	cout<<endl;
	return userNum;
}

int findUserByPhoneNumber(char* phoneNumber, int userNum, user* userList[]){
	for(int i = 0; i < userNum; i++){
		if(strcmp(phoneNumber, userList[i]->phoneNumber) == 0)
			return i;
	}
	return -1;
} 

int findUserByName(char* name, int userNum, user* userList[]){
	for(int i = 0; i < userNum; i++){
		if(strcmp(name, userList[i]->name) == 0)
			return i;
	}
	return -1;
}

int deleteUserByPhoneNumber(char* phoneNumber, int* userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, *userNum, userList);
	if(index == -1)
		cout<<"未找到用户,用户不存在,删除失败!"<<endl;
	else{
		int flag;
		cout<<"已找到以下用户,是否删除,1-是 2-否: "<<endl;
		displayUserByIndex(index, userList);
		scanf("%d",&flag);
		if(flag == 1 || flag == 2){
			if(flag == 1){
				free(userList[index]);
				for(int i = index; i < *userNum - 1; i++){
					userList[i] = userList[i+1];
				}
				*userNum = *userNum - 1;
				userList[*userNum] = NULL;
			}	
			else
				cout<<"删除操作取消!"<<endl; 		
		}		
		else
			cout<<"非法输入,删除失败!"<<endl; 	
	} 	
} 

int deleteUserByName(char* name, int* userNum, user* userList[]){
	int index = findUserByName(name, *userNum, userList);
	if(index == -1)
		cout<<"未找到用户,用户不存在,删除失败!"<<endl;
	else{
		int flag;
		cout<<"已找到以下用户,是否删除,1-是 2-否: "<<endl;
		displayUserByIndex(index, userList);
		scanf("%d",&flag);
		if(flag == 1 || flag == 2){
			if(flag == 1){
				free(userList[index]);
				for(int i = index; i < *userNum - 1; i++){
					userList[i] = userList[i+1];
				}
				*userNum = *userNum - 1;
				userList[*userNum] = NULL;
			}	
			else
				cout<<"删除操作取消!"<<endl; 		
		}		
		else
			cout<<"非法输入,删除失败!"<<endl; 	
	} 	
}

int displayUserByIndex(int index, user* userList[]){
	cout<<endl;
	printf("用户号\t\t姓名\t\t性别\t年龄\t周一\t周二\t周三\t周四\t周五\t周六\t周日\t平均步\t连续天\n");
	printf("%s\t%-8s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\t%d\n",
				userList[index]->phoneNumber,
				userList[index]->name,
				userList[index]->sex,
				userList[index]->age,
				userList[index]->record[0],
				userList[index]->record[1],
				userList[index]->record[2],
				userList[index]->record[3],
				userList[index]->record[4],
				userList[index]->record[5],
				userList[index]->record[6],
				userList[index]->averageSteps,
				userList[index]->motionDays);
	cout<<endl;
}

int displayUserBySex(char* sex, int userNum, user* userList[]){
	for(int i = 0; i < userNum; i++){
		if(strcmp(sex, userList[i]->sex) == 0)
			displayUserByIndex(i, userList);
	}
}

int displayUserByPhoneNumber(char* phoneNumber,int userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, userNum, userList);
	if(index == -1)
		cout<<"未找到用户,用户不存在!"<<endl;
	else
		displayUserByIndex(index, userList);	
}

int displayUserByMotionDays(int daysNum, int userNum, user* userList[]){
	for(int i = 0; i < userNum; i++){
		if(daysNum == userList[i]->motionDays)
			displayUserByIndex(i, userList);
	}
}

int changeUserInfo(char* phoneNumber, int userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, userNum, userList);
	if(index == -1)
		cout<<"未找到用户,用户不存在!"<<endl;
	else{
		cout<<"用户信息已经找到,如下所示:"<<endl;
		displayUserByIndex(index, userList);
		inputUserInfo(index, userNum, userList);
		cout<<"用户信息已经修改完成,如下所示:"<<endl;
		displayUserByIndex(index, userList);
	}
}

int changeUserSteps(char* phoneNumber, int userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, userNum, userList);
	if(index == -1)
		cout<<"未找到用户,用户不存在!"<<endl;
	else{
		cout<<"用户信息已经找到,如下所示:"<<endl;
		displayUserByIndex(index, userList);
		inputUserSteps(index, userList);
		cout<<"用户信息已经修改完成,如下所示:"<<endl;
		displayUserByIndex(index, userList);
	}
}
