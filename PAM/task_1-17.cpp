
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


struct Product
{
	char product_name[40];
	char number_of_products[40];
	int price;
};

void FillOne(Product* one)
{
	cout << endl;
	cout << "������� ������������ ������: ";			cin >> one->product_name;
	cout << "������� ���������� ������: ";				cin >> one->number_of_products;
	cout << "������� ���� ������: ";					cin >> one->price;
	cout << endl;
}

void Fill_array(const int array_size, Product *data)
{
	for (int i = 0; i < array_size; i++)
	{
		cout << "������� ������������ ������: ";			cin >> data[i].product_name;
		cout << "������� ���������� ������: ";				cin >> data[i].number_of_products;
		cout << "������� ���� ������: ";					cin >> data[i].price;
		cout << endl;
	}
}

void Show_array(const int array_size, Product *data)
{
	cout << endl << "������" << "\t�������� ������\t\t����������\t\t����" << endl << endl;
	for (int i = 0; i < array_size; i++)
	{
		cout << i << "\t" << data[i].product_name << "\t\t" << data[i].number_of_products << "\t\t" << data[i].price << endl;
	}
}

void Number_of_higher_price_products(const int array_size, Product *data,const int price_of_products)
{
	int amount = 0;

	for (int i = 0; i < array_size; i++)
	{
		if (data[i].price > price_of_products)
		{
			amount++;
		}
	}

	cout << "���������� ��������� � ����� ���� �������: " << amount << endl;

}

void Bubble_price_sort(const int array_size, Product *data)
{
	Product temp;
	for (int i = 0; i < array_size - 1; i++)
	{ 
		for (int j = 0; j < array_size - i - 1; j++)
		{
			if (data[j].price > data[j + 1].price) 
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;

			}
		}
	}
}

Product* Push_middle(Product data[], Product new_array[], int const array_size, int index)
{
		Product value;
		FillOne(&value);
		int i = 0;
		for (i = 0; i < array_size; i++)
		{
			if (i != (index))
			{
				new_array[i] = data[i];
			}
			else
			{
				new_array[i] = value;
				break;
			}
			}
		for (int j = i + 1; j < array_size; j++)
		{
			new_array[j] = data[j - 1];
		}

	return new_array;

}

Product* Pop_middle(Product data[], Product new_array[], int const array_size, int index)
{
	for (int i = 0; i < array_size; i++)
	{
		if (i != index)
		{
			new_array[i] = data[i];
		}
		else
		{
			new_array[i] = data[i + 1];
			for (int j = i + 1; j < array_size; j++)
			{
				new_array[j] = data[j + 1];
			}break;
		}
	}
	
	return new_array;
}

int Menu()
{
	{
		int choice;
		cout << endl << "0 - �����" << endl;
		cout << "1 - C������� ������� � ���������� ������ ��� ������ ��� ������� � ����������� ����������� � ����������" << endl;
		cout << "2 - ����� ������� �� �����" << endl;
		cout << "3 - ������� ���������� ��������� � ����� ���� �������" << endl;
		cout << "4 - ���������� �� ����" << endl;
		cout << "5 - �������� ������� k-���" << endl;
		cout << "6 - ������� ������� k-���" << endl;
		cout << "7 - ������� � ����" << endl << endl;
		cout << "��� �����: ";
		cin >> choice;
		cout << endl;
		return choice;
	}
}

void OutpFile(Product *data, int const size) {
	string path = "Adressnormal.txt";
	ofstream  fout;
	fout.open(path);

	if (!fout.is_open())
	{
		cout << "Error open" << endl;
	}
	else
	{
		cout << endl << "������" << "\t�������� ������\t\t����������\t\t����" << endl << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "\t" << data[i].product_name << "\t\t" << data[i].number_of_products << "\t\t" << data[i].price << endl;
		}
	}
	fout.close();
}

int main()
{
	int array_size;

	setlocale(LC_ALL, "rus");


	cout << "������� ������ �������, � ������� ������ ��������: ";
	cin >> array_size;

	Product *data = new Product[array_size];

	while (1)
	{
		int option = Menu();
		
		switch (option)
		{
		case 1: {
			Fill_array(array_size, data);
			break; };
		case 2: {
			Show_array(array_size, data);
			break; }
		case 3: {
			int price_of_products;

			cout << "������� ����: ";
			cin >> price_of_products;

			Number_of_higher_price_products(array_size, data, price_of_products);
			break; };
		case 4: {
			Bubble_price_sort(array_size, data);
			break; }
		case 5: {
			int index;
			++array_size;
			Product *new_array = new Product[array_size];

			cout << "������� ������ �������, ����� �������� �� ������ �������� �������: ";
			cin >> index;

			if (index < array_size)
			{
				cout << endl;
				new_array = Push_middle(data, new_array, array_size, index);

				delete[] data;
				data = new_array;
			}
			else
			{
				cout << endl << "������� ����� ������ � ����� �����, ������� ������/������ ������� ������ �������" << endl;
				break;
			}

			break; };
		case 6: {
			int index;
			--array_size;

			Product *new_array = new Product[array_size];

			cout << "������� ������ �������, ����� �������� �� ������ ������� �������: ";
			cin >> index;

			if (index <= array_size)
			{
				cout << endl;
				new_array = Pop_middle(data, new_array, array_size, index);

				delete[] data;	
				data = new_array;
			}
			else
			{
				cout << endl << "������� ����� ������ � ����� �����, ������� ������/������ ������� ������ �������" << endl;
			}

			break; };
		case 7: {
			OutpFile(data, array_size);
			break;
		}
		}		
	}
	delete[] data;

	return 0;
}

