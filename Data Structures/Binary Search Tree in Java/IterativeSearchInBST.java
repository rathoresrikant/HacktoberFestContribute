package com.company;

public class IterativeSearchInBST {
    static class Node{
        int key;
        Node left;
        Node right;
        Node(int k){
            this.key = k;
            left=right=null;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(15);
        root.left = new Node(5);
        root.left.left=new Node(3);

        root.right=new Node(20);
        root.right.left=new Node(18);
        root.right.left.left=new Node(16);
        root.right.right = new Node(80);

        int x =16;
        if (search(root,x)){
            System.out.println("Element found");
        }else {
            System.out.println("Element not found");
        }

    }

    public static boolean search(Node root, int x){
        while (root != null){
            if (root.key==x){
                return true;
            }else if (root.key>x){
                root=root.left;
            }else {
                root=root.right;
            }
        }
        return false;

    }


}
