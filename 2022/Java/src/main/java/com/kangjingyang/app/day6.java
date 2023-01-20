package com.kangjingyang.app;

import java.util.ArrayList;
import java.util.Queue;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedList;

public class day6 {
    private Queue<Character> Q = new LinkedList<Character>();

    public void phase1(ArrayList<String> Lines) {
        int i = 0;
        for (char C : Lines.get(0).toCharArray()) {
            i++;
            Q.add(C);
            if (Q.size() < 4) {
                continue;
            } else {
                if (Q.size() > 4) {
                    Q.remove();
                }
                if (isQValid(4)) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }

    public void phase2(ArrayList<String> Lines) {
        int i = 0;
        for (char C : Lines.get(0).toCharArray()) {
            i++;
            Q.add(C);
            if (Q.size() < 14) {
                continue;
            } else {
                if (Q.size() > 14) {
                    Q.remove();
                }
                if (isQValid(14)) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }

    private boolean isQValid(int stringSize) {
        if (Q.size() != stringSize) {
            return false;
        }
        Set<Character> S = new HashSet<>();
        for (char C : Q) {
            S.add(C);
        }
        return S.size() == Q.size();
    }
}
