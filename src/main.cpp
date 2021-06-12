#include <iostream>
#include <sstream>
#include <string>

unsigned
applyOperator(std::string op, unsigned v1, unsigned v2) {
	if (op == "+") {
		return v1 + v2;
	}
	if (op == "-") {
		return v1 - v2;
	} else {
		throw "Invalid operator";
	}
}

unsigned
fromHex2Dec(std::string hexNumber) {
	std::stringstream ss;
	ss << hexNumber;
	int decNumber;
	ss >> std::hex >> decNumber;
	return decNumber;
}

unsigned
getNumber(std::string v) {
	std::string numberSystem = v.substr(0, 2);
	std::string number = v.substr(2, v.length() - 2);
	if (numberSystem == "0d" || numberSystem == "0D")
		return std::stoi(number);
	if (numberSystem == "0x" || numberSystem == "0X")
		return fromHex2Dec(number);
	else
		throw "Invalid number system";
}

unsigned
getResult(std::string line) {
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
	std::cout << "0d" << number << std::endl;
}

int
main() {
	std::cout << "=================================" << std::endl;
	std::cout << "Welcome to the Awesome Calculator" << std::endl;
	std::cout << "=================================" << std::endl;

	std::string line;
	while (getline(std::cin, line)) {
		printResult(getResult(line));
	}
	return 0;
}
