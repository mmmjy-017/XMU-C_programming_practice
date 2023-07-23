#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;
// 由于是直接用字符数组存数独，以字符串的方式读入，每行后面在读入的时候会被自动加上一个 '\0'，所以数组大小 N 要开到 10，才能避免溢出。

char g[N][N];

bool dfs(int x, int y) {
	if (y == 9) return true;                  // 如果当前列跳出了最后一列，则直接放回 true
	if (x == 9) return dfs(0, y + 1);         // 如果当前行跳出了最后一行，则返回下一列第?行
	if (g[x][y] != '.') return dfs(x + 1, y); // 如果当前行已有数字，直接跳过

	bool st[N];                               // st 数组存当前位置 (x, y) 还能填哪些数
	memset(st, false, sizeof st);             // 要记得初始化~

	for (int i = 0; i < N - 1; i ++ )         // 看一下该列上有哪些数字被填过了
		if (g[i][y] > 47 && g[i][y] < 58)
			st[g[i][y] ^ 48] = true;

	for (int i = 0; i < N - 1; i ++ )         // 看一下该行上有哪些数字被填过了
		if (g[x][i] > 47 && g[x][i] < 58)
			st[g[x][i] ^ 48] = true;

	int sx = x / 3 * 3, sy = y / 3 * 3;       // 找到当前九宫格的左上角位置
	for (int i = sx; i < sx + 3; i ++ )       // 看一下该九宫格内有哪些数字被填过了
		for (int j = sy; j < sy + 3; j ++ )
			if (g[i][j] > 47 && g[i][j] < 58)
				st[g[i][j] ^ 48] = true;

	for (int i = 1; i < N; i ++ )             // 枚举当前格内能填的所有数字
		if (!st[i]) {
			g[x][y] = i ^ 48;                 // 如果能填，那么填上，并搜索下一格
			if (dfs(x + 1, y)) return true;
		}
	g[x][y] = '.';                            // 如果搜完了所有可填数字，或没有可填数字，那么将该格改为未填状态
	return false;                             // 并返回 false
}

int main() {
	for (int i = 0; i < N - 1; i ++ )
		scanf("%s", g[i]);                    // 以字符串方式读入

	dfs(0, 0);                                // 从 (0, 0) 开始爆搜

	for (int i = 0; i < N - 1; i ++) {
		putchar('\n');
		for (int j = 0; j < N - 1; j ++ )
			putchar(g[i][j]);                 // 输出填好的数独。由于数据保证有解且有唯一解，所以不需特判任何情况，直接输出即可
	}
	return 0;
}
