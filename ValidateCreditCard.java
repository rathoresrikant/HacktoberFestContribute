import java.util.Scanner;

public class CardValidator {

    public static void main(String[] args) {
        System.out.println("Please enter your card number:");
        Scanner scanner = new Scanner(System.in);
        String cardNumber = scanner.nextLine();

        if (isValidCardNumber(cardNumber)) {
            System.out.println("Card number is valid.");
            identifyCardType(cardNumber);
            displayAccountNumber(cardNumber);
        } else {
            System.out.println("Card number is not valid.");
            suggestCheckDigit(cardNumber);
        }
        scanner.close();
    }

    // Validate card number using Luhn's algorithm
    private static boolean isValidCardNumber(String cardNumber) {
        if (!isNumeric(cardNumber) || !(cardNumber.length() >= 12 && cardNumber.length() <= 19)) {
            return false;
        }
        
        int sum1 = 0, sum2 = 0;

        for (int x = cardNumber.length() - 2; x >= 0; x -= 2) {
            int digit = Character.getNumericValue(cardNumber.charAt(x));
            int doubled = digit * 2;
            sum1 += (doubled > 9) ? (doubled % 10 + 1) : doubled;
        }

        for (int x = cardNumber.length() - 1; x >= 0; x -= 2) {
            sum2 += Character.getNumericValue(cardNumber.charAt(x));
        }

        int totalSum = sum1 + sum2;
        return totalSum % 10 == 0;
    }

    // Check if the string is numeric
    private static boolean isNumeric(String str) {
        for (char c : str.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }

    // Identify card type based on the number
    private static void identifyCardType(String cardNumber) {
        String firstDigit = String.valueOf(cardNumber.charAt(0));
        String firstTwoDigits = cardNumber.substring(0, 2);
        String firstFourDigits = cardNumber.substring(0, 4);

        switch (firstDigit) {
            case "3":
                System.out.println("Card Type: Travel/Entertainment (Amex)");
                break;
            case "4":
                System.out.println("Card Type: Visa");
                break;
            case "5":
                System.out.println("Card Type: Mastercard");
                break;
            case "6":
                System.out.println("Card Type: Discover/Merchandising");
                break;
            case "7":
                System.out.println("Card Type: Petroleum");
                break;
            case "8":
                System.out.println("Card Type: Healthcare and Telecommunications");
                break;
            default:
                System.out.println("Card Type: Unknown");
                break;
        }
        
        // Additional checks for specific card ranges
        if (firstTwoDigits.equals("34") || firstTwoDigits.equals("37")) {
            System.out.println("Card Type: American Express");
        } else if (firstTwoDigits.matches("51|52|53|54|55")) {
            System.out.println("Card Type: Mastercard");
        } else if (firstFourDigits.equals("6011") || firstFourDigits.matches("644|65")) {
            System.out.println("Card Type: Discover");
        }
    }

    // Display account number extracted from the card number
    private static void displayAccountNumber(String cardNumber) {
        String accountNumber = cardNumber.substring(6, cardNumber.length() - 1);
        System.out.println("Account Number: " + accountNumber);
    }

    // Suggest a check digit if the card number is not valid
    private static void suggestCheckDigit(String cardNumber) {
        char lastDigit = cardNumber.charAt(cardNumber.length() - 1);
        int sum = calculateLuhnSum(cardNumber.substring(0, cardNumber.length() - 1));
        int checkDigit = (10 - (sum % 10)) % 10;
        System.out.println("Suggested Check Digit: " + checkDigit);
    }

    // Calculate sum for Luhn's algorithm excluding the last digit
    private static int calculateLuhnSum(String number) {
        int sum1 = 0, sum2 = 0;

        for (int x = number.length() - 2; x >= 0; x -= 2) {
            int digit = Character.getNumericValue(number.charAt(x));
            int doubled = digit * 2;
            sum1 += (doubled > 9) ? (doubled % 10 + 1) : doubled;
        }

        for (int x = number.length() - 1; x >= 0; x -= 2) {
            sum2 += Character.getNumericValue(number.charAt(x));
        }

        return sum1 + sum2;
    }
}
