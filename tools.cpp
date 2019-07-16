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
		return "周一";
	if(flag == 1)
		return "周二";
	if(flag == 2)
		return "周三";
	if(flag == 3)
		return "周四";
	if(flag == 4)
		return "周五";
	if(flag == 5)
		return "周六";
	if(flag == 6)
		return "周日";			
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
	printf("**         运动信息管理系统            **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	printf("**① %-8s\t② %-8s**\n", "用户信息管理", "修改运动信息");
	printf("**③ %-8s\t\t④ %-8s**\n", "运动排行榜", "定制运动路线");
	printf("**⑤ %-8s\t\t⑥ %-8s    **\n", "数据保存", "退出系统");
	printf("*****************************************\n");
}

void displayUserMenu(){
	printf("*****************************************\n");
	printf("**           用户信息管理              **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	printf("**① %-8s\t\t  ② %-8s**\n", "添加用户", "删除用户");
	printf("**③ %-8s\t\t  ④ %-8s**\n", "查询用户", "修改用户");
	printf("**⑤ %-8s\t  ⑥ %-8s**\n", "显示所有用户","返回上一层");
	printf("*****************************************\n");
}

void displayDeleteUserMenu(){
	printf("*****************************************\n");
	printf("**              删除用户               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	printf("**① %-8s         ② %-8s**\n", "按用户号删除", "按昵称删除");
	printf("*****************************************\n");
}

void displayFindUserMenu(){
	printf("*****************************************\n");
	printf("**              查询用户               **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	printf("**① %-8s         ② %-8s**\n", "按用户号查询", "按性别查询");
	printf("**③ %-8s\n", "按连续运动天数查询");
	printf("*****************************************\n");
}

void displayRankMenu(){
	printf("*****************************************\n");
	printf("**               排行榜                **\n");
	printf("**       Made By Tyrant Lucifer        **\n"); 
	printf("*****************************************\n");
	printf("◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("*****************************************\n");
	printf("**① %-8s           ② %-8s**\n", "当天排行榜", "一周排行榜");
	printf("**③ %-8s\n", "连续运动天数");
	printf("*****************************************\n");
} 


 

