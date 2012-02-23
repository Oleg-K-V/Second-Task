//10 завдання
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
{//перевіряє чи в числі є рівні чифри поряд крім нулів
	for (int i=(int)0;i<(int)3;++i)
	{
		if (k.kod[i]!=0&&k.kod[i]==k.kod[i+1])
			return 1;
	}
	return 0;
}
//---------------------------------------------------------
int perkod(Pov a,Pov b)
{//порівнюєм коди
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
	}//зчитуємо дані
	//--------------------------------------------------------
	int kilkist=(int)0;
	for (int i=(int)0;i<n-(int)1;++i)
	{
		for(int j=i+(int)1;j<n;++j)//В циклі перевіряєм всі значення
		{
			
			if(perkod(pp[i],pp[j]))//якщо поточне більше за наступне
			{
				Pov zm=pp[i];
				pp[i]=pp[j];
				pp[j]=zm;//міняєм місцями
			}
		}
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{//рахуєм кількість слів які повторюються
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
