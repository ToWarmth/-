#include <iostream>
using namespace std;

int num;
struct Node {
	int data;
	Node *next;
} *p, *q,*r,*px,*qx;

class List {
public:
	 List();
	~List();
	void Print();
private:
	Node *first;
};

List::List() {
	int a;
	cout << "������������Ҫ���������\n";
	cin >> a;
	first = new Node;
	first->data = a;
	first->next = NULL;
	p = first;
	for (int i = 2; i <= num; i++) {
		cin >> a;
		q = new Node;
		q->data = a;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	for (p = first; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->data > q->data) {
				int tmp = q->data;
				q->data = p->data;
				p->data = tmp;
			}
		}
	}
	/*p = first->next;
	q = p->next;
	px = first;
	qx = p;
	while (p->next != NULL) {//������ֵС�ڸ�ֵ�����������ڸ�ֵ����������ֵ�����
		if (p->data > q->data) {//ֱ�ӽ���
			if (p->next == q) {
				px->next = q;
				p->next = q->next;
				q->next = p;
				p = q->next;//������ϣ�p������һλ����֮��ʼ��
				q = p->next;
				continue;
			}
			else {
				px->next = q;
				r = p->next;
				p->next = q->next;
				q->next = r;
				qx->next = p;
				p = q->next;
				q = p->next;
			}
		}
		while (p->data <= q->data) {
			if (q->next != NULL) {
				qx = q;
				q = q->next;
				if (p->data > q->data) {
					if (p->next == q) {
						px->next = q;
						p->next = q->next;
						q->next = p;
						p = q->next;//������ϣ�p������һλ����֮��ʼ��
						q = p->next;
						break;
					}
					else {
						px->next = q;
						r = p->next;
						p->next = q->next;
						q->next = r;
						qx->next = p;
						p = q->next;
						q = p->next;
						break;
					}
				}
			}
			else {
				px = p;
				p = p->next;
			}
			if (p == NULL) break;
		};
	};*/
	}

List::~List() {
	while (first->next != NULL) {
		q = first->next;
		first->next = q->next;
		delete q;
	};
	cout << "\n��������ɾ�����������!";
}

void List::Print() {
	p = first;
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
