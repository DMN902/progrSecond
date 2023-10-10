#include <iostream>
#include <clocale>
#include "MenuInterface.h"
#include "Tests.h"

using namespace std;


int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Задается базовый и производный класс. Необходимо разработать поля и методы," << endl
		<< "наследуемые из базового класса, а также собственные компоненты базовых классов" << endl
		<< "Базовй класс - средство передвижения. Поля в нем: вес, мощность мотора, скорость" << endl
		<< "Производный класс - автомобиль" << endl
		<< "Производный класс второго поколения - спортивный автомобиль, грузовой автомобиль" << endl << endl;
	cout << "Агишев Даниил" << endl
		<< "Контрольная работа №2" << endl
		<< "Вариант №1" << endl
		<< "группа 423" << endl << endl;

	if (StartTests()) {
		cout << endl << "Тесты пройдены успешно." << endl << endl;
		StartProgram();
	}
	else {
		cout << endl << "Тесты провалены." << endl;
	}
	return EXIT_SUCCESS;
}
