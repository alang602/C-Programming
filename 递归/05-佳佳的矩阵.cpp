
**佳佳的矩阵**

/*
【输入描述】

输入一个正整数n（1≤n≤500），表示你应该输出一个n阶矩阵。

【输出描述】

	输出共包括n行，每行包含n个正整数，表示你输出的矩阵。
 
【样例输入】

4

【样例输出】

10 11 12 1

9  16 13 2

8  15 14 3

7  6  5  4


可以使用递推思路：
第一圈：
10 11 12 1

9        2

8        3

7  6  5  4

然后再递归打印内部的圈

*/





#include <iostream.h>

using namespace std;




/*
        填充数组matrix(size*size)

	起始下表(x,y)
	初始值initValue
*/

void fillMatrix(int** matrix, int x, int y, int size, int initValue) {


	if (size == 0) return;

	if (size == 1) {
		matrix[x][y] = initValue;
		return;
	}

	// 右
	for (int i = 0; i < size; i++) {
		matrix[x][y] = initValue;
		x++;
		initValue++;
	}

	//下
	x = x - 1;
	for (int i = 0; i < size - 1; i++) {
		y--;
		matrix[x][y] = initValue;
		initValue++;
	}

	//左
	for (int i = 0; i < size - 1; i++) {
		x--;
		matrix[x][y] = initValue;
		initValue++;
	}

	//上
	for (int i = 0; i < size - 2; i++) {
		y++;
		matrix[x][y] = initValue;
		initValue++;
	}


	//递归
	fillMatrix(matrix, x + 1, y, size - 2, initValue);
}



int main()
{
        
	cout << "please input N:";
	int N;
	cin >> N;

	// 这里的二维数组不是固定大小的，需要根据输入N，动态创建二维数组： N*N
	int** matrix = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		matrix[i] = (int*)malloc(N * sizeof(int));
	}

	// 起始点1是在：第0行N-列：
	fillMatrix(matrix, 0, N-1, N, 1);

	//print
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	//记得释放动态二维数组，防止内存泄漏
	for (int i = 0; i < N; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;


}


