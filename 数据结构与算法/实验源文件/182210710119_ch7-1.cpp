#include <iostream>
using namespace std;

int *p,n,m;   //nΪ˳���ĳ��ȣ�mΪ��Ҫ���ҵ����ݡ�

void CreatList() {//����һ��˳���
	cout << "����������Ҫ������˳����д洢�����ݵĸ���:";
	cin >> n;
	p = new int[n+1];
	cout << "��������������˳����д洢�����ݣ�\n";
	for (int i = 0; i <= n-1; i++) 
		cin >> p[i];
	cout << "˳����ѽ�����";
}

void OrderSearch() {//˳����˳������㷨
	int k;
	cout << "������������ҵ����ݣ�";
	cin >> k;
	p[n] = k;
	int i = 0;
	while (p[i] != k)
		i++;
	if (i != n ) cout << "���ҳɹ���������˳����" << i + 1 << "λ�������±���"<<i<<"!";
	else cout << "����ʧ��";
}

int main()
{  
	CreatList();
	OrderSearch();
}
