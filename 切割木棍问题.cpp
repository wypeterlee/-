#include <iostream>
#include <cstring>
using namespace std; //�Ե����ϣ�����ѭ�������õݹ飻

void main()  {
		int n;
		cin>>n;
		int price[11]={0,1,5,8,9,10,17,17,20,23,28};
		int *r=new int [n+1];
		for(int k = 0; k<= n; ++k)
			r[k] = 0; 
		for(int i = 1; i <= n; ++i)
		{          
			int q = INT_MIN;
			for(int j = 1; j <= i; ++j)//�����ģΪi���������
			{              
		if(q < (price[j] + r[i-j]))//��Ϊi>i-j�����Ե�����r[i]ʱ��r[i-j]�Ѿ����������ֱ����
					q = (price[j] + r[i-j]);  
			}          
			r[i] = q;  //�ҳ�i���λ�õ����Ž⣻
		}
		cout<<r[n];  //n�׳���ľͷ������ֵ��
	} 