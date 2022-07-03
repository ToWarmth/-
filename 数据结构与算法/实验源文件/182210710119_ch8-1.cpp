#include <iostream>
using namespace std;

int num;
struct Node {
	int data;
	Node *next;
} *p, *q,*r;

class List {
public:
	 List();
	~List();
	void Print();
private:
	Node *first1;   //first1�ڴ洢�ڵ�ֵΪ�գ���Ϊ���뷽�����õ�
	Node *first2;   //first2���ǿսڵ㣬�ǽ��������貿�ֵ�����ĵ�һ���ڵ㣬���д洢����
};

List::List() {
	int a;
	cout << "������������Ҫ���������\n";
	first1 = new Node;
	first1->next = NULL;
	cin >> a;
	p = new Node;
	p->data = a;
	p->next = NULL;
	first1->next = p;
	cin >> a;
	first2 = new Node;
	first2->data = a;
	first2->next = NULL;
	p = first2;
	for (int i = 3; i <= num; i++) {
		cin >> a;
		q = new Node;
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}

	while (first2 != NULL) {
		p = first1->next;
		q = first2;
		if (p->data > q->data) {//ͷ��������������ڵ�С����������һ���ڵ��ֵ
			first2 = q->next;
			q->next = p;
			first1->next = q;
			p = first1->next;
			q = first2;
		}
		while ( (p->data <= q->data)&&(first2!=NULL)) {
			if ((p->next == NULL) && (p->data <= q->data)) {//β���ж���β����� 
				first2 = q->next;
					q->next = NULL;
					p->next = q;
					break;
			}
			if (p->next->data > q->data) {//�м���ж����м����� 
				first2 = q->next;
				r = p->next;
				q->next = r;
				p->next = q;
				p = first1->next;
				q = first2;
				break;
			}
			else p = p->next;
		};
	};
	}

List::~List() {
	while (first1->next != NULL) {
		q = first1->next;
		first1->next = q->next;
		delete q;
	};
	cout << "\n��������ɾ�����������!";
}

void List::Print() {
	p = first1;
	do {
		p = p->next;
		cout << p->data<<"\t";
	} while (p->next!=NULL);
}

int main() {
	cout << "������������������ĸ���:";
	cin >> num;
	List *s = new List();
	s->Print();
	delete s;
}
