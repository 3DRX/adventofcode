import java.util.ArrayList;
import java.util.LinkedList;
import java.io.*;

public class Main {

    static ArrayList<String> data;
    static LinkedList<String> list;
    static int oxygen;
    static int co2;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        oxygen = 0;
        co2 = 0;
        input();
        list = generateList();
        getOxygen();
        oxygen = Integer.parseInt(list.get(0), 2);
        list = generateList();
        getCo2();
        co2 = Integer.parseInt(list.get(0), 2);
        System.out.format("the ans is: %d\n", oxygen * co2);
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

    private static LinkedList<String> generateList() {
        LinkedList<String> res = new LinkedList<String>();
        for (int i = 0; i < data.size(); i++) {
            res.add(data.get(i));
        }
        return res;
    }

    private static void getOxygen() {
        while (list.size() > 1) {
            // System.out.println(list.size());
            int one = 0;
            int zero = 0;
            // count
            for (int i = 0; i < data.size(); i++) {
                if (data.get(i).charAt(0) == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            if (one >= zero) {
                // remove strings start with 0
                for (int i = 0; i < list.size(); i++) {
                    if (list.get(i).charAt(0) == '0') {
                        list.remove(i);
                        i--;
                    }
                }
            } else {
                // remove strings start with 1
                for (int i = 0; i < list.size(); i++) {
                    if (list.get(i).charAt(0) == '1') {
                        list.remove(i);
                        i--;
                    }
                }
            }
        }
    }

    private static void getCo2() {
        while (list.size() > 1) {
            int one = 0;
            int zero = 0;
            // count
            for (int i = 0; i < data.size(); i++) {
                if (data.get(i).charAt(0) == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            if (one >= zero) {
                // remove strings start with 1
                for (int i = 0; i < list.size(); i++) {
                    if (list.get(i).charAt(0) == '1') {
                        list.remove(i);
                    }
                }
            } else {
                // remove strings start with 0
                for (int i = 0; i < list.size(); i++) {
                    if (list.get(i).charAt(0) == '0') {
                        list.remove(i);
                    }
                }
            }
        }
    }
}
