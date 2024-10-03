/*
    定义用到的结构、宏定义、常量等等。
*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>

// EasyX 
#include <graphics.h>
#include <conio.h>




//  ------- 宏定义  ------------
// 窗口大小（基于节点，15*75， 20*25）
#define WINDOW_WIDTH   75
#define WINDOW_HEIGHT  25
//窗口大小（基于像素）
#define WINDOW_WIDTH_PIX  15*WINDOW_WIDTH
#define WINDOW_HEIGHT_PIX 20*WINDOW_HEIGHT


// 围墙大小(基于节点，15*60, 20*25)
#define WALL_WIDTH     60
#define WALL_HEIGHT    25
// 围墙大小（基于像素）
#define WALL_WIDTH_PIX  15*WALL_WIDTH
#define WALL_HEIGHT_PIX 20*WALL_HEIGHT

//蛇身节点数
#define SNAKE_INIT_SIZE 4
#define SNAKE_INIT_X    150
#define SNAKE_INIT_Y    60

//内部墙的初始坐标
#define WALL_FIRST_LEFT_TOP_X  210
#define WALL_FIRST_LEFT_TOP_Y  100
#define WALL_FIRST_RIGHT_LOW_X 225
#define WALL_FIRST_RIGHT_LOW_Y 260

#define WALL_SECOND_LEFT_TOP_X  480
#define WALL_SECOND_LEFT_TOP_Y  300
#define WALL_SECOND_RIGHT_LOW_X 660
#define WALL_SECOND_RIGHT_LOW_Y 320


//====================
// 虚拟键代码： 可以搜索到常用虚拟键代码
// 如果最低位被置为1则说明，该按键被按过，否则为0。 
// 如果我们要判断⼀个键是否被按过，可以检测GetAsyncKeyState返回值的最低值是否为1
//====================
#define KEY_PRESS(VK) ((GetAsyncKeyState(VK)&0x1)?1:0)





//------ enum --------
// 游戏的状态
enum GAME_STATUS {
    OK = 1,             // 正常运行状态
    ESC,                // 按了ESC，正常退出
    KILL_BY_WALL,       // 撞到外墙
    KILL_BY_INNER_WALL, // 撞到内部墙
    KILL_BY_SELF        // 撞到自身
};


// 蛇头的方向
enum DIRECTION {
    UP  =1,       //向上
    DOWN,         //向下
    LEFT,         //向左
    RIGHT,        //向右
    INIT          //向右
};


enum SLEEP_TIME {
    MIN_SLEEP_TIME     = 50,    //最小
    DEFAULT_SLEEP_TIME = 300,   //初始
    MAX_SLEEP_TIME     = 500    //最大
};

enum FOOD_SCORES {
    MIN_FOOD_SCORE     = 5,    //最小
    DEFAULT_FOOD_SCORE = 20,   //初始
    MAX_FOOD_SCORE     = 40    //最大
};







// -------- 结构定义  -----------

/*
    蛇节点用链表结构存储，存储坐标
*/
struct SnakeNode {
    int x;
    int y;

    SnakeNode* next;
};

//内部墙
struct Wall {
    //矩形墙的左上点坐标(x是15倍数，y是20倍数）
    int left_top_x;
    int left_top_y;

    //矩形墙的右下点坐标
    int right_low_x;
    int right_low_y;

    Wall* next;
};




/*
    游戏封装，包含蛇、食物、状态、score
*/
struct SnakeGame {
    // 蛇节点链表
    SnakeNode* pSnakeNodeList;         

    // Food
    SnakeNode* pFood;

    Wall* pWall;

    // 游戏当前状态
    GAME_STATUS status;

    // 蛇当前行进的方向
    DIRECTION direction;

    // 当前Scores
    int scores;

    // 蛇休眠时间，休眠时间越短，蛇的速度越快，休眠时间越长，蛇的速度越慢，用来控制游戏的难度
    int SleepTime;

    // 当前食物的score，蛇的速度越快，食物的score越高
    int food_score;

};



// -------- 函数定义  -----------
bool Determine(char str[]);

void SetPos(int x, int y);

void GameStart(SnakeGame* pSnakeGame);

void GameRun(SnakeGame* pSnakeGame);

void GameEnd(SnakeGame* pSnakeGame);

void PrintWelcome();
void CreateMap();
void InitSnake(SnakeGame* pSnakeGame);
void CreateFood(SnakeGame* pSnakeGame);

void PrintHelpInfo();
void ShowScores(SnakeGame* pSnakeGame);
void SnakeMove(SnakeGame* pSnakeGame);


void insert_snake_node(SnakeNode*& pHead, SnakeNode* pNode);

void PrintSnake(SnakeNode* pHead);

bool isFood(SnakeNode* pFood, SnakeNode* pNode);


void EatFood(SnakeGame* pSnakeGame, SnakeNode* pNode);
void EatAsNoFood(SnakeGame* pSnakeGame, SnakeNode* pNode);

int KillByWall(SnakeGame* pSnakeGame);
int KillBySelf(SnakeGame* pSnakeGame);