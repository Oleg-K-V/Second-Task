//11 завдання
#include <iostream>
using namespace std;
union LastName
{
	char lastname[20];
	int slovo[5];
};
struct Student
{
	LastName lastname;
	char name[8];
	double serbal;
};
int perst(LastName a,LastName b)
{//порівнюєм коди
	if (a.lastname[0]==b.lastname[0])
	{
		if (a.lastname[1]==b.lastname[1])
		{
			if (a.lastname[2]==b.lastname[2])
			{
				if (a.lastname[3]==b.lastname[3])
				{
					if (a.lastname[4]==b.lastname[4])
						return 0;
					else if (a.lastname[4]>b.lastname[4])
						return 1;
				}
				else if (a.lastname[3]>b.lastname[3])
					return 1;
			}
			else if (a.lastname[2]>b.lastname[2])
				return 1;
		}
		else if (a.lastname[1]>b.lastname[1])
			return 1;
	}
	else if (a.lastname[0]>b.lastname[0])
		return 1;
	return 0;
}
int main()
{
	int n=(int)3;
	Student* sp=(Student*)calloc((size_t)n,sizeof(Student));
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		cin>>sp[i].lastname.lastname;
		cin>>sp[i].name;
		cin>>sp[i].serbal;
	}//зчитуємо дані
	//--------------------------------------------------------
	for (int i=(int)0;i<n-(int)1;++i)
	{
		for(int j=i+(int)1;j<n;++j)//В циклі перевіряєм всі значення
		{
			if(perst(sp[i].lastname,sp[j].lastname))//якщо поточне більше за наступне
			{
				Student zm=sp[i];
				sp[i]=sp[j];
				sp[j]=zm;//міняєм місцями
			}
		}
	}
	//------------------------------------------------------
	Student M1=sp[(int)1],M2=sp[(int)0];
	int nom=(int)1;
	for (int i=(int)0;i<n;++i)
	{//вибираєм першого найкращого
		if (M1.serbal<sp[i].serbal)
		{
			M1=sp[i];
			nom=i;
		}
	}
	for (int i=(int)1;i<n;++i)
	{//вибираємо другого найкращого
		if (M2.serbal<sp[i].serbal&&i!=nom)
			M2=sp[i];
	}
	//--------------------------------------------------------
	for (int i=(int)0;i<n;++i)
	{
		cout<<sp[i].lastname.lastname<<'\t';
		cout<<sp[i].name<<'\t';
		cout<<sp[i].serbal<<endl;
	}
	cout<<"Krachumu studentamu je:"<<endl
		<<M1.lastname.lastname<<'\t'<<M1.name<<'\t'<<M1.serbal<<endl
		<<M2.lastname.lastname<<'\t'<<M2.name<<'\t'<<M2.serbal<<endl;
	free(sp);
	//--------------------------------------------------------
	{
		cin.clear();
		char ch;
		cout<<"Wedit sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
