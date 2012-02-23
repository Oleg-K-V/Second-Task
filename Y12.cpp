//12 завдання
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
struct _Point
{//Структура для завдання 12
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
	double zm1=(double)((p1.x-p2.x)*(p1.x-p2.x));//знаходимо квадрат різниці по х
	double zm2=(double)((p1.y-p2.y)*(p1.y-p2.y));//знаходимо квадрат різниці по у
	double zm3=zm1+zm2;
	double res=pow(zm3,0.5);//знаходим довжину
	return res;
}
void Sort_Color(vector<_Point> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		_Point Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.color<m[j].color)//якщо максимальне менше за поточне
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
void Sort_Color(vector<_Point> &m,XY &p1,XY &p2,double &v)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		_Point Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		XY Z1,Z2;
		Z1.x=Max.x;
		Z1.y=Max.y;//зчитуєм кординати
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.color==m[j].color)
			{//перевіряєм чи кольори співпадають
				Z2.x=m[j].x;
				Z2.y=m[j].y;//зчитуєм кординати
				double res=vidstan(Z1,Z2);//знаходим відстать між кординатами
				if (res>v)
				{//перевіряєм чи поточна відстать не є найдовшою
					p1.x=Max.x;
					p1.y=Max.y;
					p2.x=Z2.x;
					p2.y=Z2.y;
					v=res;//присвоюєм всі значення
				}
			}
			if(Max.color<m[j].color)//якщо максимальне менше за поточне
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

ostream& operator<<(ostream &os,const _Point& a)
{
	string m=(string)"\t|";
	return os<<dec<<(char)'|'<<a.x<<m<<a.y<<m<<hex<<a.color<<(string)"\t|"//повертаєм в потік ostrim всю структуру
			 <<endl<<(string)"-------------------------"
			 <<endl;
}
vector<_Point> P;//створюємо таблицю
int main()
{
	string zm;
	while (getline(cin,zm))//зчитуємо дані по рядочкам
	{
		istringstream is(zm);//Розкриваєм зчитаний рядок в потік
		unsigned int _x=(unsigned int)0,_y=(unsigned int)0;
		int c=(int)0;
		string per;
		is>>_x>>_y>>hex>>c>>per;//зчитуємо значення
		if (_x==(unsigned int)0&&_y==(unsigned int)0)break;//виконуєм перевірку зчитаних даних
		else if(per.size()>(int)1)//перевірка лишнього слова
			cout<<(string)"Wedeno lushni slovo\n";
		else //якщо ми пройшли всі перевірки на коректність введених даних
		{
			_Point a(_x,_y,c);
			P.push_back(a);//записуємо дані в таблицю
		}
	}
	if (P.size()>(size_t)0)//перевіряєм чи було введено кординати
	{
		XY p1,p2;
		double v=(double)0;
		if (P.size()>(size_t)1)//перевіряєм чи було ведено більше 2-х кординат
			Sort_Color(P,p1,p2,v);//викликаєм функцію сортування з пошуком найдовшої відстані
		else Sort_Color(P);//викликаєм функцію сортування
		cout<<(string)"-------------------------"<<endl;
		for (int i=(int)0;i<(int)P.size();i++)
		{
			cout<<P[i];//почергово виводим таблицю
		}
		if (!v)//перевіряєм чи було знайдено найдовшу відстань між кординатами
			cout<<"Nebulo znaideni spivpadin"<<endl;//якщо ні виводм повідомлення
		else 
		{
			cout<<"naibelsha vidstan mig tochkamu ("//якщо та то виводим дані
				<<dec<<p1.x<<','<<p1.y<<")("<<p2.x<<','<<p2.y<<") = "<<v<<endl;
		}
	}
	{//затримка
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
