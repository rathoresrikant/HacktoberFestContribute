package com.company;

import java.util.Map;
import java.util.TreeMap;

public class TreeMapExample1 {
    public static void main(String[] args) {
        TreeMap<Integer,String > t = new TreeMap<Integer, String >();

        t.put(10,"vaibhav");
        t.put(15,"nirmal");
        t.put(5,"ide");

        System.out.println(t);
        System.out.println(t.containsKey(10));

        for (Map.Entry<Integer, String> e : t.entrySet()){
            System.out.println(e.getKey()+" "+ e.getValue());
        }

        System.out.println("\n");

        System.out.println(t.higherKey(10));
        System.out.println(t.lowerKey(10));
        System.out.println(t.floorKey(10));
        System.out.println(t.ceilingKey(10));

        // returns the key-value pair corresponding
        // to higher key and prints the associated value
        System.out.println(t.higherEntry(10).getValue());

        // returns the key-value pair corresponding
        // to lower key prints the associated value
        System.out.println(t.lowerEntry(10).getValue());

        // returns a key-value mapping associated
        // with the greatest key <= to the given key
        System.out.println(t.floorEntry(10).getValue());

        // returns a key-value mapping associated
        // with the least key >= to the given key
        System.out.println(t.ceilingEntry(10).getValue());


    }
}
