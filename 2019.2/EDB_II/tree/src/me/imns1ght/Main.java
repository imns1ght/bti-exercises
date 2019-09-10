package me.imns1ght;

public class Main {
	public static void main(String[] args) {
		Node root = new Node("Raiz");
		Node child = root.addChild("Filho 1");

		Node child2 = new Node("Filho 2");
		root.addChild(child2);

		child.addChild(new Node("Neto 1"));
	}
}
