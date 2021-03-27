package com.company;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.testng.Assert;

class ListTest {

    List list1 = new List();
    List list2 = new List();
    List list3 = new List();

    @Test
    void addByIndex() {
        System.out.println("==============================");
        list3.addFirst(1);
        list3.addFirst(3);
        list3.addFirst(2);

        list1.addFirst(1);
        list1.addFirst(2);
        list1.addByIndex(3, 1);
        //list1.print1();
        Assert.assertEquals(list1.getLength(), list3.getLength(), "Done!");
        for (int i = 0; i < list1.getLength(); i++){
            Assert.assertEquals(list1.get(i), list3.get(i), "Done!");
        }
        System.out.println("==============================");
    }

    @org.junit.jupiter.api.Test
    void removeAt() {
        System.out.println("==============================");
        list3.addFirst(1);

        list1.addFirst(1);
        list1.addFirst(2);
        list1.removeAt(2);
        Assert.assertEquals(list1.getLength(), list3.getLength(), "Done!");
        for (int i = 0; i < list1.getLength(); i++){
            Assert.assertEquals(list1.get(i), list3.get(i), "Done!");
        }
        System.out.println("==============================");
    }

    @org.junit.jupiter.api.Test
    void find() {
        System.out.println("==============================");
        list1.addFirst(1);
        list1.addFirst(2);
        list1.addFirst(3);
        list1.addFirst(4);
        list1.find(3);
        Assert.assertEquals(list1.find1(3), 3, "Done!");
        System.out.println("==============================");
    }

    @org.junit.jupiter.api.Test
    void print() {
        System.out.println("==============================");
        list3.addFirst(1);
        list3.addFirst(2);
        list3.addFirst(3);
        list3.addFirst(4);


        list1.addFirst(1);
        list1.addFirst(2);
        list1.addFirst(3);
        list1.addFirst(4);
        //list1.print();
        Assert.assertEquals(list1.getLength(), list3.getLength(), "Done!");
        for (int i = 0; i < list1.getLength(); i++){
            Assert.assertEquals(list1.get(i), list3.get(i), "Done!");
        }
        System.out.println("==============================");
    }

    @org.junit.jupiter.api.Test
    void get() {
        System.out.println("==============================");
        list1.addFirst(1);
        list1.addFirst(2);
        list1.addFirst(3);
        list1.addFirst(4);
        //System.out.println(list1.get(2));

        Assert.assertEquals(list1.get(2), 2, "Done!");
        System.out.println("==============================");
    }

    @org.junit.jupiter.api.Test
    void sort() {
        System.out.println("==============================");
        //System.out.println("До сортировки: ");
        list3.addFirst(161);
        list3.addFirst(18);
        list3.addFirst(7);
        list3.addFirst(4);


        list1.addFirst(18);
        list1.addFirst(161);
        list1.addFirst(4);
        list1.addFirst(7);
        /*list1.print();
        System.out.println("После сортировки: ");
        list1.sort(list1);
        //list1.print();*/

        list1.sort(list1);
        Assert.assertEquals(list1.getLength(), list3.getLength(), "Done!");
        for (int i = 0; i < list1.getLength(); i++){
            Assert.assertEquals(list1.get(i), list3.get(i), "Done!");
        }
        System.out.println("==============================");
    }

    @Test
    void merge() {
        System.out.println("==============================");
        list3.addFirst(18);
        list3.addFirst(7);
        list3.addFirst(4);
        list3.addFirst(2);



        list1.addFirst(18);
        list1.addFirst(7);
        list2.addFirst(2);
        list2.addFirst(4);

        list1.Merge(list1,list2);

        Assert.assertEquals(list1.getLength(), list3.getLength(), "Done!");
        for (int i = 0; i < list1.getLength(); i++){
            Assert.assertEquals(list1.get(i), list3.get(i), "Done!");
        }
        System.out.println("==============================");

    }
    int a = 3;
    int b = 3;


    @Test
    void rebase() {
        System.out.println("==============================");
        list1.addFirst(18);
        list1.addFirst(161);
        list1.addFirst(4);
        list1.addFirst(7);
        list2.addFirst(2);
        list2.addFirst(4);
        list2.addFirst(76);
        list2.addFirst(89);

        list1.Rebase(list1,list2);
        Assert.assertEquals(list1.Rebase1(list1, list2), 1, "Done!");
        System.out.println("==============================");
    }
}