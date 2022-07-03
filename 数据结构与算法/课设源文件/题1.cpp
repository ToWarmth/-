#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}*ListNode;

typedef ListNode *LinkList;
ListNode head, p, q;

void CreateList(int *a,int n) {
	head = new Node;
	head->next = NULL;
	p = new Node;
	head->next = p;
	p->data = a[0];
	p->next = NULL;
	for (int i = 1; i < n; i++) {
		q = new Node;
		q->data = a[i];
		q->next = NULL;
		p->next = q;
		p = q;
	}
}

void PrintList() {
	p = head->next;
	cout << "������������������Ϊ��";
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
}

void InsertList(int location, int value) {
	p = head;
	int counter = 0;
	while (counter != location - 1) {
		p = p->next;
		counter++;
	}
	q = new Node;
	q->data = value;
	q->next = p->next;
	p->next = q;
	p = head->next;
	cout << "�ڵ�" << location << "��λ�ò���" << value << "��������������Ϊ��";
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
}

void DeleteList(int location) {
	p = head;
	int counter = 0;
	while ((counter != location - 1) && p != NULL) {
		p = p->next;
		counter++;
	}
	p->next = p->next->next;
	p = head->next;
	cout << "ɾ����" << location << "��λ�õĽڵ�󣬵���������Ϊ��";
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
}

int main() {
	int n,location;
	cout << "�����뵥���������ݵĸ���:";
	cin >> n;
	int *a = new int[n];
	cout << "���������뵥�����е�����:";
	for (int i = 0; i < n; i++) cin >> a[i];
	CreateList(a,n);
	PrintList();
	cout << "�����������������Ԫ�ص�λ�á�ֵ:";
	cin >> location >> n;
	InsertList(location,n );
	cout << "����������ɾ������Ԫ�ص�λ��:";
	cin >> location;
	DeleteList(location);
}
