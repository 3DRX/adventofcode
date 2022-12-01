package com.kangjingyang;

import java.util.ArrayList;

import java.io.*;

public class day3_1 {

    static ArrayList<String> data;
    static String gamma;
    static String epsilon;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        gamma = "";
        epsilon = "";
        input();
        lalala();
        System.out.format("the ans is: %d\n", Integer.parseInt(gamma, 2) * Integer.parseInt(epsilon, 2));
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
        // get gamma rate and epsilon rate
        for (int k = 0; k < data.get(0).length(); k++) {
            int one = 0;
            int zero = 0;
            for (int i = 0; i < data.size(); i++) {
                if (data.get(i).charAt(k) == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            if (one > zero) {
                gamma = gamma + "1";
                epsilon = epsilon + "0";
            } else {
                gamma = gamma + "0";
                epsilon = epsilon + "1";
            }
        }
    }
}
