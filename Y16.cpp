
//10 завдання
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
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		School Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.school>m[j].school)//якщо максимальне менше за поточне
			{
				Max=m[j];//зчитуєм поточне
				n=j;//зчитуєм номер поточного
			}
		}
		if (n!=i)//перевіряєм чи номер змінився
		{//виконуємо перестаноку максимального з поточним
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
	for (int i=(int)1;(size_t)i<k.size();++i)//В циклі перевіряєм кожне значення
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
	for (int i=(int)0;(size_t)i<m.size();++i)//В циклі перевіряєм кожне значення
	{
		if (m[i].school!=k[k.size()-(size_t)1].school)//чи школа не зінилася
			k.push_back(m[i].school);//якщо змінилася то заводим новий вий примірник структури
		if(m[i].clas[0]=='9') //перевіряєм чи учень девятикласник
			k[k.size()-(size_t)1].kilkict++;//якщо ні то збільшуєм лічильник девятикласників
	}
}
//---------------------------------------------------------
ostream& operator<<(ostream &os,const School& a)
{
	string p,im,s=(string)"\t|";
	if (a.priz.size()<(size_t)7)//перевіряєм довжину назви
		p=(string)"\t\t|";
	else p=s;
	if (a.imja.size()<(size_t)7)//перевіряєм довжину номера
		im=(string)"\t\t|";
	else im=s;
	return os<<(char)'|'<<a.priz<<p<<a.imja<<im<<a.school<<s<<a.clas<<(string)"\t|"//повертаєм в потік ostrim всю структуру
			 <<endl<<(string)"-------------------------------------------------"
			 <<endl;
}
vector<School> Zmag;//створюємо таблицю
int main()
{
	string zm;
	while (getline(cin,zm))//зчитуємо дані по рядочкам
	{
		istringstream is(zm);//Розкриваєм зчитаний рядок в потік
		string p,im,c,per;
		int s=(int)0;
		is>>p>>im>>s>>c>>per;//зчитуємо 
		if (p==(string)"end")break;//виконуєм перевірку зчитаних даних
		if (p.size()>=(int)15||p.size()<(int)1)//переірка довжини назви 
			cout<<(string)"Prizvushce zadovge\n";
		else if(im.size()>(int)8||im.size()<(int)1)//перевірка довжини номера
			cout<<(string)"Nekorektne Im’ja shkolara\n";
		else if(s>(int)120||s<(int)1) //перевірка коректності року випуску
			cout<<(string)"Nekorektna shkola \n";
		else if(c.size()!=(int)3)//перевірка коректності пробігу авто
			cout<<(string)"Nekorektnui prodig avto\n";
		else if(per.size()>(int)1)//перевірка лишнього числа
			cout<<(string)"Wedeno lushni slovo\n";
		else //якщо ми пройшли всі перевірки на коректність введених даних
		{
			School a(p,im,s,c);
			Zmag.push_back(a);//записуємо дані в таблицю
		}
	}
	if (Zmag.size()>(size_t)0)
	{
		vector<Klass> K;
		Sort_school(Zmag);//викликаєм функцію сортування
		Sotn_klass(Zmag,K);
		cout<<(string)"-------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)Zmag.size();i++)
		{
			cout<<Zmag[i];//почергово виводим таблицю
		}
		cout<<"naibilshe 9-tu klasnukiv v "<<K[find_max(K)].school<<" shkoli"<<endl;
	}
	{//затримка
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
