#pragma once
#include "Functions.h"

bool StartTests();														//Запуск модульных тестов
void CreateTestVector(vector <any> &vec, int size);						//Создание векторов для тестов
bool CompareVectors(vector <any> &testVec, vector <any>& resultVec);	//Сравнение тестовых векторов с корректным резултатом