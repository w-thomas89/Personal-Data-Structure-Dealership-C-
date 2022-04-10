#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string phone = "(515)-123-4567";
    string fix = regex_replace(phone, regex(R"([\D])"), "");
    cout << fix;
}
