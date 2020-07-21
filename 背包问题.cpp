#include<iostream>
#include<stack>
using namespace std;
#define N 100
class
HeapNode //����HeapNode�����
{
public:
double upper,price,weight;//upperΪ���ļ�ֵ���ޣ�price�ǽ������Ӧ�ļ�ֵ��weightΪ�������Ӧ������
int level,x[N];//��ڵ����Ӽ����������Ĳ����
};
double MaxBound(int i);
double Knap();
void AddLiveNode(double up,double cp,double cw,bool ch,int level);
stack<HeapNode>
High;//����High
double w[N],p[N];//����Ʒ�����ͼ�ֵ����Ϊ˫���ȸ�����
double cw,cp,c=30;//cwΪ��ǰ������cpΪ��ǰ��ֵ�����屳������Ϊ30
int n=3;//��������Ϊ3
int main()
{
	cout<<"�밴��˳������3����Ʒ��������"<<endl;
	int i;
	for(i=1;i<=n;i++)
		cin>>w[i];//����3����Ʒ������
	cout<<"�밴˳������3����Ʒ�ļ�ֵ��"<<endl;
	for(i=1;i<=n;i++)
		cin>>p[i];//����3����Ʒ�ļ�ֵ
	cout<<"����ֵΪ��";
	cout<<Knap()<<endl;//����Knap�������������ֵ
	return 0;
}
double MaxBound(int j)//MaxBound�������������
{
	double
		left=c-cw,b=cp;//ʣ�������ͼ�ֵ����
	while(j<=n&&w[j]<=left)//����Ʒ��λ������ֵ�ݼ�װ��ʣ������
	{
		left-=w[j];
		b+=p[j];
		j++;
	}
	if(j<=n)
		b+=p[j]/w[j]*left;//װ��ʣ������װ������
	return b;
}
void AddLiveNode(double up,double cp,double cw,bool ch,int lev)//��һ���µĻ�����뵽�Ӽ���������High��
{
	HeapNode be;
	be.upper=up;
	be.price=cp;
	be.weight=cw;
	be.level=lev;
	if(lev<=n)
		High.push(be);//����stackͷ�ļ���push����
}
double Knap()//���ȶ��з�֧���޷�����������ֵ��bestx�������Ž�
{
	int i=1;cw=cp=0;double bestp=0,up=MaxBound(1);//����MaxBound�����ֵ���ޣ�bestΪ����ֵ
	while(1)//��Ҷ�ӽ��
	{
		double wt=cw+w[i];
		if(wt<=c)//����ӽ��Ϊ���н��
		{
			if(cp+p[i]>bestp) bestp=cp+p[i];
				AddLiveNode(up,cp+p[i],cw+w[i],true,i+1);
		}
		up=MaxBound(i+1);
			if(up>=bestp)//���������ܺ����Ž�
				AddLiveNode(up,cp,cw,false,i+1);
			if(High.empty()) return bestp;
			HeapNode node=High.top();//ȡ��һ��չ���
			High.pop();
			cw=node.weight;
			cp=node.price;
			up=node.upper;
			i=node.level;
		}
	}