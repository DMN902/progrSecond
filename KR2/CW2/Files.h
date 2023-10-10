#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Functions.h"

using namespace filesystem;

bool IsDataCorrect(ifstream &file);					//Проверка корректности данных в файле
string CheckFile();									//Проверка корректности имени файла
void GetFromFile(vector<any> &Arr, string path);		//Счиитывание из файла
void SaveToFile(vector<any> &Arr);					//Сохранение в файл