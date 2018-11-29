package com.adventOfCode;

import java.awt.Point;

public class HexGridNavigator {
	public static int findFewestStepsToDestination(String commaDelimitedSteps) {
		String[] steps = commaDelimitedSteps.split(",");
		
		Point destination = new Point();
		
		
		for (String step : steps) {
			followStep(destination, step);
		}
		
		return findMinimumStepsToPoint(destination);
	}
	
	public static int findFewestStepsToFurthestPoint(String commaDelimitedSteps) {
		String[] steps = commaDelimitedSteps.split(",");
		
		Point destination = new Point();
		
		int minimumStepsToFurthestDistance = 0;
		
		
		for (String step : steps) {
			followStep(destination, step);
			
			int minimumStepsToCurrentLocation = findMinimumStepsToPoint(destination);
			
			if (minimumStepsToCurrentLocation > minimumStepsToFurthestDistance) {
				minimumStepsToFurthestDistance = minimumStepsToCurrentLocation;
			}
		}
		
		return minimumStepsToFurthestDistance;
	}

	private static void followStep(Point destination, String step) {
		/* In a hex grid, movements that include a E/W component move a "half step" north or south.
		 *  We'll reduce that complexity by considering pure N/S movement to be 2 steps
		 */
		if (step.contains("n")) {
			destination.y = step.contains("e") || step.contains("w") ? destination.y + 1 : destination.y + 2;
		} else if (step.contains("s")) {
			destination.y = step.contains("e") || step.contains("w") ? destination.y - 1 : destination.y - 2;
		}
		
		if (step.contains("e")) {
			destination.x++;
		} else if (step.contains("w")) {
			destination.x--;
		}
	}

	private static int findMinimumStepsToPoint(Point destination) {
		int stepCount = 0;
		
		Point location = new Point();
		while (!location.equals(destination)) {
			int northMovement = 0;
			int eastMovement = 0;
			
			if (location.x != destination.x) {
				eastMovement = destination.x > location.x ? 1 : -1;
				
				if (location.y == destination.y) {
					northMovement = 1;
				}
			}
			
			if (location.y != destination.y) {
				northMovement = findVerticalMovement(destination, location, eastMovement);
				
			}
			
			location.y = location.y + northMovement;
			location.x = location.x + eastMovement;
			
			stepCount++;
		}
		
		return stepCount;
	}

	private static int findVerticalMovement(Point destination, Point location, int eastMovement) {
		if (eastMovement == 0) {
			return destination.y > location.y ? 2 : -2;
		} 
		
		return destination.y > location.y ? 1 : -1;
		
	}
}
