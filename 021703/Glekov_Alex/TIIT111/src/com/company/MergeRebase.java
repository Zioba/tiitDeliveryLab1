package com.company;

public class MergeRebase {

    public void Merge(List inputlist, List addlist1){
        for (int i = 0; i < addlist1.getLength(); i++){

            inputlist.addFirst(addlist1.get(i));

        }
        inputlist.print();
    }


    public void Rebase(List inputList, List addList1){

        for (int i = 0; i < inputList.getLength(); i++) {

            for (int j = 0; j < addList1.getLength(); j++) {

                if (inputList.get(i) == addList1.get(j)){
                    System.out.println(inputList.get(i) + " == " + addList1.get(j));
                }

            }

        }

    }

}
