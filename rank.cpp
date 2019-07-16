#include "rank.h"

int sortByDay(int userNum, user* userList[], int flag){
	int i, j;
	user* temp;
    for (i=0; i<userNum-1; i++){
    	for (j=0; j<userNum-1-i; j++){ 
            if (userList[j]->record[flag-1] < userList[j+1]->record[flag-1]){
                temp = userList[j];
                userList[j] = userList[j+1];
                userList[j+1] = temp;
            }
        } 
	}
	cout<<endl;
	cout<<"��"<<flag<<"�����а�����:"<<endl;
}

int sortByMotionDays(int userNum, user* userList[]){
	int i, j;
	user* temp;
    for (i=0; i<userNum-1; i++){
    	for (j=0; j<userNum-1-i; j++){ 
            if (userList[j]->motionDays < userList[j+1]->motionDays){
                temp = userList[j];
                userList[j] = userList[j+1];
                userList[j+1] = temp;
            }
        } 
	}
	cout<<endl;
	cout<<"�����˶��������а�����:"<<endl;
}

int sortByWeek(char* phoneNumber, int userNum, user* userList[]){
	int index = findUserByPhoneNumber(phoneNumber, userNum, userList);
	if(index == -1)
		cout<<"δ�ҵ��û�,�û�������!"<<endl;
	else{
		int i,j,temp;
		int recordTemp[2][7];
		for(i=0; i<7; i++){
			recordTemp[1][i] = userList[index]->record[i];
			recordTemp[0][i] = i;
		}
		for(i=0; i<6; i++){
    		for (j=0; j<6-i; j++){ 
            	if (recordTemp[1][j] < recordTemp[1][j+1]){
            		temp = recordTemp[0][j];
                	recordTemp[0][j] = recordTemp[0][j+1];
                	recordTemp[0][j+1] = temp;
                	temp = recordTemp[1][j];
                	recordTemp[1][j] = recordTemp[1][j+1];
                	recordTemp[1][j+1] = temp;	
            	}
        	} 
		}
		displayUserByIndex(index, userList);
		cout<<"���û����ܲ������а�����:"<<endl;
		for(i=0; i<7; i++){
			cout<<getWeek(recordTemp[0][i])<<": "<<recordTemp[1][i]<<endl;	
		}
			
	}
}

int displayRankByDay(int userNum, user* userList[]){
	int flag;
	cout<<"����������Ҫ�鿴������(1-7): ";
	scanf("%d", &flag);
	sortByDay(userNum, userList, flag);
	displayUserList(userNum, userList);
}

int displayRankByMotionDays(int userNum, user* userList[]){
	sortByMotionDays(userNum, userList);
	displayUserList(userNum, userList);
}

int displayRankByWeek(char* phoneNumber, int userNum, user* userList[]){
	sortByWeek(phoneNumber, userNum, userList);
}
