//10 ��������
#include <iostream>
using namespace std;
//---------------------------------------------------------
struct Pov
{
	char kod[4];
	char povidomlena[30];
};
//---------------------------------------------------------
int KodRivnui(Pov k)
{//�������� �� � ���� � ��� ����� ����� ��� ����
	for (int i=(int)0;i<(int)3;++i)
	{
		if (k.kod[i]!=0&&k.kod[i]==k.kod[i+1])
			return 1;
	}
	return 0;
}
//---------------------------------------------------------
int perkod(Pov a,Pov b)
{//�������� ����
	if (a.kod[0]==b.kod[0])
	{
		if (a.kod[1]==b.kod[1])
		{
			if (a.kod[2]==b.kod[2])
			{
				if (a.kod[3]==b.kod[3])
					return 0;
				else if (a.kod[3]<b.kod[3])
					return 1;
			}
			else if (a.kod[2]<b.kod[2])
				return 1;
		}
		else if (a.kod[1]<b.kod[1])
			return 1;
	}
	else if (a.kod[0]<b.kod[0])
		return 1;
	return 0;
}
//---------------------------------------------------------
int main()
{
	int n=(int)3;
	Pov* pp=(Pov*)calloc((size_t)n,sizeof(Pov));
	for (int i=(int)0;i<n;++i)
	{
		cin>>pp[i].kod;
		cin>>pp[i].povidomlena;
	}//������� ���
	//--------------------------------------------------------
	int kilkist=(int)0;
	for (int i=(int)0;i<n-(int)1;++i)
	{
		for(int j=i+(int)1;j<n;++j)//� ���� ��������� �� ��������
		{
			
			if(perkod(pp[i],pp[j]))//���� ������� ����� �� ��������
			{
				Pov zm=pp[i];
				pp[i]=pp[j];
				pp[j]=zm;//����� ������
			}
		}
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{//����� ������� ��� �� ������������
		kilkist+=KodRivnui(pp[i]);
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		cout<<pp[i].kod<<'\t';
		cout<<pp[i].povidomlena<<endl;
	}
	//-------------------------------------------------------
	cout<<"Pvidomlen z kodamu v jakuh poruch je dvi odnakovi chufru "
	<<kilkist<<endl;
	//--------------------------------------------------------
	free(pp);
	//--------------------------------------------------------
	{
		cin.clear();
		char ch;
		cout<<"Wedit sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
