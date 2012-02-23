//10 завдання
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
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		Avto Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.vupusk<m[j].vupusk)//якщо максимальне менше за поточне
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
ostream& operator<<(ostream &os,const Avto& a)
{
	string m,n,s=(string)"\t\t|";
	if (a.marka.size()<(size_t)8)//перевіряєм довжину назви
		m=s;
	else m=(string)"\t";
	if (a.nomer.size()==(size_t)6)//перевіряєм довжину номера
		n=(string)"\t\t\t|";
	else n=s;
	return os<<(char)'|'<<a.marka<<m<<a.nomer<<n<<a.vupusk<<s<<a.probig<<(string)"\t|"//повертаєм в потік ostrim всю структуру
			 <<endl<<(string)"-----------------------------------------------------------------"
			 <<endl;
}
vector<Avto> Car;//створюємо таблицю
int main()
{
	string zm;
	while (getline(cin,zm))//зчитуємо дані по рядочкам
	{
		istringstream is(zm);//Розкриваєм зчитаний рядок в потік
		string m,n,per;
		int v=(int)0,p=(int)0;
		is>>m>>n>>v>>p>>per;//зчитуємо 
		if (m==(string)"end")break;//виконуєм перевірку зчитаних даних
		if (m.size()>=(int)15)//переірка довжини назви 
			cout<<(string)"Nazva mashunu zadovga\n";
		else if((n.size()!=(int)8)&&(n.size()!=(int)6))//перевірка довжини номера
			cout<<(string)"Nekorektnui nomer mashunu\n";
		else if(v>(int)2012||v<(int)1900) //перевірка коректності року випуску
			cout<<(string)"Nekorektnui rik vupysky\n";
		else if(p==(int)0||p>(int)1000000)//перевірка коректності пробігу авто
			cout<<(string)"Nekorektnui prodig avto\n";
		else if(per.size()>(int)1)//перевірка лишнього числа
			cout<<(string)"Wedeno lushni slovo\n";
		else //якщо ми пройшли всі перевірки на коректність введених даних
		{
			Avto a(m,n,v,p);
			Car.push_back(a);//записуємо дані в таблицю
		}
	}
	if (Car.size()>(size_t)0)
	{
		Sort_avto(Car);//викликаєм функцію сортування
		cout<<(string)"-----------------------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)Car.size();i++)
		{
			cout<<Car[i];//почергово виводим таблицю
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
