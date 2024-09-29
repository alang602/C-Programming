
#include "Snake.h"

//判断是否再来一局
bool Determine(char str[]) {
	char arr[4] = "Yes";
	int ret = strcmp(str, arr);
	if (ret == 0) {
		return true;
	}
	else {
		return false;
	}
}


//设置光标的位置
void SetPos(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//获取标准输出的句柄(⽤来标识不同设备的数值)
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}


/*
    游戏开始前的初始化工作
*/
void GameStart(SnakeGame* pSnakeGame) {
	//打印欢迎界面
	PrintWelcome();

	//创建地图
	CreateMap();

	//初始化蛇身
	InitSnake(pSnakeGame);

	//初始化食物
	CreateFood(pSnakeGame);

	return;
}


/*
	开始游戏
*/
void GameRun(SnakeGame* pSnakeGame) {

	// 在屏幕右侧打印帮助信息
	PrintHelpInfo();

	// 循环处理
	// 1. 刷新屏幕右侧的Score信息
	// 2. 根据用户输入，不同处理：
	//    1）方向键：  计算下一个节点
	//    2）ESC：    正常退出,更新游戏状态
	//    3）F3/F4:   加速、减速, 加速后增加当前食物的分数，减速后降低当前食物的分数
	//    4) SPACE:   暂停
	do {
		ShowScores(pSnakeGame);

		// 向上
		if (KEY_PRESS(VK_UP)) {
			cleardevice();
			outtextxy(100, 100, _T("UP"));
		}
		//向下
		else if (KEY_PRESS(VK_DOWN)) {
			cleardevice();
			outtextxy(100, 100, _T("DOWN"));
		}
		//向左
		else if (KEY_PRESS(VK_LEFT)) {
			cleardevice();
			outtextxy(100, 100, _T("LEFT"));
		}
		//向右
		else if (KEY_PRESS(VK_RIGHT)) {
			cleardevice();
			outtextxy(100, 100, _T("RIGHT"));
		}
		// ESC 退出
		else if (KEY_PRESS(VK_ESCAPE)) {
			// 更新状态，ESC退出游戏
			pSnakeGame->status = ESC;
		}
		//空格暂停
		else if (KEY_PRESS(VK_SPACE)) {
			// 暂停游戏
			system("pause");
		}
		// F3 : 加速
		else if (KEY_PRESS(VK_F3)) {
			cleardevice();
			outtextxy(100, 100, _T("F3"));
		}
		// F4：减速
		else if (KEY_PRESS(VK_F4)) {
			cleardevice();
			outtextxy(100, 100, _T("F4"));
		}

		// 蛇走一步
		SnakeMove(pSnakeGame);

		//休眠
		Sleep(pSnakeGame->SleepTime);
	} while (pSnakeGame->status == OK);   // 如果不是OK，退出游戏


	return;
}



/*
	开始结束的扫尾工作
*/
void GameEnd(SnakeGame* pSnakeGame) {

	// 根据不同退出status，打印不同退出信息
	switch (pSnakeGame->status) {
	case ESC:
		outtextxy(250, 200, _T("您主动退出游戏!"));
		break;
	case KILL_BY_WALL:
		outtextxy(250, 200, _T("您撞墙了,游戏结束!"));
		break;
	case KILL_BY_SELF:
		outtextxy(250, 200, _T("您撞到自己了,游戏结束!"));
		break;
	}
	
	// 释放蛇节点

	// 释放Food

	return;
}


//打印欢迎信息，包括方向键功能，ESC：退出游戏， 空格：暂停， F3/F4：加速减速
void PrintWelcome() {

}

//创建游戏地图：打印一圈墙
void CreateMap(){
	// 创建绘图窗口
    initgraph(WINDOW_WIDTH_PIX, WINDOW_HEIGHT_PIX);  

	return;
}

//初始化蛇，蛇以链表形式存储，蛇头pSnakeGame->pSnakeNodeList
void InitSnake(SnakeGame* pSnakeGame) {
	

	//初始化蛇链表

	//打印蛇身
	


	pSnakeGame->pFood = NULL;

	// Status
	pSnakeGame->status = OK;

	// 默认向右
	pSnakeGame->direction = RIGHT;

	// 初始0分
	pSnakeGame->scores = 0;

	// 初始休眠时间
	pSnakeGame->SleepTime = DEFAULT_SLEEP_TIME;

	return;

}


// 创建Food, Food不能和蛇身体相交
void CreateFood(SnakeGame* pSnakeGame) {

	// 使用Rand()随机生成Food的坐标

	int x = 0;
	int y = 0;

	srand((unsigned int)time(NULL));

loop:
	do {
		x = rand() % (WINDOW_WIDTH_PIX - 30) + 15;
		y = rand() % (WINDOW_HEIGHT_PIX - 40) + 20;
	} while (x % 15 != 0 || y % 20 != 0);

	//For testing
	outtextxy(x, y, _T("CreateFood"));

	//检查与蛇身是否相交，相交重新随机生成坐标

	// 坐标生成后，创建Food节点（pSnakeGame->pFood如果非空，先free)

	// 打印Food

	return;
}


/*
     游戏主界面打印帮助信息


*/
void PrintHelpInfo() {
	return;
}

//刷新显示当前Scores
void ShowScores(SnakeGame* pSnakeGame) {
	return;
}



/*
    蛇行走
	1. 根据方向计算下一步坐标
	2. 下一步是不是Food ： 1）是Food，吃掉Food  2）不是Food
	3. 重新打印蛇
*/
void SnakeMove(SnakeGame* pSnakeGame) {
	return;
}

