
//10 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct School
{
	string priz,imja,clas;
	int school;
	School(string p,string im,int s,string c)
		:priz(p),imja(im),school(s),clas(c){}
};
//---------------------------------------------------------
struct Klass
{
	int school,kilkict;
	Klass(int s)
		:school(s),kilkict((int)0){}
};
//---------------------------------------------------------
void Sort_school(vector<School> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		School Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.school>m[j].school)//���� ����������� ����� �� �������
			{
				Max=m[j];//������ �������
				n=j;//������ ����� ���������
			}
		}
		if (n!=i)//��������� �� ����� �������
		{//�������� ����������� ������������� � ��������
			m[n]=m[i];
			m[i]=Max;
		}
	}
}
//---------------------------------------------------------
int find_max(vector<Klass> &k)
{
	int Max=k[0].kilkict;
	int n=(int)0;
	for (int i=(int)1;(size_t)i<k.size();++i)//� ���� ��������� ����� ��������
	{
		if (Max<k[i].kilkict)
		{
			Max=k[i].kilkict;
			n=i;
		}
	}
	return n;
}
//---------------------------------------------------------
void Sotn_klass(vector<School> &m,vector<Klass> &k)
{
	k.push_back(m[0].school);
	for (int i=(int)0;(size_t)i<m.size();++i)//� ���� ��������� ����� ��������
	{
		if (m[i].school!=k[k.size()-(size_t)1].school)//�� ����� �� �������
			k.push_back(m[i].school);//���� �������� �� ������� ����� ��� �������� ���������
		if(m[i].clas[0]=='9') //��������� �� ����� �������������
			k[k.size()-(size_t)1].kilkict++;//���� � �� ������� �������� ��������������
	}
}
//---------------------------------------------------------
ostream& operator<<(ostream &os,const School& a)
{
	string p,im,s=(string)"\t|";
	if (a.priz.size()<(size_t)7)//��������� ������� �����
		p=(string)"\t\t|";
	else p=s;
	if (a.imja.size()<(size_t)7)//��������� ������� ������
		im=(string)"\t\t|";
	else im=s;
	return os<<(char)'|'<<a.priz<<p<<a.imja<<im<<a.school<<s<<a.clas<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"-------------------------------------------------"
			 <<endl;
}
vector<School> Zmag;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ��������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		string p,im,c,per;
		int s=(int)0;
		is>>p>>im>>s>>c>>per;//������� 
		if (p==(string)"end")break;//������� �������� �������� �����
		if (p.size()>=(int)15||p.size()<(int)1)//������� ������� ����� 
			cout<<(string)"Prizvushce zadovge\n";
		else if(im.size()>(int)8||im.size()<(int)1)//�������� ������� ������
			cout<<(string)"Nekorektne Im�ja shkolara\n";
		else if(s>(int)120||s<(int)1) //�������� ���������� ���� �������
			cout<<(string)"Nekorektna shkola \n";
		else if(c.size()!=(int)3)//�������� ���������� ������ ����
			cout<<(string)"Nekorektnui prodig avto\n";
		else if(per.size()>(int)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			School a(p,im,s,c);
			Zmag.push_back(a);//�������� ��� � �������
		}
	}
	if (Zmag.size()>(size_t)0)
	{
		vector<Klass> K;
		Sort_school(Zmag);//�������� ������� ����������
		Sotn_klass(Zmag,K);
		cout<<(string)"-------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)Zmag.size();i++)
		{
			cout<<Zmag[i];//��������� ������� �������
		}
		cout<<"naibilshe 9-tu klasnukiv v "<<K[find_max(K)].school<<" shkoli"<<endl;
	}
	{//��������
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
