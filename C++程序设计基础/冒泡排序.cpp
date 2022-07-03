#include <iostream>
using namespace std;

void Swap(int &a,int &b)
{ int tmp=a;
  a=b;
  b=tmp;
}

void SortBubble(int *a,int size)
{ for(int i=size-1;i>=0;i--)
	for(int j=0;j<i;j++)
		if(a[j]>a[j+1])  Swap(a[j],a[j+1]);
}

void Print(int *a,int size)
{ for(int i=0;i<size;i++)
  cout<<a[i]<<" ";
  cout<<endl;
}

int main(){
	int n;
	cout<<"�����������С��";
	cin>>n;
	int *a=new int[n];
	cout<<"����������Ԫ�أ�";
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<"����ǰ��";
	Print(a,n);	
	SortBubble(a,n);
	cout<<"�����";
	Print(a,n);
	cout<<endl;
	system("pause");
	return 0;
}
