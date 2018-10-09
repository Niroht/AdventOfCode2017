package com.adventOfCode;

public class InverseCaptcha {
	private InverseCaptcha() {
	}
	
    public static int calculateInverseCaptcha(String input){
        int sum = 0;

        for(int i = 0; i < input.length(); i++){
            int currentValueAsInt = Character.getNumericValue(input.charAt(i));
            int nextIndex = i == input.length() - 1 ? 0 : i + 1;
            int nextValueAsInt = Character.getNumericValue(input.charAt(nextIndex));

            if (currentValueAsInt == nextValueAsInt){
                sum += currentValueAsInt;
            }
        }

        return sum;
    }

    public static int calculateInverseCaptchaPartTwo(String input){
        int sum = 0;

        for(int i = 0; i < input.length(); i++){
            int currentValueAsInt = Character.getNumericValue(input.charAt(i));
            int desiredIndex = (i + input.length() / 2);
            int nextIndex = desiredIndex > input.length() - 1 ? desiredIndex - input.length() : desiredIndex;
            int nextValueAsInt = Character.getNumericValue(input.charAt(nextIndex));

            if (currentValueAsInt == nextValueAsInt){
                sum += currentValueAsInt;
            }
        }

        return sum;
    }
}
