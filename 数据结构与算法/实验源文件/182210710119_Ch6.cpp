#include <iostream>
#include <cstring>
#include <queue>
#define MAXVEX 100
#define INFINITY 65535
using namespace std;


int visited[MAXVEX] = { 0 };
int stack[MAXVEX];
queue<int> q;

typedef struct stGraph
{
	char vexs[MAXVEX];//���ͼ�ж��������
	int arc[MAXVEX][MAXVEX];//�ڽӾ���
	int VNum, ENum;//������������
}MGraph;

void CreatMGraph(MGraph *G)
{
	int i = 0, j = 0, k = 0;
	cout << "�����붥�����ͱ���(ʾ������6��8)��" << endl;
	cin >> G->VNum >> G->ENum;
	cout << "������ͼ�Ķ��㣨ʾ������0��1��2��3��4��5����\n";
	for (i = 0; i < G->VNum; i++)
	{
		cin >> G->vexs[i];
	}

	for (i = 0; i < G->VNum; i++)
		for (j = 0; j < G->VNum; j++)
		{
			G->arc[i][j] = INFINITY;
		}

	for (k = 0; k < G->ENum; k++)
	{
		cout << "������(vi,vj)�ϵ��±꣬i,j��ʾ������0-1��0-2��0-5��1-2��2-3��2-4��3-4��3-5����" << endl;
		cin >> i >> j ;
		G->arc[i][j] = 1;
		G->arc[j][i] = 1;
	}
}

void DFSTraverse(MGraph *G, int v)
{
	int top = -1;
	int j;
	cout << G->vexs[v] << " "; visited[v] = 1;
	stack[++top] = v;
	while (top != -1)
	{
		v = stack[top];
		for (j = 0; j < G->VNum; j++)
			if (G->arc[v][j] != INFINITY && visited[j] == 0) {
				cout << G->vexs[j] << " ";
				visited[j] = 1;
				stack[++top] = j;
				break;
			}
		if (j == G->VNum) top--;
	}
}

void BFSTraverse(MGraph *G)
{
	int i, j;
	for (i = 0; i < G->VNum; i++) visited[i] = 0;

	queue<int> q;
	for (i = 0; i < G->VNum; i++)
	{
		if (visited[i] == 0)
		{
			cout << G->vexs[i] << " ";
			visited[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				i = q.front();
				q.pop();
				for (j = 0; j < G->VNum; j++)
					if (G->arc[i][j] != INFINITY && visited[j] == 0) {
						cout << G->vexs[j] << " ";
						visited[j] = 1;
						j = q.front();
					}
			}
		}
	}
}

int main()
{
	MGraph *G = new MGraph;
	int v;
	CreatMGraph(G);
	cout << "������Ҫ��ΪԴ��Ķ�����±�ֵ��ʾ�����룺0����" ;
	cin>>v;
	cout << "\n��ͼ��������ȱ���˳��Ϊ:" << endl;
	DFSTraverse(G, v);
	cout << endl;
	cout << "��ͼ�Ĺ�����ȱ���˳��Ϊ��" << endl;
	BFSTraverse(G);
	return 0;
}
