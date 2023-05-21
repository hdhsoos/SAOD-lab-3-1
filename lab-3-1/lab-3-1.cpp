#include "double_linked_list.cpp"
#include "laba3.h"

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	setlocale(LC_ALL, "rus");
	menu();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		// достигнут ли конец и введено ли больше одного "слова"
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Попробуйте снова.\n" << endl;
	}
	return a;
}


void menu() {
	int command, choice;
	int search_data;
	List l;
	while (true) {
		cout << "\nВыберите команду из списка:\n";
		cout << "1. Вывод текущего состояния списка на экран (проход с начала списка)\n";
		cout << "2. Проверка пустоты списка\n";
		cout << "3. Вывод текущего состояния списка на экран (проход с конца списка)\n";
		cout << "4. Добавить элемент в список\n";
		cout << "5. Удалить элемент из списка\n";
		cout << "6. Поиск элемента с заданной информационной частью (с начала списка)\n";
		cout << "7. Поиск элемента с заданной информационной частью (с конца списка)\n";
		cout << "8. Очистить список\n";
		cout << "0. Завершить работу программы\n";
		cout << "Номер команды: ";
		command = failure();
		switch (command) {
		case 0:
			return;
			break;
		case 1:
			output_list(l);
			break;
		case 2:
			if (is_Empty(l)) cout << "Список пуст" << endl;
			else cout << "Список не пуст" << endl;
			break;
		case 3:
			routput_list(l);
			break;
		case 4:
			push(l);
			break;
		case 5:
			remove(l);
			break;
		case 6:
			cout << "Введите информационную часть искомого элемента: " << endl;
			cin >> search_data;
			find(l, search_data);
			break;
		case 7:
			cout << "Введите информационную часть искомого элемента: " << endl;
			cin >> search_data;
			rfind(l, search_data);
			break;
		case 8:
			if (!is_Empty(l)) {
				destroy(l);
			}
			else {
				cout << "Список пуст, удалять нечего";
			}
			break;
		default:
			cout << "\nТакой команды нет, введите другое число" << endl;
			break;
		}
	}
}
