#include "MenuInterface.h"

void ShowMainMenu() {
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Загрузить из файла" << endl;
	cout << "2 - Ввести вручную" << endl << endl;
}

void ShowSecondMenu() {
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Вывести список" << endl;
	cout << "2 - Добавить транспорт в список" << endl;
	cout << "3 - Удалить транспорт из списка" << endl;
	cout << "4 - Сохранить список в файл" << endl;
	cout << "5 - Вернуться в основное меню" << endl;
	cout << "6 - Закрыть программу" << endl << endl;
}

void ShowSaveMenu(vector<any> &Arr) {
	cout << "Сохранить список в файл?" << endl
		<< "1 - ДА			2 - НЕТ" << endl;
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
				cout << "Нет такого пункта меню" << endl << endl;
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
					cout << "Список пуст." << endl;
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
					cout << "Список пуст" << endl;
				}
				break;
			case saveList:
				if (!TransportArr.empty()) {
					SaveToFile(TransportArr);
				}
				else {
					cout << "Список пуст" << endl;
				}
				break;
			case back:
				exitFlag = true;
				break;
			case closeProgram:
				cout << "Завершение работы...";
				exitAllFlag = true;
				exitFlag = true;
				break;
			default:
				cout << "Нет такого пункта меню" << endl << endl;
				break;
			}
		} while (!exitFlag);
		TransportArr.clear();
	} while (!exitAllFlag);
	return EXIT_SUCCESS;
}

