#include <iostream>
using namespace std;

int n, m;

struct BiSortTreeNode{
	int data;
	BiSortTreeNode *lchild;
	BiSortTreeNode *rchild;
}; BiSortTreeNode *first;

void CreatTree(){
	cout << "��������������ж��ٸ��������룺";
	cin >> n;
	cout << "�������������������������:\n";
	cin >> m;
	BiSortTreeNode *p= new BiSortTreeNode();
	p->data = m;
	p->lchild = NULL;
	p->rchild = NULL;
	first = p;
	BiSortTreeNode *r = p;
	int i=1;
	do{
		cin >> m;
		BiSortTreeNode *q = new BiSortTreeNode();
		q->data = m;
		while (m < (p->data)){
			if (p->lchild != NULL)   p = p->lchild;
			else { p->lchild = q; }
			if (m > (p->data)) {
				if (p->rchild != NULL) p = p->rchild;
				else { p->rchild = q; }
			}
		};
		while (m > (p->data)) {
			if (p->rchild != NULL) p = p->rchild;
			else { p->rchild = q; }
			if (m < (p->data)) {
				if (p->lchild != NULL)   p = p->lchild;
				else { p->lchild = q; }
			}
		};		
		i++;
		p = r;
	}while (i != n );
}

void Sort(BiSortTreeNode *p) {
	if (p == NULL) return;
	else {
		Sort(p->lchild);
		cout << p->data<<"\t";
		Sort(p->rchild);
	}
}

void SearchLayer() {
	int Searching, Layer = 1;
	cout << "\n������������ҵ�����:";
	cin >> Searching;
	BiSortTreeNode *p = first;
	if (Searching == p->data) cout << "��������ԭ�����ڲ���Ϊ��" << Layer << "��";
	else {
		while (p->data != Searching) {
			while (Searching < p->data) {
				p = p->lchild;
				Layer++;
				if ((p->lchild == NULL) && (p->data != Searching)) {
					cout << "���ź���δ���ҵ������ݡ�";
					return;
				}
			};
			while (Searching > p->data) {
				p = p->rchild;
				Layer++;
				if ((p->rchild == NULL) && (p->data != Searching)) {
					cout << "���ź���δ���ҵ������ݡ�";
					return;
				}
			}
		};
		cout << "��������ԭ�����ڲ���Ϊ��" << Layer << "��";
	}
}

int main(){
	CreatTree();
	cout << "����Ϊ��С��������Ϊ��";
	Sort(first);
	SearchLayer();
}
