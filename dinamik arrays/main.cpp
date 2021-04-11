#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int* arr, const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void push_row_back(int** arr, int& m, const int n);

void pop_back(int*& arr, int& n); //������� ������� � ����� �������
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

//#define PUSH_BACK
//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: " << endl;
	cin >> n;
	int* arr = new int[n] {};
	Fillrand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������:"; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������:"; cin >> value;
	cout << "������� ������:"; cin >> value;
	insert(arr, n, value, index);
	int index;
	cout << "������� ����������� ��������:"; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);
	cout << "�������� ���������� ��������:\n ";
	pop_back(arr, n);
	Print(arr, n);
	cout << "�������� �������� ��������: \n";
	pop_front(arr, n);
	Print(arr, n);
	delete[] arr;
	insert(arr, n, index, value);
	Print(arr, n);
	delete[]arr;

#endif // DINAMIC_MEMORY_1
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////     ���������� ���������� ������������� �������     /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int m;   //���������� �����
	int n;  //���������� ��������� ������
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	//1) ������� ������ ����������, � ��������� ��� ����� � ��������� �� ���������:
	int** arr = new int* [m];
	//2) �������� ������ ��� ������ ���������� �������
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////           ������������� ���������� ������������� �������             //////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	FillRand(arr, m, n);
	Print(arr, m, n);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////      �������� ���������� ������������� �������         /////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 1) �������� �����:

	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	// 2) �������� ������� ����������:
	delete[] arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void push_back(int*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i]; // �������� �������� ��������������
	}
	//3) ����� ���� ��� ������ ����������� �������� ������ ����� �������
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;

}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1/*�������,�����������*/]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i]; // �������� �������� �� ��������� �� ���� ������� ������
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	/*for (int i = 0; i < index; i++)
	{
		buffer[i ] = arr[i];
	}
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];*/
	for (int i = 0; i < n; i++)
	{
		true;
		if (i < index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//(i < index) ? buffer[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[index] = value;
	n++;
}


void push_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};

	}
	for (int j = 0; j < n; j++)
	{
		buffer[i][j]= arr[i] [j];
	}
}
void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};  // �������� ������ ��������� ����������� ������ ������
	//��� ���� ����� ������� ������� �� �������, � �������� ������ ����� ����������� ��� �������� ����� ����������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	delete[]arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{

}
void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		buffer[i] = arr [ i < index ? i : i + 1];

	}
	delete[]arr;
	arr = buffer;
}




