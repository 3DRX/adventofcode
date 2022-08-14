package com.kangjingyang;

import java.util.ArrayList;

import java.io.*;

public class day1_1 {

    static ArrayList<String> data;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        input();
        int ans = lalala();
        System.out.format("the ans is: %d\n", ans);
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

    private static int lalala() {
        int res = 0;
        int last = 0;
        for (int i = 0; i < data.size(); i++) {
            if (i == 0) {
            } else if (Integer.parseInt(data.get(i)) > last) {
                res++;
            }
            last = Integer.parseInt(data.get(i));
        }
        return res;
    }
}
