
#include "Snake.h"

//判断是否再来一局
bool Determine(char str[]) {
	char arr1[4] = "Yes";
	char arr2[4] = "YES";
	char arr3[2] = "Y";
	char arr4[2] = "y";

	if (   strcmp(str, arr1) == 0 
		|| strcmp(str, arr2) == 0
		|| strcmp(str, arr3) == 0
		|| strcmp(str, arr4) == 0) {
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
			//cleardevice();
			//outtextxy(100, 100, _T("UP"));

			pSnakeGame->direction = UP;
		}
		//向下
		else if (KEY_PRESS(VK_DOWN)) {
			pSnakeGame->direction = DOWN;
		}
		//向左
		else if (KEY_PRESS(VK_LEFT)) {
			pSnakeGame->direction = LEFT;
		}
		//向右
		else if (KEY_PRESS(VK_RIGHT)) {
			pSnakeGame->direction = RIGHT;
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
		else if (KEY_PRESS(0x31)) {
			
			pSnakeGame->SleepTime -= 30;
			if (pSnakeGame->SleepTime < MIN_SLEEP_TIME) pSnakeGame->SleepTime = MIN_SLEEP_TIME;

			pSnakeGame->food_score += 5;
			if (pSnakeGame->food_score > MAX_FOOD_SCORE) pSnakeGame->food_score = MAX_FOOD_SCORE;
		}
		// F4：减速
		else if (KEY_PRESS(0x32)) {
			pSnakeGame->SleepTime += 30;
			if (pSnakeGame->SleepTime > MAX_SLEEP_TIME) pSnakeGame->SleepTime = MAX_SLEEP_TIME;

			pSnakeGame->food_score -= 5;
			if (pSnakeGame->food_score < MIN_FOOD_SCORE) pSnakeGame->food_score = MIN_FOOD_SCORE;
		}

		//休眠
		Sleep(pSnakeGame->SleepTime);

		// 蛇走一步
		SnakeMove(pSnakeGame);

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
	case KILL_BY_INNER_WALL:
		outtextxy(250, 200, _T("您撞到内部墙了,游戏结束!"));
		break;
	case KILL_BY_SELF:
		outtextxy(250, 200, _T("您撞到自己了,游戏结束!"));
		break;
	}
	
	// 释放蛇节点
	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;
	while (pHead != NULL) {
		SnakeNode* q = pHead->next;

		free(pHead);
		pHead = q;
	}

	// 释放Food
	SnakeNode* pFood = pSnakeGame->pFood;
	if (pFood != NULL) {
		free(pFood);
	}

	//释放内部Wall
	Wall* pWall = pSnakeGame->pWall;
	while (pWall != NULL) {
		Wall* q = pWall->next;

		free(pWall);
		pWall = q;
	}

	return;
}


//打印欢迎信息，包括方向键功能，ESC：退出游戏， 空格：暂停， F3/F4：加速减速
void PrintWelcome() {

}

//创建游戏地图：打印一圈墙
void CreateMap(){
	// 创建绘图窗口
    initgraph(WINDOW_WIDTH_PIX, WINDOW_HEIGHT_PIX);  

	IMAGE image_wall;
	loadimage(&image_wall, _T("..//Images//wall.jpg"),15,20);

	//上
	for (int x = 0; x < WALL_WIDTH_PIX; x = x + 15) {
		putimage(x, 0, &image_wall);
	}
	//下
	for (int x = 0; x < WALL_WIDTH_PIX; x = x + 15) {
		putimage(x, WALL_HEIGHT_PIX-20, &image_wall);
	}
	//左
	for (int y = 20; y < WALL_HEIGHT_PIX - 20; y = y + 20) {
		putimage(0, y, &image_wall);
	}
	//右
	for (int y = 20; y < WALL_HEIGHT_PIX - 20; y = y + 20) {
		putimage(WALL_WIDTH_PIX - 15, y, &image_wall);
	}


	return;
}






//初始化蛇，蛇以链表形式存储，蛇头pSnakeGame->pSnakeNodeList
void InitSnake(SnakeGame* pSnakeGame) {
	

	//初始化蛇链表
	for (int i = SNAKE_INIT_SIZE-1; i >=0 ; i--) {
		SnakeNode* pNode = new SnakeNode();
		pNode->x = SNAKE_INIT_X - 15 * i;
		pNode->y = SNAKE_INIT_Y;
		pNode->next = NULL;

		insert_snake_node(pSnakeGame->pSnakeNodeList, pNode);
	}

	//打印蛇身
	PrintSnake(pSnakeGame->pSnakeNodeList);
	

	// Food
	pSnakeGame->pFood = NULL;

	// Status
	pSnakeGame->status = OK;

	// 默认向右
	pSnakeGame->direction = INIT;

	// 初始0分
	pSnakeGame->scores = 0;

	// 初始休眠时间
	pSnakeGame->SleepTime = DEFAULT_SLEEP_TIME;

	//食物的初始分数
	pSnakeGame->food_score = DEFAULT_FOOD_SCORE;

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
		x = rand() % (WALL_WIDTH_PIX - 30) + 15;
		y = rand() % (WALL_HEIGHT_PIX - 40) + 20;
	} while (x % 15 != 0 || y % 20 != 0);



	//检查与蛇身是否相交，相交重新随机生成坐标
	bool flag = false;
	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;
	while (pHead != NULL) {
		if (pHead->x == x || pHead->y == y) {
			flag = true;
			break;
		}

		pHead = pHead->next;
	}
	//相交
	if (flag) {
		goto loop;
	}



	// 坐标生成后，创建Food节点（pSnakeGame->pFood如果非空，先free)
	SnakeNode* pFood = pSnakeGame->pFood;
	if (pFood != NULL) {
		free(pFood);
		pSnakeGame->pFood = NULL;
	}

	// 生成food节点
	pFood = new SnakeNode();
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	pSnakeGame->pFood = pFood;

    //加载food
	IMAGE image_food;
	loadimage(&image_food, _T("..//Images//food.jpg"), 15, 20);
	//打印Food
	putimage(pFood->x, pFood->y, &image_food);

	return;
}


/*
     游戏主界面打印帮助信息


*/
void PrintHelpInfo() {
	//显示帮助信息
	outtextxy(WALL_WIDTH_PIX + 15, 40, _T("方向键 ← ↑ → ↓ 控制蛇"));
	outtextxy(WALL_WIDTH_PIX + 15, 80, _T("数字1/数字2 : 加速、减速"));
	outtextxy(WALL_WIDTH_PIX + 15, 120, _T("ESC键 : 退出"));
	outtextxy(WALL_WIDTH_PIX + 15, 160, _T("空格键 : 暂停游戏"));

	return;
}

//刷新显示当前Scores
void ShowScores(SnakeGame* pSnakeGame) {

	// 食物SCORE
	outtextxy(WALL_WIDTH_PIX + 15, 200, _T("当前食物SCORE :"));

	TCHAR food_score[5];
	_stprintf(food_score, _T("%d"), pSnakeGame->food_score);
	settextcolor(RED);
	outtextxy(WALL_WIDTH_PIX + 15, 220, food_score);
	settextcolor(WHITE);

	//显示Score
	outtextxy(WALL_WIDTH_PIX + 15, 260, _T("分数 : "));

	TCHAR score[5];
	_stprintf(score, _T("%d"), pSnakeGame->scores);
	settextcolor(RED);
	outtextxy(WALL_WIDTH_PIX + 15, 280, score);
	settextcolor(WHITE);

	return;
}



/*
    蛇行走
	1. 根据方向计算下一步坐标
	2. 下一步是不是Food ： 1）是Food，吃掉Food  2）不是Food
	3. 重新打印蛇
*/
void SnakeMove(SnakeGame* pSnakeGame) {

	//没有移动，直接退出
	if (pSnakeGame->direction == INIT) return;

	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;

	// Create new node
	SnakeNode* pNode = new SnakeNode();
	switch (pSnakeGame->direction)
	{
	//UP
	case UP:
	{
		pNode->x = pHead->x;
		pNode->y = pHead->y - 20;
	}
	break;

	//DOWN
	case DOWN:
	{
		pNode->x = pHead->x;
		pNode->y = pHead->y + 20;
	}
	break;

	//LEFT
	case LEFT:
	{
		pNode->x = pHead->x-15;
		pNode->y = pHead->y;
	}
	break;

	//右
	case RIGHT:
	{
		pNode->x = pHead->x+15;
		pNode->y = pHead->y;
	}
	break;

	}

	// 判断是不是Food
	if (isFood(pSnakeGame->pFood, pNode)) {
		EatFood(pSnakeGame, pNode);
	}
	//如果不是Food
	else {
		EatAsNoFood(pSnakeGame, pNode);
	}

	// 检查是否撞墙
	KillByWall(pSnakeGame);

	// 检查是否撞到自己
	KillBySelf(pSnakeGame);

	return;
}





/*
    插入蛇节点
*/
void insert_snake_node(SnakeNode* &pHead, SnakeNode* pNode) {
	//空链表
	if (pHead == NULL) {
		pHead = pNode;
		return;
	}

	// 直接插到蛇头
	pNode->next = pHead;
	pHead = pNode;

	return;
}



// 打印蛇身
void PrintSnake(SnakeNode* pHead) {

	//加载蛇头和蛇身
	IMAGE image_snake_head;
	loadimage(&image_snake_head, _T("..//Images//snake_head.jpg"), 15, 20);
	IMAGE image_snake_body;
	loadimage(&image_snake_body, _T("..//Images//snake_body.jpg"), 15, 20);

	SnakeNode* pNode = pHead;
	while (pNode != NULL) {
		// 蛇头
		if (pNode == pHead) {
			putimage(pNode->x, pNode->y, &image_snake_head);
		}
		// 蛇身
		else {
			putimage(pNode->x, pNode->y, &image_snake_body);
		}

		pNode = pNode->next;
	}

	return;
}



// 判断下一个pNode是不是food
bool isFood(SnakeNode* pFood, SnakeNode* pNode) {
	if (pFood == NULL || pNode == NULL) {
		return false;
	}

	if (pFood->x == pNode->x && pFood->y == pNode->y) {
		return true;
	}

	return false;
}


// 吃掉食物
void EatFood(SnakeGame* pSnakeGame, SnakeNode* pNode) {

	//将新节点插到蛇头
	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;
	insert_snake_node(pHead, pNode);
	//蛇头更新
	pSnakeGame->pSnakeNodeList = pHead;

	// 打印
	PrintSnake(pHead);

	// 加分
	pSnakeGame->scores = pSnakeGame->scores + pSnakeGame->food_score;

	//释放原来的food节点
	free(pSnakeGame->pFood);
	pSnakeGame->pFood = NULL;

	//重新CreateFood
	CreateFood(pSnakeGame);

	return;


}

// 不是食物，移动
void EatAsNoFood(SnakeGame* pSnakeGame, SnakeNode* pNode) {

	//将新节点插到蛇头
	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;
	insert_snake_node(pHead, pNode);
	//蛇头可能更新
	pSnakeGame->pSnakeNodeList = pHead;

	// 找到蛇尾
	SnakeNode* q = pHead->next;
	SnakeNode* p = q;
	while (q->next != NULL) {
		p = q;
		q = q->next;
	}

	//将蛇尾从链表中删除
	p->next = NULL;

	//擦除蛇尾（用背景色的矩形框填充）
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	fillrectangle(q->x, q->y, q->x + 15, q->y + 20);   //矩形框，左上坐标：(x,y), 右下坐标(x+15, y+20)

	// 释放蛇尾
	free(q);
	
	// 打印
	PrintSnake(pHead);

	return;

}



// 检查是否撞墙
int KillByWall(SnakeGame* pSnakeGame) {

	SnakeNode* pNode = pSnakeGame->pSnakeNodeList;

	while (pNode) {
		if (   pNode->x == 0 || pNode->x == WALL_WIDTH_PIX - 15
			|| pNode->y == 0 || pNode->y == WALL_HEIGHT_PIX - 20) {
			pSnakeGame->status = KILL_BY_WALL;
			return 1;
		}

		pNode = pNode->next;
	}

	return 0;

}






// 检查是否撞到自己
int KillBySelf(SnakeGame* pSnakeGame) {

	// 头节点
	SnakeNode* pHead = pSnakeGame->pSnakeNodeList;

	// 检查链表中是否有和头节点坐标重复的
	SnakeNode* pNode = pHead->next;
	while (pNode != NULL) {
		if (pNode->x == pHead->x && pNode->y == pHead->y) {
			pSnakeGame->status = KILL_BY_SELF;

			return 1;
		}

		pNode = pNode->next;
	}

	return 0;
}