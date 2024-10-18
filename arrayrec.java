import java.util.ArrayList;
import java.util.List;

public class SubsequenceFinder {

    public static void main(String[] args) {
        int[] array = {1, 2, 3};
        List<List<Integer>> subsequences = findSubsequences(array);
        
        // Print the subsequences
        System.out.println("All Subsequences:");
        for (List<Integer> subsequence : subsequences) {
            System.out.println(subsequence);
        }
    }

    // Function to find all subsequences
    public static List<List<Integer>> findSubsequences(int[] array) {
        List<List<Integer>> result = new ArrayList<>();
        findSubsequencesHelper(array, 0, new ArrayList<>(), result);
        return result;
    }

    // Helper function to generate subsequences using recursion
    private static void findSubsequencesHelper(int[] array, int index, List<Integer> current, List<List<Integer>> result) {
        // Add the current subsequence to the result
        result.add(new ArrayList<>(current));

        // Iterate through the remaining elements
        for (int i = index; i < array.length; i++) {
            current.add(array[i]); // Include the current element
            findSubsequencesHelper(array, i + 1, current, result); // Recur with the next index
            current.remove(current.size() - 1); // Backtrack to find other subsequences
        }
    }
}
