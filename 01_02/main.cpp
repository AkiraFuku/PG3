#include <stdio.h>
#include<algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


std::vector<std::string>  ReadFile(const std::string& filename) {
	std::vector<std::string> lines;
	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return lines;
	}
	std::string line;
	while (std::getline(infile, line)) {
		std::string buf;
		for (char ch :line)
		{
			buf += ch;
			if (ch == ',') {
				lines.push_back(buf);
				buf.clear();
			}

		}
	}
	
	return lines;


}
void PrintAsciiCodes(const std::string& text) {
    for (char ch : text) {
        // 文字とASCIIコードを表示
        printf("'%c' : %d\n", ch, static_cast<int>(ch));
    }
}

void WriteVector(const std::vector<std::string>& vec) {
	for (const auto& str : vec) {
		std::cout << str << std::endl;
		//PrintAsciiCodes(str);


	}
}

std::vector<std::string> SortVector(std::vector<std::string>& vec) {
	
	std::sort(vec.begin(), vec.end());
	return vec;
}

int main() {
	
	std::vector<std::string> lines = ReadFile("PG3_2025_01_02.txt");
	WriteVector(lines);
	std::cout << "-----Sorted-----" << std::endl;
	lines= SortVector(lines);
	WriteVector(lines);

	return 0;
}