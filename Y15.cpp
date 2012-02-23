//15 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
struct XY
{
	int x,y;
	XY(int _x,int _y)
		:x(_x),y(_y){}
	XY()
		:x((int)0),y((int)0){}
};
struct _Point
{//��������� ��� �������� 15
	XY vershuna1,vershuna2,vershuna3;
	double perumtr;
	_Point(XY v1,XY v2,XY v3,double p)
		:vershuna1(v1),vershuna2(v2),vershuna3(v3),perumtr(p){}
};

double vidstan(XY p1,XY p2)
{
	double zm1=(double)((p1.x-p2.x)*(p1.x-p2.x));//��������� ������� ������ �� �
	double zm2=(double)((p1.y-p2.y)*(p1.y-p2.y));//��������� ������� ������ �� �
	double zm3=zm1+zm2;
	double res=pow(zm3,0.5);//�������� �������
	return res;
}
//---------------------------------------------------------
double perumtr(XY v1,XY v2,XY v3)
{
	return vidstan(v1,v2)+vidstan(v2,v3)+vidstan(v3,v1);
}
//---------------------------------------------------------
void Sort_perumtr(vector<_Point> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		_Point Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.perumtr<m[j].perumtr)//���� ����������� ����� �� �������
			{
				Max=m[j];//������ �������
				n=j;//������ ����� ���������
			}
		}
		if (n!=i)//��������� �� ����� �������
		{//�������� ������������ ������������� � ��������
			m[n]=m[i];
			m[i]=Max;
		}
	}
}
//---------------------------------------------------------
double Find(vector<_Point> &m)
{
	double min2=m[m.size()-(int)1].perumtr*(int)2;
	double n=(double)0; 
	for (int i=(int)0;(size_t)i<m.size();++i)//� ���� ��������� ����� ��������
	{
		if (m[i].perumtr>=min2)
			n++;//��������� �� ������� ��������� � ����� � ����������� �������
		return n;
	}
	return n;
}
//---------------------------------------------------------
ostream& operator<<(ostream &os,const _Point& a)
{
	string m=(string)"\t|";
	return os<<dec<<(char)'|'<<a.vershuna1.x<<m<<a.vershuna1.y<<m
							 <<a.vershuna2.x<<m<<a.vershuna2.y<<m
							 <<a.vershuna3.x<<m<<a.vershuna3.y<<m
							 <<a.perumtr<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"---------------------------------------------------------"
			 <<endl;
}
vector<_Point> P;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ��������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		XY v1,v2,v3;
		string per;
		is>>v1.x>>v1.y>>v2.x>>v2.y>>v3.x>>v3.y>>per;//������� ��������
		if (v1.x==(int)0&&v1.y==(int)0)break;//������� �������� �������� �����
		else if(per.size()>(int)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			_Point a(v1,v2,v3,perumtr(v1,v2,v3));
			P.push_back(a);//�������� ��� � �������
		}
	}
	if (P.size()>(size_t)0)//��������� �� ���� ������� ���������
	{
		Sort_perumtr(P);//�������� ������� ����������
		cout<<(string)"--------------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)P.size();i++)
		{
			cout<<P[i];//��������� ������� �������
		}
	cout<<"Procent trukutnukiv z perumetrom bilshum za perumtr naimenshogo pomnogenui na 2 rivnui = "
		<<(int)((Find(P)/(double)P.size())*100)<<" %"<<endl; 
	}
	{//��������
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
