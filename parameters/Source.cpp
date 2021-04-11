#include <iostream>;
using namespace std;
#define tab "\t"
//define 
// #define создает макроопределение(макрос)
void Exchange(int& a, int& b);

void main() 
{
	setlocale(LC_ALL,"Russian");
	int a = 2;
	int b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b);
	cout << a << tab << b << endl;

}
void Exchange(int& a, int& b)//Реализация(определение) фунции- Fnction definishion
{
	int c = a;
	a = b;
	b = c;
}
/*
 - по значению 
 -по указателю
 -по ссылке

*/