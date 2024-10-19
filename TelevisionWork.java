import java.util.Scanner;

class Television {
    private boolean power; // Indicates if the TV is on or off
    private boolean muted; // Indicates if the TV is muted
    private int volume;    // Volume level (0 to 10)
    private int channel;   // Current channel (1 to 99)

    // Default constructor
    public Television() {
        this(false, false, 3, 1); // Default values
    }

    // Parameterized constructor
    public Television(boolean power, boolean muted, int volume, int channel) {
        this.power = power;
        this.muted = muted;
        this.volume = (volume >= 0 && volume <= 10) ? volume : 3;
        this.channel = (channel >= 1 && channel <= 99) ? channel : 1;
    }

    // Toggle power state
    public void togglePower() {
        power = !power;
    }

    // Toggle mute state
    public void toggleMute() {
        if (power) {
            muted = !muted;
        }
    }

    // Increase volume
    public void increaseVolume() {
        if (power && volume < 10) {
            volume++;
        }
    }

    // Decrease volume
    public void decreaseVolume() {
        if (power && volume > 0) {
            volume--;
            muted = false; // Unmute when volume is decreased
        }
    }

    // Change to the next channel
    public void nextChannel() {
        if (power) {
            channel = (channel < 99) ? channel + 1 : 1;
        }
    }

    // Change to the previous channel
    public void previousChannel() {
        if (power) {
            channel = (channel > 1) ? channel - 1 : 99;
        }
    }

    // Set specific channel
    public void setChannel(int channel) {
        if (power) {
            if (channel >= 1 && channel <= 99) {
                this.channel = channel;
            } else {
                System.out.println("Invalid channel. Please enter a channel between 1 and 99.");
            }
        }
    }

    // Display current state of the TV
    public void displayStatus() {
        if (power) {
            System.out.println("TV is ON");
            System.out.println("Current Channel: " + channel);
            if (muted) {
                System.out.println("TV is muted");
            } else {
                System.out.println("Volume Level: " + volume);
            }
        } else {
            System.out.println("TV is OFF");
        }
    }

    // Main method for user interaction
    public static void main(String[] args) {
        Television tv = new Television();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            tv.displayStatus(); // Show current status
            System.out.println("\nMenu:");
            System.out.println("1. Toggle Power");
            System.out.println("2. Toggle Mute");
            System.out.println("3. Increase Volume");
            System.out.println("4. Decrease Volume");
            System.out.println("5. Next Channel");
            System.out.println("6. Previous Channel");
            System.out.println("7. Set Channel");
            System.out.println("0. Exit");

            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    tv.togglePower();
                    break;
                case 2:
                    tv.toggleMute();
                    break;
                case 3:
                    tv.increaseVolume();
                    break;
                case 4:
                    tv.decreaseVolume();
                    break;
                case 5:
                    tv.nextChannel();
                    break;
                case 6:
                    tv.previousChannel();
                    break;
                case 7:
                    System.out.print("Enter channel number (1-99): ");
                    int channel = scanner.nextInt();
                    tv.setChannel(channel);
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }

        } while (choice != 0);

        scanner.close();
    }
}
