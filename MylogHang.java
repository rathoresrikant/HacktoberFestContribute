import java.util.Scanner;
import java.util.Random;

class Hangman {
    private static final String[] CITIES = {
        "DELHI", "KARACHI", "NEWYORK", "LONDON", "TOKYO", 
        "SURAT", "KABUL", "DUBAI", "JAIPUR", "PUNE"
    };
    private static final int MAX_LIVES = 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        boolean playAgain;

        do {
            String cityToGuess = CITIES[random.nextInt(CITIES.length)];
            playGame(scanner, cityToGuess);
            playAgain = askToPlayAgain(scanner);
        } while (playAgain);

        System.out.println("Thank you for playing Hangman!");
        scanner.close();
    }

    private static void playGame(Scanner scanner, String cityToGuess) {
        StringBuilder currentGuess = new StringBuilder("_".repeat(cityToGuess.length()));
        StringBuilder incorrectGuesses = new StringBuilder();
        int numLives = 0;

        System.out.println("GUESS THE WORLD'S LARGEST CITY");
        System.out.println("Rule: You have " + MAX_LIVES + " chances to guess the correct letters.");

        while (numLives < MAX_LIVES) {
            displayCurrentState(currentGuess, incorrectGuesses);
            char guessedLetter = getValidGuess(scanner, incorrectGuesses, currentGuess);

            if (cityToGuess.indexOf(guessedLetter) != -1) {
                updateGuess(cityToGuess, currentGuess, guessedLetter);
            } else {
                incorrectGuesses.append(guessedLetter);
                numLives++;
                System.out.println("MISSES = " + incorrectGuesses);
            }

            if (currentGuess.indexOf("_") == -1) {
                System.out.println("Congratulations! You've guessed the city: " + cityToGuess);
                return;
            }
        }

        System.out.println("You've run out of lives! The city was: " + cityToGuess);
    }

    private static void displayCurrentState(StringBuilder currentGuess, StringBuilder incorrectGuesses) {
        System.out.println("YOUR CURRENT GUESSES: " + currentGuess);
        System.out.println("INCORRECT GUESSES: " + incorrectGuesses);
    }

    private static char getValidGuess(Scanner scanner, StringBuilder incorrectGuesses, StringBuilder currentGuess) {
        char guessedLetter;
        while (true) {
            System.out.print("GUESS A LETTER: ");
            String input = scanner.nextLine().toUpperCase();
            if (input.length() != 1 || !Character.isLetter(input.charAt(0))) {
                System.out.println("Please enter a single letter.");
                continue;
            }
            guessedLetter = input.charAt(0);
            if (incorrectGuesses.indexOf(String.valueOf(guessedLetter)) != -1 || currentGuess.indexOf(String.valueOf(guessedLetter)) != -1) {
                System.out.println("You've already guessed that letter. Try again.");
            } else {
                break;
            }
        }
        return guessedLetter;
    }

    private static void updateGuess(String cityToGuess, StringBuilder currentGuess, char guessedLetter) {
        for (int i = 0; i < cityToGuess.length(); i++) {
            if (cityToGuess.charAt(i) == guessedLetter) {
                currentGuess.setCharAt(i, guessedLetter);
            }
        }
    }

    private static boolean askToPlayAgain(Scanner scanner) {
        System.out.print("DO YOU WANT TO PLAY AGAIN? (Y/N): ");
        String response = scanner.nextLine().trim().toUpperCase();
        return response.equals("Y");
    }
}
