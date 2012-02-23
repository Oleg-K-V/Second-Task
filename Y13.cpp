//13 завдання
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ST\std_lib_facilities.h>

using namespace std;
struct MedKarta
{//Структура для завдання 13
	string Lastname;
	char stat;
	int vik,zrist,vaga;
	MedKarta(string l,int vi,char s,int z,int va)
		:Lastname(l),vik(vi),stat(s),zrist(z),vaga(va){}
};
//---------------------------------------------------------
void Sort_MedKartu(vector<MedKarta> &m)
{
	for (int i=(int)0;(size_t)i<m.size()-(size_t)1;++i)//В циклі перевіряєм кожне значення
	{
		MedKarta Max=m[i];//зчитуємо потоне значення
		int n=i;//зчитуєм поточний номер
		for(int j=i+(int)1;(size_t)j<m.size();++j)//в циклі знаходимо максимальне занчення
		{
			if(Max.Lastname[0]>m[j].Lastname[0])
			{//якщо максимальне менше за поточне
				Max=m[j];//зчитуєм поточне
				n=j;//зчитуєм номер поточного
			}
			else if(Max.Lastname[0]==m[j].Lastname[0])
			{
				int s1=(int)Max.Lastname.size();
				int s2=(int)m[j].Lastname.size();
				for (int k=(int)0;k<(s1>s2?s2:s1);++k)
					if (Max.Lastname[k]<m[j].Lastname[k])
					{//якщо максимальне менше за поточне
						Max=m[j];//зчитуєм поточне
						n=j;//зчитуєм номер поточного
					}
				if (n==j)
				{
					if(s1<s2)
					{//якщо максимальне менше за поточне
						Max=m[j];//зчитуєм поточне
						n=j;//зчитуєм номер поточного
					}
				}
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
void SeredneVZ(const vector<MedKarta> &m)
{
	vector<MedKarta> M,W;
	for (int i=(int)0;i<(int)m.size();++i)
	{//Розділяєм Чоловіків і жінок в 2 різних вектора
		if (m[i].stat=='M')
			M.push_back(m[i]);
		else W.push_back(m[i]);
	}
	int serVM=0,serZM=0,serVW=0,serZW=0;
	//--------------------------------------------------------
	if (M.size()>(size_t)0)
	{//сумаємо зріст і вагу чоловіків
		for(int i=(int)0;i<(int)M.size();++i)
		{
			serVM+=M[i].vaga;
			serZM+=M[i].zrist;
		}
		serVM/=(int)M.size();//Вічисляєм середню вагу 
		serZM/=(int)M.size();//Вічисляєм середній зріст
		cout<<(string)"Seredne znachena sered cholowikiw:"<<endl
			<<(string)"Serednii zrist ("<<serZM<<")"<<endl
			<<(string)"Serednii Vaga  ("<<serVM<<")"<<endl;
	}
	else cout<<(string)"Chilovikiv ne bulo wedeno\n";
	//--------------------------------------------------------
	if (W.size()>(size_t)0)
	{//сумаємо зріст і вагу чоловіків
		for(int i=(int)0;i<(int)W.size();++i)
		{
			serVW+=W[i].vaga;
			serZW+=W[i].zrist;
		}
		serVW/=(int)W.size();//Вічисляєм середню вагу
		serZW/=(int)W.size();//Вічисляєм середній зріст
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
	if (a.Lastname.size()>=(size_t)8)//перевіряєм довжину назви
		l=s;
	else l=(string)"\t\t|";
	return os<<(char)'|'<<a.Lastname<<l<<a.vik<<s<<a.stat<<s<<a.zrist<<s<<a.vaga<<(string)"\t|"//повертаєм в потік ostrim всю структуру
			 <<endl<<(string)"-------------------------------------------------"
			 <<endl;
}
vector<MedKarta> MK;//створюємо таблицю
int main()
{
	string zm;
	while (getline(cin,zm))//зчитуємо дані по рядком
	{
		istringstream is(zm);//Розкриваєм зчитаний рядок в потік
		string l,in,per;
		int vi,z,va;
		char s;
		is>>l>>in>>vi>>s>>z>>va>>per;//зчитуємо 
		if (l==(string)"end")break;//виконуєм перевірку зчитаних даних
		if (l.size()>=(size_t)10)//переірка довжини прізвще 
			cout<<(string)"Zadovge prizvushce\n";
		else if(vi>(int)150||vi<(int)0)//Пеевіряємо вік
			cout<<(string)"Wedit korektnu stat daty narodgenja\n";
		else if(in.size()!=(size_t)4)//перевірка ініціали
			cout<<(string)"Wedit korektnu inicialu\n";
		else if(s!=(char)'W'&&s!=(char)'M') //перевірка стать
			cout<<(string)"Wedit korektnu stat\n";
		else if(z>(int)300||z<(int)0)//перевіряєм зріст
			cout<<(string)"Wedit korektnu zrist\n";
		else if(va>(int)250||va<(int)0)//перевіряєм вагу
			cout<<(string)"Wedit korektnu vagu\n";
		else if(per.size()>(size_t)1)//перевірка лишнього слова
			cout<<(string)"Wedeno lushni slovo\n";
		else //якщо ми пройшли всі перевірки на коректність введених даних
		{
			MedKarta a(l+' '+in,vi,s,z,va);
			MK.push_back(a);//записуємо дані в таблицю
		}
	}
	if (MK.size()>(size_t)0)
	{
		Sort_MedKartu(MK);//викликаєм функцію сортування
		cout<<"-------------------------------------------------"<<endl;
		for (int i=(int)0;i<(int)MK.size();i++)
		{
			cout<<MK[i];//почергово виводим таблицю
		}
		SeredneVZ(MK);//Викликаєм функцію середнього значення
	}
	{//затримка
		cin.clear();
		char ch;
		cout<<(string)"Wedit budlaska ljybui sumvol dla zavershena"<<endl;
		cin>>ch;
	}
	return 0;
}
