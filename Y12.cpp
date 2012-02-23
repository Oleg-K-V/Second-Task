//12 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
struct _Point
{//��������� ��� �������� 12
	unsigned int x,y;
	int color;
	_Point(unsigned int _x,unsigned int _y,int c)
		:x(_x),y(_y),color(c){}
};
struct XY
{
	int x,y;
	XY(int _x,int _y)
		:x(_x),y(_y){}
	XY()
		:x((int)0),y((int)0){}
};
double vidstan(XY p1,XY p2)
{
	double zm1=(double)((p1.x-p2.x)*(p1.x-p2.x));//��������� ������� ������ �� �
	double zm2=(double)((p1.y-p2.y)*(p1.y-p2.y));//��������� ������� ������ �� �
	double zm3=zm1+zm2;
	double res=pow(zm3,0.5);//�������� �������
	return res;
}
void Sort_Color(vector<_Point> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		_Point Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.color<m[j].color)//���� ����������� ����� �� �������
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
void Sort_Color(vector<_Point> &m,XY &p1,XY &p2,double &v)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		_Point Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		XY Z1,Z2;
		Z1.x=Max.x;
		Z1.y=Max.y;//������ ���������
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.color==m[j].color)
			{//��������� �� ������� ����������
				Z2.x=m[j].x;
				Z2.y=m[j].y;//������ ���������
				double res=vidstan(Z1,Z2);//�������� ������� �� �����������
				if (res>v)
				{//��������� �� ������� ������� �� � ���������
					p1.x=Max.x;
					p1.y=Max.y;
					p2.x=Z2.x;
					p2.y=Z2.y;
					v=res;//��������� �� ��������
				}
			}
			if(Max.color<m[j].color)//���� ����������� ����� �� �������
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

ostream& operator<<(ostream &os,const _Point& a)
{
	string m=(string)"\t|";
	return os<<dec<<(char)'|'<<a.x<<m<<a.y<<m<<hex<<a.color<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"-------------------------"
			 <<endl;
}
vector<_Point> P;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ��������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		unsigned int _x=(unsigned int)0,_y=(unsigned int)0;
		int c=(int)0;
		string per;
		is>>_x>>_y>>hex>>c>>per;//������� ��������
		if (_x==(unsigned int)0&&_y==(unsigned int)0)break;//������� �������� �������� �����
		else if(per.size()>(int)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			_Point a(_x,_y,c);
			P.push_back(a);//�������� ��� � �������
		}
	}
	if (P.size()>(size_t)0)//��������� �� ���� ������� ���������
	{
		XY p1,p2;
		double v=(double)0;
		if (P.size()>(size_t)1)//��������� �� ���� ������ ����� 2-� ��������
			Sort_Color(P,p1,p2,v);//�������� ������� ���������� � ������� �������� ������
		else Sort_Color(P);//�������� ������� ����������
		cout<<(string)"-------------------------"<<endl;
		for (int i=(int)0;i<(int)P.size();i++)
		{
			cout<<P[i];//��������� ������� �������
		}
		if (!v)//��������� �� ���� �������� �������� ������� �� �����������
			cout<<"Nebulo znaideni spivpadin"<<endl;//���� � ������ �����������
		else 
		{
			cout<<"naibelsha vidstan mig tochkamu ("//���� �� �� ������� ���
				<<dec<<p1.x<<','<<p1.y<<")("<<p2.x<<','<<p2.y<<") = "<<v<<endl;
		}
	}
	{//��������
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
