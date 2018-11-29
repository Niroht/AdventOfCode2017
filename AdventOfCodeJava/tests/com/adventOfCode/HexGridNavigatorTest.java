package com.adventOfCode;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class HexGridNavigatorTest {
	@Test
	public void findFewestStepsToDestination_allSameDirection() {
		// arrange
		String input = "ne,ne,ne";
		
		// act
		int result = HexGridNavigator.findFewestStepsToDestination(input);
		
		// assert
		assertEquals(3, result);
	}
	
	@Test
	public void findFewestStepsToDestination_reversePathBackToOrigin() {
		// arrange
		String input = "ne,ne,sw,sw";
		
		// act
		int result = HexGridNavigator.findFewestStepsToDestination(input);
		
		// assert
		assertEquals(0, result);
	}

	
	@Test
	public void findFewestStepsToDestination_singleTurn() {
		// arrange
		String input = "ne,ne,s,s";
		
		// act
		int result = HexGridNavigator.findFewestStepsToDestination(input);
		
		// assert
		assertEquals(2, result);
	}
	
	@Test
	public void findFewestStepsToDestination_multipleTurns() {
		// arrange
		String input = "se,sw,se,sw,sw";
		
		// act
		int result = HexGridNavigator.findFewestStepsToDestination(input);
		
		// assert
		assertEquals(3, result);
	}
	
	@Test
	public void findFewestStepsToFurthestPoint_allSameDirection() {
		// arrange
		String input = "ne,ne,ne";
		
		// act
		int result = HexGridNavigator.findFewestStepsToFurthestPoint(input);
		
		// assert
		assertEquals(3, result);
	}
	
	@Test
	public void findFewestStepsToFurthestPoint_reversePathBackToOrigin() {
		// arrange
		String input = "ne,ne,sw,sw";
		
		// act
		int result = HexGridNavigator.findFewestStepsToFurthestPoint(input);
		
		// assert
		assertEquals(2, result);
	}
	
	@Test
	public void findFewestStepsToFurthestPoint_reversePathBackToLeftDown() {
		// arrange
		String input = "sw,sw,ne,ne";
		
		// act
		int result = HexGridNavigator.findFewestStepsToFurthestPoint(input);
		
		// assert
		assertEquals(2, result);
	}
	
	@Test
	public void findFewestStepsToFurthestPoint_singleTurn() {
		// arrange
		String input = "ne,ne,s,s";
		
		// act
		int result = HexGridNavigator.findFewestStepsToFurthestPoint(input);
		
		// assert
		assertEquals(2, result);
	}
	
	@Test
	public void findFewestStepsToFurthestPoint_multipleTurns() {
		// arrange
		String input = "sw,sw,sw,s,ne,ne,ne,s,s,s,s,s,se,n,n,n,n,";
		
		// act
		int result = HexGridNavigator.findFewestStepsToFurthestPoint(input);
		
		// assert
		assertEquals(7, result);
	}
}
