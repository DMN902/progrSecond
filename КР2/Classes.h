#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Input.h"

using namespace std;

////////////////////////////////////////////////////////////////
//		means of transportation                   
class transport {
protected:
	string typeOfTransport;
	int weight;
	int engine_power;
	int speed;

public:
	transport();
	transport(string typeOfTransport_, int weight_, int engine_power_, int speed_);

	void SetType(string typeOfTransport_);
	void SetWeight(int weight_);
	void SetEnginePower(int engine_power_);
	void SetSpeed(int speed_);
	virtual void SetAll();

	string GetType();
	int GetWeight();
	int GetEnginePower();
	int GetSpped();

	void ShowWeight();
	void ShowEnginePower();
	void ShowSpeed();

	virtual void ShowAll();

	virtual ~transport(){}

};

////////////////////////////////////////////////////////////////
//		class cars		                      
class car : public transport {
protected:
	string brand;
public:
	car();
	car(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_);

	void SetBrand(string brand_);
	void SetAll() override;
	
	string GetBrand();
	void ShowBrand();
	void ShowAll() override;
};


////////////////////////////////////////////////////////////////
//		class sports car                      
class sportsCar : public car {
private:
	string model;
public:
	sportsCar();
	sportsCar(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_, string model_);

	void SetModel(string model_);
	void SetAll() override;
	string GetModel();
	void ShowModel();
	void ShowAll() override;
};

////////////////////////////////////////////////////////////////
//		class truck
class truck : public car {
protected:
	int capacity = 0;
public:
	truck();
	truck(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_, int capacity_);

	void SetCapacity(int capacity_);
	void SetAll() override;
	int GetCapacity();
	void ShowCapacity();
	void ShowAll() override;
};