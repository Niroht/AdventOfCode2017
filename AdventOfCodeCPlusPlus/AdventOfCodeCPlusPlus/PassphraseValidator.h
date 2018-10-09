#pragma once

#include <string>;


using namespace std;

class PassphraseValidator
{
public:
	PassphraseValidator();
	
	bool BasicValidate(string input);

	bool ComplexValidate(string input);
};

