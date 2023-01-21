package com.kangjingyang.app;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

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
        day7 solution = new day7();
        solution.phase2(Lines);
    }
}
