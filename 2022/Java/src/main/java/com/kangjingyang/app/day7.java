package com.kangjingyang.app;

import com.kangjingyang.app.utils.BinaryTreeNode;

import java.util.ArrayList;

public class day7 {

    public void phase1(ArrayList<String> Lines) {
        BinaryTreeNode treeRoot = new BinaryTreeNode();
        BinaryTreeNode workingNode = treeRoot;
        for (String line : Lines) {
            String[] parsed = line.split(" ");
            if (parsed[0].equals("$")) {
                if (parsed[1].equals("cd")) {
                    continue;
                } else if (parsed[1].equals("ls")) {
                    workingNode = workingNode.autoChangeDirectory();
                }
            } else {
                if (parsed[0].equals("dir")) {
                    workingNode.addSubDir();
                } else {
                    int dirSize = Integer.parseInt(parsed[0]);
                    workingNode.addFile(dirSize);
                }
            }
        }
        dfs(treeRoot);
    }

    public void phase2(ArrayList<String> Lines) {
    }

    private void dfs(BinaryTreeNode root) {
        System.out.println(root.getData());
        for (BinaryTreeNode sub : root.getSubDirs()) {
            dfs(sub);
        }
    }
}
