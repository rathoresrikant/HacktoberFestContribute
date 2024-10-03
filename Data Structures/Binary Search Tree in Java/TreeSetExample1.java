package com.company;

//add, contains, iterator, remove

import java.util.Iterator;
import java.util.TreeSet;

public class TreeSetExample1 {
    public static void main(String[] args) {
        TreeSet<String> s = new TreeSet<String>();

        s.add("vaibhav");
        s.add("nirmal");
        s.add("ide");

        System.out.println(s);

        System.out.println(s.contains("ide"));

        Iterator<String> i = s.iterator();

        while (i.hasNext()){
            System.out.print(i.next()+ " ");
        }
        s.remove("nirmal");

        System.out.println("\nAfter removing : \n");

        for(String x : s){
            System.out.print(x+ " ");
        }

    }
}
