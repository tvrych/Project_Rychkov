#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <fstream>
#include <list>
#include <vector>
using namespace std;

class Pokupets
{
public:
	Pokupets(string name, int time, int summ);
	string Get_Name();
	int Get_Time();
	int Get_Summ();
	void printinfo();
private:
	string name;
	int time, summ;
};
bool operator <(Pokupets _Left, Pokupets _Right);
bool operator >(Pokupets _Left, Pokupets _Right);
void add_elment(priority_queue<Pokupets>& q);
void pokupetz_swaper(priority_queue<Pokupets>& q);
void add_new_queue(vector<priority_queue<Pokupets>>& Vec);
void intersect_queues(vector<priority_queue<Pokupets>>& Vec);
void reading_from_file(ifstream& fin, vector<priority_queue<Pokupets>>& Vec);