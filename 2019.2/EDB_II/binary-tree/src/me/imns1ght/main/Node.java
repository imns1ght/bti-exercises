package me.imns1ght.main;

import me.imns1ght.visitor.*;

public class Node {
	private int value;
	private Node left;
	private Node right;

	public Node(int value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}

	public void setLeft(Node node) {
		this.left = node;
	}

	public void setRight(Node node) {
		this.right = node;
	}

	public void setValue(int value) {
		this.value = value;
	}

	// (Root, Left, Right)
	public void accessPreOrder(NodeVisitor v) {
		v.visit(this);

		if (this.left != null) {

			this.left.accessPreOrder(v);
		}

		if (this.right != null) {
			this.right.accessPreOrder(v);
		}
	}

	// (Left, Root, Right) 
	public void accessInOrder(NodeVisitor v) {
		if (this.left != null) {
			this.left.accessInOrder(v);
		}

		v.visit(this);

		if (this.right != null) {
			this.right.accessInOrder(v);
		}
	}

	// (Left, Right, Root)
	public void accessPostOrder(NodeVisitor v) {
		if (this.left != null) {
			this.left.accessPostOrder(v);
		}

		if (this.right != null) {
			this.right.accessPostOrder(v);
		}

		v.visit(this);
	}

	public int getValue() {
		return value;
	}
}

