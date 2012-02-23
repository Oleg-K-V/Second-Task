//11 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct Student
{
	string Lastname,Name;
	double serbal;
	Student(string l,string n,double b)
		:Lastname(l),Name(n),serbal(b){}
};
//---------------------------------------------------------
void Sort_Student(vector<Student> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		Student Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(tolower(Max.Lastname[(int)0])>tolower(m[j].Lastname[(int)0]))
			{//���� ����������� ����� �� ������� 
				Max=m[j];//������ �������
				n=j;//������ ����� ���������
			}
			else if(tolower(Max.Lastname[(int)0])==tolower(m[j].Lastname[(int)0]))
			{
				int s1=(int)Max.Lastname.size();
				int s2=(int)m[j].Lastname.size();
				for (int k=(int)0;k<(s1>s2?s2:s1);++k)
					if (tolower(Max.Lastname[k])<tolower(m[j].Lastname[k]))
					{//���� ����������� ����� �� �������
						Max=m[j];//������ �������
						n=j;//������ ����� ���������
					}
				if (n==j)
				{
					if(s1<s2)
					{//���� ����������� ����� �� �������
						Max=m[j];//������ �������
						n=j;//������ ����� ���������
					}
				}
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
void Best_Student(const vector<Student> &m)
{
	if ((size_t)m.size()<2)
	{//�������� ��������� ������� ���������
		cout<<(string)"Wedeno zamala kilkist studentiv\n";
		return;
	}
	Student M1=m[(int)1],M2=m[(int)0];
	int n=(int)1;
	for (int i=(int)0;i<(int)m.size();++i)
	{//������� ������� ����������
		if (M1.serbal<m[i].serbal)
		{
			M1=m[i];
			n=i;
		}
	}
	for (int i=(int)1;i<(int)m.size();++i)
	{//�������� ������� ����������
		if (M2.serbal<m[i].serbal&&i!=n)
			M2=m[i];
	}
	cout<<(string)"Naikrashcumu studentamu grypu je:"<<endl
		<<M1.Lastname<<endl<<M2.Lastname<<endl;
}
//---------------------------------------------------------
ostream& operator<<(ostream &os,const Student& a)
{
	string l,n,s=(string)"\t\t|";
	if (a.Lastname.size()<(size_t)8)//��������� ������� �����
		l=s;
	else l=(string)"\t|";
	if (a.Name.size()<(size_t)7)
		n=s;
	else n=(string)"\t|";
	return os<<(char)'|'<<a.Lastname<<l<<a.Name<<n<<a.serbal<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"-----------------------------------------"
			 <<endl;
}
vector<Student> St;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ��������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		string l,n,per;
		double b=(double)0;
		is>>l>>n>>b>>per;//������� 
		if (l==(string)"end")break;//������� �������� �������� �����
		if (l.size()>=(size_t)15)//������� ������� ������ 
			cout<<(string)"Zadovge prizvushce\n";
		else if(n.size()>(size_t)10)//�������� ������� ���
			cout<<(string)"Zadovge imja\n";
		else if(b>(double)100) //�������� ���������� ���������� ����
			cout<<(string)"Nekorektnui serednii bal\n";
		else if(per.size()>(size_t)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			Student a(l,n,b);
			St.push_back(a);//�������� ��� � �������
		}
	}
	if (St.size()>(size_t)0)
	{
		Sort_Student(St);//�������� ������� ����������
		cout<<(string)"-----------------------------------------"<<endl;
		for (int i=(int)0;i<(int)St.size();i++)
		{
			cout<<St[i];//��������� ������� �������
		}
	}
	Best_Student(St);//�������� ������� ������ ������ ��������
	{//��������
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
