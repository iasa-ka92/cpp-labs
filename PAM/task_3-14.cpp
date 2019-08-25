#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Coor
{

public:
	Coor();
	Coor(double valueX, double valueY);
	~Coor();

	double GetX()
	{
		return x;
	}

	Coor& SetX(double valueX)
	{
		this->x = valueX;
		return *this;
	}

	double GetY()
	{
		return y;
	}

	Coor& SetY(double valueY)
	{
		this->y = valueY;
		return *this;
	}

	void Print()
	{
		cout << "x =\t" << x << "\t" << "y =\t" << y << endl;
	}

	Coor(const Coor &other)
	{
		this->x = other.x;
		this->y = other.y;
	}

public:
	double x, y;
};

Coor::Coor(double valueX, double valueY)
{
	cout << "ß êîíñòðóêòîð Coor" << endl;
	x = valueX;
	y = valueY;
}

Coor::Coor()
{
	cout << "ß êîíñòðóêòîð Coor" << endl;
	x = 0;
	y = 0;
}

Coor::~Coor()
{
	cout << "ß äåñòðóêòîð Coor" << endl;
}

class ExistenceLifeForm
{
public:

	ExistenceLifeForm();

	ExistenceLifeForm(char* dataN, int valueA, double ValueX, double valueY);

	ExistenceLifeForm(const ExistenceLifeForm &other)
	{
		this->Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
		this->Age = other.Age;
		this->Coordinat = other.Coordinat;
	}

	~ExistenceLifeForm();

	virtual void Move() = 0;

	void Print()
	{
		cout << Name << "\t" << Age << "\t";
		this->Coordinat.Print();
		cout << endl;
	}

protected:
	char* Name;
	int Age;
	Coor Coordinat;
};

ExistenceLifeForm::ExistenceLifeForm(char* dataN, int valueA, double valueX, double valueY) :Coordinat(valueX, valueY)
{
	this->Name = new char[strlen(dataN) + 1];
	strcpy(this->Name, dataN);
	Age = valueA;
	cout << "ß êîíñòðóêòîð ëàéâôîðì" << endl;
}

ExistenceLifeForm::ExistenceLifeForm() :Coordinat(0, 0)
{
	this->Name = new char[7];
	strcpy(Name, "noname");
	Age = 0;
	cout << "ß êîíñòðóêòîð ëàéâôîðì" << endl;
}

ExistenceLifeForm::~ExistenceLifeForm()
{
	cout << "ß äåñòðóêòîð ëàéâôîðì" << endl;
	delete[] Name;
}

class Creature : public ExistenceLifeForm, public Coor
{
public:
	Creature();
	Creature(char* dataN, int valueA, double valueX, double valueY);
	Creature(Creature &other);
	~Creature();

	void Print()
	{
		cout << Name << "\t" << Age << "\t"<<LifeStatus;
		this->Coordinat.Print();
		cout << endl;
	}

	void Move() = 0;
	bool LifeStatus;
};

Creature::Creature()
{
	cout << "ÿ êîíñòðóêòîð Creature" << endl;
	this->LifeStatus = 1;
}

Creature::Creature(char * dataN, int valueA, double valueX, double valueY):ExistenceLifeForm(dataN,valueA,valueX,valueY)
{
	cout << "ÿ êîíñòðóêòîð Creature" << endl;
	this->LifeStatus = 1;
}

Creature::Creature(Creature & other)
{
	cout << "ÿ êîíñòðóêòîð Creature" << endl;
	this->Age = other.Age;
	this->Name = other.Name;
	this->Coordinat = other.Coordinat;
	this->LifeStatus = 1;
}

Creature::~Creature()
{
	cout << "ÿ äåêîíñòðóêòîð Creature" << endl;
}

class Plant: public ExistenceLifeForm
{
public:
	Plant(char * dataN, int valueA, double valueX, double valueY);
	Plant();
	Plant(Plant &other);
	void Move()
	{
		this->Print();
	}
	~Plant();
	void Print()
	{
		this->Coordinat.Print();
		cout << endl;
	}
};

Plant::Plant(char * dataN, int valueA, double valueX, double valueY):ExistenceLifeForm(dataN,valueA,valueX,valueY)
{
	cout << "ÿ êîíñòðóêòîð Plant" << endl;
}

Plant::Plant()
{
	cout << "ÿ êîíñòðóêòîð Plant" << endl;
}

Plant::Plant(Plant & other)
{
	cout << "ÿ êîíñòðóêòîð Plant" << endl;
	this->Age = other.Age;
	this->Name = other.Name;
	this->Coordinat = other.Coordinat;
}

Plant::~Plant()
{
	cout << "ÿ äåêîíñòðóêòîð Plant" << endl;
}

class UnMovedObject : public ExistenceLifeForm
{
public:
	UnMovedObject();
	UnMovedObject(char * dataN, int valueA, double valueX, double valueY);
	UnMovedObject(UnMovedObject &other);
	~UnMovedObject();

	void Move()
	{
		this->Print();
	}
	void Print()
	{
		cout << Name << endl;
		this->Coordinat.Print();
		cout << endl;
	}

};

UnMovedObject::UnMovedObject()
{
	cout << "ÿ êîíñòðóêòîð UnMovedObject" << endl;
}

UnMovedObject::UnMovedObject(char * dataN, int valueA, double valueX, double valueY) : ExistenceLifeForm(dataN, valueA, valueX, valueY)
{
	cout << "ÿ êîíñòðóêòîð UnMovedObject" << endl;
}

UnMovedObject::UnMovedObject(UnMovedObject &other)
{
	this->Age = other.Age;
	this->Name = other.Name;
	this->Coordinat = other.Coordinat;
	cout << "ÿ êîíñòðóêòîð UnMovedObject" << endl;
}

UnMovedObject::~UnMovedObject()
{
	cout << "ÿ äåêîíñòðóêòîð UnMovedObject" << endl;
}

class Herbivorous : public Creature
{
public:
	Herbivorous();
	Herbivorous(char * dataN, int valueA, double valueX, double valueY);
	Herbivorous(Herbivorous &other);
	~Herbivorous();

	void Move()
	{
		this->Coordinat.x++;
		this->Coordinat.y++;
		this->Age++;
		if (Age < this->MaxAgeHerbivous)
		{
			this->LifeStatus = 1;
		}
		else
		{
			this->LifeStatus = 0;
		}
	}

	void Print()
	{
		cout << Name << "\t" << Age << "\t";
		this->Coordinat.Print();
		cout << endl;
	}

	static int MaxAgeHerbivous;
};

Herbivorous::Herbivorous()
{
	this->MaxAgeHerbivous = 50;
	cout << "ÿ êîíñòðóêòîð Herbivorous" << endl;
}

Herbivorous::Herbivorous(char * dataN, int valueA, double valueX, double valueY) : Creature(dataN, valueA, valueX, valueY)
{
	cout << "ÿ êîíñòðóêòîð Herbivorous" << endl;
}

Herbivorous::Herbivorous(Herbivorous &other)
{
	this->Age = other.Age;
	this->Name = other.Name;
	this->Coordinat = other.Coordinat;
	cout << "ÿ êîíñòðóêòîð Herbivorous" << endl;
}

Herbivorous::~Herbivorous()
{
	cout << "ÿ äåñòðóêòîð Herbivorous" << endl;
}

int Herbivorous::MaxAgeHerbivous = 50;

class Predator : public Creature
{
public:
	Predator();
	Predator(char * dataN, int valueA, double valueX, double valueY);
	Predator(Predator &other);
	~Predator();

	void Print()
	{
		cout << Name << "\t" << Age ;
		this->Coordinat.Print();
		cout << endl;
	}

	void Move()
	{
		this->Coordinat.x++;
		this->Coordinat.y++;
		this->Age++;
		if (Age < this->MaxAgePredator)
		{
			this->LifeStatus = 1;
		}
		else
		{
			this->LifeStatus = 0;
		}
	}

	static int MaxAgePredator;
};

Predator::Predator()
{
	this->MaxAgePredator = 100;
	cout << "ÿ êîíñòðóêòîð Predator" << endl;
}

Predator::Predator(char * dataN, int valueA, double valueX, double valueY) : Creature(dataN, valueA, valueX, valueY)
{
	cout << "ÿ êîíñòðóêòîð Predator" << endl;
}

Predator::Predator(Predator &other)
{
	this->Age = other.Age;
	this->Name = other.Name;
	this->Coordinat = other.Coordinat;
	cout << "ÿ êîíñòðóêòîð Predator" << endl;
}

Predator::~Predator()
{
	cout << "ÿ äåñòðóêòîð Predator" << endl;
}

int Predator::MaxAgePredator = 100;

int main()
{
	setlocale(LC_ALL, "Rus");

	Plant P1;
	P1.Move();

	UnMovedObject Un1;
	Un1.Move();

	Predator Pre1;
	Pre1.Print();
	Pre1.Move();

	Herbivorous H1;
	H1.Print();

	return 0;
}
