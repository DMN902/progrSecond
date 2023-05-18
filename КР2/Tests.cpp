#include "Tests.h"

bool StartTests() {
	vector <any> testVector;
	vector <any> resultVector;
	bool flagAdd = false;
	bool flagDel = false;
	CreateTestVector(resultVector, ControlSize);
	CreateTestVector(testVector, TestSize);
	Add(testVector, true);
//	cout << "jdjdjjdjdjdjjdjdj" << endl;
//	PrintAll(testVector);
//	PrintAll(resultVector);
	flagAdd = CompareVectors(testVector, resultVector);
	testVector.clear();
	resultVector.clear();
	CreateTestVector(resultVector, TestSize);
	CreateTestVector(testVector, ControlSize);
	Delete(testVector, true);
//	PrintAll(testVector);
//	PrintAll(resultVector);
	flagDel = CompareVectors(testVector, resultVector);
	if (flagAdd && flagDel) {
		return true;
	}
	else {
		return false;
	}
}

void CreateTestVector(vector <any>& vec, int size) {
	transport transportTmp;
	car carTmp;
	sportsCar sportsCarTmp;
	truck truckTmp;
	int param = 0;
	int num = 0;
	string strParam = "empty";
	
	transportTmp.SetType("Transport");
	transportTmp.SetWeight(param);
	transportTmp.SetEnginePower(param);
	transportTmp.SetSpeed(param);
	param++;
	carTmp.SetType("Car");
	carTmp.SetWeight(param);
	carTmp.SetEnginePower(param);
	carTmp.SetSpeed(param);
	carTmp.SetBrand(strParam);
	param++;
	sportsCarTmp.SetType("Sport_car");
	sportsCarTmp.SetWeight(param);
	sportsCarTmp.SetEnginePower(param);
	sportsCarTmp.SetSpeed(param);
	sportsCarTmp.SetBrand(strParam);
	sportsCarTmp.SetModel(strParam);
	param++;
	truckTmp.SetType("Truck");
	truckTmp.SetWeight(param);
	truckTmp.SetEnginePower(param);
	truckTmp.SetSpeed(param);
	truckTmp.SetBrand(strParam);
	truckTmp.SetCapacity(param);

	while (num < size) {
		vec.push_back(transportTmp);
		num++;
		if (num >= size)
			break;
		vec.push_back(carTmp);
		num++;
		if (num >= size)
			break;
		vec.push_back(sportsCarTmp);
		num++;
		if (num >= size)
			break;
		vec.push_back(truckTmp);
		num++;
		if (num >= size)
			break;
	}
}

bool CompareVectors(vector <any>& testVec, vector <any>& resultVec) {
	if (testVec.size() == resultVec.size()) {
		for (int i = 0; i < testVec.size(); i++) {
			string typeT = testVec[i].type().name();
			string typeR = resultVec[i].type().name();
			if (typeT == "class transport" && typeR == "class transport") {
				transport testTmp = any_cast<transport>(testVec[i]);
				transport resultTmp = any_cast<transport>(resultVec[i]);
				if (testTmp.GetType() == resultTmp.GetType() &&
					testTmp.GetWeight() == resultTmp.GetWeight() &&
					testTmp.GetEnginePower() == resultTmp.GetEnginePower() &&
					testTmp.GetSpped() == resultTmp.GetSpped()) {
					continue;
				}
				else {
					return false;
					//break;
				}
			}
			else if (typeT == "class car" && typeR == "class car") {
				car testTmp = any_cast<car>(testVec[i]);
				car resultTmp = any_cast<car>(resultVec[i]);
				if (testTmp.GetType() == resultTmp.GetType() &&
					testTmp.GetWeight() == resultTmp.GetWeight() &&
					testTmp.GetEnginePower() == resultTmp.GetEnginePower() &&
					testTmp.GetSpped() == resultTmp.GetSpped() &&
					testTmp.GetBrand() == resultTmp.GetBrand()) {
					continue;
				}
				else {
					return false;
					//break;
				}
			}
			else if (typeT == "class sportsCar" && typeR == "class sportsCar") {
				sportsCar testTmp = any_cast<sportsCar>(testVec[i]);
				sportsCar resultTmp = any_cast<sportsCar>(resultVec[i]);
				if (testTmp.GetType() == resultTmp.GetType() &&
					testTmp.GetWeight() == resultTmp.GetWeight() &&
					testTmp.GetEnginePower() == resultTmp.GetEnginePower() &&
					testTmp.GetSpped() == resultTmp.GetSpped() &&
					testTmp.GetBrand() == resultTmp.GetBrand() &&
					testTmp.GetModel() == resultTmp.GetModel()) {
					continue;
				}
				else {
					return false;
					//break;
				}
			}
			else if (typeT == "class truck" && typeR == "class truck") {
				truck testTmp = any_cast<truck>(testVec[i]);
				truck resultTmp = any_cast<truck>(resultVec[i]);
				if (testTmp.GetType() == resultTmp.GetType() &&
					testTmp.GetWeight() == resultTmp.GetWeight() &&
					testTmp.GetEnginePower() == resultTmp.GetEnginePower() &&
					testTmp.GetSpped() == resultTmp.GetSpped() &&
					testTmp.GetBrand() == resultTmp.GetBrand() &&
					testTmp.GetCapacity() == resultTmp.GetCapacity()) {
					continue;
				}
				else {
					return false;
					//break;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}