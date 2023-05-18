#include <iostream>
#include <clocale>
#include "MenuInterface.h"
#include "Tests.h"

using namespace std;


int main() {
	setlocale(LC_CTYPE, "Russian");
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
