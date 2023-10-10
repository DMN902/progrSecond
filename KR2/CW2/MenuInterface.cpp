#include "MenuInterface.h"

void ShowMainMenu() {
	cout << "�������� ����� ����:" << endl;
	cout << "1 - ��������� �� �����" << endl;
	cout << "2 - ������ �������" << endl << endl;
}

void ShowSecondMenu() {
	cout << "�������� ����� ����:" << endl;
	cout << "1 - ������� ������" << endl;
	cout << "2 - �������� ��������� � ������" << endl;
	cout << "3 - ������� ��������� �� ������" << endl;
	cout << "4 - ��������� ������ � ����" << endl;
	cout << "5 - ��������� � �������� ����" << endl;
	cout << "6 - ������� ���������" << endl << endl;
}

void ShowSaveMenu(vector<any> &Arr) {
	cout << "��������� ������ � ����?" << endl
		<< "1 - ��			2 - ���" << endl;
	if (GetBool()) {
		SaveToFile(Arr);
	}
}

int StartProgram() {
	bool exitFlag;
	bool exitAllFlag;
	do {
		string filePath = "";
		vector <any> TransportArr;
		do {
			exitFlag = true;
			ShowMainMenu();
			MainMenu MainMenuUserChoice = MainMenuChoice();

			switch (MainMenuUserChoice)
			{
			case file:
				filePath = CheckFile();
				GetFromFile(TransportArr, filePath);
				break;
			case Manual:
				Add(TransportArr, false);
				break;
			default:
				cout << "��� ������ ������ ����" << endl << endl;
				exitFlag = false;
				break;
			}
		} while (!exitFlag);
		do {
			exitFlag = false;
			exitAllFlag = false;
			ShowSecondMenu();
			SecondMenu SecondMenuUserChoice = SecondMenuChoice();
			switch (SecondMenuUserChoice)
			{
			case showList:
				if (!TransportArr.empty()) {
					PrintAll(TransportArr);
				}
				else {
					cout << "������ ����." << endl;
				}
				break;
			case addTransport:
				Add(TransportArr, false);
				break;
			case deleteTransport:
				if (!TransportArr.empty()) {
					Delete(TransportArr, false);
				}
				else {
					cout << "������ ����" << endl;
				}
				break;
			case saveList:
				if (!TransportArr.empty()) {
					SaveToFile(TransportArr);
				}
				else {
					cout << "������ ����" << endl;
				}
				break;
			case back:
				exitFlag = true;
				break;
			case closeProgram:
				cout << "���������� ������...";
				exitAllFlag = true;
				exitFlag = true;
				break;
			default:
				cout << "��� ������ ������ ����" << endl << endl;
				break;
			}
		} while (!exitFlag);
		TransportArr.clear();
	} while (!exitAllFlag);
	return EXIT_SUCCESS;
}

