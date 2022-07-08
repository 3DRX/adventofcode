import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        try {
            Path path = Paths.get("../input.io");
            java.util.Scanner scanner = new java.util.Scanner(path);
            int count = 0;
            int last = -1;
            while (scanner.hasNextLine()) {
                int ipt = scanner.nextInt();
                if (last == -1) {
                } else if (last < ipt) {
                    count++;
                }
                last = ipt;
            }
            System.out.println(count);
        } catch (IOException e) {
        }
    }
}
