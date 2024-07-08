#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json_scanner.h"
#include "json_parser.h"
#include "json_parser.tab.h"

/**
 *
 *
 * bison  --defines=json_parser.tab.h -L c++ -l -o json_parser.tab.cpp  json_parser.y
 * re2c -t json_scanner_defs.h --no-generation-date -bci -o json_scanner.cpp json_scanner.re
 */
static std::vector<char> ReadAllBytes(char const* filename)
{
    std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
    // std::ifstream ifs(filename, std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(result.data(), pos);

    return result;
}

int main() {
    std::string filename = "D:\\Vagrant2\\Re2cStudy\\test.json";

    auto file = ReadAllBytes(filename.c_str());
    std::cout << "size: " << file.size() << std::endl;
    std::cout << "strlen: " << strlen(file.data()) << std::endl;
    size_t sz = file.size();
    char *data = new char[sz+1];
    data[sz] = 0;
    auto source = file.data();
    strncpy(data, source , sz);

    json_parser p;
    json_scanner_init(&p.scanner, data, sz);
    Json::JsonParser parser(&p);
    int t = parser.parse();
    std::cout << "parse file: " << t << std::endl;
    std::cout << "result array size: " << p.result.js_array.size() << std::endl;

    p.result.print();
    // Json::JsonParser::symbol_type result = parser.

    /*
    json_scanner_type s{};

    int token = json_lexer(&s);
    while (token != JSON_T_EOI) {
        std::cout << "token code: " << token << ", ";
        if (token == JSON_T_STRING
            || token == JSON_T_INT
            || token == JSON_T_DOUBLE
        ) {
            std::cout << s.str << std::endl;
        }
        else if(token == JSON_T_ERROR) {
            std::cout << "Error happen at Ln " << s.line_num+1 << ", Col " << s.line_col+1 << std::endl;
            break;
        }
        else {
            std::cout << static_cast<char>(token) << std::endl;
        }
        token = json_lexer(&s);
    }

    */

    delete data;

    return 0;
}
