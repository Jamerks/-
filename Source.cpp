#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

ifstream input;
ofstream output;


class marks
{
public:
	bool flag = true;
	string name;
	char res[8];
	int amarks[8];
};

struct date
{
	int day;
	int month;
	int year;
};

void printdate(date data)
{
	if (data.day > 9)
	{
		cout << data.day;
	}
	else
	{
		cout << '0' << data.day;
	}
	cout << '.';
	if (data.month > 9)
	{
		cout << data.month;
	}
	else
	{
		cout << '0' << data.month;
	}
	cout << '.';
	cout << data.year << ' ';
}

class node
{
public:
	string secname;
	string name;
	string otv;
	string fac;
	string kafedra;
	string group;
	string studak;
	date dr;
	bool pol;
	int postup;
	marks ocenka[10];
	class node* next;
	node()
	{
	}
};

class node* myhead;

int countitem = 0;

void printitem()
{
	class node* current = myhead;
	cout << endl;
	system("cls");
	cout << '\t' << "0.\t Добавить нового студента." << endl << endl;
	int item = 0;
	while (current)
	{
		cout << '\t' << item + 1 << ".\t";
		item++;
		cout << " " << current->secname << ' ' << current->name << ' ' << current->otv << ' ' << current->group << endl;
		current = current->next;
	}
}

void safe()
{
	output.open("file.txt", ios_base::out);
	class node* current = myhead;
	while (current)
	{
		output << current->secname << ' ' << current->name << ' ' << current->otv << ' ' << current->fac << ' ' << current->kafedra << ' ' << current->group << ' ' << current->studak << ' ';
		output << current->dr.day << ' ' << current->dr.month << ' ' << current->dr.year << ' ' << current->pol << ' ' << current->postup << ' ';
		for (int i = 0; i < 5; i++)
		{
			output << current->ocenka[i].name << ' ';
			output << current->ocenka[i].flag << ' ';
			for (int j = 0; j < 8; j++)
			{
				output << current->ocenka[i].res[j] << ' ';
			}
		}
		for (int i = 5; i < 10; i++)
		{
			output << current->ocenka[i].name << ' ';
			output << current->ocenka[i].flag << ' ';
			for (int j = 0; j < 8; j++)
			{
				output << current->ocenka[i].amarks[j] << ' ';
			}
		}
		output << endl;
		current = current->next;
	}
	output.close();
}

void additem(node data, int& Count)
{
	class node* newitem = new node();
	newitem->secname = data.secname;
	newitem->name = data.name;
	newitem->otv = data.otv;
	newitem->fac = data.fac;
	newitem->kafedra = data.kafedra;
	newitem->group = data.group;
	newitem->studak = data.studak;
	newitem->dr.day = data.dr.day;
	newitem->dr.month = data.dr.month;
	newitem->dr.year = data.dr.year;
	newitem->pol = data.pol;
	newitem->postup = data.postup;
	for (int i = 0; i < 10; i++)
	{
		newitem->ocenka[i] = data.ocenka[i];
	}
	for (int i = 0; i < 10; i++)
	{
		newitem->ocenka[i].name = data.ocenka[i].name;
		newitem->ocenka[i].flag = data.ocenka[i].flag;
	}
	if (Count == 0)
	{
		newitem->next = NULL;
	}
	else
	{
		newitem->next = myhead;
	}
	myhead = newitem;
	countitem++;
	Count++;
}

void deleteitem(int index, int& count)
{
	if (index > 0 and count > 0 and index <= count)
	{

		class node* current = myhead;
		class node* old;
		if (index == 1)
		{
			old = myhead;
			myhead = current->next;
			delete old;
			countitem--;
			count--;
		}
		else {
			int i = 0;
			while (current)
			{
				if (i == index - 2) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countitem--;
					count--;
					break;
				}
				current = current->next;
				i++;
			}

		}
	}
	safe();
}

bool checkdate(date data)
{
	if (data.day >= 1 and data.day <= 31 and data.month >= 1 and data.month <= 12 and data.year <= 2023 and data.year >= 1000)
		return true;
	else
		return false;
}





void printmarks(node* otm)
{
	cout << "\n\nРезультаты зачетов:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << otm->ocenka[i].name << ": ";

		for (int j = 0; j < 8; j++)
		{
			cout << otm->ocenka[i].res[j] << " ";
		}
		cout << endl;
	}

	cout << "\nРезультаты экзаменов:" << endl;
	for (int i = 5; i < 10; i++)
	{
		cout << otm->ocenka[i].name << ": ";

		for (int j = 0; j < 8; j++)
		{
			cout << otm->ocenka[i].amarks[j] << " ";
		}
		cout << endl;
	}
}

void editmarks(node* stud, int index)
{
	system("cls");
	class node* current = myhead;
	for (int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}
	printmarks(current);
	cout << "Какой предмет вам требуется отредактировать:\n";

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " - " << current->ocenka[i].name << endl;
	}


	int ch;
	cin >> ch;
	switch (ch)
	{
	case 0:
		break;
	default:
		cout << "Редактирование предмета: " << current->ocenka[ch - 1].name << endl;


		int sem;
		cout << "Введите семестр для изменения: от 1 до 8\n";
		cin >> sem;
		switch (sem)
		{
		case 0:
			break;
		default:
		a9:
			int mark;
			char test;
			if (current->ocenka[ch - 1].flag)
			{
				cout << "Введите отметку: от 2 до 5\n";
				cin >> mark;
				if (mark < 2 or mark > 5)
				{
					cout << "Ошибка ввода отметки: отметка выходит за диапазон от 2 до 5.\n";
					goto a9;
				}
				current->ocenka[ch - 1].amarks[sem - 1] = mark;
			}

			else
			{
				cout << "Введите результат: (Н - незачет З - зачет)\n";
				cin >> test;
				if (test != 'Н' and test != 'З')
				{
					cout << "\n Ошибка. Введите З или Н.\n";
					goto a9;
				}
				current->ocenka[ch - 1].res[sem - 1] = test;
			}
			break;
		}
		break;
	}

	safe();

}

void edit_name_marks(node* stud, int index)
{
	system("cls");
	class node* current = myhead;
	for (int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}
	printmarks(current);
	cout << "Какой предмет вам требуется отредактировать:\n";

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " - " << current->ocenka[i].name << endl;
	}


	int ch;
	cin >> ch;
	switch (ch)
	{
	case 0:
		break;
	default:
		cout << "Редактирование предмета: " << current->ocenka[ch - 1].name << endl;
		cout << "Введите новое название предмета: ";
		cin >> current->ocenka[ch - 1].name;
	}

	safe();

}

void edititem(int index, int& Count)
{
	string a1, b1, c1;
	class node* current = myhead;
	if (index >= 0 and index <= countitem and countitem > 0)
	{
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		int st;
	c1:
		system("cls");


		cout << endl << "ФИО: " << current->secname << ' ' << current->name << ' ' << current->otv;
		cout << "\nДата рождения: "; printdate(current->dr);
		cout << "\nГод поступления: " << current->postup;
		cout << endl;
		cout<< "Факультет: "<< current->fac << "\nКафедра: " << current->kafedra << endl << "Группа: " << current->group
			<< "\nНомер зачетной книжки: " << current->studak << endl << "Пол: ";



		if (current->pol == 1)
		{
			cout << "Мужчина" << ' ';
		}
		else
		{
			cout << "Женщина" << ' ';
		}

		printmarks(current);
		cout << "\n\nВведите, что вам требуется изменить в данных студента: \n 0 - Удалить студента\n 1 - Фамилию \n 2 - Имя \n 3 - Отчестово";
		cout << "\n 4 - Факультет \n 5 - Кафедру \n 6 - Номер зачетной книжки \n 7 - Группу \n 8 - Дату рождения \n 9 - Пол \n 9 - Год поступления \n 11 - Изменить оценки \n 12 - Изменить названия предметов \n 13 - Вернуться в меню\n";
		cin >> st;
		string a, b;
		switch (st)
		{
		case 0:
			deleteitem(index, Count);
			break;
		case 1:
		y1:
			cout << "\n Введите новую фамилию:\t";
			cin >> a;
			if (size(a) > 20)
			{
				cout << "Ошибка. Фамилия не должна быть длиннее 20 символов\n";
				goto y1;
			}
			for (int i = 0; i < size(a); i++)
				if (a[i] >= '\0' && a[i] <= '@' or a[i] >= '[' && a[i] <= '`' or a[i] >= '{' && a[i] <= 191)
				{
					cout << "Ошибка. Фамилия должна содержать только буквы латинского или русского алфавита\n";
					goto y1;
				}
			current->secname = a;
			break;
		case 2:
		y2:
			cout << "\n Введите новое имя:\t";
			cin >> b;
			if (size(b) > 20)
			{
				cout << "Ошибка. Имя не должно быть длиннее 20 символов\n";
				goto y2;
			}
			for (int i = 0; i < size(b); i++)
				if (b[i] >= '\0' && b[i] <= '@' or b[i] >= '[' && b[i] <= '`' or b[i] >= '{' && b[i] <= 191)
				{
					cout << "Ошибка ввода. Имя должно содержать только буквы латинского или русского алфавита\n";
					goto y2;
				}
			current->name = b;
			break;

		case 3:
		y3:
			cout << "\n Введите новое отчество:\t";
			cin >> b;
			if (size(b) > 20)
			{
				cout << "Ошибка. отчество не должно быть длиннее 20 символов\n";
				goto y2;
			}
			for (int i = 0; i < size(b); i++)
				if (b[i] >= '\0' && b[i] <= '@' or b[i] >= '[' && b[i] <= '`' or b[i] >= '{' && b[i] <= 191)
				{
					cout << "Ошибка ввода. отчество должно содержать только буквы латинского или русского алфавита\n";
					goto y3;
				}
			current->otv = b;
			break;

		case 4:
			cout << "\n Введите новый факультет:\t";
			cin >> current->fac;
			break;
		case 5:
			cout << "\n Введите новую кафедру:\t";
			cin >> current->kafedra;
			break;
		case 6:
			cout << "\n Введите новый номер зачетной книжки:\t";
			cin >> current->studak;
			break;
		case 7:
			cout << "\n Введите новую группу:\t";
			cin >> current->group;
			break;
		case 8:
		p1:	cout << "\n Введите новую дату рождения:\t";
			date tempdata;
			cin >> a1 >> b1 >> c1;
			for (int i = 0; i < size(a1); i++) if (!(a1[i] > '/' and a1[i] < ':')) { cout << "В дате требуется использовать только цифры\n"; goto p1; }
			tempdata.day = stoi(a1);
			for (int i = 0; i < size(b1); i++) if (!(b1[i] > '/' and b1[i] < ':')) { cout << "В дате требуется использовать только цифры\n"; goto p1; }
			tempdata.month = stoi(b1);
			for (int i = 0; i < size(c1); i++) if (!(c1[i] > '/' and c1[i] < ':')) { cout << "В дате требуется использовать только цифры\n"; goto p1; }
			tempdata.year = stoi(c1);
			if (checkdate(tempdata)) current->dr = tempdata;
			else
			{
				cout << "Ошибка в дате рождения\n";
				goto p1;
			}
			break;
		case 9:
			cout << "\n Введите новый пол: 1 - мужчина 0 - женщина\t";
			cin >> current->pol;
			break;
		case 10:
			cout << "\n Введите новый год поступления:\t";
			cin >> current->postup;
			break;
		case 11:
			editmarks(current, index);
			break;

		case 12:
			edit_name_marks(current, index);
			break;

		case 13:
			break;
		default:
			goto c1;
		}
		safe();
	}
	else
	{
		cout << "Ошибка ввода индекса";
	}
}

void creatingfile()
{
	output.open("file.txt", ios_base::app);
	output.close();
}

int countofrows()
{
	int count = 0;
	input.open("file.txt", ios_base::in);
	while (!input.eof())
	{
		if (input.get() == '\n')
		{
			count++;
		}
	}
	input.close();
	return count;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node temp;
	setlocale(LC_ALL, "ru");
	string a1, b1, c1;
	int ch;
	int count = 0;
	creatingfile();
	count = countofrows();
	cout << " count = " << count << endl;
	int& Count = count;
	int max = count;


	input.open("file.txt", ios_base::in); 
	for (int i = 0; i < max; i++)
	{
		input >> temp.secname >> temp.name >> temp.otv >> temp.fac >> temp.kafedra >> temp.group >> temp.studak >> temp.dr.day >> temp.dr.month >> temp.dr.year >> temp.pol >> temp.postup;
		for (int i = 0; i < 10; i++)
		{
			input >> temp.ocenka[i].name;
			input >> temp.ocenka[i].flag;
			for (int j = 0; j < 8; j++)
			{
				string b;
				input >> b;
				if (b == "Н" or b == "З")
					temp.ocenka[i].res[j] = b[0];

				else
					temp.ocenka[i].amarks[j] = stoi(b);

			}
		}
		additem(temp, Count);
	}
	input.close();


a1:	printitem();
	cout << "\n Введите, кого хотите изменить: \n";
	cin >> ch;
	if (ch > countitem or ch < 0) { cout << "Ошибка. Введен неверный индекс\n"; goto a1; }
	string a, b, c;
	switch (ch)
	{
	case 0:
	b1:
		cout << "Введите фамилию:\n";
		cin >> a;
		if (size(a) > 20)
		{
			cout << "Ошибка. Фамилия не должна быть длиннее 20 символов\n";
			goto b1;
		}
		for (int i = 0; i < size(a); i++)
			if (a[i] >= '\0' && a[i] <= '@' or a[i] >= '[' && a[i] <= '`' or a[i] >= '{' && a[i] <= 191)
			{
				cout << "Ошибка ввода. Фамилия должна содержать только буквы латинского или русского алфавита\n";
				goto b1;
			}
		temp.secname = a;
	b2:
		cout << "Введите  имя:\n";
		cin >> b;
		if (size(b) > 20)
		{
			cout << "Ошибка. Имя не должно быть длиннее 20 символов\n";
			goto b2;
		}
		for (int i = 0; i < size(b); i++)
			if (b[i] >= '\0' && b[i] <= '@' or b[i] >= '[' && b[i] <= '`' or b[i] >= '{' && b[i] <= 191)
			{
				cout << "Ошибка ввода. Имя должно содержать только буквы латинского или русского алфавита\n";
				goto b2;
			}
		temp.name = b;

	b3:
		cout << "Введите  отчество:\n";
		cin >> c;
		if (size(c) > 20)
		{
			cout << "Ошибка. отчество не должно быть длиннее 20 символов\n";
			goto b3;
		}
		for (int i = 0; i < size(b); i++)
			if (c[i] >= '\0' && c[i] <= '@' or c[i] >= '[' && c[i] <= '`' or c[i] >= '{' && c[i] <= 191)
			{
				cout << "Ошибка ввода. отчество должно содержать только буквы латинского или русского алфавита\n";
				goto b3;
			}

		temp.otv = c;
		cout << "Введите  факультет:\n";
		cin >> temp.fac;
		cout << "Введите  кафедру:\n";
		cin >> temp.kafedra;
		cout << "Введите  группу:\n";
		cin >> temp.group;
		cout << "Введите  номер зачетной книжки:\n";
		cin >> temp.studak;

	z1:
		cout << "Введите  дату рождения:\n";
		date tempdata;
		cin >> a1 >> b1 >> c1;
		for (int i = 0; i < size(a1); i++) if (!(a1[i] > '/' and a1[i] < ':')) { cout << "В дате нужно использовать только цифры\n"; goto z1; }
		tempdata.day = stoi(a1);
		for (int i = 0; i < size(b1); i++) if (!(b1[i] > '/' and b1[i] < ':')) { cout << "В дате нужно использовать только цифры\n"; goto z1; }
		tempdata.month = stoi(b1);
		for (int i = 0; i < size(c1); i++) if (!(c1[i] > '/' and c1[i] < ':')) { cout << "В дате нужно использовать только цифры\n"; goto z1; }
		tempdata.year = stoi(c1);
		if (checkdate(tempdata)) temp.dr = tempdata;
		else
		{
			cout << "Ошибка в указании даты\n";
			goto z1;
		}
		cout << "Введите  пол: 1 - мужчина 0 - женщина\n";
		cin >> temp.pol;
		cout << "Введите год поступления:\n";
		cin >> temp.postup;



		cout << "Введите названия зачетов:\n";

		for (int i = 0; i < 5; i++)
		{
			string boof;
			cin >> boof;
			temp.ocenka[i].name = boof;
			temp.ocenka[i].flag = false;
		}

		cout << "Введите названия экзаменов:\n";

		for (int i = 5; i < 10; i++)
		{
			string boof;
			cin >> boof;
			temp.ocenka[i].name = boof;
			temp.ocenka[i].flag = true;
		}


		cout << "Введите результаты зачетов(Н - незачет З - зачет):\n";

		for (int i = 0; i < 5; i++)
		{
			cout << "Посеместровые зачеты по предмету: " << temp.ocenka[i].name << endl;
			for (int j = 0; j < 8; j++)
			{
			x3:
				char w;
				cin >> w;
				if (w != 'Н' and w != 'З')
				{
					cout << "\n Ошибка. Может быть только Н или З. \n";
					goto x3;
				}
				temp.ocenka[i].res[j] = w;
			}
		}

		cout << "Введите отметки по предметам:\n";

		for (int i = 5; i < 10; i++)
		{
			cout << "Посеместровые отметки по предмету: " << temp.ocenka[i].name << endl;
			for (int j = 0; j < 8; j++)
			{
			x4:
				int test;
				cin >> test;
				if (test < 2 or test > 5)
				{
					cout << "\n Ошибка. Отметка не может быть меньше 2 или больше 5\n";
					goto x4;
				}
				temp.ocenka[i].amarks[j] = test;
			}
		}
		additem(temp, Count);
		safe();
		goto a1;
	default:
		edititem(ch, Count);
		goto a1;
	}
}
