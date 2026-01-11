import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int yearX = scanner.nextInt();
        int yearY = scanner.nextInt();
        for(int year = yearX; year <= yearY; year += 60) {
            System.out.printf("All positions change in year %d%n", year);
        }
    }
}