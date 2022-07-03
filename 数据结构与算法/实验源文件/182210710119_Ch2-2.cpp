#include <iostream>
using namespace std;

struct Node {
	int data;   //��ʾÿ���ڵ����洢������
	Node *next;   //ÿ���ڵ�ĺ�̣�ָ����һ���ڵ�
};

class SeqList {
public: friend struct Node;
		Node *first;   //��������ָ��ͷ�ڵ��ͷָ��

		SeqList(int *num, int n);   
		~SeqList();   //���������������ٵ������ͷ��ڴ�ռ������
		void PrintList();    //��������ĺ����������Ǳ������������
		void Delete(int n);   //ɾ�������ڵ�ĺ���
};

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
	cout << "������������нڵ�ҵ��ɾ��";
};

void SeqList::PrintList()
{
	cout << "�ӵ�һ���ڵ㿪ʼ�ڵ��ڴ洢������ֵΪ:";
	Node *p = first;
	p = p->next;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
}

void SeqList::Delete(int n)
{
		Node *p = first->next;
		while (p->next != NULL){
			if (p->data == p->next->data){
			Node *q = p->next;
			p->next = q->next;
			delete q; 
			}
			else {
				p = p->next;   //���ڵ�洢���������ݶ���ͬ������ʹ�ڵ���ת��ֱ������������ѭ��
			}
		}
		cout << endl<<"ɾ��ֵ��ͬ�Ľڵ��,";
		this->PrintList();
}

int main()
{
	int n;   ////�����û���Ҫ������������
	cout << "����������Ҫ������������:";
	cin >> n;
	int *num=new int[n];   
	cout << "������������������������������ݣ��������ǵݼ��������У�:\n";
	for (int i = 0; i < n; i++)
		cin >> num[i];
	SeqList *a = new SeqList(num, n);
	a->PrintList();
	a->Delete(n);
	cout << endl;
	delete a;
}
