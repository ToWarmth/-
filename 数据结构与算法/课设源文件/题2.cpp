#include <iostream>
using namespace std;

typedef struct Node
{
	int id, key;
	struct Node *next;
}*ListNode;

typedef ListNode *LinkList;
ListNode head, feet, p, q;

void CreateList(int n, int *a) {
	head = new Node;
	head->id = 1;
	head->key = a[0];
	head->next = NULL;
	p = head;
	for (int i = 2; i <= n; i++) {
		q = new Node;
		q->id = i;
		q->key = a[i - 1];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	p->next = head;
	feet = p;
}

void Johnsphus(int m, int n) {
	while (1 > 0) {
		p = head;
		q = feet;
		for (int num = 1; num < m; num++) {//�ұ�����m���Ǹ��ڵ�
			q = q->next;
			p = p->next;
		}
		if (p->next == q) {
			cout << p->id << "\t";
			q->next=q; 
			cout << q->id;
			delete q;
			break;
		}
		cout << p->id << "\t";
		m = p->key;
		q->next = p->next;
		p = q->next;
		head = p;
		feet = q;
	}
}

void PrintList() {
	p = head;
	cout << "��Ϸ�ߵ����\t��Ӧ����\n";
	do {
		cout << p->id << "\t\t" << p->key << "\n";
		p = p->next;
	} while (p != head);
	cout << "\n";
}

int main() {
	int n, m;
	cout << "��������Լɪ����Ϸ��������";
	cin >> n;
	int *a = new int[n];
	cout << "����������ÿ���������õ�����:\n";
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
	}
	CreateList(n, a);
	PrintList();
	cout << "��ָʾһ����������Ϊ��������ֵ:";
	cin >> m;
	cout << "��������Ϊ��";
	Johnsphus(m, n);
}
