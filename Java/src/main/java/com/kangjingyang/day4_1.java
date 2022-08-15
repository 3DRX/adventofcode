package com.kangjingyang;

import java.util.ArrayList;
import java.io.*;

public class day4_1 {

    static ArrayList<String> data;
    static int[] numbers;
    static ArrayList<GRID> Grids;

    public static void main(String[] args) {
        data = new ArrayList<String>();
        Grids = new ArrayList<GRID>();
        input();
        algo();
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
        // -------------------------
        // init numbers
        numbers = new int[data.get(0).length()];
        String[] temp = data.get(0).split(",");
        for (int i = 0; i < temp.length; i++) {
            numbers[i] = Integer.parseInt(temp[i]);
        }
        // init GRID
        int countLine = 1;
        GRID newGrid = new GRID();
        for (int i = 2; i < data.size(); i++) {
            int t = 0;
            for (String str_num : data.get(i).trim().split(" ")) {
                if (str_num == "") {
                    continue;
                }
                newGrid.grid[countLine - 1][t] = new NUM(Integer.parseInt(str_num));
                t++;
            }
            if (countLine == 5) {
                countLine = 1;
                Grids.add(newGrid);
                i++;
            } else {
                countLine++;
            }
        }
        // validation
        // for (GRID gd : Grids) {
        //     for (int i = 0; i < 5; i++) {
        //         for (int j = 0; j < 5; j++) {
        //             System.out.format("%2d ", gd.grid[i][j].value);
        //         }
        //         System.out.println();
        //     }
        //     System.out.println();
        // }
    }

    private static void algo() {
    }
}

public class NUM {
    int value;
    boolean isLit;

    public NUM(int value) {
        this.value = value;
        this.isLit = false;
    }
}

public class GRID {
    NUM[][] grid = new NUM[5][5];
}
