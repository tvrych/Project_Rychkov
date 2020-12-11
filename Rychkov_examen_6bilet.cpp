#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Toy 
{
public:
	Toy(string name, int cost, string age)
	{
		this->name = name;
		this->cost = cost;
		this->age = age;
	}
	string Get_name()
	{
		return name;
	}
	int Get_cost()
	{
		return cost;
	}
	string Get_age()
	{
		return age;
	}
	void printinfo()
	{
		cout << "name= " << name << "\n";
		cout << "cost= " << cost << "\n";
		cout << "age interval= " << age << "\n";
		cout << "\n";
	}


private:
	
	string name, age;
	int cost;
};




void reading_from_file(ifstream& fin, vector<Toy>& Vec)
{
	string name = "";
	string cost = "";
	string age = "";
	int counter = 0;
	if (fin.is_open())
	{
		cout << "File is open\n";
		while (!fin.eof())
		{
			counter++;
			if (counter == 1)
			{
				getline(fin, name);
			}
			else if (counter == 2)
			{
				getline(fin, cost);
			}
			else if (counter == 3)
			{
				getline(fin, age);
				Toy* toy = new Toy(name, stoi(cost), age);//stoi - string to int;
				Vec.push_back(*toy);
				counter = 0;
			}
		}
	}
}



int main()
{
	string path = "Toys.txt";
	ifstream fin(path);
	vector <Toy> Vec;
	vector<string> ageVec1;
	vector <int> ageVec2;
	vector <int> ageVec3;
	int count1, count2;
	reading_from_file(fin, Vec);
	for (int i = 0; i < Vec.size(); i++)
	{
		Toy blank = Vec[i];
		blank.printinfo();
		ageVec1.push_back(Vec[i].Get_age());
		for (string i:ageVec1)
		{
			for (int j = i[0]; j < (i[2] + i[3]) - 38; j++)
			{
				for (int q = i[0]+4; q < (i[2] + i[3])+5; q++)
				{
					count1 = j - 48;
					count2 = q - 48;
						if (count1 == 4 && count2 == 10)
						{
							cout << "Toy for 4 and 10 years:\n";
							blank.printinfo();
						}
				}

			}
		}

		if (Vec[i].Get_cost() < 40)
		{
			for (int j = 0; i < ageVec2.size(); j++)
			{
				if (ageVec2[j] == 5)
				{
					cout << "Toy costs less than 40 grivnas for kids at the age of 5:\n ";
					blank.printinfo();
					break;
					ageVec2.clear();
				}
			}

		}
	    
	}

}

/*#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Toy
{
public:
	Toy(string name, int cost, int age)
	{
		this->name = name;
		this->cost = cost;
		this->age = age;
	}
	string Get_name()
	{
		return name;
	}
	int Get_cost()
	{
		return cost;
	}
	int Get_age()
	{
		return age;
	}
	void printinfo()
	{
		cout << "name= " << name << "\n";
		cout << "cost= " << cost << "\n";
		cout << "age= " << age << "\n";
		cout << "\n";
	}


private:

	string name;
	int cost, age;
};




void reading_from_file(ifstream& fin, vector<Toy>& Vec)
{
	string name = "";
	string cost = "";
	string age = "";
	int counter = 0;
	if (fin.is_open())
	{
		cout << "File is open\n";
		while (!fin.eof())
		{
			counter++;
			if (counter == 1)
			{
				getline(fin, name);
			}
			else if (counter == 2)
			{
				getline(fin, cost);
			}
			else if (counter == 3)
			{
				getline(fin, age);
				Toy* toy = new Toy(name, stoi(cost), stoi(age));//stoi - string to int;
				Vec.push_back(*toy);
				counter = 0;
			}
		}
	}
}



int main()
{
	string path = "Toys.txt";
	ifstream fin(path);
	vector <Toy> Vec;
	reading_from_file(fin, Vec);
	for (int i = 0; i < Vec.size(); i++)
	{
		Toy blank = Vec[i];
		blank.printinfo();
		if (Vec[i].Get_cost() < 40 && Vec[i].Get_age() == 5)
		{
			cout << "Toy costs less than 40 grivnas for kids at the age of 5:\n ";
			blank.printinfo();
		}

	}





}*/

