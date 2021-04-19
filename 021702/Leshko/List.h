#ifndef LIST_H
#define LIST_H

struct Elem
{
	int data; // данные
	Elem* next, * prev;
};

class List
{
public:

	// Голова, хвост
	Elem* Head, * Tail;
	// Количество элементов
	int Count;


	// Конструктор
	List();

	// Деструктор
	~List();

	// Получить количество
	int getCount();

	// Удалить весь список
	void delAll();
	// Удаление элемента, если параметр не указывается,
	// то функция его запрашивает
	void del(int pos = 0);
	// Вставка элемента, если параметр не указывается,
	// то функция его запрашивает
	void insert(int pos = 0);
	// Пересечение
	void intersection(List&, List&);
	// Объединение
	void merge(List&, List&);

	// Добавление в конец списка
	void addTail(int n);

	// Добавление в начало списка
	void addHead(int n);

	// Печать списка
	void print();
	// Печать определенного элемента
	void print(int pos);
	// Сортировка
	void sort_info();
};

#endif // LINKEDLIST_H