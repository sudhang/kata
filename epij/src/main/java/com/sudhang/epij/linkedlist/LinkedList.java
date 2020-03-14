package com.sudhang.epij.linkedlist;

import java.util.Comparator;

public class LinkedList<T> {
	ListNode<T> head;
	
	public LinkedList(T startVal) {
		this.head = new ListNode<T>(startVal);
	}
	
	public ListNode<T> getHead() {
		return head;
	}
	
	private ListNode<T> getTail() {
		ListNode<T> p = head;
		while (p.next != null) {
			p = p.next;
		}
		return p;
	}

	public ListNode<T> get(int k) {
		ListNode<T> p = head;
		int i = 0;
		while (p != null && i < k) {
			p = p.next;
			i++;
		}
		return p;
	}

	public void append(ListNode<T> newNode) {
		ListNode<T> tail = this.getTail();
		tail.next = newNode;
	}

	public LinkedList<T> append(T ... newVals) {
		ListNode<T> tail = this.getTail();

		for (T val : newVals) {
			ListNode<T> newNode = new ListNode<T>(val);
			tail.next = newNode;
			tail = newNode;
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
	
	public LinkedList<T> reverse() {
		ListNode<T> prev = null;
		ListNode<T> curr = this.head;
		ListNode<T> next = null;
		
		while (curr != null) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}
		
		this.head = prev;
		
		return this;
	}
	
	public boolean isSorted(LinkedList<T> merged, Comparator<? super T> comp) {
		ListNode<T> p = merged.getHead();
		while(p.next != null) {
			if (comp.compare(p.data, p.next.data) > 0) {
				return false;
			}
			p = p.next;
		}
		return true;
	}

	public ListNode<T> getKthFromEnd(int k) {
		ListNode<T> fast = this.getHead();
		ListNode<T> slow = this.getHead();
		
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
	
	@Override
	public boolean equals(Object obj) {
		if (obj == this) {
			return true;
		}
		if (!(obj instanceof LinkedList<?>)) {
			return false;
		}
		
		ListNode<?> h1 = ((LinkedList<?>) obj).getHead();
		ListNode<T> h2 = this.getHead();
		
		while (h1  != null) {
			if (h2 == null) {
				return false;
			}
			if ( ! h1.data.equals(h2.data) ) {
				return false;
			}
			h1 = h1.next;
			h2 = h2.next;
		}
		if (h2 != null) {
			return false;
		}
			
		return true;
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

	public ListNode<T> getStartOfCycle() {
		ListNode<T> fast = this.getHead();
		ListNode<T> slow = this.getHead();

		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;

			if (slow == fast) {
				// there is a cycle!
				// note: but it is not necessarily *starting* at these nodes
				// maybe the 'meeting point' of the fast and slow nodes
				// is somewhere inside the cycle

				// calculate cycle length
				int cycLen = 0;
				do {
					cycLen++;
					fast = fast.next;
				} while (slow != fast);

				ListNode<T> fast2 = this.getHead();
				ListNode<T> slow2 = this.getHead();

				for (int i = 0; i < cycLen; i++) {
					fast2 = fast2.next;
				}
				
				while (slow2 != fast2) {
					slow2 = slow2.next;
					fast2 = fast2.next;
				}

				return slow2;
			}
		}
		return null;
	}

}
