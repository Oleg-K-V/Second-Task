//10 ��������
#include <iostream>
using namespace std;
union Marka
{
	char marka[20];
	int slovo[5];
};
//---------------------------------------------------------
struct Avto
{
	Marka marka;
	char nomer[8];
	int vupusk,probig;
};
//---------------------------------------------------------
struct SerProb
{
	Marka marka;
	int probig,lich;
};
//---------------------------------------------------------
bool operator ==(Marka a,Marka b)
{
	for (int i=(int)0;i<(int)5;++i)
	{
		if (a.slovo[i]!=b.slovo[i])
			return false;
	}
	return true;
}
//---------------------------------------------------------
bool operator !=(Marka a,Marka b)
{
	return !(a==b);
}
//---------------------------------------------------------
int main()
{
	int n=(int)3;
	Avto* ap=(Avto*)calloc((size_t)n,sizeof(Avto));
	SerProb* sp=(SerProb*)calloc((size_t)n,sizeof(SerProb));
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		sp[i].marka.marka[0]='\0';
		sp[i].probig=(int)0;
		sp[i].lich=(int)0;
	}//��������� ����� 0
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		cin>>ap[i].marka.marka;
		cin>>ap[i].nomer;
		cin>>ap[i].vupusk;
		cin>>ap[i].probig;
	}//������� ���
	//--------------------------------------------------------
	for (int i=(int)0;i<n-(int)1;++i)
	{
		for(int j=i+(int)1;j<n;++j)//� ���� ��������� �� ��������
		{
			if(ap[i].vupusk>ap[j].vupusk)//���� ������� ����� �� ��������
			{
				Avto zm=ap[i];
				ap[i]=ap[j];
				ap[j]=zm;//����� ������
			}
		}
	}
	//------------------------------------------------------
	int nom=(int)0;
	sp[nom].marka=ap[nom].marka;//������ ���� ����� ������ 
	nom++;
	for (int i=(int)0;i<n;++i)
	{//��������� ����� ����� ��������� 
		if (sp[0].marka!=ap[i].marka)
		{//���� ����� ������������ �� �����
			int zm=0;
			for(int j=(int)1;j<nom;++j)
			{//� ���� ��������� �� �� ����� �� �������� � ������� 2
				if (ap[i].marka==sp[j].marka)
					zm=1;
			}
			if (!zm)//���� �� ��������, �������
			{
				sp[nom].marka=ap[i].marka;
				nom++;
			}
		}
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<nom;++i)
	{
		for(int j=(int)0;j<n;++j)
		{
			if(sp[i].marka==ap[j].marka)
			{
				sp[i].probig+=ap[j].probig;
				sp[i].lich++;
			}
		}
	}//������ ��� �� ������ ��� ����� ���������
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		cout<<ap[i].marka.marka<<'\t';
		cout<<ap[i].nomer<<'\t';
		cout<<ap[i].vupusk<<'\t';
		cout<<ap[i].probig<<endl;
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<nom;++i)
	{
		cout<<sp[i].marka.marka<<'\t';
		cout<<sp[i].probig/sp[i].lich<<endl;
	}
	//--------------------------------------------------------
	free(sp);
	free(ap);//delete[]ap;
	//--------------------------------------------------------
	{
		cin.clear();
		char ch;
		cout<<"Wedit sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
