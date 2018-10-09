package com.adventOfCode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InverseCaptchaTest {

    @Test
    void calculateInverseCaptcha_pairsOfRepeatingDigits() {
        // act
        int result = InverseCaptcha.calculateInverseCaptcha("1122");

        // assert
        assertEquals(3, result);
    }

    @Test
    void calculateInverseCaptcha_allRepeatingDigits(){
        // act
        int result = InverseCaptcha.calculateInverseCaptcha("1111");

        // assert
        assertEquals(4, result);
    }

    @Test
    void calculateInverseCaptcha_noRepeatingDigits(){
        // act
        int result = InverseCaptcha.calculateInverseCaptcha("1234");

        // assert
        assertEquals(0, result);
    }

    @Test
    void calculateInverseCaptcha_repeatingDigitAtEnd(){
        // act
        int result = InverseCaptcha.calculateInverseCaptcha("91212129");

        // assert
        assertEquals(9, result);
    }

    @Test
    void calculateInverseCaptchaPartTwo_pairsOfRepeatingDigits(){
        // act
        int result = InverseCaptcha.calculateInverseCaptchaPartTwo("1212");

        // assert
        assertEquals(6, result);
    }

    @Test
    void calculateInverseCaptchaPartTwo_noRepeatingDigits(){
        // act
        int result = InverseCaptcha.calculateInverseCaptchaPartTwo("1221");

        // assert
        assertEquals(0, result);
    }

    @Test
    void calculateInverseCaptchaPartTwo_singleRepeatingSet(){
        // act
        int result = InverseCaptcha.calculateInverseCaptchaPartTwo("123425");

        // assert
        assertEquals(4, result);
    }

    @Test
    void calculateInverseCaptchaPartTwo_trioOfRepeatingDigits(){
        // act
        int result = InverseCaptcha.calculateInverseCaptchaPartTwo("123123");

        // assert
        assertEquals(12, result);
    }

    @Test
    void calculateInverseCaptchaPartTwo_oneDigitRepeatedFourTimes(){
        // act
        int result = InverseCaptcha.calculateInverseCaptchaPartTwo("12131415");

        // assert
        assertEquals(4, result);
    }
}