package com.kangjingyang;

import java.util.ArrayList;

import java.io.*;

public class day1_2 {

    static ArrayList<String> data;

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

    public static void main(String[] args) {
        data = new ArrayList<String>();
        input();
        int ans = algo();
        System.out.format("the ans is: %d\n", ans);
    }

    private static int algo() {
        int res = 0;
        for (int i = 0; i < data.size() - 3; i++) {
            if (Integer.parseInt(data.get(i)) < Integer.parseInt(data.get(i + 3))) {
                res++;
            }
        }
        return res;
    }
}
