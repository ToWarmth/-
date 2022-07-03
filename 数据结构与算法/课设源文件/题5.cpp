#include <iostream>
using namespace std;

int n, m;

struct BiSortTreeNode {
	int data;
	BiSortTreeNode *lchild;
	BiSortTreeNode *rchild;
}*first,*p,*q,*r;

void seekLocation() {
	if (m < (p->data)) {
		if (p->lchild != NULL)   p = p->lchild;
	    else { p->lchild = q; }
		seekLocation();
	}
	if (m > (p->data)) {
		if (p->rchild != NULL) p = p->rchild;
		else { p->rchild = q; }
		seekLocation();
		}
	}

void CreatTree() {
	cout << "��������������ж��ٸ��������룺";
	cin >> n;
	cout << "�������������������������:";
	cin >> m;
	p = new BiSortTreeNode();
	p->data = m;
	p->lchild = NULL;
	p->rchild = NULL;
	first = p;
	r = p;
	int i = 1;
	do {
		cin >> m;
		q = new BiSortTreeNode();
		q->data = m;
		seekLocation();
		i++;
		p = r;
	} while (i != n);
}

void PreOrder(BiSortTreeNode *p) {
	if (p == NULL) return;
	else {
		cout << p->data << "\t";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void Order(BiSortTreeNode *p) {
	if (p == NULL) return;
	else {
		Order(p->lchild);
		cout << p->data << "\t";
		Order(p->rchild);
	}
}

int main() {
	CreatTree();
	cout << "ǰ������ö����������Ϊ:";
	PreOrder(first);
	cout << "\n��������ö��������������Ϊ��";
	Order(first);
}
