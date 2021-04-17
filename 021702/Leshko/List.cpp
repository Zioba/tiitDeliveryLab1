#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}


List::~List()
{
	// Удаляем все элементы
	delAll();
}

void List::addHead(int n)
{
	// новый элемент
	Elem* temp = new Elem;

	// Предыдущего нет
	temp->prev = 0;
	// Заполняем данные
	temp->data = n;
	// Следующий - бывшая голова
	temp->next = Head;

	// Если элементы есть?
	if (Head != 0)
		Head->prev = temp;

	// Если элемент первый, то он одновременно и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		// иначе новый элемент - головной
		Head = temp;

	Count++;
}

void List::addTail(int n)
{
	// Создаем новый элемент
	Elem* temp = new Elem;
	// Следующего нет
	temp->next = 0;
	// Заполняем данные
	temp->data = n;
	// Предыдущий - бывший хвост
	temp->prev = Tail;

	// Если элементы есть?
	if (Tail != 0)
		Tail->next = temp;

	// Если элемент первый, то он одновременно и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		// иначе новый элемент - хвостовой
		Tail = temp;

	Count++;
}

void List::sort_info() {
	Elem* t = NULL, * t1;
	int r;
	do {
		for (t1 = Head; t1->next != t; t1 = t1->next)
			if (t1->data > t1->next->data) {
				r = t1->data;
				t1->data = t1->next->data;
				t1->next->data = r;
			}
		t = t1;
	} while (Head->next != t);
}

void List::insert(int pos)
{
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}

	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count + 1)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}

	// Если вставка в конец списка
	if (pos == Count + 1)
	{
		// Вставляемые данные
		int data;
		cout << "Input new number: ";
		cin >> data;
		// Добавление в конец списка
		addTail(data);
		return;
	}
	else if (pos == 1)
	{
		// Вставляемые данные
		int data;
		cout << "Input new number: ";
		cin >> data;
		// Добавление в начало списка
		addHead(data);
		return;
	}

	// Счетчик
	int i = 1;

	// Отсчитываем от головы n - 1 элементов
	Elem* Ins = Head;

	while (i < pos)
	{
		// Доходим до элемента,
		// перед которым вставляемся
		Ins = Ins->next;
		i++;
	}

	// Доходим до элемента,
	// который предшествует
	Elem* PrevIns = Ins->prev;

	// Создаем новый элемент
	Elem* temp = new Elem;

	// Вводим данные
	cout << "Input new number: ";
	cin >> temp->data;

	// настройка связей
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	Count++;
}

void List::del(int pos)
{
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}

	// Счетчик
	int i = 1;

	Elem* Del = Head;

	while (i < pos)
	{
		// Доходим до элемента,
		// который удаляется
		Del = Del->next;
		i++;
	}

	// Доходим до элемента,
	// который предшествует удаляемому
	Elem* PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	Elem* AfterDel = Del->next;

	// Если удаляем не голову
	if (PrevDel != 0 && Count !=

		1)
		PrevDel->next = AfterDel;
	// Если удаляем не хвост
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	// Удаляются крайние?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	// Удаление элемента
	delete Del;

	Count--;
}

void List::print(int pos)
{
	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "List !!!\n";
		return;
	}

	Elem* temp;

	// Определяем с какой стороны
	// быстрее двигаться
	if (pos <= Count / 2)
	{
		// Отсчет с головы
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->next;
			i++;
		}
	}

	else
	{
		// Отсчет с хвоста
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->prev;
			i++;
		}
	}
	// Вывод элемента
	cout << pos << " element: ";
	cout << temp->data << endl;
}

void List::print()
{
	// Если в списке присутствуют элементы, то пробегаем по нему
	// и печатаем элементы, начиная с головного
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

void List::delAll()
{
	// Пока остаются элементы, удаляем по одному с головы
	while (Count != 0)
		del(1);
}

int List::getCount()
{
	return Count;
}

void List::intersection(List& L, List& M)
{
	List Result;
	M.sort_info();
	L.sort_info();
	Elem* t = M.Head;
	Elem* p = L.Head;
	while (t != NULL && p != NULL)
	{
		if (t->data == p->data)
		{
			Result.addHead(t->data);
			t = t->next;
			p = p->next;
		}
		else
			if (t->data < p->data)
				t = t->next;
			else
				p = p->next;
	}
	Result.sort_info();
	Result.print();
}

void List::merge(List& L, List& M)
{
	List Result;

	Elem* p, * g;

	for (p = M.Head; p != NULL; p = p->next)
	{
		Result.addHead(p->data);
	}

	for (p = L.Head; p != NULL; p = p->next)
	{
		Result.addHead(p->data);
	}

	int m = 0;
	int counter1;
	for (p = Result.Head; p != NULL; p = p->next)
	{
		m++;
		counter1 = 0;
		for (g = Result.Head; g != NULL; g = g->next)
		{
			if (p->data == g->data)
			{
				counter1++;
			}

		}
		if (counter1 > 1)
		{
			if (p != Result.Head)
			{
				p = p->prev;
				Result.del(m);
				m--;
			}
		}
	}
	Result.sort_info();
	Result.print();
}