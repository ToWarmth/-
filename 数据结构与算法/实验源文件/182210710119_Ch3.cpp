#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Queue {
public: friend Node;
		Node *rear;
		Queue(int *que, int n);   //��������
		~Queue();   //ɾ��������������Ԫ�ط���
		void Into();   //��ӷ���
		void Away();   //���ӷ���
		void Print();   //��ӡ����
};

Queue::Queue(int *que, int n) {
	Node *s=new Node;
	s->data = que[0];
	s->next = NULL;
	Node *q = s;
	for (int i = 1; i <= n - 1; i++) {
		Node *p = new Node;
		p->data = que[i];
		p->next = NULL;
		q->next = p;
		q = p;
	}
	rear = q;
	rear->next = s;
}

Queue::~Queue(){
	cout << "\n���ã�������������Ԫ�ؾ���ɾ����";
}

void Queue::Into() {
	Node *p = new Node;
	cout << "\n���������Ԫ�ص�ֵ:";
	cin >> p->data;
	p->next = rear->next;
	rear->next = p;
	rear = p;
}

void Queue::Away() {
	Node *p = rear->next;
	rear->next = p->next;
	delete p;
}

void Queue::Print() {
	cout << "��ǰ���У��Ӷ�ͷ�ŵ���βӦΪ��";
	Node *temporary = rear->next;
	do{
		cout << temporary->data<<'\t';
		temporary = temporary->next;
	}while (temporary != rear->next);
}

int main()
{
	int n;
	cout << "���������뽨���ĳ�ʼ���еĳ���:";
	cin >> n;
	while (n <= 0) {
		cout << "�����ܽ����ն��л򸺶��У���������壬���������룺";
		cin >> n;
	};
	int *num = new int[n];
	cout << "�������������������ĳ�ʼ�������洢�����ݣ��Ӷ�ͷ����β����\n";
	for (int i = 0; i <= n - 1; i++)
		cin >> num[i];
	Queue *test = new Queue(num, n);
	test->Print();
	test->Into();
	test->Print();
	test->Away();
	cout << endl<<"��ͷԪ�س��Ӻ�";
	test->Print();
	delete test;
}
