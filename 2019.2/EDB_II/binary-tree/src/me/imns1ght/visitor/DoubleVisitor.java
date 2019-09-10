package me.imns1ght.visitor;

import me.imns1ght.main.Node;

public class DoubleVisitor implements NodeVisitor {
	@Override
	public void visit(Node node) {
		node.setValue(node.getValue() * 2);
	}
}
