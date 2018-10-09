#pragma once
#include <string>;

using namespace std;

class InverseCaptcha {
public:
	InverseCaptcha(void);
	int CalculateInverseCaptcha(string input);
	int CalculateInverseCaptchaPartTwo(string input);
};