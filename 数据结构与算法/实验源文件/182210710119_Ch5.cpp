#include <iostream>
using namespace std;

struct Node {
	char character;
};

class BiTree {
public:
	BiTree(int num, int n);
	~BiTree();
	void PreOrder(int i, int num);
	Node *item;
};

BiTree::BiTree(int num, int n) {
	int top = 0;
	item = new Node[num];
	cout << "\n�밴������������������������ȫ�������Ľڵ����洢��ֵ��ֵΪ�ַ����Ҿ�����Ҫ�ظ�������Ϊ��Ľڵ㣬������#��(ʾ�����룺ABC#D#E����\n";
	for (int i = 0; i < num; i++) {
		cin >> item[i].character;
		if (item[i].character != '#') top++;
		if (top == n) {
			i++;
			do {
				item[i].character = '#';
				i++;
			} while (i < num);
		}
	}
}

BiTree::~BiTree() {
	cout << "\n��������ȫɾ����лл�����������";
}

void BiTree::PreOrder(int i, int num) {   //ǰ������㷨,�������ӵ�ֵΪ#���������
	if (item[i].character != '#') cout << item[i].character;
	if (2 * i + 1 < num)  PreOrder(2 * i + 1, num);
	if (2 * i + 2 < num)  PreOrder(2 * i + 2, num);
}

int Power(int n) {
		int s = 1;
		for (int i = 0; i < n; i++)
			s *= 2;
		s -= 1;
		return s;
	}

	int main()
	{
		int n;
		cout << "������򣺽���������Ϊ��ȫ���������������š���������ڵ��ڴ洢��ֵ���洢ֵΪ�ַ����������ڵ��ڶ������в������ڣ�������#���ﵽ��������ԭ������Ҫ��󣬺����ڵ�����ʼ��Ϊ#����������ʾ�����¡�\n\n\n";
		cout << "��������������ԭ�������Ľڵ���Ŀ��ʾ�����룺5��:";
		cin >> n;
		BiTree *q = new BiTree(Power(n), n);   //�Ѷ�������Ϊ��ȫ��������������洢�ռ䲻��
		cout << "ǰ���������Ϊ��";
		q->PreOrder(0,Power(n));   //ǰ�����
		delete q;
	}

