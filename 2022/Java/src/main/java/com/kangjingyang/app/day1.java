package com.kangjingyang.app;

import java.util.ArrayList;

public class day1 {
    public void phase1(ArrayList<String> Lines) {
        int res = 0;
        int current_elf = 0;
        for (String line : Lines) {
            if (line.equals("")) {
                if (res < current_elf) {
                    res = current_elf;
                }
                current_elf = 0;
            } else {
                int current_line = Integer.parseInt(line);
                current_elf += current_line;
            }
        }
        System.out.println(res);
    }

    public void phase2(ArrayList<String> Lines) {
        int[] res = new int[3];
        int current_elf = 0;
        for (String line : Lines) {
            if (line.equals("")) {
                if (res[0] < current_elf && res[1] >= current_elf) {
                    res[0] = current_elf;
                } else if (res[1] < current_elf && res[2] >= current_elf) {
                    res[0] = res[1];
                    res[1] = current_elf;
                } else if (res[2] < current_elf) {
                    res[0] = res[1];
                    res[1] = res[2];
                    res[2] = current_elf;
                }
                current_elf = 0;
            } else {
                int current_line = Integer.parseInt(line);
                current_elf += current_line;
            }
        }
        System.out.println(res[0] + res[1] + res[2]);
    }
}
