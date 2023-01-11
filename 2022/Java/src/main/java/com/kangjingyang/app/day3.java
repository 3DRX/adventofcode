package com.kangjingyang.app;

import java.util.ArrayList;
import java.util.HashSet;

public class day3 {
    public void phase1(ArrayList<String> Lines) {
        int priority_sum = 0;
        for (String line : Lines) {
            String first = line.substring(0, line.length() / 2);
            String second = line.substring(line.length() / 2, line.length());
            priority_sum += get_priority(first, second);
        }
        System.out.println(priority_sum);
    }

    public void phase2(ArrayList<String> Lines) {
        int i = 0;
        HashSet<Character> Set1 = new HashSet<Character>();
        HashSet<Character> Set2 = new HashSet<Character>();
        int res = 0;
        for (String line : Lines) {
            if (i == 0) {
                i++;
                for (char a : line.toCharArray()) {
                    Set1.add(a);
                }
            } else if (i == 1) {
                i++;
                for (char b : line.toCharArray()) {
                    Set2.add(b);
                }
            } else {
                i = 0;
                for (char c : line.toCharArray()) {
                    if (Set1.contains(c) && Set2.contains(c)) {
                        if (c >= 'a' && c <= 'z') {
                            res += c - 'a' + 1;
                        } else {
                            res += c - 'A' + 27;
                        }
                        Set1.clear();
                        Set2.clear();
                        break;
                    }
                }
            }
        }
        System.out.println(res);
    }

    private int get_priority(String first, String second) {
        int res = 0;
        HashSet<Character> Set = new HashSet<Character>();
        char r = '\0';
        for (char a : first.toCharArray()) {
            Set.add(a);
        }
        for (char b : second.toCharArray()) {
            if (Set.contains(b)) {
                r = b;
                break;
            }
        }
        if (r == '\0') {
            throw new ArithmeticException("no same char in both String");
        }
        if (r >= 'a' && r <= 'z') {
            res = r - 'a' + 1;
        } else {
            res = r - 'A' + 27;
        }
        return res;
    }
}
