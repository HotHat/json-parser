/* json parser */

%{
#include <stdio.h>
#include "json.h"
#include "json_parser.h"
%}

/* Bison declarations. */
%require "3.2
%define api.prefix {json_yy}
/* %define api.pure full */
%define api.parser.class {JsonParser}
%define api.namespace {Json}
%param  { json_parser *parser  }

%union {
	JsonValue *value;
}

%token <value> JSON_T_NUL
%token <value> JSON_T_TRUE
%token <value> JSON_T_FALSE
%token <value> JSON_T_INT
%token <value> JSON_T_DOUBLE
%token <value> JSON_T_STRING
%token <value> JSON_T_ESTRING
%token JSON_T_EOI
%token JSON_T_ERROR

%type <value> json object key value array
%type <value> members member elements

%code {
static int json_yylex(Json::JsonParser::semantic_type *value, json_parser *parser);
static void json_yyerror(json_parser *parser, char const *msg);

}


%% /* The grammar follows. */
json:
    value JSON_T_EOI { parser->result = *($$); YYACCEPT; }
;

value:
    object
|   array
|	JSON_T_STRING
|	JSON_T_ESTRING
|	JSON_T_INT
|	JSON_T_DOUBLE
|	JSON_T_NUL
|	JSON_T_TRUE
|	JSON_T_FALSE
;

array:
  '[' {
     printf("array start\n");
   }
  elements array_end {
     printf("array end\n");
     $$ = new JsonValue(*($3), JSON_ARRAY);
  }
;

array_end:
']'
|
'}' { printf("array end mismatched!\n"); YYERROR; }
;

elements:
    %empty { printf(" empty element\n"); $$ = new JsonValue(JSON_ARRAY); }
|
    value {
        std::cout << " element value: " << $1->js_str << std::endl;
        $$ = new JsonValue(JSON_ARRAY);
        $$->js_array.push_back(JsonValue(*($1)));
    }
|   elements ',' value { std::cout << " more element value: " << $3->js_str << std::endl;  $1->js_array.push_back(JsonValue(*($3))); }


object:
    '{'
     members object_end { printf("not empty object\n"); }
;

object_end:
    '}'
|
    ']' { YYERROR; }
;

members:
    member
|   member ',' members
;

member:
    key ':' value {
        std::cout << "key:" << $1->js_str << " value:" << $3->js_str << std::endl;
    }
;

key:
    JSON_T_STRING { $$ = new JsonValue(*$1);  std::cout << "key:" << $$->js_str <<  std::endl;}
|	JSON_T_ESTRING
;

%%

static int json_yylex(Json::JsonParser::semantic_type *value, json_parser *parser)
{
	int token = json_lexer(&parser->scanner);
	value->value = new JsonValue(*(parser->scanner.val));
	// value->value = parser->scanner.val;
	std::cout << "yylex: " << value->value->js_str << std::endl;
	return token;
}

void Json::JsonParser::error(const std::string& msg)
{
	std::cout << msg << std::endl;
}

