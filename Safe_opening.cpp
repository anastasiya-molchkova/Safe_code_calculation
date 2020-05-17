/* Известно, что сейф открывается при правильном вводе кода из 3-x цифр в диапазоне от 0 до 9. 
Задайте код и затем откройте сейф, используя метод перебора с помощью цикла for. */

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

// возвращает истину, если код состоит из цифр
bool check_code_is_valid(const string& code)
{
	for (const auto& symbol : code)
		if (!isdigit(symbol)) return false;
	return true;
}

// получает от пользователя трёхзначный код, состоящий из цифр
string get_code()
{
	cout << "Введите трёхзначный код, состоящий из цифр: ";
	string code;
	getline(cin,code);
	while ((code.length() != 3) || (check_code_is_valid(code) == false))
	{
		cout << "Ошибка! Нужно ввести трёхзначный код, состоящий из цифр: ";
		cin.clear();
		getline(cin, code);
	}
	return code;
}

// возвращает количество итераций, понадобившихся для подбора кода
unsigned code_selection(const string& known_code)
{
	const unsigned short number_of_possible_symbols = 10;
	const char code_symbols[number_of_possible_symbols] = { '0','1','2','3','4','5','6','7','8','9' };
	unsigned iterations_numb(0);
	for (unsigned short i1=0; i1< number_of_possible_symbols; i1++)
		for (unsigned short i2 = 0; i2 < number_of_possible_symbols; i2++)
			for (unsigned short i3 = 0; i3 < number_of_possible_symbols; i3++)
			{
				iterations_numb++;
				string code_selection{};
				code_selection.push_back(code_symbols[i1]);
				code_selection.push_back(code_symbols[i2]);
				code_selection.push_back(code_symbols[i3]);
				if (code_selection == known_code)
					return iterations_numb;
			}
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Программа быстро подбирает трёхзначные коды к сейфам." << endl;
	
	while (true)
	{
		string code = get_code();
		cout << "Код был подобран за " << code_selection(code) << " итераций" << endl;
	}
}