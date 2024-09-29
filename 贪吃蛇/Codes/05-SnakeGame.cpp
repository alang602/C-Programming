
#include "Snake.h"


int main()
{
    setlocale(LC_ALL, "");
    
    char str[4]=" ";
    char c = false;

    char ch;
    do {
        SnakeGame   snakeGame = { 0 };

        //游戏开始
        GameStart(&snakeGame);

        //游戏运行
        GameRun(&snakeGame);

        //游戏结束
        GameEnd(&snakeGame);

        // 重复游戏
        outtextxy(250, 240, _T("再来一局吗（Yes/No):"));

        scanf("%s", str);
        c = Determine(str);


        //ch = getchar();
        //getchar();       // 读取回车
        //system("cls");
    } while (c); //while (ch == 'Y' || ch == 'y');
    

    //closegraph();

    return 0;
}


