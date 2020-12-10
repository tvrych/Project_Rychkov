#include "PriorityQueue_Rychkov.h"

int main()
{
	string path = "PriorityQueue_Rychkov_test.txt";
	ifstream fin(path);
	srand(time(NULL));
	priority_queue<Pokupets> q,q2;
	int summ, req;
	vector<priority_queue<Pokupets>> Vec;
	Pokupets Oleg("Oleg", 123, 1300);
	Pokupets Egor("Egor", 121, 1200);
	Pokupets Dima("Dima", 120, 1000);
	Pokupets Stas("Stas", 208, 1307);
	q.push(Oleg);
	q.push(Egor);
	q.push(Dima);
	q2.push(Stas);
	Vec.push_back(q);
	Vec.push_back(q2);
start:
	
	cout << "Choose action:\n";
	cout << "(1)Input manually\n" << "(2)Use data from text file\n" << "(3)Exit\n";
	cin >> req;


	switch (req)
	{
	case 1:
		cout << "Choose action:\n";
		cout << "(1)Add customer\n" << "(2)Add waiting line\n" << "(3)Swap customers\n" << "(4)Intersect waiting lines\n " << "(5)Exit\n";
		cin >> req;
		switch (req)
		{
		case 1:
			cout << "Choose queue\t";
			for (int i = 0; i < Vec.size(); i++)
			{
				cout << i + 1 << "; ";
			}
			cout << endl;
			cin >> req;
			if (req<1 || req>Vec.size())
			{
				cout << "Incorrect queue!\n";
				exit(0);
			}
			add_elment(Vec[req-1]);
			break;
		case 2:
			add_new_queue(Vec);
			break;
		case 3:
			cout << "Choose queue\t";
			for (int i = 0; i < Vec.size(); i++)
			{
				cout << i + 1 << "; ";
			}
			cout << endl;
			cin >> req;
			if (req<1 || req>Vec.size())
			{
				cout << "Incorrect queue!\n";
				exit(0);
			}
			pokupetz_swaper(Vec[req - 1]);
			break;
		case 4:
			intersect_queues(Vec);
			break;
		case 5:
			goto finish;
			break;

		default: cout << "Incorrect input!\n";
			break;
		}
		goto start;
		break;
	case 2:
		reading_from_file(fin, Vec);
		goto start;
		break;
	case 3:
		break;
	default:cout << "Incorrect input!\n";
		goto start;
		break;
	}
 
finish:

	for (int iter = 0; iter < Vec.size(); iter++)
	{
		cout << "Queue " << iter + 1 << ":\n";
		if (Vec[iter].empty())
		{
			cout << "Queue is empty\n";
		}
		else
		{
			while (!Vec[iter].empty())
			{
				Pokupets blank = Vec[iter].top();
				summ = rand() % 750 + 250;
				if (summ < blank.Get_Summ())
				{
					blank.printinfo();
					cout << "\n\n";
					Vec[iter].pop();
				}
			}
		}
	}
	

}