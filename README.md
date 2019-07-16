# NCIAE_ Data_Structure

### 概述

​	本项目是源自于北华航天工业学院大二数据结构科目的结业实训，整体来说较为简单，主要是数据结构中一些基础知识：例如线性表的删除、遍历、增加、排序；图的生成与迪杰斯特拉算法；文件的读写等。

### 模块设计

#### 1.初始化模块（init.cpp）

 - 初始化用户信息
 - 初始化图信息

#### 2. 用户信息管理模块（user.cpp）

- 增加用户
- 删除用户
- 查找用户
- 修改用户

#### 3. 排序模块（rank.cpp）

- 冒泡排序

#### 4. 辅助功能模块（tools.cpp）

- 求平均步数
- 求连续运动天数
- 求星期
- 数组转置
- 打印菜单

#### 5. 图结构模块（map.cpp）

- 构建图
- 迪杰斯特拉算法

### 数据结构设计

- 用户信息结构体

```C
typedef struct user
{
	char name[20];				// 用户昵称
	char phoneNumber[12];		// 用户编号
	char sex[2];				// 用户性别
	int record[7];				// 用户7天步数
	int age;					// 用户年龄
	double averageSteps;		// 用户7天平均步数
	int motionDays;				// 用户连续运动天数
}user;
```

- 图结构体

```C
typedef struct graph
{
    char vexs[MAX][MAX];		// 地点名称
    int vexnum;           		// 节点数目
    float matrix[MAX][MAX];		// 地图边数
}Graph, *PGraph;
```

