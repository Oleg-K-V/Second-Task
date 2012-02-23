//15 завдання
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
{//Структура для завдання 15
	XY vershuna1,vershuna2,vershuna3;
	double perumtr;
	_Point(XY v1,XY v2,XY v3,double p)
		:vershuna1(v1),vershuna2(v2),vershuna3(v3),perumtr(p){}
};

double vidstan(XY p1,XY p2)
{
	double zm1=(double)((p1.x-p2.x)*(p1.x-p2.x));//знаходимо квадрат різниці по х
	double zm2=(double)((p1.y-p2.y)*(p1.y-p2.y));//знаходимо квадрат різниці по у
	double zm3=zm1+zm2;
	double res=pow(zm3,0.5);//знаходим довжину
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
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		_Point Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.perumtr<m[j].perumtr)//якщо максимальне менше за поточне
			{
				Max=m[j];//зчитуєм поточне
				n=j;//зчитуєм номер поточного
			}
		}
		if (n!=i)//перевіряєм чи номер змінився
		{//виконуємо перестановку максимального з поточним
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
	for (int i=(int)0;(size_t)i<m.size();++i)//В циклі перевіряєм кожне значення
	{
		if (m[i].perumtr>=min2)
			n++;//Перевіряєм чи поточне вписується в рамки і інкрементуєм кількість
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
							 <<a.perumtr<<(string)"\t|"//повертаєм в потік ostrim всю структуру
			 <<endl<<(string)"---------------------------------------------------------"
			 <<endl;
}
vector<_Point> P;//створюємо таблицю
int main()
{
	string zm;
	while (getline(cin,zm))//зчитуємо дані по рядочкам
	{
		istringstream is(zm);//Розкриваєм зчитаний рядок в потік
		XY v1,v2,v3;
		string per;
		is>>v1.x>>v1.y>>v2.x>>v2.y>>v3.x>>v3.y>>per;//зчитуємо значення
		if (v1.x==(int)0&&v1.y==(int)0)break;//виконуєм перевірку зчитаних даних
		else if(per.size()>(int)1)//перевірка лишнього слова
			cout<<(string)"Wedeno lushni slovo\n";
		else //якщо ми пройшли всі перевірки на коректність введених даних
		{
			_Point a(v1,v2,v3,perumtr(v1,v2,v3));
			P.push_back(a);//записуємо дані в таблицю
		}
	}
	if (P.size()>(size_t)0)//перевіряєм чи було введено кординати
	{
		Sort_perumtr(P);//викликаєм функцію сортування
		cout<<(string)"--------------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)P.size();i++)
		{
			cout<<P[i];//почергово виводим таблицю
		}
	cout<<"Procent trukutnukiv z perumetrom bilshum za perumtr naimenshogo pomnogenui na 2 rivnui = "
		<<(int)((Find(P)/(double)P.size())*100)<<" %"<<endl; 
	}
	{//затримка
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
