//13 ��������
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ST\std_lib_facilities.h>

using namespace std;
struct MedKarta
{//��������� ��� �������� 13
	string Lastname;
	char stat;
	int vik,zrist,vaga;
	MedKarta(string l,int vi,char s,int z,int va)
		:Lastname(l),vik(vi),stat(s),zrist(z),vaga(va){}
};
//---------------------------------------------------------
void Sort_MedKartu(vector<MedKarta> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//� ���� ��������� ����� ��������
	{
		MedKarta Max=m[i];//������� ������ ��������
		int n=i;//������ �������� �����
		for(int j=i+(int)1;(size_t)j<m.size();++j)//� ���� ��������� ����������� ��������
		{
			if(Max.Lastname[0]>m[j].Lastname[0])
			{//���� ����������� ����� �� �������
				Max=m[j];//������ �������
				n=j;//������ ����� ���������
			}
			else if(Max.Lastname[0]==m[j].Lastname[0])
			{
				int s1=(int)Max.Lastname.size();
				int s2=(int)m[j].Lastname.size();
				for (int k=(int)0;k<(s1>s2?s2:s1);++k)
					if (Max.Lastname[k]<m[j].Lastname[k])
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
void SeredneVZ(const vector<MedKarta> &m)
{
	vector<MedKarta> M,W;
	for (int i=(int)0;i<(int)m.size();++i)
	{//�������� ������� � ���� � 2 ����� �������
		if (m[i].stat=='M')
			M.push_back(m[i]);
		else W.push_back(m[i]);
	}
	int serVM=0,serZM=0,serVW=0,serZW=0;
	//--------------------------------------------------------
	if (M.size()>(size_t)0)
	{//������ ���� � ���� �������
		for(int i=(int)0;i<(int)M.size();++i)
		{
			serVM+=M[i].vaga;
			serZM+=M[i].zrist;
		}
		serVM/=(int)M.size();//³������� ������� ���� 
		serZM/=(int)M.size();//³������� ������� ����
		cout<<(string)"Seredne znachena sered cholowikiw:"<<endl
			<<(string)"Serednii zrist ("<<serZM<<")"<<endl
			<<(string)"Serednii Vaga  ("<<serVM<<")"<<endl;
	}
	else cout<<(string)"Chilovikiv ne bulo wedeno\n";
	//--------------------------------------------------------
	if (W.size()>(size_t)0)
	{//������ ���� � ���� �������
		for(int i=(int)0;i<(int)W.size();++i)
		{
			serVW+=W[i].vaga;
			serZW+=W[i].zrist;
		}
		serVW/=(int)W.size();//³������� ������� ����
		serZW/=(int)W.size();//³������� ������� ����
		cout<<(string)"Seredne znachena sered ginok:"<<endl
			<<(string)"Serednii zrist ("<<serZW<<")"<<endl
			<<(string)"Serednii Vaga  ("<<serVW<<")"<<endl;
	}
	else cout<<(string)"Ginok ne bulo wedeno\n";
}
//---------------------------------------------------------
ostream& operator<<(ostream &os,const MedKarta& a)
{
	string l,s=(string)"\t|";
	if (a.Lastname.size()>=(size_t)8)//��������� ������� �����
		l=s;
	else l=(string)"\t\t|";
	return os<<(char)'|'<<a.Lastname<<l<<a.vik<<s<<a.stat<<s<<a.zrist<<s<<a.vaga<<(string)"\t|"//�������� � ���� ostrim ��� ���������
			 <<endl<<(string)"-------------------------------------------------"
			 <<endl;
}
vector<MedKarta> MK;//��������� �������
int main()
{
	string zm;
	while (getline(cin,zm))//������� ��� �� ������
	{
		istringstream is(zm);//��������� �������� ����� � ����
		string l,in,per;
		int vi,z,va;
		char s;
		is>>l>>in>>vi>>s>>z>>va>>per;//������� 
		if (l==(string)"end")break;//������� �������� �������� �����
		if (l.size()>=(size_t)10)//������� ������� ������ 
			cout<<(string)"Zadovge prizvushce\n";
		else if(vi>(int)150||vi<(int)0)//��������� ��
			cout<<(string)"Wedit korektnu stat daty narodgenja\n";
		else if(in.size()!=(size_t)4)//�������� �������
			cout<<(string)"Wedit korektnu inicialu\n";
		else if(s!=(char)'W'&&s!=(char)'M') //�������� �����
			cout<<(string)"Wedit korektnu stat\n";
		else if(z>(int)300||z<(int)0)//��������� ����
			cout<<(string)"Wedit korektnu zrist\n";
		else if(va>(int)250||va<(int)0)//��������� ����
			cout<<(string)"Wedit korektnu vagu\n";
		else if(per.size()>(size_t)1)//�������� �������� �����
			cout<<(string)"Wedeno lushni slovo\n";
		else //���� �� ������� �� �������� �� ���������� �������� �����
		{
			MedKarta a(l+' '+in,vi,s,z,va);
			MK.push_back(a);//�������� ��� � �������
		}
	}
	if (MK.size()>(size_t)0)
	{
		Sort_MedKartu(MK);//�������� ������� ����������
		cout<<"-------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)MK.size();i++)
		{
			cout<<MK[i];//��������� ������� �������
		}
		SeredneVZ(MK);//�������� ������� ���������� ��������
	}
	{//��������
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
