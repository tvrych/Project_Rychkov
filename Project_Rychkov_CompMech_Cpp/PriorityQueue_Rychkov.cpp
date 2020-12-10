#include "PriorityQueue_Rychkov.h"

using namespace std;


Pokupets::Pokupets(string name, int time, int summ)
{
	this->name = name;
	this->time = time;
	this->summ = summ;
}

string Pokupets::Get_Name()
{
	return name;
}
int Pokupets::Get_Time()
{
	return time;
}
int Pokupets::Get_Summ()
{
	return summ;
}
void Pokupets::printinfo()
{
	cout << "name= " << name << "\n";
	cout << "time= " << time << "\n";
	cout << "summ= " << summ << "\n";
}

bool operator <(Pokupets _Left, Pokupets _Right)
{
	return _Left.Get_Time() < _Right.Get_Time();
}

bool operator >(Pokupets _Left, Pokupets _Right)
{
	return _Left.Get_Time() > _Right.Get_Time();
}

void add_elment(priority_queue<Pokupets>& q)
{
	string name;
	int time, summ;
	cout << "Add name ";
	cin.ignore(32767, '\n');
	getline(cin, name);
	cout << "Add time ";
	cin >> time;
	cout << "Add summ ";
	cin >> summ;
	Pokupets pok(name, time, summ);
	q.push(pok);
}

void pokupetz_swaper(priority_queue<Pokupets>& q)
{
	int inp1, inp2;
	vector <Pokupets> addq;
	cout << "Which two customers you want to swap?\n";
	cin >> inp1 >> inp2;
	while (!q.empty())
	{
		addq.push_back(q.top());
		q.pop();
	}
	Pokupets blank1 = addq[inp1 - 1];
	Pokupets blank2 = addq[inp2 - 1];
	string name1 = blank1.Get_Name();
	string name2 = blank2.Get_Name();
	int time1 = blank1.Get_Time();
	int time2 = blank2.Get_Time();
	int summ1 = blank1.Get_Summ();
	int summ2 = blank2.Get_Summ();
	Pokupets Input1(name2, time1, summ2);
	Pokupets Input2(name1, time2, summ1);
	addq[inp1 - 1] = Input1;
	addq[inp2 - 1] = Input2;
	for (int i = 0; i < size(addq); i++)
	{
		q.push(addq[i]);
	}

}

void add_new_queue(vector<priority_queue<Pokupets>>& Vec)
{
	priority_queue<Pokupets>* empty_q = new priority_queue<Pokupets>;
	Vec.push_back(*empty_q);
	cout << "Waiting line was added\n";
}

void intersect_queues(vector<priority_queue<Pokupets>>& Vec)
{
	if (Vec.size() != 1)
	{
		int inp1, inp2;
		cout << "Choose queues to intersect\t";
		for (int i = 0; i < Vec.size(); i++)
		{
			cout << i + 1 << "; ";
		}
		cout << endl;
		cin >> inp1 >> inp2;
		inp1--;
		inp2--;
		while (!Vec[inp2].empty())
		{
			Vec[inp1].push(Vec[inp2].top());
			Vec[inp2].pop();
		}
	}
	else
	{
		cout << "Can't intersect one queue!\n";
	}
}


void reading_from_file(ifstream& fin, vector<priority_queue<Pokupets>>& Vec)
{
	priority_queue<Pokupets> q;
	string name = "";
	string time = "";
	string summ = "";
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
				getline(fin, time);
			}
			else if (counter == 3)
			{
				getline(fin, summ);
				Pokupets* pok = new Pokupets(name, stoi(time), stoi(summ));//stoi - string to int;
				q.push(*pok);
				counter = 0;
			}
		}
		Vec.push_back(q);
	}
}