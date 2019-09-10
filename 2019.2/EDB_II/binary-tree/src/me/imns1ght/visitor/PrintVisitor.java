package me.imns1ght.visitor;

import me.imns1ght.main.Node;

public class PrintVisitor implements NodeVisitor {

	@Override
	public void visit(Node node) {
		System.out.println(node.getValue());
	}
}
