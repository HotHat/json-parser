/* json parser */

%{
#include <stdio.h>
#include "json.h"
#include "json_parser.h"
%}

/* Bison declarations. */
%require "3.2"
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
|	JSON_T_STRING { $$ = new JsonValue(*($1), JSON_STRING); }
|	JSON_T_ESTRING { $$ = new JsonValue(*($1), JSON_STRING); }
|	JSON_T_INT { $$ = new JsonValue(*($1), JSON_INT); }
|	JSON_T_DOUBLE { $$ = new JsonValue(*($1), JSON_DOUBLE); }
|	JSON_T_NUL { $$ = new JsonValue(JSON_NULL); }
|	JSON_T_TRUE { $$ = new JsonValue(JSON_TRUE); }
|	JSON_T_FALSE { $$ = new JsonValue(JSON_FALSE); }
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
        $$->js_array.push_back(*($1));
    }
|   elements ',' value { std::cout << " more element value: " << $3->js_str << std::endl;  $1->js_array.push_back(*($3)); }


object:
    '{'
     members object_end { printf("not empty object\n"); $$ = $2; }
;

object_end:
    '}'
|
    ']' { YYERROR; }
;

members:
    %empty { $$ = new JsonValue(JSON_OBJECT); std::cout << " empty object \n"; }
|   member {
        $$ = new JsonValue(*($1), JSON_OBJECT); std::cout << " just one member object \n";
    }
|   members ',' member {
       std::cout << " more element value: " << $3->js_str << "\n";
       $1->js_object.insert($3->js_object.begin(), $3->js_object.end());
    }
;

member:
    key ':' value {
        $$->js_object[$1->js_str] = *($3);
        std::cout << "object key:" << $1->js_str << " value:" << $3->js_str << std::endl;
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

