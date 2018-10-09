package com.adventOfCode;

import java.util.ArrayList;
import java.util.Arrays;

public class PassphraseValidator {
	private PassphraseValidator() {
	}
	
	public static boolean basicValidate(String passphrase) {
		String[] phraseParts = passphrase.split(" ");
		
		ArrayList<String> foundParts = new ArrayList<>();
		
		for(String phrasePart : phraseParts) {
			if (foundParts.contains(phrasePart)) {
				return false;
			}
			
			foundParts.add(phrasePart);
		}
		
		return true;
	}
	
	public static boolean complexValidate(String passphrase) {
		String[] phraseParts = passphrase.split(" ");
		
		ArrayList<String> foundParts = new ArrayList<>();
		
		for(String phrasePart : phraseParts) {
			for(String foundPart : foundParts) {
				char[] phrasePartAsArray = phrasePart.toCharArray();
				char[] foundPartAsArray = foundPart.toCharArray();
				
				Arrays.sort(phrasePartAsArray);
				Arrays.sort(foundPartAsArray);
				
				if (Arrays.equals(phrasePartAsArray, foundPartAsArray)) {
					return false;
				}
			}
			
			foundParts.add(phrasePart);
		}
		
		return true;
	}
}
