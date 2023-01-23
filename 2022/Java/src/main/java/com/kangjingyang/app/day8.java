package com.kangjingyang.app;

import java.util.ArrayList;

public class day8 {
    public void phase1(ArrayList<String> Lines) {
        ArrayList<ArrayList<Boolean>> visited = new ArrayList<>();
        int verticalLength = Lines.size();
        int horizontalLength = Lines.get(0).length();
        for (int i = 0; i < verticalLength; i++) {
            ArrayList<Boolean> oneLine = new ArrayList<>();
            for (int j = 0; j < horizontalLength; j++) {
                oneLine.add(false);
            }
            visited.set(i, oneLine);
        }
    }

    public void phase2(ArrayList<String> Lines) {
    }
}
