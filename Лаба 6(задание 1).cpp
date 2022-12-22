// Лаба 6(задание 1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;

enum BirthDate
{
	NEGATIVE,
	INCORRECTNESS,
	CANNOT
};

class Birth : public exception
{
public:
	Birth(BirthDate code) : code(code) {};
	const char* what() const throw() override {
		if (code == BirthDate::NEGATIVE) return "Вы ввели отрицательное число!";
		else if (code == BirthDate::INCORRECTNESS) return "Что-то не верится...";
		else if (code == BirthDate::CANNOT) return "Вы ещё не родились :)";
}
private:
	BirthDate code;
};

void numbers(int a)
{
	setlocale(LC_ALL, "");
	if (a == 1) cout << "Один" << endl;
	if (a == 2) cout << "Два" << endl;
	if (a == 3) cout << "Три" << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите число 1-3: " << endl;
	int b;
	cin >> b;
	try
	{
		if (b < 1 or b>3) throw "Некорректное значение";
		numbers(b);
	}
	catch (const char* msg) {

		cout << "Warring: " << msg << endl;

	}

    cout << "Введите дату рождения: " << endl;
    int date;
    cin >> date;
    try
{
	if (date >= 1850 and date <= 2022) cout << "Спасибо!" << endl;
	if (date < 1850) throw "Что-то не верится...";
	if (date > 2022) throw "Вы ещё не родились";
	if (date < 0) throw "Вы ввели отрицательное число!";
}
catch (const char* msg) {

	cout << "Warning: " << msg << endl;
}

cout << "Введите дату рождения: " << endl;
int e;
cin >> e;
try {
	if (e >= 1850 and e <= 2022) cout << "Спасибо!";
	if (e < 1850) throw Birth(BirthDate::CANNOT);
	if (e > 2022) throw Birth(BirthDate::INCORRECTNESS);
	if (e < 0) throw Birth(BirthDate::NEGATIVE);
}
catch (Birth& msg) {
	cout << msg.what() << endl;
}
catch (exception& msg) {
	cout << msg.what() << endl;
}
}






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
