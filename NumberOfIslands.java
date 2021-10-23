// Java program to count the number of islands in a 2D grid
import java.util.*;
import java.lang.*;
import java.io.*;

class Islands {
    //primary function, which returns the total number of Islands
    public int numIslands(char[][] grid) {
        // boolean array of equal size of the grid to keep track of the visited or un-visited elements
        boolean visited[][] = new boolean[grid.length][grid[0].length];
        // Variable count that will hold the number of Islands
        int count = 0;
        // Loop to iterate the elements in a grid
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // if the element is 1 and hasn't been visited yet, its adjacent vertices will be checkout using the utility function
                if (visited[i][j] == false && grid[i][j] == '1') {

                    DFStraverse(grid, i, j, visited);
                    // After the function, call count will get incremented by 1
                    count++;
                }
            }
        }
        // Returning the final count
        return count;
    }
    // Utility function to check for the element's neighbor
    static void DFStraverse(char[][] grid, int row, int col, boolean visited[][]) {
        // If any of the conditions satisfy then the return statement will be called out to the respective function call
        if (row < 0 || col < 0 || row == grid.length || col == grid[0].length || grid[row][col] == '0' || visited[row][col] == true) {
            return;
        }
        // Otherwise, update the element's status from unvisited to visited
        visited[row][col] = true;
        // Recursive call to move up
        DFStraverse(grid, row, col - 1, visited);
        // Recursive call to move down
        DFStraverse(grid, row, col + 1, visited);
        // Recursive call to move left
        DFStraverse(grid, row - 1, col, visited);
        // Recursive call to move right
        DFStraverse(grid, row + 1, col, visited);
    }
    // main function
    public static void main(String[] args) throws java.lang.Exception {
        // Scanner class to take the input from the user
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows: ");
        int rows = sc.nextInt();
        System.out.println("Enter the number of columns: ");
        int cols = sc.nextInt();

        char grid[][] = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.println("Enter [" + i + "] [" + j + "] element: ");
                // Take the character input from the user
                grid[i][j] = sc.next().charAt(0);
            }
        }
        // Create the class object
        Islands I = new Islands();
        // Printing the grid
        System.out.println("Grid:- ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        // Final function call
        System.out.println("Number of islands is: " + I.numIslands(grid));
    }
}
