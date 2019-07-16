#include "init.h"

int main()
{
	user *userList[MAX];
	Graph* G;
	G = initMapInfo();
	int userNum = initUserInfo(userList);
	int options,mainExitOption=0,userExitOption=0;
	char phoneNumber[12];
	char name[20];
	char sex[2];
	while(1){
		displayMainMenu();
		cout<<"������ѡ��: ";
		options = 0;
		scanf("%d", &options);
		switch(options){
		case 1:{
			system("cls");
			while(1){
				displayUserMenu();
				cout<<"������ѡ��: ";
				options = 0;
				scanf("%d", &options);
				switch(options){
					case 1:{
						system("cls");
						addUser(&userNum, userList);
						break;
					}
					case 2:{
						system("cls");
						displayDeleteUserMenu();
						cout<<"������ѡ��: ";
						options = 0;
						scanf("%d", &options);
						switch(options){
							case 1:{
								cout<<"�������û����: ";
								scanf("%s", phoneNumber); 
								deleteUserByPhoneNumber(phoneNumber, &userNum, userList);
								break;
							}
							case 2:{
								cout<<"�������û��ǳ�: ";
								scanf("%s", name);
								deleteUserByName(name, &userNum, userList); 
								break;
							}
							default:{
								cout<<"��������!"<<endl;
								system("pause"); 
								break;
							}
						}
						break;
					}
					case 3:{
							system("cls");
							displayFindUserMenu();
							cout<<"������ѡ��: ";
							options = 0;
							scanf("%d", &options);
							switch(options){
								case 1:{
									cout<<"�������û����: ";
									scanf("%s", phoneNumber);
									displayUserByPhoneNumber(phoneNumber, userNum, userList);
									system("pause");
									break;
								}
								case 2:{
									cout<<"�������Ա�(�� Ů): ";
									scanf("%s", sex);
									displayUserBySex(sex, userNum, userList);
									system("pause");
									break;
								}
								case 3:{
									cout<<"�������˶�����: ";
									scanf("%d", &options);
									displayUserByMotionDays(options, userNum, userList);
									system("pause");
									break;
								}
								default:{
									cout<<"��������!"; 
									system("pause");
									break;
								}
							}
							break;
						}
					
					case 4:{
						cout<<"������Ҫ�޸ĵ��û����: ";
						scanf("%s", phoneNumber);
						changeUserInfo(phoneNumber, userNum, userList);
						break;
					}
					case 5:{
						displayUserList(userNum, userList);
						system("pause");
						break;
					} 
					case 6:{
						userExitOption = 1;
						break;
					} 
					default:{
						cout<<"��������!";
						system("pause");
						break;
					}
				}
				if(userExitOption)
					break;
				system("cls");
				fflush(stdin);
			}
			break;
		}
		case 2:{
			cout<<"����������Ҫ�޸ĵ��û���: ";
			cin>>phoneNumber; 
			changeUserInfo(phoneNumber, userNum, userList);
			break;
		}
		case 3:{
			system("cls");
			displayRankMenu();
			cout<<"������ѡ��: ";
			options = 0;
			scanf("%d", &options);
			switch(options){
				case 1:{
					displayRankByDay(userNum, userList);
					break;
				}
				case 2:{
					cout<<"�������û����: ";
					scanf("%s", phoneNumber); 
					displayRankByWeek(phoneNumber, userNum, userList);
					break;
				}
				case 3:{
					displayRankByMotionDays(userNum, userList);
					break;
				}
				default:{
					cout<<"��������"; 
					break;
				}
			}
			break;
		}
		case 4:{
			displayMapInfo(G);
			cout<<"�����������(1-20): ";
			scanf("%d", &options);
			dijkstra(*G, options-1); 
			break;
		}		
		case 5:{
			saveData(userNum, userList);		
			break;
		}
		case 6:{
			mainExitOption = 1;
			break;
		}
		default:{
			cout<<"��������,����������!"<<endl;
			break;
		}

		}
		if(mainExitOption)
			break;
		system("pause");
		system("cls");
		fflush(stdin);	
	}
	return 0;
}
