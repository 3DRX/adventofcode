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
        int ans = algo();
        System.out.println("the ans is");
        System.out.println(ans);
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
        // for (int i = 0; i < 5; i++) {
        // for (int j = 0; j < 5; j++) {
        // System.out.format("%2d ", gd.grid[i][j].value);
        // }
        // System.out.println();
        // }
        // System.out.println();
        // }
    }

    private static int algo() {
        int ans = 0;
        for (int number : numbers) {
            checkOutGrids(number);
            int temp = checkBingo();
            if (temp == -1) {
                continue;
            } else {
                ans = calScore(temp, number);
                break;
            }
        }
        return ans;
    }

    private static void checkOutGrids(int target) {
        for (GRID grd : Grids) {
            grd.checkOut(target);
        }
    }

    private static int checkBingo() {
        int rtn = -1;
        for (GRID grd : Grids) {
            int temp = grd.checkBingo();
            if (temp == -1) {
                continue;
            } else {
                rtn = temp;
            }
        }
        return rtn;
    }

    private static int calScore(int index, int num_just_called) {
        int ans = Grids.get(index).sum_unmarked_nums();
        System.out.format("Sum: %d\n", ans);
        ans *= num_just_called;
        return ans;
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

    public void checkOut(int target) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this.grid[i][j].value == target) {
                    this.grid[i][j].isLit = true;
                }
            }
        }
    }

    public int checkBingo() {
        int ret = -1;
        for (int i = 0; i < 5; i++) {
            if (this.grid[i][0].isLit &&
                    this.grid[i][1].isLit &&
                    this.grid[i][2].isLit &&
                    this.grid[i][3].isLit &&
                    this.grid[i][4].isLit) {
                ret = i;
            } else if (this.grid[0][i].isLit &&
                    this.grid[1][i].isLit &&
                    this.grid[2][i].isLit &&
                    this.grid[3][i].isLit &&
                    this.grid[4][i].isLit) {
                ret = i;
            }
        }
        return ret;
    }

    public int sum_unmarked_nums() {
        int res = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this.grid[i][j].isLit == false) {
                    res += this.grid[i][j].value;
                }
            }
        }
        return res;
    }
}
