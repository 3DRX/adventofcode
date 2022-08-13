import java.util.ArrayList;

import java.io.*;

public class Main {

    static ArrayList<String> data;
    static int horizontal_position;
    static int depth;
    static int aim;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        horizontal_position = 0;
        depth = 0;
        aim = 0;
        input();
        lalala();
        System.out.format("horizontal_position: %d\n", horizontal_position);
        System.out.format("depth: %d\n", depth);
        System.out.format("ans: %d\n", depth * horizontal_position);
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
            String[] ipt = data.get(i).split(" ");
            if (ipt[0].equals("forward")) {
                horizontal_position += Integer.parseInt(ipt[1]);
                depth += aim * Integer.parseInt(ipt[1]);
            } else if (ipt[0].equals("down")) {
                aim += Integer.parseInt(ipt[1]);
            } else if (ipt[0].equals("up")) {
                aim -= Integer.parseInt(ipt[1]);
            }
        }
    }
}
