//
// Created by admin on 2024/7/3.
//

#ifndef RE2C_STUDY_JSON_SCANNER_H
#define RE2C_STUDY_JSON_SCANNER_H
#include <iostream>
#include "json.h"
#include "json_scanner_defs.h"
//#include "json_parser.tab.h"

enum token_kind_type
{
    JSON_YYEMPTY = -2,
    JSON_YYEOF = 0,                // "end of file"
    JSON_YYerror = 256,            // error
    JSON_YYUNDEF = 257,            // "invalid token"
    JSON_T_NUL = 258,              // JSON_T_NUL
    JSON_T_TRUE = 259,             // JSON_T_TRUE
    JSON_T_FALSE = 260,            // JSON_T_FALSE
    JSON_T_INT = 261,              // JSON_T_INT
    JSON_T_DOUBLE = 262,           // JSON_T_DOUBLE
    JSON_T_STRING = 263,           // JSON_T_STRING
    JSON_T_ESTRING = 264,          // JSON_T_ESTRING
    JSON_T_EOI = 265,              // JSON_T_EOI
    JSON_T_ERROR = 266             // JSON_T_ERROR
};

typedef unsigned char json_type;

struct json_scanner_type {
    json_type *cursor;
    json_type *token;
    json_type *limit;
    json_type *marker;
    json_type *ctx_marker;
    char str[1000];
    json_type *str_start;
    int str_len;
    int line_num;
    json_type *line_start;
    int line_col;
    int state;
    JsonValue *val;
};



void json_scanner_init(json_scanner_type *s, const char *buff, size_t len);
int json_lexer(json_scanner_type *s);

;

#endif //RE2C_STUDY_JSON_SCANNER_H
