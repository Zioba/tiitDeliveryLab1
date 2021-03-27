package com.company;


public class List {

    private Node head;
    private Node tail;

    public List() {
        head = null;
        tail = null;
    }

    private boolean isEmpty() {
        return head == null;
    }

    public void addFirst(int data) {
        Node temp = new Node(data);

        if (isEmpty()) {
            tail = temp;
        } else {
            head.prev = temp;
        }

        temp.next = head;
        head = temp;
    }

    public void addLast(int data) {
        Node temp = new Node(data);

        if (isEmpty()) {
            head = temp;
        } else {
            tail.next = temp;
        }

        temp.prev = tail;
        tail = temp;
    }

    public void addByIndex(int data, int index) {
        Node cur = head;
        int c = 0;

        while (cur != null && c != index) {
            cur = cur.next;
            c++;
        }

        Node temp = new Node(data);

        cur.prev.next = temp;
        temp.prev = cur.prev;
        cur.prev = temp;
        temp.next = cur;

    }

    public void removeFirst() {
        Node temp = head;

        if (head.next == null) {
            tail = null;
        } else {
            head.next.prev = null;
        }

        head = head.next;
    }

    public void removeLast() {
        if (head.next == null) {
            head = null;
        } else {
            tail.prev.next = null;
        }

        tail = tail.prev;
    }

    public void removeAt(int key) {
        Node cur = head;

        while (cur.data != key) {
            cur = cur.next;

            if (cur == null) {
                return;
            }
        }

        if (cur == head) {
            removeFirst();
        } else {
            cur.prev.next = cur.next;
        }

        if (cur == tail) {
            removeLast();
        } else {
            cur.next.prev = cur.prev;
        }
    }

    public void find(int key) {
        Node cur = head;

        while (cur.data != key) {
            cur = cur.next;

            if (cur == null) {
                break;
            }
        }
        System.out.println(true);
    }

    public int find1(int key) {
        Node cur = head;

        while (cur.data != key) {
            cur = cur.next;

            if (cur == null) {
                break;
            }
        }
        System.out.println(true);
        int a = 0;
        if (cur.data == key) {
            a = key;
        }
        return a;
    }

    public void print() {
        Node temp = head;

        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public int print1() {
        Node temp = head;
        int a = 0;

        while (temp != null) {
            a = temp.data;
            System.out.println(temp.data);
            temp = temp.next;
        }
        return a;
    }

    public void printBack() {
        Node temp = tail;

        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.prev;
        }
    }

    public int getLength() {
        Node temp = head;
        int length = 0;
        for (temp = head; temp != null; temp = temp.next) {
            length++;
        }
        //System.out.println(length);
        return length;
    }

    public void set(int newVal, int index)
    {
        Node temp = head;
        while (index != 0)
        {
            temp = temp.next;
            index--;
        }

        temp.data = newVal;
    }

    public int get(int index) {
        Node temp = head;
        while (index != 0)
        {
            temp = temp.next;
            index--;
        }
        return temp.data;
    }

    public void sort(List list)
    {
        boolean flag = true;

        do {
            flag = true;
            for (int i = 0; i < list.getLength() - 1; i++)
            {
                if (list.get(i) > list.get(i + 1))
                {
                    flag = false;

                    int temp = list.get(i);
                    list.set(list.get(i + 1), i);
                    list.set(temp, i + 1);
                }
            }
        } while (!flag);
    }


    public static void Merge(List inputlist, List addlist1){
        for (int i = 0; i < addlist1.getLength(); i++){

            inputlist.addFirst(addlist1.get(i));

        }
        inputlist.print();
    }

    public static void Rebase(List inputList, List addList1){

        for (int i = 0; i < inputList.getLength(); i++) {

            for (int j = 0; j < addList1.getLength(); j++) {

                if (inputList.get(i) == addList1.get(j)){
                    System.out.println(inputList.get(i) + " == " + addList1.get(j));
                }
            }
        }
    }

    public static int Rebase1(List inputList, List addList1){

        int a = 0;
        for (int i = 0; i < inputList.getLength(); i++) {

            for (int j = 0; j < addList1.getLength(); j++) {

                if (inputList.get(i) == addList1.get(j)){
                    a = i;
                }
            }
        }
        return a;
    }


}


