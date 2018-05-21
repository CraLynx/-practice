#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "data.cpp"
using namespace std;

class DataBase
{
	int last_inserted_id;
	vector<Bike*> db;

public:
	DataBase() : last_inserted_id(1)
	{
		db.resize(0);	
	}
	~DataBase()
	{
		for (int i = 0; i < db.size(); i++) {
			delete db[i];
		}
	}

	int count()
	{
		return db.size();
	}

	void add(Bike *new_item)
	{
		db.push_back(new_item);
	}	

	Bike* edit(int id)
	{
		id--;
		return db.at(id);
	}

	void remove(int id)
	{
		id--;
		db.erase(db.begin() + id);
	}

	void view()
	{
		cout << setfill(' ')
			 << setw(6) << "ID|" << setfill(' ') << setw(35) << "FIO|" << setw(12) << "Type|" << setw(12) << "Stage" << '\n';
		cout << setfill('-') << setw(80) << '\n' << setfill(' ');
		for (int i = 0; i < db.size(); i++) {
			cout << setw(5) << (i+1) << "|" 
				 << setw(34) << db[i]->getFIO() << "|" 
				 << setw(11) << db[i]->getType() << "|"
				 << setw(11) << db[i]->getStage() << "|" << '\n';
		}
	}
	
	void view(int i)
	{
		i--;
	
		cout << setfill(' ')
			 << setw(6) << "ID|" << setfill(' ') << setw(35) << "FIO|" << setw(12) << "Type|" << setw(12) << "Stage" << '\n';
		cout << setfill('-') << setw(80) << '\n' << setfill(' ');
		cout << setw(5) << (i+1) << "|" 
				 << setw(34) << db[i]->getFIO() << "|" 
				 << setw(11) << db[i]->getType() << "|"
				 << setw(11) << db[i]->getStage() << "|" << '\n';
	}

};

