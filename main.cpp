#include <iostream>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

void generatePassword(std::string s, const std::string& alphabet, int len)
{
	if (len == 1)
	{
		for (int i = 0; i < alphabet.length(); i++)
		{
			std::cout << s + alphabet[i] << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < alphabet.length(); i++)
		{
			generatePassword(s + alphabet[i], alphabet, len-1);
		}
	}
}


int main()
{
	int len;
	#ifdef __EMSCRIPTEN__
    len = emscripten_run_script_int("prompt('Enter length (1-4):');");
	#else
		std::cout << "Enter length (1-4): ";
		std::cin >> len;
	#endif
	if (len > 4)
	{
		len = 4;
	}
	if (len < 1)
	{
		len = 1;
	}
	
	std::string str;
	#ifdef __EMSCRIPTEN__
    str = emscripten_run_script_string("prompt('Enter alphabet (ab, abc, abcd):');");
	#else
		std::cout << "Enter alphabet (ab, abc, abcd): ";
		std::cin >> str;
	#endif
	
	if (str.length() > 10)
	{
		str = str.substr(0, 10);
	}
	
	generatePassword("", str, len);
}