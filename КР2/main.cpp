#include <iostream>
#include <clocale>
#include "MenuInterface.h"
#include "Tests.h"

using namespace std;


int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "������ ������" << endl
		<< "����������� ������ �2" << endl
		<< "������� �1" << endl
		<< "������ 423" << endl << endl;

	if (StartTests()) {
		cout << endl << "����� �������� �������." << endl << endl;
		StartProgram();
	}
	else {
		cout << endl << "����� ���������." << endl;
	}
	return EXIT_SUCCESS;
}
