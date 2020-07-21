#include <stdio.h> //��������
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int L = 7;

int RecurMatrixChain(int i,int j,int **s,int *p);//�ݹ������Ž�

void Traceback(int i,int j,int **s);//�������Ž�

int main()
{
    int p[L]={10,20,30,15,25,35,40};//����A1...A6
    printf("����A1��A6��");
    for(int z=0;z<L;z++)
       printf("%d  ",p[z]);
	printf("\n");
    int **s = new int *[L];

    for(int i=0;i<L;i++)

        s[i] = new int[L];

    cout<<"��������ټ������Ϊ��"<<RecurMatrixChain(1,6,s,p)<<endl;

    cout<<"�������ż������Ϊ��"<<endl;

    Traceback(1,6,s);

    return 0;

}

int RecurMatrixChain(int i,int j,int **s,int *p)

{

    if(i==j) return 0;

    int u = RecurMatrixChain(i,i,s,p)+RecurMatrixChain(i+1,j,s,p)+p[i-1]*p[i]*p[j];

    s[i][j] = i;

    for(int k=i+1; k<j; k++)

    {

        int t = RecurMatrixChain(i,k,s,p) + RecurMatrixChain(k+1,j,s,p) + p[i-1]*p[k]*p[j];

        if(t<u)

        {

            u=t;

            s[i][j]=k;

        }

    }

    return u;

}

void Traceback(int i,int j,int **s)

{

    if(i==j) return;

    Traceback(i,s[i][j],s);

    Traceback(s[i][j]+1,j,s);

    cout<<"Multiply A"<<i<<","<<s[i][j];

    cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;

}