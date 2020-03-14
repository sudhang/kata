package com.sudhang.epij.linkedlist;

import java.util.Comparator;

public class LinkedListHelper {

	public static <T> LinkedList<T> mergeTwoSortedLists(LinkedList<T> l1, LinkedList<T> l2, Comparator<T> comp) {
		
		LinkedList<T> l3 = new LinkedList<T>(null);  // dummy init value
		ListNode<T> p = l3.getHead();
		
		ListNode<T> p1 = l1.getHead();
		ListNode<T> p2 = l2.getHead();
		
		while (p1 != null && p2 != null) {
			if (comp.compare(p1.data, p2.data) < 0) {
				p.next = p1;
				p1 = p1.next;
			} else {
				p.next = p2;
				p2 = p2.next;
			}
			p = p.next;
		}
		
		p.next = p1 != null ? p1 : p2;
		
		l3.setHead(l3.getHead().next);
		return l3;
		
	}
}
