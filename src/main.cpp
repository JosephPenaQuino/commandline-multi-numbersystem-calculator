#include <bitset>
#include <iostream>
#include <sstream>
#include <string>

unsigned
applyOperator(std::string op, unsigned v1, unsigned v2) {
	if (op == "+")
		return v1 + v2;
	if (op == "-")
		return v1 - v2;
	if (op == "|")
		return v1 | v2;
	if (op == "&")
		return v1 & v2;
	else
		throw "Invalid operator";
}

unsigned
fromBin2Dec(std::string binNumber) {
	return stoi(binNumber, 0, 2);
}

unsigned
fromHex2Dec(std::string hexNumber) {
	std::stringstream ss;
	ss << hexNumber;
	int decNumber;
	ss >> std::hex >> decNumber;
	return decNumber;
}

std::string
fromDec2Hex(unsigned decNumber) {
	std::stringstream ss;
	ss << std::hex << decNumber;
	std::string res(ss.str());
	return res;
}

std::string
fromDec2Bin(unsigned decNumber) {
	return std::bitset<8>(decNumber).to_string();
}

static bool
isNumber(const char c) {
	return c >= 48 && c <= 57;
}

unsigned
getNumber(std::string v) {
	std::string numberSystem = v.substr(0, 2);
	std::string number = v.substr(2, v.length() - 2);
	if (numberSystem == "0d" || numberSystem == "0D")
		return std::stoi(number);
	if (isNumber(numberSystem[0]) && isNumber(numberSystem[1]))
		return std::stoi(numberSystem + number);
	if (numberSystem == "0x" || numberSystem == "0X")
		return fromHex2Dec(number);
	if (numberSystem == "0b" || numberSystem == "0B")
		return fromBin2Dec(number);
	else {
		std::cout << "Invalid Number" << std::endl;
		exit(0);
	}
}

unsigned
getResult(std::string line) {
	if (line[0] < 48 || line[0] > 57)
		exit(0);
	std::stringstream ss(line);
	std::string v1, op, v2;
	ss >> v1;
	ss >> op;
	ss >> v2;
	unsigned vv1 = getNumber(v1);
	unsigned vv2 = getNumber(v2);
	return applyOperator(op, vv1, vv2);
}

void
printResult(unsigned number) {
	std::cout << "Results:" << std::endl;
	std::cout << "0d" << number << std::endl;
	std::cout << "0b" << fromDec2Bin(number) << std::endl;
	std::cout << "0x" << fromDec2Hex(number) << std::endl << std::endl;
}

int
main() {
	std::cout << "=================================" << std::endl;
	std::cout << "Welcome to the Awesome Calculator" << std::endl;
	std::cout << "=================================" << std::endl;

	std::string line;
	while (getline(std::cin, line)) {
		if (line.length() == 0)
			break;
		printResult(getResult(line));
	}
	return 0;
}
