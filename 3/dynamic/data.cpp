#pragma once

#include <string>
using namespace std;

class Bike
{
	string fio;
	string type;
	int stage;

public:
	Cost(string fio, string type, int stage) :
		 fio(fio), type(type), stage(stage)
	{}
	
	string getFIO()
	{
		return fio;
	}

	void setFIO(string fio)
	{
		this->fio = fio;
	}

	string getType()
	{
		return type;
	}

	void setType(string type)
	{
		this->type = type;
	}
	
	int getStage()
	{
		return stage;
	}
	
	void setStage(int stage)
	{
		this->stage = stage;
	}
};

