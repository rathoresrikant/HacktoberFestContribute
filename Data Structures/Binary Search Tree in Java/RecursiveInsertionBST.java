package com.company;

public class RecursiveInsertionBST {
    static class Node{
        int key;
        Node left,right;

        Node(int k){
            this.key= k;
            left=right=null;
        }
    }

    public static void main(String[] args) {
        Node root=new Node(10);
        root.left=new Node(5);
        root.right=new Node(15);
        root.right.left=new Node(12);
        root.right.right=new Node(18);

        int x =20;
        root = insert(root,x);
        inorder(root);

    }

    public static Node insert(Node root, int x){
        if (root == null){
            return new Node(x);
        }
        else if(root.key<x){
            root.right=insert(root.right,x);
        }
        else if (root.key>x){
            root.left=insert(root.left,x);
        }
        return root;
    }

    public static void inorder(Node root){
        if(root!=null){
            inorder(root.left);
            System.out.print(root.key+" ");
            inorder(root.right);
        }
    }
}
