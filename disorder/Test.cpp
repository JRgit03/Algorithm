#include <bits[表情]dc++.h>
using namespace std;
//广搜是遍历完它的所有邻接点 而不是一条路走到黑
//BFS所有邻接点都入队,所有邻接点的步数相同
//用数组存储它的邻接点  1代表相邻，0代表不相邻
//队列是一个结构体类型 存储它的邻接点下标和步数
const int N = 105; //最大行和列
char a[N][N];
int visited[N][N];//一个地图数组和一个访问数组
int s_x, s_y; //开始的xy坐标
int e_x, e_y; //要查找的x y下标

//定义一个方向数组
int dx[4] = {0, 1, 0, -1}; //顺时针方向 右下左上

int dy[4] = {1, 0, -1, 0};

//定义一个队列结构体
struct point {
	int x, y;
	int step;

};
//队列



int main() {
	int t;//t组测试数据
	cin >> t;
	while (t--) {
		int n, m; //定义n行m列
		queue<point> myQueue;
		int flag = 0;
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				visited[i][j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%c", &a[i][j]);
				//记录起点坐标
				if (a[i][j] == 'S') {
					s_x = i;
					s_y = j;
				}
				//记录终点坐标
				if (a[i][j] == 'E') {
					e_x = i;
					e_y = j;
				}
			}
			//吸收一个换行符
			getchar();
		}
		point start;
		start.x = s_x;
		start.y = s_y;
		start.step = 0;
		a[e_x][e_y] = '-'; //把终点改成空地
		myQueue.push(start);
		visited[s_x][s_y] = 1;//将起点标记为已经访问
		while (!myQueue.empty()) {
			//取队首元素下标
			int  x = myQueue.front().x;
			int y = myQueue.front().y;
			int step1 = myQueue.front().step;
			if (x == e_x && y == e_y) {
				//	cout << "好" << endl;
				//是终点坐标
				printf("%d\n", step1);
				flag = 1;
				break;
			}
			//将所有邻接点都入队
			//四个方向试探
			for (int k = 0; k <= 3; k++) {
				int tx, ty;
				tx = x + dx[k];
				ty = y + dy[k];
				if (a[tx][ty] == '-' && visited[tx][ty] == 0) {
					//是空地且没被访问过
					//入队
					point temp;
					temp.x = tx;
					temp.y = ty;
					temp.step = step1 + 1;
					myQueue.push(temp);
					visited[tx][ty] = 1; //标记为已经访问

				}
			}
			//找到它的邻接点入队后 让队首元素出队
			myQueue.pop();


		}
		if (flag == 0) {
			cout << "-1\n";
		}

	}
	return 0;
}