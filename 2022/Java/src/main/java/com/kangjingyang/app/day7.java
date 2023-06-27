package com.kangjingyang.app;

import com.kangjingyang.app.utils.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class day7 {
    private TreeNode treeRoot = new TreeNode();
    private int readIndex = 0;
    private int ans = 0;

    public void phase1(ArrayList<String> Lines) {
        generateTree(Lines, this.treeRoot);
        dfsGetAns(this.treeRoot);
        System.out.println(ans);
    }

    public void phase2(ArrayList<String> Lines) {
        generateTree(Lines, this.treeRoot);
        bfsGetAns();
        System.out.println(ans);
    }

    private void generateTree(ArrayList<String> Lines, TreeNode workingNode) {
        while (true) {
            if (Lines.size() == readIndex) {
                return;
            }
            String line = Lines.get(readIndex);
            readIndex++;
            String[] parsed = line.split(" ");
            if (parsed[0].equals("$")) {
                if (parsed[1].equals("cd") && !parsed[2].equals("..") && !parsed[2].equals("/")) {
                    break;
                } else {
                    continue;
                }
            } else {
                if (parsed[0].equals("dir")) {
                    workingNode.addSubDir();
                } else {
                    workingNode.addSize(Integer.parseInt(parsed[0]));
                }
            }
        }
        for (int i = 0; i < workingNode.getSubDirs().size(); i++) {
            generateTree(Lines, workingNode.getSubDirs().get(i));
            workingNode.addSize(workingNode.getSubDirs().get(i).getSize());
        }
    }

    private void dfsGetAns(TreeNode root) {
        if (root.getSize() <= 100000) {
            this.ans += root.getSize();
        }
        for (TreeNode sub : root.getSubDirs()) {
            dfsGetAns(sub);
        }
    }

    private void bfsGetAns() {
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        Q.add(this.treeRoot);
        this.ans = this.treeRoot.getSize();
        int spaceToFree = this.ans - 40000000;
        while (Q.isEmpty() == false) {
            TreeNode temp = Q.remove();
            for (TreeNode sub : temp.getSubDirs()) {
                Q.add(sub);
            }
            if (temp.getSize() < this.ans && temp.getSize() >= spaceToFree) {
                this.ans = temp.getSize();
            }
        }
    }
}
