#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string rny_string) {
    return regex_replace(rny_string, regex("m"), "rn");
}