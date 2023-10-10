#pragma once
#include <iostream>
#include "Classes.h"
#include "Enums.h"

int GetInt();									//Проверка ввода целого числа
bool GetBool();									//Проверка ввода булевого значения
int GetUnsInt();								//Проверка ввода целого неотрицательного числа
TypeOfTransport TypeOfTransportChoice();		//Проверка ввода типа транспортного средства
MainMenu MainMenuChoice();						//Проверка ввода пункта первого меню
SecondMenu SecondMenuChoice();					//Проверка ввода пункта второго меню