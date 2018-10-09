package com.adventOfCode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PassphraseValidatorTests {
	@Test
	void PassphraseValidator_BasicValidate_SimpleValid() {
		// act
		boolean result = PassphraseValidator.basicValidate("aa bb cc dd ee");
		
		// assert
		assertTrue(result);
	}
	
	@Test
	void PassphraseValidator_BasicValidate_SimpleInvalid() {
		// act
		boolean result = PassphraseValidator.basicValidate("aa bb cc dd aa");
		
		// assert
		assertFalse(result);
	}
	
	@Test
	void PassphraseValidator_BasicValidate_AlmostInvalid() {
		// act
		boolean result = PassphraseValidator.basicValidate("aa bb cc dd aaa");
		
		// assert
		assertTrue(result);
	}
	
	@Test
	void PassphraseValidator_CompexValidate_Valid() {
		// act
		boolean result = PassphraseValidator.complexValidate("abcde fghij");
		
		// assert
		assertTrue(result);
	}
	
	@Test
	void PassphraseValidator_CompexValidate_SingleAnagramInvalid() {
		// act
		boolean result = PassphraseValidator.complexValidate("abcde xyz ecdab");
		
		// assert
		assertFalse(result);
	}
	
	@Test
	void PassphraseValidator_CompexValidate_ValidWhenLengthsDifferent() {
		// act
		boolean result = PassphraseValidator.complexValidate("a ab abc abd abf abj");
		
		// assert
		assertTrue(result);
	}
	
	@Test
	void PassphraseValidator_CompexValidate_ValidOnlyTwoCharacters() {
		// act
		boolean result = PassphraseValidator.complexValidate("iiii oiii ooii oooi oooo");
		
		// assert
		assertTrue(result);
	}
	
	@Test
	void PassphraseValidator_CompexValidate_AllAnagramsInvalid() {
		// act
		boolean result = PassphraseValidator.complexValidate("oiii ioii iioi iiio");
		
		// assert
		assertFalse(result);
	}
}
