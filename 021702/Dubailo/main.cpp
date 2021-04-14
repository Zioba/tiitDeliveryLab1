#include "bor.h"
int satusmenu;
void Menu() {
    setlocale(LC_ALL, "Rus");
    cout <<"==================="<< endl
    <<"Выберете действие:" << endl
    << "(0) Выход из програмы."  << endl
    << "(1) Вставка строки в Бор." << endl
    << "(2) Поиск стрроки в Боре." << endl
    << "(3) Удаление строки из Бора." << endl
    << "(4) Вывод всего Бора." << endl
    << "Ваш выбор: ";
    cin >> satusmenu;
}

int main(){
    string  line;
    node *root = new node();    
   Menu();


    while (satusmenu !=0){
        switch (satusmenu) {
            case 1:
                cout << "Введите строку: ";
                cin >> line;
                add(line);
                Menu();
            break;
////=============================================
            case 2:
                cout << "Введите строку: ";
                cin >> line;
                has(line);
                Menu();
                break;
////=============================================
            case 3:
                cout << "Введите строку: ";
                cin >> line;
                delit(line);
                Menu();
                break;
////================================================
            case 4:
                write(node *v = root);
                Menu();
                break;
////========================================
            default:
                cout <<"Неправильно выбран пункт Меню! " << endl;
                break;

        }
    }
    cout << "Рабаота завершена! " << endl;
}
