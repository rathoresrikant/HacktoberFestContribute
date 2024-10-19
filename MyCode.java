import java.util.Scanner;
import java.util.Random;

class Hangman {
    private static final String[] CITIES = {
        "DELHI", "KARACHI", "NEWYORK", "LONDON", "TOKYO", 
        "SURAT", "KABUL", "DUBAI", "JAIPUR", "PUNE"
    };
    private static final int MAX_LIVES = 10;

    public static void main(String[] args) {
        System.out.println(" @@@@@@@@@@@@@ PLAY HANGMAN @@@@@@@@@@@@@" );
        Scanner sc = new Scanner(System.in);
        Random random = new Random();

        while (true) {
            String city = CITIES[random.nextInt(CITIES.length)];
            playGame(sc, city);
            if (!playAgain(sc)) break;
        }
        sc.close();
    }

    private static void playGame(Scanner sc, String city) {
        StringBuilder guessed = new StringBuilder("_".repeat(city.length()));
        StringBuilder incorrect = new StringBuilder();
        int lives = 0;

        while (lives < MAX_LIVES && guessed.indexOf("_") != -1) {
            displayProgress(guessed, incorrect);
            char guess = getGuess(sc, incorrect);

            if (city.indexOf(guess) != -1) {
                updateGuessed(city, guessed, guess);
            } else {
                incorrect.append(guess);
                lives++;
                System.out.println("MISSES = " + incorrect);
            }
        }
        
        displayResult(city, guessed);
    }

    private static void displayProgress(StringBuilder guessed, StringBuilder incorrect) {
        System.out.println("YOUR CORRECT GUESSES: " + guessed);
        System.out.println("GUESS A LETTER");
    }

    private static char getGuess(Scanner sc, StringBuilder incorrect) {
        char guess;
        while (true) {
            String input = sc.nextLine().toUpperCase();
            guess = input.charAt(0);
            if (Character.isLetter(guess) && incorrect.indexOf(String.valueOf(guess)) == -1) {
                break;
            }
        }
        return guess;
    }

    private static void updateGuessed(String city, StringBuilder guessed, char guess) {
        for (int i = 0; i < city.length(); i++) {
            if (city.charAt(i) == guess) {
                guessed.setCharAt(i, guess);
            }
        }
    }

    private static void displayResult(String city, StringBuilder guessed) {
        System.out.println();
        if (guessed.indexOf("_") == -1) {
            System.out.println(city + "\n@@ WON! CONGRATULATIONS, GET YOUR PRIZE @@");
        } else {
            System.out.println(city + "\n@@ YOU HAVE LOST THE GAME @@");
        }
    }

    private static boolean playAgain(Scanner sc) {
        System.out.println("DO YOU WANT TO PLAY AGAIN? (Y/N)");
        return sc.nextLine().trim().equalsIgnoreCase("Y");
    }
}
