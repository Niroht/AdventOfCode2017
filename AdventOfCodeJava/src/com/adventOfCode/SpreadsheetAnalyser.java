package com.adventOfCode;

public class SpreadsheetAnalyser {
	private SpreadsheetAnalyser() {
	}
	
    public static int calculateChecksum(int[][] input){
        int sum = 0;

        for (int[] row : input) {
            int largestNumber = 0;
            int smallestNumber = 0;

            for (int column : row){
                if (column > largestNumber){
                    largestNumber = column;
                }
                if (smallestNumber == 0 || column < smallestNumber){
                    smallestNumber = column;
                }
            }

            sum += largestNumber - smallestNumber;
        }
        
        return sum;
    }

    public static int sumEvenlyDivisbleValues(int[][] input){
        int sum = 0;

        for (int[] row : input) {
            boolean foundEvenlyDivisbleValue = false;

            for (int column = 0; column < row.length; column++){
                for (int i = 0; i < row.length; i++){
                    if (i != column && row[column] % row[i] == 0){
                        sum += row[column] / row[i];
                        foundEvenlyDivisbleValue = true;
                    }

                    if (foundEvenlyDivisbleValue) break;
                }

                if (foundEvenlyDivisbleValue) break;
            }
        }

        return sum;
    }
}
