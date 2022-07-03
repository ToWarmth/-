#include <iostream>
using namespace std;

struct Node {
	int data;   //��ʾÿ���ڵ����洢������
	Node *next;   //ÿ���ڵ�ĺ�̣�ָ����һ���ڵ�
};

class SeqList {
public: friend struct Node;
		Node *first;   //��������ָ��ͷ�ڵ��ͷָ��

		SeqList();   //�޲ι��캯��������ձ�
		SeqList(int *num, int n);   //�вι��캯��������ǿյ�����
		~SeqList();   //���������������ٵ������ͷ��ڴ�ռ������
		void PrintList();    //��������ĺ����������Ǳ������������
		void AgainList();    //��������ĺ���
		void Delete(int n);   //ɾ�������ڵ�ĺ���
};

SeqList::SeqList() {
	first = new Node;
	first->next = NULL;
}

SeqList::SeqList(int *num, int n) {
	first = new Node;
	Node *p = first;
	for (int i = 0; i < n; i++)
	{
		Node *s = new Node;
		s->data = num[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

SeqList::~SeqList() {
	while (first != NULL) {
		Node *q = first;
		first = first->next;
		delete q;
	}
	cout << "\n������������нڵ�ҵ��ɾ��";
};

void SeqList::PrintList()
{
	cout << "�����������޸ĵĵ�������������Ϊ:";
	Node *p = first;
	p = p->next;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
}

void SeqList::AgainList()
{
	Node *p = first->next;
	first->next = NULL;
	while (p != NULL) {
		Node *q = p->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}
	p = first->next;
	cout << "\n���ú�������������Ϊ��";
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
}

void SeqList::Delete(int n)
{
	int  location;
	cout << "\n����������ɾ���ڵ��λ�ã���ɾ���ڼ������ݣ�:";
	cin >> location;
	if (location <= 0) throw("λ��");
	else {
		while (location > n) {
			cout << "����Ҫɾ����λ�ó���������ķ�Χ������������ɾ���ڵ��λ��:";
			cin >> location;
		}
		Node *p = first;
		for (int counter = 0; counter < location - 1; counter++)
		{
			p = p->next;
		}
		Node *q = p->next;
		p->next = q->next;
		delete q;
		this->PrintList();
	}
}

int main()
{
	int n;   //�����û���Ҫ������������
	cout << "���������뽨����������(������Ҫ����С����лл��):";
	cin >> n;
	while (n < 0){
		cout << "�����Ȳ���Ϊ������������������:";
		cin >> n;
	};

	if (n == 0) {
		new SeqList();
		cout << "��������һ���ձ�";
	}
	else {
		int *num = new int[n]; //��̬�����������飬�����浽�����ڵ㣩��
		cout << "��ӵ�һ���ڵ㿪ʼ��������ڵ��ڴ洢������ֵ:\n";
		for (int i = 0; i < n; i++)
			cin >> num[i];
		SeqList * a = new SeqList(num, n);
		a->PrintList();
		a->Delete(n);
		a->AgainList();
		delete a;
	}
}
