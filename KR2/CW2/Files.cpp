#include "Files.h"

bool IsDataCorrect(ifstream& file) {
	string testString = "";
	int testInt = 0;
	while (!file.eof()) {
		getline(file, testString);
		if (testString == "Car") {
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false;  file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			getline(file, testString);
		}
		else if (testString == "Sport_car") {
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			getline(file, testString);
			getline(file, testString);
		}
		else if (testString == "Truck") {
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			getline(file, testString);
			file >> testInt; if (file.fail()) return false; file.get();
		}
		else if (testString == "Transport") {
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
			file >> testInt; if (file.fail()) return false; if (testInt < 0) return false; file.get();
		}
	}
	file.seekg(0, ios::beg);
	return true;
}

string CheckFile()
{
	error_code error{};

	string path{};
	bool isLoaded = false;

	ifstream file;

	do
	{
		cout << "������� ���� � �����: ";
		getline(cin, path);

		if (!ifstream(path))
		{
			cout << "��������� ���� �� ������!" << endl;
			continue;
		}

		if (!is_regular_file(path, error))
		{
			cout << "������, ������������ ����� �����!" << endl;
			continue;
		}

		file.open(path);

		if (!file)
		{
			cout << "�������� ���������. ��������� ����." << endl;
			file.close();
		}
		else if (!IsDataCorrect(file))
		{
			cout << "���� �������� ������������� ������." << endl;
			file.close();
		}
		else
			isLoaded = true;
	} while (!isLoaded);

	cout << "���� ������." << endl;
	file.close();

	return path;
}

void GetFromFile(vector<any>& Arr, string path) {
	ifstream file;
	file.open(path);
	while (!file.eof()) {
		int tmpInt = 0;
		string tmpString = "";
		string typeT = "";
		getline(file, typeT);
		if (typeT == "Car") {
			car tmp;
			tmp.SetType(typeT);
			file >> tmpInt; file.get();
			tmp.SetWeight(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetEnginePower(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetSpeed(tmpInt);
			getline(file, tmpString);
			tmp.SetBrand(tmpString);
			Arr.push_back(tmp);
		}
		else if (typeT == "Sport_car") {
			sportsCar tmp;
			tmp.SetType(typeT);
			file >> tmpInt; file.get();
			tmp.SetWeight(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetEnginePower(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetSpeed(tmpInt);
			getline(file, tmpString);
			tmp.SetBrand(tmpString);
			getline(file, tmpString);
			tmp.SetModel(tmpString);
			Arr.push_back(tmp);
		}
		else if (typeT == "Truck") {
			truck tmp;
			tmp.SetType(typeT);
			file >> tmpInt; file.get();
			tmp.SetWeight(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetEnginePower(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetSpeed(tmpInt);
			getline(file, tmpString);
			tmp.SetBrand(tmpString);
			file >> tmpInt; file.get();
			tmp.SetCapacity(tmpInt);
			Arr.push_back(tmp);
		}
		else if (typeT == "Transport") {
			transport tmp;
			tmp.SetType(typeT);
			file >> tmpInt; file.get();
			tmp.SetWeight(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetEnginePower(tmpInt);
			file >> tmpInt; file.get();
			tmp.SetSpeed(tmpInt);
			Arr.push_back(tmp);
		}
	}
	cout << "������ ��������." << endl;
	file.close();
}

void SaveToFile(vector<any>& Arr) {
	string path = "";
	bool isDataSaved = false;
	do {
		cout << "��������� �: " << endl;
		cin >> path;

		if (ifstream(path)) {
			cout << "���� ��� ����������." << endl;
			cout << "[0] - ������������ ������������ ����." << endl;
			cout << "[1] - ��������� ����." << endl;
			int tryAnotherFile = GetBool();
			if (tryAnotherFile) {
				continue;
			}
		}
		ofstream myFile(path, ofstream::app);
		error_code ec{};
		if (!is_regular_file(path, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		if (!myFile) {
			cout << "������ ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}
		myFile.close();
		myFile.open(path, ofstream::trunc);
		for (unsigned int i = 0; i < Arr.size(); i++) {
			string typeN = Arr[i].type().name();
			if (typeN == "class car") {
				car tmpVec = any_cast<car>(Arr[i]);
				myFile << tmpVec.GetType() << endl
					<< tmpVec.GetWeight() << endl
					<< tmpVec.GetEnginePower() << endl
					<< tmpVec.GetSpped() << endl
					<< tmpVec.GetBrand() << endl;
			}
			else if (typeN == "class sportsCar") {
				sportsCar tmpVec = any_cast<sportsCar>(Arr[i]);
				myFile << tmpVec.GetType() << endl
					<< tmpVec.GetWeight() << endl
					<< tmpVec.GetEnginePower() << endl
					<< tmpVec.GetSpped() << endl
					<< tmpVec.GetBrand() << endl
					<< tmpVec.GetModel() << endl;
			}
			else if (typeN == "class truck") {
				truck tmpVec = any_cast<truck>(Arr[i]);
				myFile << tmpVec.GetType() << endl
					<< tmpVec.GetWeight() << endl
					<< tmpVec.GetEnginePower() << endl
					<< tmpVec.GetSpped() << endl
					<< tmpVec.GetBrand() << endl
					<< tmpVec.GetCapacity() << endl;
			}
			else if (typeN == "class transport") {
				transport tmpVec = any_cast<transport>(Arr[i]);
				myFile << tmpVec.GetType() << endl
					<< tmpVec.GetWeight() << endl
					<< tmpVec.GetEnginePower() << endl
					<< tmpVec.GetSpped() << endl;
			}
		}
		myFile.close();
		cout << "������ ���������." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}