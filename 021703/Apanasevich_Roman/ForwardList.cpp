#include "ForwardList.h"

void ForwardList::push_back(int value)
{
	if (head == nullptr) {
		//если корня нету - создаём
		head = new Node();
		head->data = value;
	}
	else
	{
		// есть хоть один элемент
		Node* last = head;
		//Ищем узел, в котором указатель на следующий элемент = nullptr
		//Это будет последний узел в списке
		while (last->next != nullptr) {
			last = last->next;
		}

		//Создаем новый узел, заполняем его данными и присваеваем указателю на следующий элемент самого последнего узла созданный узел
		last->next = new Node();
		last->next->data = value;
	}

	//Увеличиваем размер на 1
	size++;
}

void ForwardList::pop_back()
{
	//Ставим указатель на начало списка
	Node* node = head;

	//Передвигаем указатель, пока он не будет ссылаться на последний элемент списка
	for (int i = 0; i < size; i++)
		node = node->next;
	
	//Теперь удаляем последний узел
	delete node;

	//Уменьшаем размер на 1
	size--;

	//У теперь уже последнего(ранее он был предпоследним) узла зануляем указатель на next
	getNode(size - 1)->next = nullptr;
}

int ForwardList::get(int index)
{
	//Получаем узел по индексу
	Node* node = getNode(index);
	
	//Проверяем, корректен ли был index
	if (node == nullptr)
		throw exception("Invalid index");

	//Возвращаем данные в этом узле
	return node->data;
}

void ForwardList::sort()
{
	//Пузырьковая сортировка
	bool flag;
	do
	{
		flag = true;
		for (int i = 0; i < size - 1; i++)
		{
			Node* n1 = getNode(i);
			Node* n2 = getNode(i + 1);

			if (n1->data > n2->data)
			{
				int temp = n1->data;
				n1->data = n2->data;
				n2->data = temp;
				flag = false;
			}
		}

	} while (!flag);
}

void ForwardList::join(ForwardList& other)
{
	for (int i = 0; i < other.size; i++)
		push_back(other.get(i));
}

ForwardList* ForwardList::findIntersections(ForwardList& other)
{
	//Создаем умный указатель, который сам очистит память. Он ссылается на только что созданный ForwardList
	ForwardList* retList = new ForwardList();
	
	//Проходим по каждому элементу текущего списка
	for (int i = 0; i < size; i++)
	{
		int thisElement = this->get(i);
		bool intersects = false;

		for (int j = 0; j < other.size; j++)
		{
			//Проходим по каждому элементу other списка
			int otherElement = other.get(j);
			if (otherElement == thisElement)
			{
				//Сюда попадаем если элемент есть и в текущем и в other списке
				//Ставим переменную intersects в true
				//Выходим из цикла
				intersects = true;
				break;
			}
		}

		//Если элементы есть и в первом и во втором списках
		if (intersects)
		{
			//Проверяем, есть ли этот элемент уже в списке пересекающихся элементов
			//Если есть не добавляем его
			bool alreadyExists = false;
			for (int i1 = 0; i1 < retList->size; i1++)
			{
				if (retList->get(i1) == thisElement)
				{
					alreadyExists = true;
					break;
				}
			}

			if (!alreadyExists)
				retList->push_back(thisElement);
		}
	}

	return retList;
}

void ForwardList::print()
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

ForwardList::Node* ForwardList::getNode(int index)
{
	//Если индекс не корректен, вернуть nullptr
	if (index >= size)
		return nullptr;

	Node* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	//Вернуть узел по индексу
	return current;
}
