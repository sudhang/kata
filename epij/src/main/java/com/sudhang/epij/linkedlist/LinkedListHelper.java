package com.sudhang.epij.linkedlist;

public class LinkedListHelper {

	static LinkedList<Integer> mergeTwoSortedLists(LinkedList<Integer> l1, LinkedList<Integer> l2) {
		
		LinkedList<Integer> l3 = new LinkedList<Integer>(null);  // dummy init value
		ListNode<Integer> p = l3.getHead();
		
		ListNode<Integer> p1 = l1.getHead();
		ListNode<Integer> p2 = l2.getHead();
		
		while (p1 != null && p2 != null) {
			if (p1.data < p2.data) {
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

	public static ListNode<Integer> getKthFromEnd(LinkedList<Integer> l, int k) {
		ListNode<Integer> fast = l.getHead();
		ListNode<Integer> slow = l.getHead();
		
		int i = 1;
		while (fast != null) {
			if (i > k) {
				slow = slow.next;
			}
			fast = fast.next;
			i++;
		}
		if (i < k) {
			return null;
		}
		return slow;
	}
}
