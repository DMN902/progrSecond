#include "classes.h"

////////////////////////////////////////////////////////////////
//		class transport       

transport::transport() {
	typeOfTransport = "empty";
	weight = 0;
	engine_power = 0;
	speed = 0;
}
transport::transport(string typeOfTransport_, int weight_, int engine_power_, int speed_) {
	typeOfTransport = typeOfTransport_;
	weight = weight_;
	engine_power = engine_power_;
	speed = speed_;
}

void transport::SetType(string typeOfTransport_) {
	typeOfTransport = typeOfTransport_;
}
void transport::SetWeight(int weight_) {
	weight = weight_;
}
void transport::SetEnginePower(int engine_power_) {
	engine_power = engine_power_;
}
void transport::SetSpeed(int speed_) {
	speed = speed_;
}

void transport::SetAll() {
	cout << "_________________________________________________" << endl;
	cout << "Введите вес: ";		weight = GetUnsInt();
	cout << "Введите мощность двигателя: ";		engine_power = GetUnsInt();
	cout << "Введите максимальную скорость: ";		speed = GetUnsInt();
	cout << "_________________________________________________" << endl;
}

string transport::GetType() {
	return typeOfTransport;
}

int transport::GetWeight() {
	return weight;
}
int transport::GetEnginePower() {
	return engine_power;
}
int transport::GetSpped() {
	return speed;
}

void transport::ShowWeight() {
	cout << weight;
}

void transport::ShowEnginePower() {
	cout << engine_power;
}

void transport::ShowSpeed() {
	cout << speed;
}

void transport::ShowAll() {
	cout << "Тип: " << typeOfTransport << endl
		<< "Вес: " << weight << endl
		<< "Мощность двигателя: " << engine_power << endl
		<< "Скорость: " << speed << endl;
}
////////////////////////////////////////////////////////////////
//		class car		                      

car::car() {
	weight = 0;
	engine_power = 0;
	speed = 0;
	brand = "empty";
}

car::car(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_)
	: transport(typeOfTransport_, weight_, engine_power_, speed_) {
	brand = brand_;
}

void car::SetBrand(string brand_) {
	brand = brand_;
}

void car::SetAll() {
	cout << "_________________________________________________" << endl;
	cout << "Введите вес: ";								weight = GetUnsInt();
	cout << "Введите мощность двигателя: ";			engine_power = GetUnsInt();
	cout << "Введите максимальную скорость: ";		speed = GetUnsInt();
	cout << "Введите марку: ";						cin >> brand;
	cout << "_________________________________________________" << endl;
}


string car::GetBrand() {
	return brand;
}

void car::ShowBrand() {
	cout << brand;
}

void car::ShowAll() {
	cout << "Тип: " << typeOfTransport << endl
		<< "Вес: " << weight << endl
		<< "Мощность двигателя: " << engine_power << endl
		<< "Скорость: " << speed << endl
		<< "Марка: " << brand << endl;
}
////////////////////////////////////////////////////////////////
//		class sports car

sportsCar::sportsCar() {
	weight = 0;
	engine_power = 0;
	speed = 0;
	brand = "empty";
	model = "empty";
}

sportsCar::sportsCar(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_, string model_)
	:car(typeOfTransport_, weight_, engine_power_, speed_, brand_) {
	model = model_;
}

void sportsCar::SetModel(string model_) {
	model = model_;
}

void sportsCar::SetAll() {
	cout << "_________________________________________________" << endl;
	cout << "Введите вес: ";								weight = GetUnsInt();
	cout << "Введите мощность двигателя: ";			engine_power = GetUnsInt();
	cout << "Введите максимальную скорость: ";		speed = GetUnsInt();
	cout << "Введите марку: ";						cin >> brand;
	cout << "Введите модель:";						cin >> model;
	cout << "_________________________________________________" << endl;
}

string sportsCar::GetModel() {
	return model;
}

void sportsCar::ShowModel() {
	cout << model;
}

void sportsCar::ShowAll() {
	cout << "Тип: " << typeOfTransport << endl
		<< "Вес: " << weight << endl
		<< "Мощность двигателя: " << engine_power << endl
		<< "Скорость: " << speed << endl
		<< "Марка: " << brand << endl
		<< "Модель: " << model << endl;
}

////////////////////////////////////////////////////////////////
//		class truck
truck::truck() {
	weight = 0;
	engine_power = 0;
	speed = 0;
	brand = "empty";
	capacity = 0;
}

truck::truck(string typeOfTransport_, int weight_, int engine_power_, int speed_, string brand_, int capacity_)
	:car(typeOfTransport_, weight_, engine_power_, speed_, brand_) {
	capacity = capacity_;
}

void truck::SetCapacity(int capacity_) {
	capacity = capacity_;
}

void truck::SetAll() {
	cout << "_________________________________________________" << endl;
	cout << "Введите вес: ";								weight = GetUnsInt();
	cout << "Введите мощность двигателя: ";			engine_power = GetUnsInt();
	cout << "Введите максимальную скорость: ";		speed = GetUnsInt();
	cout << "Введите марку: ";						cin >> brand;
	cout << "Введите грузоподъемность:";			capacity = GetUnsInt();
	cout << "_________________________________________________" << endl;
}

int truck::GetCapacity() {
	return capacity;
}

void truck::ShowCapacity() {
	cout << capacity;
}

void truck::ShowAll() {
	cout << "Тип: " << typeOfTransport << endl
		<< "Вес: " << weight << endl
		<< "Мощность двигателя :" << engine_power << endl
		<< "Скорость: " << speed << endl
		<< "Марка: " << brand << endl
		<< "Грузоподъемность: " << capacity << endl;
}