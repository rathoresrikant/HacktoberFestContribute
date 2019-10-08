class Solution
{
    public static int maxHeight(int height[], int width[], int length[], int n)
   {
        List<Node> boxes = getBoxes(n, length, width, height);
    //   System.out.println(boxes);
        // printBoxes(boxes);
        int[] table = new int[boxes.size()];
        for (int i=0; i<table.length; i++){
            table[i] = boxes.get(i).height;
        }
        
        int max = -1;
        for (int i=1; i<table.length; i++){
            for (int j=0; j<i; j++){
                if (boxes.get(i).length < boxes.get(j).length && boxes.get(i).width < boxes.get(j).width){
                    table[i] = Math.max(table[i], boxes.get(i).height+table[j]);
                    max = Math.max(table[i], max);
                }
            }
        }
        // printTable(table);
        return max;
   }
   
   static List<Node> getBoxes(int n, int[] l, int[] w, int[] h){
       List<Node> boxes = new ArrayList<>();
       for (int i=0; i<n; i++){
           boxes.add(new Node(l[i], w[i], h[i]));
           boxes.add(new Node(w[i], h[i], l[i]));
           boxes.add(new Node(h[i], l[i], w[i]));
       }
       Collections.sort(boxes, new Comparator<Node>(){
           public int compare(Node box1, Node box2){
               if (box1.length*box1.width >= box2.length*box2.width)
                    return -1;
                else
                    return 1;
           }
       });
       return boxes;
   }
   
   static void printBoxes(List<Node> boxes){
       for (Node box: boxes){
           System.out.println(box.length + " " + box.width + " " + box.height);
       }
   }
   
   static void printTable(int[] table){
       for (int num: table){
           System.out.print(num + " ");
       }
       System.out.println();
   }
   
   static class Node{
    int length, width, height;
    Node(int l, int w, int h){
        this.length = Math.max(l, w);
        this.width = Math.min(l, w);
        this.height = h;
    }
}
}
