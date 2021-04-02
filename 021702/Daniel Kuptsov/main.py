from msvcrt import getch
import random
import library


def select(_variants, _choice=0):
    size = len(_variants)
    while 1:
        text = ""
        for _i in range(size):
            text += _variants[_i] + ("   ", "<< ")[_i == _choice]
        print("\r" + text, end='')
        key = ord(getch())
        if key == 13:
            print("")
            return _choice
        _choice = (_choice, (_choice - 1, _choice + 1)[key == 77])[key == 77 or key == 75] % size


# чтобы работали стрелочки: Toolbar/Run/Edit Configurations/Emulate terminal in output console
choice = 0
adj_list = []
variants = [["Создать", "Добавить вершину в конец", "Добавить вершину", "Удалить вершину", "Дуга", "Обход в глубину"]]
while 1:
    choice = select(variants[0], choice)
    input_id = 0
    input_id_2 = 0
    input_value = 0
    if choice == 0:
        adj_list.clear()
        random.seed()
        random_count = random.randint(1, 10)
        random_value = 0
        int_list = []
        for i in range(random_count):
            random_value = random.randint(0, 20)
            if random_value in int_list:
                i = 0
                continue
            library.add_vertex_to_top(adj_list, random_value)
            int_list.append(random_value)
        print(adj_list)
    if choice == 1:
        try:
            input_value = int(input("Значение : "))
        except (ValueError, Exception):
            print("Некорректное значение")
            continue
        if not library.add_vertex_to_top(adj_list, input_value):
            print("Некорректное значение")
            continue
        print(adj_list)
    if choice == 2:
        try:
            input_value = int(input("Значение : "))
            if len(adj_list) > 1:
                input_id = int(input("Куда? "))
        except (ValueError, Exception):
            print("Некорректное значение")
            continue
        if not library.add_vertex(adj_list, input_value, input_id):
            print("Некорректное значение или направление")
            continue
        print(adj_list)
    elif choice == 3:
        try:
            input_id = int(input("Какую? "))
        except (ValueError, Exception):
            print("Некорректное значение")
            continue
        if not library.delete_vertex(adj_list, input_id):
            print("Не найдена")
            continue
        print(adj_list)
    elif choice == 4:
        try:
            input_id = int(input("Первая вершина : "))
            input_id_2 = int(input("Вторая вершина : "))
        except (ValueError, Exception):
            print("Некорректное значение")
        if not library.insert_link(adj_list, input_id, input_id_2):
            print("Некорректное направление")
            continue
        print(adj_list)
    elif choice == 5:
        visited = []
        library.deep_first_search(adj_list, adj_list[0], visited)
        print(visited)
