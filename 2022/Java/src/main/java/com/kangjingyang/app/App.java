package com.kangjingyang.app;

import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileInputStream;

public class App {
    public static void main(String[] args) {
        String filename;
        if (args[0].equals("test")) {
            filename = "../test.io";
        } else {
            filename = "../input.io";
        }
        ArrayList<String> Lines = new ArrayList<String>();
        try {
            File input_file = new File(filename);
            InputStreamReader reader = new InputStreamReader(new FileInputStream(input_file));
            BufferedReader br = new BufferedReader(reader);
            String line = "";
            while (true) {
                line = br.readLine();
                if (line == null) {
                    break;
                }
                Lines.add(Lines.size(), line);
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        // --------------------------------
        // day1.phase1(Lines);
        // day1.phase2(Lines);
        // day2.phase1(Lines);
        // day2.phase2(Lines);
        // day3.phase1(Lines);
        // day3.phase2(Lines);
        // day4.phase1(Lines);
        day4.phase2(Lines);
    }
}
