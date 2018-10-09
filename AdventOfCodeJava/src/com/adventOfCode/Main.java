package com.adventOfCode;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        solveDayOne();
        solveDayTwo();
        solveDayFour();
    }

    private static void solveDayOne(){
        System.out.println("Day One");
        System.out.println(InverseCaptcha.calculateInverseCaptcha(Inputs.DAY_ONE));
        System.out.println(InverseCaptcha.calculateInverseCaptchaPartTwo(Inputs.DAY_ONE));
    }

    private static void solveDayTwo(){
        String[] dayTwoRows = Inputs.DAY_TWO.split("\n");

        int[][] parsedDayTwoInput = new int[dayTwoRows.length][];
        for(int i = 0; i < dayTwoRows.length; i++){
            String[] splitRow = dayTwoRows[i].trim().split("\\s+");
            parsedDayTwoInput[i] = Arrays.stream(splitRow).mapToInt(Integer::parseInt).toArray();
        }

        System.out.println("Day Two");
        System.out.println(SpreadsheetAnalyser.calculateChecksum(parsedDayTwoInput));
        System.out.println(SpreadsheetAnalyser.sumEvenlyDivisbleValues(parsedDayTwoInput));
    }
    
    private static void solveDayFour() {
    	String[] dayFourRows = Inputs.DAY_FOUR.split("\n");
    	
    	int validSimple = 0;
    	int validComplex = 0;
    	
    	for (String dayFourRow : dayFourRows) {
    		if (PassphraseValidator.basicValidate(dayFourRow)) {
    			validSimple++;
    		}
    		if (PassphraseValidator.complexValidate(dayFourRow)) {
    			validComplex++;
    		}
    	}
    	
        System.out.println("Day Four");
        System.out.println(validSimple);
        System.out.println(validComplex);
    }
}
