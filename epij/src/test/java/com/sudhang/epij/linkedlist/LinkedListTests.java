package com.sudhang.epij.linkedlist;

import java.util.function.BooleanSupplier;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class LinkedListTests {

	@Test
	void canCreateList() {
		LinkedList<Integer>	l = new LinkedList<Integer>(76);
		
		l.append(46)
			.append(93)
			.append(1094)
			.append(-85)
			.append(45,26,77,20)
		;
		
		System.out.println(l);
		Assertions.assertNotNull(l.toString());
		Assertions.assertEquals(9, l.count());
	}
	
	
	@Test
	void mergeTwoSortedLists() {
		LinkedList<Integer> l1 = new LinkedList<Integer>(35)
				.append(45,58,76);
		LinkedList<Integer> l2 = new LinkedList<Integer>(37)
				.append(60,78,97);
		
		System.out.println("l1: " + l1);
		System.out.println("l2: " + l2);
		LinkedList<Integer> merged = LinkedListHelper.mergeTwoSortedLists(l1, l2);
		
		System.out.println("l3: " + merged);
		Assertions.assertTrue(isSortedAsc(merged));
	}
	
	
	@Test
	void getKthFromEnd() {
		LinkedList<Integer> l1 = new LinkedList<Integer>(25)
				.append(46,72,29,0,-83,94,5);
		
		
		Assertions.assertEquals(-83, LinkedListHelper.getKthFromEnd(l1, 3).data);
		Assertions.assertNull(LinkedListHelper.getKthFromEnd(l1, 50));
	}


	private boolean isSortedAsc(LinkedList<Integer> merged) {
		ListNode<Integer> p = merged.getHead();
		while(p.next != null) {
			if (p.data > p.next.data) {
				return false;
			}
			p = p.next;
		}
		return true;
	}
}
