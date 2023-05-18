#include "Functions.h"

void Add(vector<any> &Arr, bool test) {
	bool exitFlag;
	TypeOfTransport choice;
	do{
		exitFlag = true;
		if (!test) {
			cout << "Какой тип добавить?" << endl
				<< "1 - Автомобиль" << endl
				<< "2 - Спортивный автомобиль" << endl
				<< "3 - Грузовой автомобиль" << endl
				<< "4 - Транспортное средство" << endl;
				choice = TypeOfTransportChoice();
		}
		else {
			choice = transportType;
		}
		if (choice == carType) {
			car tmp;
			tmp.SetType("Car");
			Arr.push_back(tmp);
		}
		else if (choice == sportsCarType) {
			sportsCar tmp;
			tmp.SetAll();
			tmp.SetType("Sport_car");
			Arr.push_back(tmp);
		}
		else if (choice == truckType) {
			truck tmp;
			tmp.SetAll();
			tmp.SetType("Truck");
			Arr.push_back(tmp);
		}
		else if (choice == transportType) {
			transport tmp;
			if (!test) {
				tmp.SetAll();
			}
			else {
				tmp.SetWeight(0);
				tmp.SetEnginePower(0);
				tmp.SetSpeed(0);
			}
			tmp.SetType("Transport");
			Arr.push_back(tmp);
		}
		else {
			cout << "Нет такого варианта" << endl;
			exitFlag = false;
		}
	} while (!exitFlag);
}

void Delete(vector<any> &Arr, bool test) {
	int number = 0;
	if (test) {
		number = ControlSize;
	}
	else {
		cout << "Введите номер элемента, который нужно удалить: ";
		number = GetInt();
		while (number > Arr.size() || number < 1) {
			cout << "Введено некорректное значение." << endl;
			number = GetInt();
		}
	}
	for (int i = 0; i < Arr.size(); i++) {
		if (i == number - 1) {
			for (i; i < Arr.size() - 1; i++) {
				Arr[i] = Arr[i + 1];
			}
			Arr.pop_back();
			break;
		}
	}
}

void PrintAll(vector<any>& Arr) {
	for (int i = 0; i < Arr.size(); i++) {
		cout << "№" << (i + 1) << "_______________________________________________" << endl;
		string typeN = Arr[i].type().name();
		if (typeN == "class car") {
			car tmp;
			tmp = any_cast<car>(Arr[i]);
			Arr[i] = tmp;
			any_cast<car>(Arr[i]).ShowAll();
		}
		else if (typeN == "class sportsCar") {
			sportsCar tmp;
			tmp = any_cast<sportsCar>(Arr[i]);
			Arr[i] = tmp;
			any_cast<sportsCar>(Arr[i]).ShowAll();
		}
		else if (typeN == "class truck") {
			truck tmp;
			tmp = any_cast<truck>(Arr[i]);
			Arr[i] = tmp;
			any_cast<truck>(Arr[i]).ShowAll();
		}
		else if (typeN == "class transport") {
			transport tmp;
			tmp = any_cast<transport>(Arr[i]);
			Arr[i] = tmp;
			any_cast<transport>(Arr[i]).ShowAll();
		}
		cout << "_________________________________________________" << endl;
	}
}