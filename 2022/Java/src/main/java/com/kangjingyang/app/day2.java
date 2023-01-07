package com.kangjingyang.app;

import java.util.ArrayList;

public class day2 {
    public static void phase1(ArrayList<String> Lines) {
        int total_score = 0;
        for (String line : Lines) {
            char a = line.split(" ")[0].toCharArray()[0];
            char b = line.split(" ")[1].toCharArray()[0];
            total_score += get_score(a, b);
        }
        System.out.println(total_score);
    }

    public static void phase2(ArrayList<String> Lines) {
        int total_score = 0;
        for (String line : Lines) {
            char a = line.split(" ")[0].toCharArray()[0];
            char b = line.split(" ")[1].toCharArray()[0];
            total_score += get_score(a, get_choice(a, b));
        }
        System.out.println(total_score);
    }

    private static char get_choice(char a, char b) {
        if (a == 'A') {
            if (b == 'X') {
                return 'Z';
            } else if (b == 'Y') {
                return 'X';
            } else {
                return 'Y';
            }
        } else if (a == 'B') {
            if (b == 'X') {
                return 'X';
            } else if (b == 'Y') {
                return 'Y';
            } else {
                return 'Z';
            }
        } else {
            if (b == 'X') {
                return 'Y';
            } else if (b == 'Y') {
                return 'Z';
            } else {
                return 'X';
            }
        }
    }

    private static int get_res(char a, char b) {
        // returns:
        // 1) b wins
        // 2) b loses
        // 3) tie
        if ((a == 'A' && b == 'X') ||
                (a == 'B' && b == 'Y') ||
                (a == 'C' && b == 'Z')) {
            return 3;
        } else if ((a == 'A' && b == 'Z') ||
                (a == 'B' && b == 'X') ||
                (a == 'C' && b == 'Y')) {
            return 2;
        } else {
            return 1;
        }
    }

    private static int get_score(char a, char b) {
        int res = 0;
        if (b == 'X') {
            res += 1;
        } else if (b == 'Y') {
            res += 2;
        } else {
            res += 3;
        }
        int game_res = get_res(a, b);
        if (game_res == 3) {
            res += 3;
        } else if (game_res == 2) {
            res += 0;
        } else {
            res += 6;
        }
        return res;
    }
}
