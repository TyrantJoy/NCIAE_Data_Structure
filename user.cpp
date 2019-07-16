#include "user.h"

int inputUserInfo(int index, int userNum, user* userList[]){
	
	cout<<"����������: ";
	scanf("%s", userList[index]->name);
	while(1){
		char phoneNumber[12];
		cout<<"������绰����: ";
		scanf("%s", phoneNumber);
		if(findUserByPhoneNumber(phoneNumber, userNum, userList) == -1 &&
		   strlen(phoneNumber) == 11){
			strcpy(userList[index]->phoneNumber, phoneNumber);
			break;	
		}
		else
			cout<<"�û����Ѿ����ڻ�С��11λ,����������!"<<endl; 
	} 
	
	while(1){
		char sex[2];
		cout<<"�������Ա�: ";
		scanf("%s", sex);
		if(strcmp(sex, "��") == 0 || strcmp(sex, "Ů") == 0){
			strcpy(userList[index]->sex, sex);
			break;
		}
		else
			cout<<"����Ƿ�,����������!"<<endl; 
	}
	
	while(1){
		cout<<"����������: ";
		if(scanf("%d", &userList[index]->age) == 1){
			fflush(stdin);
			break;
		}
		else{
			cout<<"����Ƿ�,����������!"<<endl;
			fflush(stdin);
		}
	}
}

int inputUserSteps(int index, user* userList[]){
	
	for(int i = 0; i < 7; i++){
		while(1){
			cout<<"�������"<<i+1<<"��Ĳ���: ";
			if(scanf("%d", &userList[index]->record[i]) == 1){
				fflush(stdin);
				break;
			}
			else{
				cout<<"����Ƿ�,����������!"<<endl;
				fflush(stdin);
			}
		}
	}
	userList[index]->averageSteps = getAverageSteps(userList[index]->record);
	userList[index]->motionDays = getMotionDays(userList[index]->record);	
}

int addUser(int* userNum, user* userList[]){
	printf("*****************************************\n");
	printf("**              �����û�               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	userList[*userNum] = (user*)malloc(sizeof(user));	
	inputUserInfo(*userNum, *userNum, userList);
	inputUserSteps(*userNum, userList);
	*userNum = *userNum + 1;
	return *userNum;
}

int displayUserList(int userNum, user* userList[]){
	cout<<endl;
	printf("�û���\t\t����\t\t�Ա�\t����\t��һ\t�ܶ�\t����\t����\t����\t����\t����\tƽ����\t������\n"); 
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
		cout<<"δ�ҵ��û�,�û�������,ɾ��ʧ��!"<<endl;
	else{
		int flag;
		cout<<"���ҵ������û�,�Ƿ�ɾ��,1-�� 2-��: "<<endl;
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
				cout<<"ɾ������ȡ��!"<<endl; 		
		}		
		else
			cout<<"�Ƿ�����,ɾ��ʧ��!"<<endl; 	
	} 	
} 

int deleteUserByName(char* name, int* userNum, user* userList[]){
	int index = findUserByName(name, *userNum, userList);
	if(index == -1)
		cout<<"δ�ҵ��û�,�û�������,ɾ��ʧ��!"<<endl;
	else{
		int flag;
		cout<<"���ҵ������û�,�Ƿ�ɾ��,1-�� 2-��: "<<endl;
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
				cout<<"ɾ������ȡ��!"<<endl; 		
		}		
		else
			cout<<"�Ƿ�����,ɾ��ʧ��!"<<endl; 	
	} 	
}

int displayUserByIndex(int index, user* userList[]){
	cout<<endl;
	printf("�û���\t\t����\t\t�Ա�\t����\t��һ\t�ܶ�\t����\t����\t����\t����\t����\tƽ����\t������\n");
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
		cout<<"δ�ҵ��û�,�û�������!"<<endl;
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
		cout<<"δ�ҵ��û�,�û�������!"<<endl;
	else{
		cout<<"�û���Ϣ�Ѿ��ҵ�,������ʾ:"<<endl;
		displayUserByIndex(index, userList);
		inputUserInfo(index, userNum, userList);
		cout<<"�û���Ϣ�Ѿ��޸����,������ʾ:"<<endl;
		displayUserByIndex(index, userList);
	}
}

int changeUserSteps(char* phoneNumber, int userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, userNum, userList);
	if(index == -1)
		cout<<"δ�ҵ��û�,�û�������!"<<endl;
	else{
		cout<<"�û���Ϣ�Ѿ��ҵ�,������ʾ:"<<endl;
		displayUserByIndex(index, userList);
		inputUserSteps(index, userList);
		cout<<"�û���Ϣ�Ѿ��޸����,������ʾ:"<<endl;
		displayUserByIndex(index, userList);
	}
}
