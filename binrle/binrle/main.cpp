#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PackFile(ifstream & inputFile, ofstream & outputFile)
{
	char ch;
	int countChar = 0;
	while (inputFile.read((char*)&ch, sizeof(char)))
	{
		++countChar;
		if ((ch != (char)inputFile.peek()) || (countChar == 255) || (inputFile.peek() == EOF))
		{
			outputFile.write((char*)&countChar, sizeof(char));
			outputFile.write(&ch, sizeof(char));
			countChar = 0;
		}
	}
}

void UnpackFile(ifstream & inputFile, ofstream & outputFile)
{
	char ch;
	unsigned char count;
	while (inputFile.read((char*)&count, sizeof(count)) && inputFile.read((char*)&ch, sizeof(char)))
	{
		for (int i = 0; i < count; ++i)
		{
			outputFile << ch;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: rle.exe pack <input file> <output file>\n";
		cout << "Or\n";
		cout << "Usage: rle.exe unpack <input file> <output file>\n";
		return 1;
	}

	ifstream inputFile(argv[2], ios::binary | ios::in);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	ofstream outputFile(argv[3], ios::binary | ios::out);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return 1;
	}

	string mode = argv[1];
	if (mode == "pack")
	{
		PackFile(inputFile, outputFile);
	}
	else if (mode == "unpack")
	{
		UnpackFile(inputFile, outputFile);
	}
	else
	{
		cout << "You have not correctly specified the parameter <unpack || pack>\n";
		return 1;
	}
	return 0;

}