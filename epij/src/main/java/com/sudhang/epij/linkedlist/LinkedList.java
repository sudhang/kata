package com.sudhang.epij.linkedlist;

public class LinkedList<T> {
	ListNode<T> head;
	
	public LinkedList(T startVal) {
		this.head = new ListNode<T>(startVal);
	}
	
	public ListNode<T> getHead() {
		return head;
	}
	
	public LinkedList<T> append(T ... newVals) {
		ListNode<T> p = head;

		while (p.next != null) {
			p = p.next;
		}
		
		for (T val : newVals) {
			ListNode<T> newNode = new ListNode<T>(val);
			p.next = newNode;
			p = newNode;
		}
		
		return this;
	}
	
	public Integer count() {
		ListNode<T> p = head;
		Integer count = 0;
		while (p != null) {
			count++;
			p = p.next;			
		}
		return count;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		ListNode<T> p = head;
		
		while (p != null) {
			sb.append(p.data + ", ");
			p = p.next;
		}
		return sb.toString();
	}

	public void setHead(ListNode<T> next) {
		this.head = next;
	}

}
