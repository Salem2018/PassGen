#include <windows.h>
#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
	SetConsoleTitle("PassGen");

	unsigned short a, b;
	char c[] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	std::cout << "Number of passwords: ";
	std::cin >> a;

	std::cout << "Number of characters in the password: ";
	std::cin >> b;
	const unsigned short d = b;

	srand(time(0));
	std::ofstream outFile("PassGen.txt");

	for(a; a > 0; a--)
	{
		for(b; b > 0; b--)
		{
			outFile << c[rand() % 62 + 0];
		}

		if(b == 0)
		{
			outFile << std::endl;
			b = d;
		}
	}

	outFile << std::endl;
	outFile << "Maxim Goryachev [Salem]\nICQ: 740968157";
	outFile.close();

	ShellExecute(NULL, "open", "notepad.exe", "PassGen.txt", NULL, SW_SHOWNORMAL);
	return 0;
}