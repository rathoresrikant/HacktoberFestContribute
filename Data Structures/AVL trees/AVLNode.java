public class NodeAVL {
    private Data data;       // Encapsulated fields
    private NodeAVL left;
    private NodeAVL right;
    private NodeAVL top;
    private int balance;

    // Constructor
    public NodeAVL(Data data) {
        this.data = data;      // Directly assigning values
        this.left = null;
        this.right = null;
        this.top = null;
        this.balance = 0;
    }

    // Getters and Setters
    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this.data = data;
    }

    public NodeAVL getLeft() {
        return left;
    }

    public void setLeft(NodeAVL left) {
        this.left = left;
    }

    public NodeAVL getRight() {
        return right;
    }

    public void setRight(NodeAVL right) {
        this.right = right;
    }

    public NodeAVL getTop() {
        return top;
    }

    public void setTop(NodeAVL top) {
        this.top = top;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }
}
