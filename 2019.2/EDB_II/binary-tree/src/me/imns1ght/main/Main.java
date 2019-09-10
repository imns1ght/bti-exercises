package me.imns1ght.main;

import me.imns1ght.visitor.*;

public class Main {
	public static void main(String[] args) {
		Node root = new Node(10);
		root.setLeft(new Node(5));
		root.setRight(new Node(30));
		root.setValue(20);
		PrintVisitor p = new PrintVisitor();
		DoubleVisitor d = new DoubleVisitor();
		SumVisitor s = new SumVisitor();

		root.accessInOrder(s);
		System.out.println("A soma dos nós é " + s.getSum());

		root.accessPreOrder(d);

		System.out.println("Pré-ordem");
		root.accessPreOrder(p);
		// 20 5 30
		System.out.println("Em-ordem");
		root.accessInOrder(p);
		// 5 20 30
		System.out.println("Pós-ordem");
		root.accessPostOrder(p);
		// 5 30 20
	}
}
