#include <iostream>
using namespace std;

const int n = 2;   //nΪͣ��������
const int m = 5;
int a, c, key1 = 0, key2 = 0, key3 = 0, i = 0, Percost = 3, LastExit;
char b, d;

struct Cars {
	int ID;
	char State;
	int Time;
	Cars *next;
}*p, *q, *r, *head, *near;

Cars *Stack1[n], *Stack2[m];  

void parkingmode() {
	head = new Cars;
	cout << "�밴ʱ���Ⱥ�˳������������״̬���������ա��������и�״̬��ʱ�̣���ʽ��A 1 1����";
	cin >> b >> a >> c;
	head->ID = a;
	head->State = b;
	head->Time = c;
	p = head;
	Stack1[0] = head;
	key1++;
	cout << "����Ϊ" << Stack1[key1 - 1]->ID << "�ĳ���ͣ��ͣ�����ӱ����ϵ�" << key1 << "��λ�á�\n";
	do {
		i = 0;
		cout << "�밴ʱ���Ⱥ�˳������������״̬���������ա��������и�״̬��ʱ�̣���ʽ��A 1 1����";
		cin >> b >> a >> c;
		if (b == 'E') {
			cout << "�������";
			break;
		}
		if (b == 'A') {
			q = new Cars;
			q->ID = a;
			q->State = b;
			q->Time = c;
			if (key1 - 1 < n - 1) { //ͣ������δװ��
				key1++;
				Stack1[key1 - 1] = q;
				for (int j = 0; j <= key1 - 1; j++)
					cout << "����Ϊ" << Stack1[j]->ID << "�ĳ���ͣ��ͣ�����ӱ����ϵ�" << j + 1 << "��λ�á�\n";
			}
			else {  //ͣ��������
				if (key3 == 0) { //����û�����Ŷ�
					head = q;
					head->next = NULL;
					r = head;
					key3++;
				}
				else {   //�����г����Ŷ�
					q->next = NULL;
					r->next = q;   // �������bug�����������������
					key3++;
				}
				for (int j = 0; j <= key1 - 1; j++)
					cout << "����Ϊ" << Stack1[j]->ID << "�ĳ���ͣ��ͣ�����ӱ����ϵ�" << j + 1 << "��λ�á�\n";
				cout << "����Ϊ" << q->ID << "�ĳ���ͣ�ڱ����" << key3 << "��λ�á�\n";
			}
		}
		if (b == 'D') {
			while (Stack1[i]->ID != a) {
				i++;
			}
			for (int j = key1 - 1; j > i; j--) {//Stack2��ջ�����±����Ƕˣ�����ĳ������Ž������˻���
				Stack2[key2++] = Stack1[j];
				Stack1[j] = NULL;
			}
			cout << "����Ϊ" << Stack1[i]->ID << "�ĳ���ͣ����" << (c - Stack1[i]->Time) << "Сʱ��Ӧ�շ�" << (c - Stack1[i]->Time)*Percost << "Ԫ��\n";
			for (int j = key2 - 1, tmp = i; j >= i; j--) {//Stack2�ĳ������γ�ջ���Ƶ�Stack1ͣ������
				Stack1[tmp++] = Stack2[j];
				Stack2[j] = NULL;
				key2--;
			}
			key1--;
			//����û�³���������ǰ���Ŷӵĳ�ҲҪ����
			if (key3 == 0) { //����û�����Ŷ�

			}
			else {   //�����г����Ŷ�
				LastExit = c;
				key1++;
				Stack1[key1 - 1] = head;
				Stack1[key1 - 1]->Time = LastExit;
				head = head->next;
				key3--;
			}
		}
	} while (1 > 0);
}

int main() {
	parkingmode();
}
