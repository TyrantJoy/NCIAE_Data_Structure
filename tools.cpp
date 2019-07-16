#include "tools.h"

double getAverageSteps(int record[]){
	double sum = 0;
	for(int i = 0; i < 7; i++)
		sum += record[i];
	sum = sum / 7.0; 
	return sum;
}

int getMotionDays(int record[]){
	int zeroNums = 0;
	int j = 0;
	int max = 0;
	for(int i = 0; i < 7; i++){
		if(record[i] == 0)
			zeroNums++;		
	}
	int indexs[zeroNums];
	for(int i = 0; i < 7; i++){
		if(record[i] == 0){
			indexs[j] = i;
			j++;
		}	
	}
	if(zeroNums == 0)
		return 7;
	if(zeroNums == 1){
		if(indexs[0] >= 3)
			return indexs[0];
		else
			return (6 - indexs[0]);
	}
	if(indexs[0] > max)
		max = indexs[0];
	if((6 - indexs[zeroNums-1]) > max)
		max = 6 - indexs[zeroNums-1];
	for(int i = 0; i < zeroNums - 1; i++){
		int temp = indexs[i+1] - indexs[i] - 1;
		if(temp > max)
			max = temp;	
	}
	return max;		
}

const char* getWeek(int flag){
	if(flag == 0)
		return "��һ";
	if(flag == 1)
		return "�ܶ�";
	if(flag == 2)
		return "����";
	if(flag == 3)
		return "����";
	if(flag == 4)
		return "����";
	if(flag == 5)
		return "����";
	if(flag == 6)
		return "����";			
}

void invertArray(int a[], int num){
	int i,j,temp;
	for (i=0,j=num-1; i<j; ++i, --j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void displayMainMenu(){
	printf("*****************************************\n");
	printf("**         �˶���Ϣ����ϵͳ            **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	printf("**�� %-8s\t�� %-8s**\n", "�û���Ϣ����", "�޸��˶���Ϣ");
	printf("**�� %-8s\t\t�� %-8s**\n", "�˶����а�", "�����˶�·��");
	printf("**�� %-8s\t\t�� %-8s    **\n", "���ݱ���", "�˳�ϵͳ");
	printf("*****************************************\n");
}

void displayUserMenu(){
	printf("*****************************************\n");
	printf("**           �û���Ϣ����              **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	printf("**�� %-8s\t\t  �� %-8s**\n", "����û�", "ɾ���û�");
	printf("**�� %-8s\t\t  �� %-8s**\n", "��ѯ�û�", "�޸��û�");
	printf("**�� %-8s\t  �� %-8s**\n", "��ʾ�����û�","������һ��");
	printf("*****************************************\n");
}

void displayDeleteUserMenu(){
	printf("*****************************************\n");
	printf("**              ɾ���û�               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	printf("**�� %-8s         �� %-8s**\n", "���û���ɾ��", "���ǳ�ɾ��");
	printf("*****************************************\n");
}

void displayFindUserMenu(){
	printf("*****************************************\n");
	printf("**              ��ѯ�û�               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	printf("**�� %-8s         �� %-8s**\n", "���û��Ų�ѯ", "���Ա��ѯ");
	printf("**�� %-8s\n", "�������˶�������ѯ");
	printf("*****************************************\n");
}

void displayRankMenu(){
	printf("*****************************************\n");
	printf("**               ���а�                **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("����������������������\n");
	printf("*****************************************\n");
	printf("**�� %-8s           �� %-8s**\n", "�������а�", "һ�����а�");
	printf("**�� %-8s\n", "�����˶�����");
	printf("*****************************************\n");
} 


 

