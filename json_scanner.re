#include <iostream>
#include "json_scanner.h"

#define	YYCTYPE     json_type
#define	YYCURSOR    s->cursor
#define	YYLIMIT     s->limit
#define	YYMARKER    s->marker
#define	YYCTXMARKER s->ctx_marker
#define YYGETCONDITION()        s->state
#define YYSETCONDITION(yystate) s->state = yystate

#define JSON_CONDITION_SET(condition) YYSETCONDITION(yyc##condition)
#define JSON_CONDITION_GOTO(condition) goto yyc_##condition
#define JSON_CONDITION_SET_AND_GOTO(condition) \
	JSON_CONDITION_SET(condition); \
	JSON_CONDITION_GOTO(condition)

// static void json_scanner_copy_string(json_scanner_type *s, int esc_size)
// {
// 	size_t len = s->cursor - s->str_start - esc_size - 1;
// 	if (len) {
// 		memcpy(s->pstr, s->str_start, len);
// 		s->pstr += len;
// 	}
// }

static int json_hex_to_int(char code)
{
	if (code >= '0' && code <= '9') {
		return code - '0';
	} else if (code >= 'A' && code <= 'F') {
		return code - ('A' - 10);
	} else if (code >= 'a' && code <= 'f') {
		return code - ('a' - 10);
	} else {
		/* this should never happened (just to suppress compiler warning) */
		return -1;
	}
}

static int json_ucs2_to_int_ex(json_scanner_type *s, int size, int start)
{
	int i, code = 0;
	json_type *pc = s->cursor - start;
	for (i = 0; i < size; i++) {
		code |= json_hex_to_int(*(pc--)) << (i * 4);
	}
	return code;
}

static int json_ucs2_to_int(json_scanner_type *s, int size)
{
	return json_ucs2_to_int_ex(s, size, 1);
}

static void print_token(const char *name)
{
    std::cout << name << std::endl;
}

void json_scanner_init(json_scanner_type *s, const char *buff, size_t len)
{
    s->cursor = (json_type *)buff;
    s->limit = s->cursor + len;
    s->line_num = 0;
    s->line_col = 0;
    s->line_start = s->cursor;
    s->val = new JsonValue();
    JSON_CONDITION_SET(JS);
}

int json_lexer(json_scanner_type *s)
{

std:
	s->token = s->cursor;

/*!re2c
	re2c:indent:top = 1;
	re2c:yyfill:enable = 0;

	DIGIT   = [0-9] ;
	DIGITNZ = [1-9] ;
	UINT    = "0" | ( DIGITNZ DIGIT* ) ;
	INT     = "-"? UINT ;
	// EINT    = "0" DIGIT+;
	HEX     = DIGIT | [a-fA-F] ;
	HEXNZ   = DIGITNZ | [a-fA-F] ;
	HEX7    = [0-7] ;
	HEXC    = DIGIT | [a-cA-C] ;
	FLOAT   = INT "." DIGIT+ ;
	EXP     = ( INT | FLOAT ) [eE] [+-]? DIGIT+ ;
	NL      = "\r"? "\n" ;
	WS      = [ \t\r]+ ;
	EOI     = "\000";
	CTRL    = [\x00-\x1F] ;
	UTF8T   = [\x80-\xBF] ;
	UTF8_1  = [\x00-\x7F] ;
	UTF8_2  = [\xC2-\xDF] UTF8T ;
	UTF8_3A = "\xE0" [\xA0-\xBF] UTF8T ;
	UTF8_3B = [\xE1-\xEC] UTF8T{2} ;
	UTF8_3C = "\xED" [\x80-\x9F] UTF8T ;
	UTF8_3D = [\xEE-\xEF] UTF8T{2} ;
	UTF8_3  = UTF8_3A | UTF8_3B | UTF8_3C | UTF8_3D ;
	UTF8_4A = "\xF0"[\x90-\xBF] UTF8T{2} ;
	UTF8_4B = [\xF1-\xF3] UTF8T{3} ;
	UTF8_4C = "\xF4" [\x80-\x8F] UTF8T{2} ;
	UTF8_4  = UTF8_4A | UTF8_4B | UTF8_4C ;
	UTF8    = UTF8_1 | UTF8_2 | UTF8_3 | UTF8_4 ;
	ANY     = [^] ;
	ESCPREF = "\\" ;
	ESCSYM  = ( "\"" | "\\" | "/" | [bfnrt] ) ;
	ESC     = ESCPREF ESCSYM ;
	UTFSYM  = "u" ;
	UTFPREF = ESCPREF UTFSYM ;
	UCS2    = UTFPREF HEX{4} ;
	UTF16_1 = UTFPREF "00" HEX7 HEX ;
	UTF16_2 = UTFPREF "0" HEX7 HEX{2} ;
	UTF16_3 = UTFPREF ( ( ( HEXC | [efEF] ) HEX ) | ( [dD] HEX7 ) ) HEX{2} ;
	UTF16_4 = UTFPREF [dD] [89abAB] HEX{2} UTFPREF [dD] [c-fC-F] HEX{2} ;

	<JS>"{"                  { return '{'; }
	<JS>"}"                  { return '}'; }
	<JS>"["                  { return '['; }
	<JS>"]"                  { return ']'; }
	<JS>":"                  { return ':'; }
	<JS>","                  { return ','; }
	<JS>"null"               {
	    print_token("null");
		return JSON_T_NUL;
	}
	<JS>"true"               {
	    print_token("true");
		return JSON_T_TRUE;
	}
	<JS>"false"              {
	    print_token("false");
		return JSON_T_FALSE;
	}
	//<JS>EINT                  {
    //    print_token("JSON_ERROR_CTRL_CHAR_1");
    //    s->line_col = s->token - s->line_start;
    //    return JSON_T_ERROR;
    //}
	<JS>INT                  {
	    // INT
		bool bigint = 0, negative = s->token[0] == '-';
		// size_t digits = (size_t) (s->cursor - s->token - negative);
		char t[100] = {};
		size_t sz = s->cursor - s->token;
		// strncpy(s->str, (const char *)s->token, sz);
		// s->str[sz] = '\0';
		s->val->js_str.erase();
		s->val->js_str.append((const char *)s->token, sz);
		// print_token(t);

        return JSON_T_INT;

	}
	<JS>FLOAT|EXP            {
	    // FLOAT|EXP
		char t[100] = {};
		size_t sz = s->cursor - s->token;
		// strncpy(s->str, (const char *)s->token, sz);
		// s->str[sz] = '\0';
		s->val->js_str.erase();
		s->val->js_str.append((const char *)s->token, sz);
		return JSON_T_DOUBLE;
	}
	<JS>NL                {
	    // carry return
	    s->line_num += 1;
	    s->line_col = 0;
	    s->line_start = s->cursor;
        goto std;
	}
	<JS>WS                {
	    // white space
        goto std;
    }
	<JS>EOI                  {
		if (s->limit < s->cursor) {
			return JSON_T_EOI;
		} else {
            print_token("JSON_ERROR_CTRL_CHAR_1");
            s->line_col = s->cursor - s->line_start;
			return JSON_T_ERROR;
		}
	}
	<JS>["]                  {
	    // start of string
		// s->str_start = s->cursor;
		// s->str_esc = 0;
		// s->utf8_invalid = 0;
		// s->utf8_invalid_count = 0;
		s->str_len = 0;
		s->str_start = s->cursor;
		s->val->js_str.erase();
		JSON_CONDITION_SET_AND_GOTO(STR_P1);
	}
	<JS>CTRL                 {
		print_token("JSON_ERROR_CTRL_CHAR_2");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
	<JS>UTF8                 {
		print_token("JSON_ERROR_SYNTAX_3");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
	<JS>ANY                  {
		print_token("JS: JSON_ERROR_UTF8_4");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}

	<STR_P1>CTRL             {
		print_token("JSON_ERROR_CTRL_CHAR_5");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}

	<STR_P1>UTF16_1             {
	    // utf16_1
        int utf16 = json_ucs2_to_int(s, 2);
        s->str[s->str_len] = (char) utf16;
        s->str_len += 1;
        s->str_start = s->cursor;
		s->val->js_str.push_back((char)utf16);
        JSON_CONDITION_GOTO(STR_P1);
    }

     <STR_P1>UTF16_2             {
        // utf16_2
        int utf16 = json_ucs2_to_int(s, 3);
        char u1 = (char) (0xc0 | (utf16 >> 6));
        char u2 = (char) (0x80 | (utf16 & 0x3f));
        s->str[s->str_len] = u1;
        s->str[s->str_len+1] = u2;
        s->str_len += 2;
		s->val->js_str.push_back(u1);
		s->val->js_str.push_back(u2);
        s->str_start = s->cursor;
        JSON_CONDITION_GOTO(STR_P1);
    }
    <STR_P1>UTF16_3             {
        // utf16_3
        int utf16 = json_ucs2_to_int(s, 4);
        char u1 = (char) (0xe0 | (utf16 >> 12));
        char u2 = (char) (0x80 | ((utf16 >> 6) & 0x3f));
        char u3 = (char) (0x80 | (utf16 & 0x3f));
        s->str[s->str_len] = u1;
        s->str[s->str_len + 1] = u2;
        s->str[s->str_len + 2] = u3;
        s->str_len += 3;
		s->val->js_str.push_back(u1);
		s->val->js_str.push_back(u2);
		s->val->js_str.push_back(u3);
        s->str_start = s->cursor;
        JSON_CONDITION_GOTO(STR_P1);
    }

    <STR_P1>UTF16_4             {
	    // utf16_4
        int utf32, utf16_hi, utf16_lo;
        utf16_hi = json_ucs2_to_int(s, 4);
        utf16_lo = json_ucs2_to_int_ex(s, 4, 7);
        utf32 = ((utf16_lo & 0x3FF) << 10) + (utf16_hi & 0x3FF) + 0x10000;
        char u1 = (char) (0xf0 | (utf32 >> 18));
        char u2 = (char) (0x80 | ((utf32 >> 12) & 0x3f));
        char u3 = (char) (0x80 | ((utf32 >> 6) & 0x3f));
        char u4 = (char) (0x80 | (utf32 & 0x3f));
        s->str[s->str_len] = u1;
        s->str[s->str_len + 1] = u2;
        s->str[s->str_len + 2] = u3;
        s->str[s->str_len + 3] = u4;
        s->str_len += 4;
		s->val->js_str.push_back(u1);
		s->val->js_str.push_back(u2);
		s->val->js_str.push_back(u3);
		s->val->js_str.push_back(u4);
        s->str_start = s->cursor;
        JSON_CONDITION_GOTO(STR_P1);
    }

	<STR_P1>ESC              {
	    // preview char
	    char m = *(s->cursor - 1);
	    char esc;
		switch (m) {
            case 'b':
                esc = '\b';
                break;
            case 'f':
                esc = '\f';
                break;
            case 'n':
                esc = '\n';
                break;
            case 'r':
                esc = '\r';
                break;
            case 't':
                esc = '\t';
                break;
            case '\\':
            case '/':
            case '"':
                esc = *s->cursor;
                break;
            default:
                s->line_col = s->cursor - s->line_start;
                print_token("JSON_ERROR_SYNTAX_6");
                return JSON_T_ERROR;
        }
		s->str[s->str_len] = esc;
		s->str_len += 1;
		s->str_start = s->cursor;
		s->val->js_str.push_back(esc);
		JSON_CONDITION_GOTO(STR_P1);
	}
	<STR_P1>ESCPREF           {
	    print_token("JSON_ERROR_SYNTAX_7");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
	<STR_P1>["]              {
        // end of string
        s->str[s->str_len] = '\0';
	    JSON_CONDITION_SET(JS);
        return JSON_T_STRING;
	}
	<STR_P1>UTF8             {
	    // str_p1 utf8
	    size_t len = s->cursor - s->str_start;
	    strncpy(s->str+s->str_len, (const char *)s->str_start, len);
	    s->str_len += len;
		s->val->js_str.append((const char *)s->str_start, len);
	    s->str_start = s->cursor;

	    JSON_CONDITION_GOTO(STR_P1);
	}

    <STR_P1>UCS2             {
        // USC2
        //s->errcode = JSON_ERROR_UTF16;
        print_token("JSON_ERROR_UTF16_8");
        s->line_col = s->cursor - s->line_start;
        return JSON_T_ERROR;
    }

	<STR_P1>ANY              {
	    // str_p1 any
	    print_token("STR_P1: JSON_ERROR_UTF8_9");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}

*/

}
