package com.kangjingyang.app;

import java.util.ArrayList;

public class BinaryTreeNode {
    private int data;
    private ArrayList<BinaryTreeNode> subDirs;
    private BinaryTreeNode parent;
    private boolean visited;

    BinaryTreeNode() {
        this.data = 0;
        this.subDirs = new ArrayList<BinaryTreeNode>();
        this.parent = null;
        this.visited = false;
    }

    public void addSubDir() {
        BinaryTreeNode newNode = new BinaryTreeNode();
        newNode.parent = this;
        this.subDirs.add(newNode);
    }

    public void addFile(int fileSize) {
        this.data += fileSize;
    }

    public BinaryTreeNode autoChangeDirectory() {
        for (BinaryTreeNode node : this.subDirs) {
            if (node.isVisited() == false) {
                node.setVisited(true);
                return node;
            }
        }
        return this.parent;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public ArrayList<BinaryTreeNode> getSubDirs() {
        return subDirs;
    }

    public void setSubDirs(ArrayList<BinaryTreeNode> subDirs) {
        this.subDirs = subDirs;
    }

    public BinaryTreeNode getParent() {
        return parent;
    }

    public void setParent(BinaryTreeNode parent) {
        this.parent = parent;
    }

    public boolean isVisited() {
        return visited;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }
}

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
    }

    public void phase2(ArrayList<String> Lines) {
    }
}
