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
		cout<<"请输入选项: ";
		options = 0;
		scanf("%d", &options);
		switch(options){
		case 1:{
			system("cls");
			while(1){
				displayUserMenu();
				cout<<"请输入选项: ";
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
						cout<<"请输入选项: ";
						options = 0;
						scanf("%d", &options);
						switch(options){
							case 1:{
								cout<<"请输入用户编号: ";
								scanf("%s", phoneNumber); 
								deleteUserByPhoneNumber(phoneNumber, &userNum, userList);
								break;
							}
							case 2:{
								cout<<"请输入用户昵称: ";
								scanf("%s", name);
								deleteUserByName(name, &userNum, userList); 
								break;
							}
							default:{
								cout<<"输入有误!"<<endl;
								system("pause"); 
								break;
							}
						}
						break;
					}
					case 3:{
							system("cls");
							displayFindUserMenu();
							cout<<"请输入选项: ";
							options = 0;
							scanf("%d", &options);
							switch(options){
								case 1:{
									cout<<"请输入用户编号: ";
									scanf("%s", phoneNumber);
									displayUserByPhoneNumber(phoneNumber, userNum, userList);
									system("pause");
									break;
								}
								case 2:{
									cout<<"请输入性别(男 女): ";
									scanf("%s", sex);
									displayUserBySex(sex, userNum, userList);
									system("pause");
									break;
								}
								case 3:{
									cout<<"请输入运动天数: ";
									scanf("%d", &options);
									displayUserByMotionDays(options, userNum, userList);
									system("pause");
									break;
								}
								default:{
									cout<<"输入有误!"; 
									system("pause");
									break;
								}
							}
							break;
						}
					
					case 4:{
						cout<<"请输入要修改的用户编号: ";
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
						cout<<"输入有误!";
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
			cout<<"请输入你想要修改的用户号: ";
			cin>>phoneNumber; 
			changeUserInfo(phoneNumber, userNum, userList);
			break;
		}
		case 3:{
			system("cls");
			displayRankMenu();
			cout<<"请输入选项: ";
			options = 0;
			scanf("%d", &options);
			switch(options){
				case 1:{
					displayRankByDay(userNum, userList);
					break;
				}
				case 2:{
					cout<<"请输入用户编号: ";
					scanf("%s", phoneNumber); 
					displayRankByWeek(phoneNumber, userNum, userList);
					break;
				}
				case 3:{
					displayRankByMotionDays(userNum, userList);
					break;
				}
				default:{
					cout<<"输入有误！"; 
					break;
				}
			}
			break;
		}
		case 4:{
			displayMapInfo(G);
			cout<<"请输入起点编号(1-20): ";
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
			cout<<"输入有误,请重新输入!"<<endl;
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
