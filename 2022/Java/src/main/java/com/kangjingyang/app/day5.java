package com.kangjingyang.app;

import java.util.ArrayList;
import java.util.Stack;

public class day5 {
    private static ArrayList<ArrayList<Character>> crates = new ArrayList<ArrayList<Character>>();
    private static boolean start_command = false;

    public void phase1(ArrayList<String> Lines) {
        ArrayList<String> head = new ArrayList<String>();
        for (String line : Lines) {
            if (start_command == false) {
                if (line.equals("")) {
                    start_command = true;
                    processHead(head);
                } else {
                    head.add(line);
                }
            } else {
                String[] iptArray = line.split(" ");
                int x = Integer.parseInt(iptArray[1]);
                int from = Integer.parseInt(iptArray[3]) - 1;
                int to = Integer.parseInt(iptArray[5]) - 1;
                for (int i = 0; i < x; i++) {
                    Character temp = crates.get(from).get(crates.get(from).size() - 1);
                    crates.get(to).add(temp);
                    crates.get(from).remove(crates.get(from).size() - 1);
                }
            }
        }
        for (ArrayList<Character> row : crates) {
            System.out.print(row.get(row.size() - 1));
        }
        System.out.println();
    }

    public void phase2(ArrayList<String> Lines) {
        ArrayList<String> head = new ArrayList<String>();
        for (String line : Lines) {
            if (start_command == false) {
                if (line.equals("")) {
                    start_command = true;
                    processHead(head);
                } else {
                    head.add(line);
                }
            } else {
                String[] iptArray = line.split(" ");
                int x = Integer.parseInt(iptArray[1]);
                int from = Integer.parseInt(iptArray[3]) - 1;
                int to = Integer.parseInt(iptArray[5]) - 1;
                Stack<Character> S = new Stack<Character>();
                for (int i = 0; i < x; i++) {
                    Character temp = crates.get(from).get(crates.get(from).size() - 1);
                    crates.get(from).remove(crates.get(from).size() - 1);
                    S.push(temp);
                }
                for (int i = 0; i < x; i++) {
                    crates.get(to).add(S.pop());
                }
            }
        }
        for (ArrayList<Character> row : crates) {
            System.out.print(row.get(row.size() - 1));
        }
        System.out.println();
    }

    private void processHead(ArrayList<String> head) {
        String lastLine = head.get(head.size() - 1);
        head.remove(head.size() - 1);
        for (int i = 0; i < lastLine.length(); i++) {
            char c = lastLine.toCharArray()[i];
            if (c == ' ') {
                continue;
            } else {
                ArrayList<Character> row = new ArrayList<Character>();
                int k = head.size() - 1;
                char theChar = ' ';
                while (k >= 0) {
                    theChar = head.get(k).toCharArray()[i];
                    if (theChar == ' ') {
                        break;
                    }
                    row.add(theChar);
                    k--;
                }
                crates.add(row);
            }
        }
    }
}
