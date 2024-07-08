//
// Created by admin on 2024/7/5.
//

#ifndef RE2C_STUDY_JSON_PARSER_H
#define RE2C_STUDY_JSON_PARSER_H
#include "json_scanner.h"



struct json_parser {
    json_scanner_type scanner;

    JsonValue result;
};

int json_parse(json_parser *parser);

int json_yyparse(json_parser *parser);

#endif //RE2C_STUDY_JSON_PARSER_H
