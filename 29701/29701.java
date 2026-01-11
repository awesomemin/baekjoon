import java.util.HashMap;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        HashMap<String, String> decodeTable = new HashMap<String, String>();
        decodeTable.put(".-", "A");
        decodeTable.put("-...", "B");
        decodeTable.put("-.-.", "C");
        decodeTable.put("-..", "D");
        decodeTable.put(".", "E");
        decodeTable.put("..-.", "F");
        decodeTable.put("--.", "G");
        decodeTable.put("....", "H");
        decodeTable.put("..", "I");
        decodeTable.put(".---", "J");
        decodeTable.put("-.-", "K");
        decodeTable.put(".-..", "L");
        decodeTable.put("--", "M");
        decodeTable.put("-.", "N");
        decodeTable.put("---", "O");
        decodeTable.put(".--.", "P");
        decodeTable.put("--.-", "Q");
        decodeTable.put(".-.", "R");
        decodeTable.put("...", "S");
        decodeTable.put("-", "T");
        decodeTable.put("..-", "U");
        decodeTable.put("...-", "V");
        decodeTable.put(".--", "W");
        decodeTable.put("-..-", "X");
        decodeTable.put("-.--", "Y");
        decodeTable.put("--..", "Z");
        decodeTable.put(".----", "1");
        decodeTable.put("..---", "2");
        decodeTable.put("...--", "3");
        decodeTable.put("....-", "4");
        decodeTable.put(".....", "5");
        decodeTable.put("-....", "6");
        decodeTable.put("--...", "7");
        decodeTable.put("---..", "8");
        decodeTable.put("----.", "9");
        decodeTable.put("-----", "0");
        decodeTable.put("--..--", ",");
        decodeTable.put(".-.-.-", ".");
        decodeTable.put("..--..", "?");
        decodeTable.put("---...", ":");
        decodeTable.put("-....-", "-");
        decodeTable.put(".--.-.", "@");
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        String decoded = "";
        for(int i = 0; i < N; i++) {
            decoded += decodeTable.get(scanner.next());
        }
        System.out.println(decoded);
    }
}