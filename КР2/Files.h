#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Functions.h"

using namespace filesystem;

bool IsDataCorrect(ifstream &file);
string CheckFile();
void GetFromFile(vector<any> &Arr,string path);
void SaveToFile(vector<any> &Arr);