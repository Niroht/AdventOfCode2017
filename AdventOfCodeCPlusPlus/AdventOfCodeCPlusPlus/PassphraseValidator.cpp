#include <vector>;
#include <sstream>;
#include <iterator>;
#include <string>;
#include <algorithm>;

#include "PassphraseValidator.h"

PassphraseValidator::PassphraseValidator()
{
}

bool PassphraseValidator::BasicValidate(string input)
{
	istringstream inputStream(input);
	vector<string> passphrasePieces((istream_iterator<string>(inputStream)), istream_iterator<string>());

	vector<string> foundPieces;

	for each (string passphrasePiece in passphrasePieces)
	{
		if (foundPieces.size() == 0) 
		{
			foundPieces.push_back(passphrasePiece);
			continue;
		}

		for each (string foundPiece in foundPieces)
		{
			if (passphrasePiece == foundPiece) 
			{
				return false;
			}
		}

		foundPieces.push_back(passphrasePiece);
	}

	return true;
}

bool PassphraseValidator::ComplexValidate(string input)
{
	istringstream inputStream(input);
	vector<string> passphrasePieces((istream_iterator<string>(inputStream)), istream_iterator<string>());

	vector<string> foundPieces;

	for each (string passphrasePiece in passphrasePieces)
	{
		if (foundPieces.size() == 0)
		{
			foundPieces.push_back(passphrasePiece);
			continue;
		}

		for each (string foundPiece in foundPieces)
		{
			if (passphrasePiece == foundPiece)
			{
				return false;
			}

			bool isAnagram = true;
			if (passphrasePiece.length() == foundPiece.length())
			{
				string copiedPassphrasePiece = passphrasePiece;
				string copiedFoundPiece = foundPiece;

				sort(copiedPassphrasePiece.begin(), copiedPassphrasePiece.end());
				sort(copiedFoundPiece.begin(), copiedFoundPiece.end());

				if (copiedPassphrasePiece == copiedFoundPiece) 
				{
					return false;
				}
			}
		}

		foundPieces.push_back(passphrasePiece);
	}

	return true;
}
