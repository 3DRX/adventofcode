import java.util.ArrayList;

import java.io.*;

public class Main {

    static ArrayList<String> data;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        input();
        lalala();
    }

    private static void input() {
        try {
            BufferedReader in = new BufferedReader(new FileReader("../input.io"));
            StringBuffer sb;
            while (in.ready()) {
                sb = new StringBuffer(in.readLine());
                data.add(data.size(), sb.toString());
            }
            in.close();
        } catch (IOException e) {
            System.out.println("you fucked up");
        }
    }

    private static void lalala() {
        for (int i = 0; i < data.size(); i++) {
        }
    }
}
