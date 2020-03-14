package com.sudhang.epij.linkedlist;

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
		LinkedList<Integer> merged = LinkedListHelper.mergeTwoSortedLists(l1, l2, ((o1, o2) -> o1.compareTo(o2)));
		
		System.out.println("l3: " + merged);
		Assertions.assertTrue(merged.isSorted(merged, ((o1, o2) -> o1.compareTo(o2)) ));
	}
	
	
	@Test
	void getKthFromEnd() {
		LinkedList<Integer> l1 = new LinkedList<Integer>(25)
				.append(46,72,29,0,-83,94,5);
		
		
		Assertions.assertEquals(-83, l1.getKthFromEnd(3).data);
		Assertions.assertNull(l1.getKthFromEnd(50));
	}

	@Test
	void detectsCyclesCorrectly() {
		// No cycle
		LinkedList<Integer> l1 = new LinkedList<Integer>(25)
				.append(45, 63, 62, -34, 6, 0, 14);
		Assertions.assertNull(l1.getStartOfCycle());
		System.out.println("l1:" + l1);
		
		// Cycle Present
		ListNode<Integer> cycleStart = l1.get(3);
		l1.append(cycleStart);
		ListNode<Integer> returnedCycleStart = l1.getStartOfCycle();
		System.out.println("returnedCycleStart: " + returnedCycleStart.data);
		Assertions.assertNotNull(returnedCycleStart);
		Assertions.assertEquals(cycleStart, returnedCycleStart);
		Assertions.assertEquals(62, returnedCycleStart.data);
	}
	
	@Test
	void reversingWorks() {
		LinkedList<Integer> l1 = new LinkedList<Integer>(23)
				.append(54,652,73,73);
		LinkedList<Integer> l2 = new LinkedList<Integer>(73)
				.append(73,652,54,23);
		
		Assertions.assertEquals(l2, l1.reverse());
	}

}
