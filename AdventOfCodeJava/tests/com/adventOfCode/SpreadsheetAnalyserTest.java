package com.adventOfCode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SpreadsheetAnalyserTest {
    @Test
    void calculateChecksum_calculates(){
        // arrange
        int[][] input = new int[][]{
                new int[] { 5, 1, 9, 5},
                new int[] { 7, 5, 3},
                new int[] { 2, 4, 6, 8}
        };

        // act
        int result = SpreadsheetAnalyser.calculateChecksum(input);

        // assert
        assertEquals(18, result);
    }

    @Test
    void sumEvenlyDivisbleValues_sums(){
        // arrange
        int[][] input = new int[][]{
                new int[] { 5, 9, 2, 8},
                new int[] { 9, 4, 7, 3},
                new int[] { 3, 8, 6, 5}
        };

        // act
        int result = SpreadsheetAnalyser.sumEvenlyDivisbleValues(input);

        // assert
        assertEquals(9, result);
    }
}