package com.kangjingyang.app;

import java.util.ArrayList;

public class day4 {
    public static void phase1(ArrayList<String> Lines) {
        int ans = 0;
        for (String line : Lines) {
            int a_left = Integer.parseInt(line.split(",")[0].split("-")[0]);
            int a_right = Integer.parseInt(line.split(",")[0].split("-")[1]);
            int b_left = Integer.parseInt(line.split(",")[1].split("-")[0]);
            int b_right = Integer.parseInt(line.split(",")[1].split("-")[1]);
            if (a_left <= b_left && a_right >= b_right) {
                ans++;
            } else if (b_left <= a_left && b_right >= a_right) {
                ans++;
            }
        }
        System.out.println(ans);
    }

    public static void phase2(ArrayList<String> Lines) {
        int ans = 0;
        for (String line : Lines) {
            int a_left = Integer.parseInt(line.split(",")[0].split("-")[0]);
            int a_right = Integer.parseInt(line.split(",")[0].split("-")[1]);
            int b_left = Integer.parseInt(line.split(",")[1].split("-")[0]);
            int b_right = Integer.parseInt(line.split(",")[1].split("-")[1]);
            if (a_left > b_right || b_left > a_right) {
            } else {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
