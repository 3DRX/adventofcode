package com.kangjingyang.app.utils;

import java.util.ArrayList;

public class TreeNode {
    private int size;
    private ArrayList<TreeNode> subDirs;

    public TreeNode() {
        this.size = 0;
        this.subDirs = new ArrayList<TreeNode>();
    }

    public void addSubDir() {
        TreeNode newNode = new TreeNode();
        this.subDirs.add(newNode);
    }

    public void addSize(int fileSize) {
        this.size += fileSize;
    }

    public int getSize() {
        return size;
    }

    public ArrayList<TreeNode> getSubDirs() {
        return subDirs;
    }
}
