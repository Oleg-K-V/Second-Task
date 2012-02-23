//10 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
struct Avto
{
	string marka,nomer;
	int vupusk,probig;
	Avto(string m,string n,int v,int p)
		:marka(m),nomer(n),vupusk(v),probig(p){}
};
void Sort_avto(vector<Avto> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		Avto Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.vupusk<m[j].vupusk)//���� ����������� ����� �� �������
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
ostream& operator<<(ostream &os,const Avto& a)
{
	string m,n,s=(string)"\t\t|";
	if (a.marka.size()<(size_t)8)//��������� ������� �����
		m=s;
	else m=(string)"\t";
	if (a.nomer.size()==(size_t)6)//��������� ������� ������
		n=(string)"\t\t\t|";
	else n=s;
	return os<<(char)'|'<<a.marka<<m<<a.nomer<<n<<a.vupusk<<s<<a.probig<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"-----------------------------------------------------------------"
			 <<endl;
}
vector<Avto> Car;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ��������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		string m,n,per;
		int v=(int)0,p=(int)0;
		is>>m>>n>>v>>p>>per;//������� 
		if (m==(string)"end")break;//������� �������� �������� �����
		if (m.size()>=(int)15)//������� ������� ����� 
			cout<<(string)"Nazva mashunu zadovga\n";
		else if((n.size()!=(int)8)&&(n.size()!=(int)6))//�������� ������� ������
			cout<<(string)"Nekorektnui nomer mashunu\n";
		else if(v>(int)2012||v<(int)1900) //�������� ���������� ���� �������
			cout<<(string)"Nekorektnui rik vupysky\n";
		else if(p==(int)0||p>(int)1000000)//�������� ���������� ������ ����
			cout<<(string)"Nekorektnui prodig avto\n";
		else if(per.size()>(int)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			Avto a(m,n,v,p);
			Car.push_back(a);//�������� ��� � �������
		}
	}
	if (Car.size()>(size_t)0)
	{
		Sort_avto(Car);//�������� ������� ����������
		cout<<(string)"-----------------------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)Car.size();i++)
		{
			cout<<Car[i];//��������� ������� �������
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
