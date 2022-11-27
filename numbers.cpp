/****************************
* Рексиус Анастасия         *
* ПИ-221                    *
* Арабские и римские числа  *
*****************************/

#include <bits/stdc++.h>

using namespace std;

int value(char romanValue) {
	if (romanValue == 'I')
		return 1;
	if (romanValue == 'V')
		return 5;
	if (romanValue == 'X')
		return 10;
	if (romanValue == 'L')
		return 50;
	if (romanValue == 'C')
		return 100;
	if (romanValue == 'D')
		return 500;
	if (romanValue == 'M')
		return 1000;

	return 0;
}

int romanToArabic(string& str) {
	int resultOfConvert = 0;
	
	for (int numberIndex = 0; numberIndex < str.length(); numberIndex++) {
		int s1 = value(str[numberIndex]);
        if (numberIndex + 1 < str.length()) {
			int s2 = value(str[numberIndex + 1]);
			if (s1 >= s2) {
				resultOfConvert = resultOfConvert + s1;
			}
			else {
				resultOfConvert = resultOfConvert + s2 - s1;
				numberIndex++;
			}
		}
		else {
			resultOfConvert = resultOfConvert + s1;
		}
	}
	return resultOfConvert;
}

string arabicToRoman(int arabicNumber) {
    string mValue[] = { "", "M", "MM", "MMM" };
    string cValue[] = { "",  "C",  "CC",  "CCC",  "CD",
                   "D", "DC", "DCC", "DCCC", "CM" };
    string xValue[] = { "",  "X",  "XX",  "XXX",  "XL",
                   "L", "LX", "LXX", "LXXX", "XC" };
    string iValue[] = { "",  "I",  "II",  "III",  "IV",
                   "V", "VI", "VII", "VIII", "IX" };
 
    string thousands = mValue[arabicNumber / 1000];
    string hundreds = cValue[(arabicNumber % 1000) / 100];
    string tens = xValue[(arabicNumber % 100) / 10];
    string ones = iValue[arabicNumber % 10];
 
    string resultOfConvert = thousands + hundreds + tens + ones;
 
    return resultOfConvert;
}

int main() {
    int arabicNumber = 0;
    string romanNumber = " ";
	string choice;
	cout << "напишите 'р', если хотите перевести из римской в арабскую, иначе 'а': ";
	cin >> choice;
	if (choice == "р") {
	  cout << "Римское число: ";
	  cin >> romanNumber;
	  cout << "Полученное арабское число:  " << romanToArabic(romanNumber) << endl; 
	}
	else if (choice == "а") {
	   cout << "Арабское число: ";
	   cin >> arabicNumber;
	   cout << "Полученное римское число: " << arabicToRoman(arabicNumber) << endl; 
	} else {
	   cout << "Ошибка: такого значения нет.";
	  }
}
