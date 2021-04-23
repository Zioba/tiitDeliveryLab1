#include "ForwardList.h"

using namespace std;

int main()
{
	ForwardList list;
	list.push_back(430);
	list.push_back(0);
	list.push_back(10);
	list.push_back(342);

	ForwardList list2;
	list2.push_back(0);
	list2.push_back(342);
	list2.push_back(6);
	list2.push_back(10);
	list2.push_back(342);

	auto inter = list.findIntersections(list2);
	inter->print();

	cout << "---------------------------\n\n";

	ForwardList list1;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_back(40);
	list1.push_back(50);

	list1.pop_back();
	list1.pop_back();
	list1.pop_back();
	list1.push_back(100);

	list1.print();

	system("pause");

	return 0;





	
	
	
	//проверка является ли граф ацеклическим
	//матрица смежности 1.2
}