"""lab1. Одномерный массив. Сортировка массива. Вставка элемента в
отсортированный массив. Поиск элемента в отсортированном массиве.
Объединение двух отсортированных массивов. Пересечение двух
отсортированных массивов."""


def sorting(array):
    array.sort()

def AddElement(Element, array):
    array += [Element]

def SearchElement(Element, array):
    return array.index(Element)

def Union(array_1, array_2):
    i, j = 0, 0
    array = []
    while i < len(array_1) and j < len(array_2):
        if array_1[i] < array_2[j]:
            array += [array_1[i]]
            i += 1
        elif array_2[j] < array_1[i]:
            array += [array_2[j]]
            j += 1
        else:
            array += [array_2[j]]
            j += 1
            i += 1
    while i < len(array_1):
        array += [array_1[i]]
        i += 1
    while j < len(array_2):
        array += [array_2[j]]
        j += 1
    return array

def Intersection(arr1, arr2):
    i, j = 0, 0
    array = []
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            i += 1
        elif arr2[j] < arr1[i]:
            j += 1
        else:
            array += [arr2[j]]
            j += 1
            i += 1
    return array