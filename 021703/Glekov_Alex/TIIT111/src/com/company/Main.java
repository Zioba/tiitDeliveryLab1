package com.company;

import java.util.Scanner;

public class Main {


    public static int menue() {
        System.out.println("Введите число: ");
        System.out.println("======================");
        System.out.println("1 - создать первый(1) список");
        System.out.println("12 - создать второй(2) список");
        System.out.println("2 - вставка элемента в список");
        System.out.println("3 - удаление элемента из списка");
        System.out.println("4 - сортировка списка");
        System.out.println("5 - поиск элемента в списке");
        System.out.println("6 - объединение двух списков(1 и 2)");
        System.out.println("7 - пересечение двух списков(1 и 2)");
        System.out.println("8 - выйти");
        System.out.println("======================");

        Scanner kkk = new Scanner(System.in);
        int a = kkk.nextInt();
        return a;
    }


    public static void main(String[] args) {

        List list1 = new List();
        List list2 = new List();
/*
        System.out.println("Введите число: ");
        System.out.println("======================");
        System.out.println("1 - создать первый список");
        System.out.println("12 - создать второй список");
        System.out.println("2 - вставка элемента в список");
        System.out.println("3 - удаление элемента из списка");
        System.out.println("4 - сортировка списка");
        System.out.println("5 - поиск элемента в списке");
        System.out.println("6 - объединение двух списков");
        System.out.println("7 - пересечение двух списков");
        System.out.println("======================");

        Scanner kkk = new Scanner(System.in);
        int a = kkk.nextInt();*/

        if (menue() == 1) {
            System.out.println("Первый список создан");
            menue();
        } else if (menue() == 12) {
            System.out.println("Второй список создан");
            menue();
        } else if (menue() == 2) {
            System.out.println("Введите номер списка,в кторый хотите вставить число: ");
            Scanner kkk1 = new Scanner(System.in);
            int a = kkk1.nextInt();
            if (a == 1) {
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                System.out.println("Введите номер места: ");
                Scanner kkk3 = new Scanner(System.in);
                int c = kkk3.nextInt();
                list1.addByIndex(a, c);
            } else if (a == 2) {
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                System.out.println("Введите номер места: ");
                Scanner kkk3 = new Scanner(System.in);
                int c = kkk3.nextInt();
                list2.addByIndex(a, c);
            } else {
                System.out.println("Такого списка не существует");
            }
            menue();
        } else if (menue() == 3) {
            System.out.println("Введите номер списка, из которого хотите удалить число: ");
            Scanner kkk1 = new Scanner(System.in);
            int a = kkk1.nextInt();
            if (a == 1) {
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                list1.removeAt(b);
            } else if (a == 2) {
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                list2.removeAt(b);
            }else{
                System.out.println("Такого списка не существует");
            }
            menue();
        } else if(menue() == 4){
                System.out.println("Введите номер списка, который вы хотите отсортировать: ");
                Scanner kkk3 = new Scanner(System.in);
                int v = kkk3.nextInt();
                if (v == 1) {
                    list1.sort(list1);
                } else if (v == 2) {
                    list2.sort(list2);
                }else{
                    System.out.println("Такого списка не существует");
                }
                menue();
        }else if(menue() == 5){
            System.out.println("Введите номер списка, в котором хотите найти число: ");
            Scanner kkk3 = new Scanner(System.in);
            int v = kkk3.nextInt();
            if (v == 1){
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                list1.find(b);
            }else if (v == 2){
                System.out.println("Введите число: ");
                Scanner kkk2 = new Scanner(System.in);
                int b = kkk2.nextInt();
                list2.find(b);
            }else{
                System.out.println("Такого списка не существует");
            }
            menue();
        }else if( menue() == 6){
            MergeRebase mergeRebase = new MergeRebase();
            List.Merge(list1,list2);
            menue();
        }else if(menue() == 7){
            MergeRebase mergeRebase = new MergeRebase();
            List.Rebase(list1, list2);
        }else if(menue() == 8){
            return;
        }else {
            System.out.println("Такого пункта не существует");
            menue();
        }

    }
}
