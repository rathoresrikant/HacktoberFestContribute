public class TNode
    {
        public TNode Root;
        public TNode Right;
        public TNode Left;
        public int data;

        public TNode()
        {
            Right = null;
            Left = null;
            Root = null;
            data = 0;
        }
        public TNode(int val)
        {
            Right = null;
            Left = null;
            Root = null;
            data = val;
        }
    }

    class LinkedList
    {
        TNode tn = new TNode();

        public TNode MRoot;
        TNode temp;
        TNode inorder(TNode a, int b)
        {

            if (a.data != b)
            {
                if (a.Left != null)
                {
                    a=inorder(a.Left, b);
                }
                if (a.data != b)
                {
                    if (a.Right != null)
                    {
                       a= inorder(a.Right, b);
                    }
                }
              
            }
            if (a.data == b)
            {
                return a;
            }
            else
            {
                return a.Root;
            }
        }

        public void DeleteNode(int val) {
            temp = inorder(MRoot, val);
            if (temp.Left == null && temp.Right == null)
            {
                if (temp.Root.Left == temp)
                {
                    temp.Root.Left = null;
                }
                else if (temp.Root.Right == temp)
                {
                    temp.Root.Left = null;
                }
            }
            else if (temp.Left == null && temp.Right !=null) {
                if (temp.Root.Left == temp)
                {
                    temp.Root.Left = temp.Left;
                }
                else if (temp.Root.Right == temp)
                {
                    temp.Root.Right = temp.Left;
                }
            }

            else if (temp.Left != null && temp.Right == null)
            {
                if (temp.Root.Left == temp)
                {
                    temp.Root.Left = temp.Right;
                }
                else if (temp.Root.Right == temp)
                {
                    temp.Root.Right = temp.Right;
                }
            }
        }
        public void InserAtMroot(int val)
        {
            TNode nw = new TNode(val);
            MRoot = nw;
        }

        public void InsertAtLeft(int A, int val)
        {
            TNode nw = new TNode(val);

            if (MRoot.data == A)
            {

                MRoot.Left = nw;
                nw.Root = MRoot;
            }
            else
            {
                temp = inorder(MRoot, A);
                temp.Left = nw;
                nw.Root = temp;
            }
        }

        public void InsertAtRight(int A, int val)
        {
            TNode nw = new TNode(val);
            if (MRoot.data == A)
            {

                MRoot.Right = nw;
                nw.Root = MRoot;
            }
            else
            {
                temp = inorder(MRoot, A);
                temp.Right = nw;
                nw.Root = temp;
            }
        }

        public void Insert(int [] array) {
            InserAtMroot(array[0]);
            int i = 1;
            temp=MRoot;
            while (i < array.Length) {
               
                if (array[i] < temp.data)
                {
                    if (temp.Left != null)
                    {
                        temp = temp.Left;
                    }
                    else
                    {
                        InsertAtLeft(temp.data, array[i]);
                        i++;
                        temp = MRoot;
                    }
                }
                else if(array[i]>=temp.data) {
                    if (temp.Right != null)
                    {
                        temp = temp.Right;
                    }
                    else
                    {
                        InsertAtRight(temp.data, array[i]);
                        i++;
                        temp = MRoot;
                    }
                }
            
            }
        }

        public void displayInOrder(TNode Root)
        {
            if (Root != null)
            {
                displayInOrder(Root.Left);
                Console.WriteLine(Root.data);
                displayInOrder(Root.Right);
            }
           
        }
    }

    class Program
    {

        public static void Main(String[] args)
        {
            int[] array = {25,52,18,76,35};
            LinkedList L = new LinkedList();
            L.Insert(array);
            Console.WriteLine("Elements of tree accoridng to infix notation");
            L.displayInOrder(L.MRoot);
            L.DeleteNode(18);
            Console.WriteLine("After Deleting 18");
            L.displayInOrder(L.MRoot);
        }
    }
}
