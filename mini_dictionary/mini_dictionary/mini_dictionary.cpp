#include "stdafx.h"
#include "mini_dictionary.h"

using namespace std;
using namespace boost;

static const string EXIT_DICTIONARY = "...";

bool IsEmptyFile(ifstream & file)
{
	return file.peek() == ifstream::traits_type::eof();
}

Dictionary GetDictionaryFromFile(string const&dictionaryFileName)
{
	Dictionary dictionary;
	ifstream dictionaryFile(dictionaryFileName);
	if (dictionaryFile.is_open() && !IsEmptyFile(dictionaryFile))
	{
		string buffer;
		while (getline(dictionaryFile, buffer))
		{
			vector<string> translation;
			boost::split(translation, buffer, boost::is_any_of("|"));
			dictionary.emplace(translation[0], translation[1]);
		}
	}
	else
	{
		std::cout << "Dictionary could not be opened and it will work with an empty dictionary\n";
	}
	return dictionary;
}

bool ProcessingNewWords(string &newWord, Dictionary &dictionary)
{
	cout << ">";
	string translationNewWord;
	getline(cin, translationNewWord);
	bool dictionaryHasChanged = false;
	if (!translationNewWord.empty())
	{
		dictionary.emplace(newWord, translationNewWord);
		dictionaryHasChanged = true;
		cout << "Слово " << newWord << " сохранено в словаре как " << translationNewWord << ".\n";
	}
	else
	{
		cout << "Слово " << newWord << " проигнорировано.\n";
	}
	return dictionaryHasChanged;
}

boost::optional<string> FindTranslation(string inputWord, Dictionary &dictionary)
{
	boost::optional<string> findWord;
	to_lower(inputWord);
	auto iterator = dictionary.find(inputWord);
	if (iterator != dictionary.end())
	{
		findWord = iterator->second;
	}
	return findWord;
}

std::string GetString(pair<std::string, std::string> translation)
{
	return  translation.first + "|" + translation.second;
}


void SaveChangesToFile(Dictionary const& dictionary, string const& dictionaryFileName)
{
	ofstream dictionaryFile(dictionaryFileName);

	std::transform(dictionary.begin(), dictionary.end(), std::ostream_iterator<std::string>(dictionaryFile, "\n"), GetString);
}

void StartTranslation(Dictionary &dictionary, string const&dictionaryFileName)
{
	string inputWord;
	string translatedWord;
	cout << ">";
	bool dictionaryHasChanged = false;
	while (getline(cin, inputWord) && (inputWord != EXIT_DICTIONARY))
	{
		if (!inputWord.empty())
		{
			auto translatedWord = FindTranslation(inputWord, dictionary);
			if (translatedWord)
			{
				cout << *translatedWord << "\n";
			}
			else
			{
				cout << "Неизвестное слово " << inputWord << ". Введите перевод или пустую строку для отказа.\n";
				dictionaryHasChanged = ProcessingNewWords(inputWord, dictionary);
			}
			cout << ">";
		}
		else
		{
			cout << ">";
		}
	}
	if (dictionaryHasChanged)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
		char save;
		cin >> save;
		save = tolower(save);
		if (save == 'y')
		{
			SaveChangesToFile(dictionary, dictionaryFileName);
			cout << "Изменения сохранены. До свидания." << endl;
		}
	}
}
