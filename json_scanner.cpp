/* Generated by re2c 2.0.3 */
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


	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;
		if (YYGETCONDITION() < 1) {
			goto yyc_JS;
		} else {
			goto yyc_STR_P1;
		}
/* *********************************** */
yyc_JS:
		{
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,  64,   0,   0,   0,  64,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				 64,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128, 128, 128, 128, 128, 128, 128, 128, 
				128, 128,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};
			yych = *YYCURSOR;
			if (yych <= ']') {
				if (yych <= '"') {
					if (yych <= '\f') {
						if (yych <= 0x08) {
							if (yych >= 0x01) goto yy4;
						} else {
							if (yych <= '\t') goto yy6;
							if (yych <= '\n') goto yy9;
							goto yy4;
						}
					} else {
						if (yych <= 0x1F) {
							if (yych <= '\r') goto yy11;
							goto yy4;
						} else {
							if (yych <= ' ') goto yy6;
							if (yych <= '!') goto yy12;
							goto yy14;
						}
					}
				} else {
					if (yych <= '0') {
						if (yych <= ',') {
							if (yych <= '+') goto yy12;
							goto yy16;
						} else {
							if (yych <= '-') goto yy18;
							if (yych <= '/') goto yy12;
							goto yy19;
						}
					} else {
						if (yych <= 'Z') {
							if (yych <= '9') goto yy21;
							if (yych <= ':') goto yy23;
							goto yy12;
						} else {
							if (yych <= '[') goto yy25;
							if (yych <= '\\') goto yy12;
							goto yy27;
						}
					}
				}
			} else {
				if (yych <= '}') {
					if (yych <= 's') {
						if (yych <= 'f') {
							if (yych <= 'e') goto yy12;
							goto yy29;
						} else {
							if (yych == 'n') goto yy30;
							goto yy12;
						}
					} else {
						if (yych <= 'z') {
							if (yych <= 't') goto yy31;
							goto yy12;
						} else {
							if (yych <= '{') goto yy32;
							if (yych <= '|') goto yy12;
							goto yy34;
						}
					}
				} else {
					if (yych <= 0xEC) {
						if (yych <= 0xC1) {
							if (yych <= 0x7F) goto yy12;
							goto yy36;
						} else {
							if (yych <= 0xDF) goto yy38;
							if (yych <= 0xE0) goto yy39;
							goto yy40;
						}
					} else {
						if (yych <= 0xF0) {
							if (yych <= 0xED) goto yy41;
							if (yych <= 0xEF) goto yy40;
							goto yy42;
						} else {
							if (yych <= 0xF3) goto yy43;
							if (yych <= 0xF4) goto yy44;
							goto yy36;
						}
					}
				}
			}
			++YYCURSOR;
			{
		if (s->limit < s->cursor) {
			return JSON_T_EOI;
		} else {
            print_token("JSON_ERROR_CTRL_CHAR_1");
            s->line_col = s->cursor - s->line_start;
			return JSON_T_ERROR;
		}
	}
yy4:
			++YYCURSOR;
			{
		print_token("JSON_ERROR_CTRL_CHAR_2");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy6:
			yych = *++YYCURSOR;
yy7:
			if (yybm[0+yych] & 64) {
				goto yy6;
			}
			{
	    // white space
        goto std;
    }
yy9:
			++YYCURSOR;
			{
	    // carry return
	    s->line_num += 1;
	    s->line_col = 0;
	    s->line_start = s->cursor;
        goto std;
	}
yy11:
			yych = *++YYCURSOR;
			if (yych == '\n') goto yy9;
			goto yy7;
yy12:
			++YYCURSOR;
yy13:
			{
		print_token("JSON_ERROR_SYNTAX_3");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy14:
			++YYCURSOR;
			{
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
yy16:
			++YYCURSOR;
			{ return ','; }
yy18:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy13;
			if (yych <= '0') goto yy19;
			if (yych <= '9') goto yy21;
			goto yy13;
yy19:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy45;
			} else {
				if (yych <= 'E') goto yy47;
				if (yych == 'e') goto yy47;
			}
yy20:
			{
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
yy21:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yybm[0+yych] & 128) {
				goto yy21;
			}
			if (yych <= 'D') {
				if (yych == '.') goto yy45;
				goto yy20;
			} else {
				if (yych <= 'E') goto yy47;
				if (yych == 'e') goto yy47;
				goto yy20;
			}
yy23:
			++YYCURSOR;
			{ return ':'; }
yy25:
			++YYCURSOR;
			{ return '['; }
yy27:
			++YYCURSOR;
			{ return ']'; }
yy29:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'a') goto yy48;
			goto yy13;
yy30:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'u') goto yy49;
			goto yy13;
yy31:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'r') goto yy50;
			goto yy13;
yy32:
			++YYCURSOR;
			{ return '{'; }
yy34:
			++YYCURSOR;
			{ return '}'; }
yy36:
			++YYCURSOR;
yy37:
			{
		print_token("JS: JSON_ERROR_UTF8_4");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy38:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy37;
			if (yych <= 0xBF) goto yy12;
			goto yy37;
yy39:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x9F) goto yy37;
			if (yych <= 0xBF) goto yy51;
			goto yy37;
yy40:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy37;
			if (yych <= 0xBF) goto yy51;
			goto yy37;
yy41:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy37;
			if (yych <= 0x9F) goto yy51;
			goto yy37;
yy42:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x8F) goto yy37;
			if (yych <= 0xBF) goto yy52;
			goto yy37;
yy43:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy37;
			if (yych <= 0xBF) goto yy52;
			goto yy37;
yy44:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy37;
			if (yych <= 0x8F) goto yy52;
			goto yy37;
yy45:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy46;
			if (yych <= '9') goto yy53;
yy46:
			YYCURSOR = YYMARKER;
			if (yyaccept <= 1) {
				if (yyaccept == 0) {
					goto yy20;
				} else {
					goto yy13;
				}
			} else {
				if (yyaccept == 2) {
					goto yy37;
				} else {
					goto yy55;
				}
			}
yy47:
			yych = *++YYCURSOR;
			if (yych <= ',') {
				if (yych == '+') goto yy56;
				goto yy46;
			} else {
				if (yych <= '-') goto yy56;
				if (yych <= '/') goto yy46;
				if (yych <= '9') goto yy57;
				goto yy46;
			}
yy48:
			yych = *++YYCURSOR;
			if (yych == 'l') goto yy59;
			goto yy46;
yy49:
			yych = *++YYCURSOR;
			if (yych == 'l') goto yy60;
			goto yy46;
yy50:
			yych = *++YYCURSOR;
			if (yych == 'u') goto yy61;
			goto yy46;
yy51:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy12;
			goto yy46;
yy52:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy51;
			goto yy46;
yy53:
			yyaccept = 3;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych <= '/') goto yy55;
				if (yych <= '9') goto yy53;
			} else {
				if (yych <= 'E') goto yy47;
				if (yych == 'e') goto yy47;
			}
yy55:
			{
	    // FLOAT|EXP
		char t[100] = {};
		size_t sz = s->cursor - s->token;
		// strncpy(s->str, (const char *)s->token, sz);
		// s->str[sz] = '\0';
		s->val->js_str.erase();
		s->val->js_str.append((const char *)s->token, sz);
		return JSON_T_DOUBLE;
	}
yy56:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy46;
			if (yych >= ':') goto yy46;
yy57:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy55;
			if (yych <= '9') goto yy57;
			goto yy55;
yy59:
			yych = *++YYCURSOR;
			if (yych == 's') goto yy62;
			goto yy46;
yy60:
			yych = *++YYCURSOR;
			if (yych == 'l') goto yy63;
			goto yy46;
yy61:
			yych = *++YYCURSOR;
			if (yych == 'e') goto yy65;
			goto yy46;
yy62:
			yych = *++YYCURSOR;
			if (yych == 'e') goto yy67;
			goto yy46;
yy63:
			++YYCURSOR;
			{
	    print_token("null");
		return JSON_T_NUL;
	}
yy65:
			++YYCURSOR;
			{
	    print_token("true");
		return JSON_T_TRUE;
	}
yy67:
			++YYCURSOR;
			{
	    print_token("false");
		return JSON_T_FALSE;
	}
		}
/* *********************************** */
yyc_STR_P1:
		yych = *YYCURSOR;
		if (yych <= 0xDF) {
			if (yych <= '[') {
				if (yych <= 0x1F) goto yy71;
				if (yych == '"') goto yy75;
				goto yy73;
			} else {
				if (yych <= '\\') goto yy77;
				if (yych <= 0x7F) goto yy73;
				if (yych <= 0xC1) goto yy79;
				goto yy81;
			}
		} else {
			if (yych <= 0xEF) {
				if (yych <= 0xE0) goto yy82;
				if (yych == 0xED) goto yy84;
				goto yy83;
			} else {
				if (yych <= 0xF0) goto yy85;
				if (yych <= 0xF3) goto yy86;
				if (yych <= 0xF4) goto yy87;
				goto yy79;
			}
		}
yy71:
		++YYCURSOR;
		{
		print_token("JSON_ERROR_CTRL_CHAR_5");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy73:
		++YYCURSOR;
		{
	    // str_p1 utf8
	    size_t len = s->cursor - s->str_start;
	    strncpy(s->str+s->str_len, (const char *)s->str_start, len);
	    s->str_len += len;
		s->val->js_str.append((const char *)s->str_start, len);
	    s->str_start = s->cursor;

	    JSON_CONDITION_GOTO(STR_P1);
	}
yy75:
		++YYCURSOR;
		{
        // end of string
        s->str[s->str_len] = '\0';
	    JSON_CONDITION_SET(JS);
        return JSON_T_STRING;
	}
yy77:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 'e') {
			if (yych <= '/') {
				if (yych == '"') goto yy88;
				if (yych >= '/') goto yy88;
			} else {
				if (yych <= '\\') {
					if (yych >= '\\') goto yy88;
				} else {
					if (yych == 'b') goto yy88;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'f') goto yy88;
				if (yych == 'n') goto yy88;
			} else {
				if (yych <= 's') {
					if (yych <= 'r') goto yy88;
				} else {
					if (yych <= 't') goto yy88;
					if (yych <= 'u') goto yy90;
				}
			}
		}
yy78:
		{
	    print_token("JSON_ERROR_SYNTAX_7");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy79:
		++YYCURSOR;
yy80:
		{
	    // str_p1 any
	    print_token("STR_P1: JSON_ERROR_UTF8_9");
        s->line_col = s->cursor - s->line_start;
		return JSON_T_ERROR;
	}
yy81:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy73;
		goto yy80;
yy82:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x9F) goto yy80;
		if (yych <= 0xBF) goto yy92;
		goto yy80;
yy83:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy92;
		goto yy80;
yy84:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0x9F) goto yy92;
		goto yy80;
yy85:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x8F) goto yy80;
		if (yych <= 0xBF) goto yy93;
		goto yy80;
yy86:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy93;
		goto yy80;
yy87:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0x8F) goto yy93;
		goto yy80;
yy88:
		++YYCURSOR;
		{
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
yy90:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy91;
				if (yych <= '0') goto yy94;
				goto yy95;
			} else {
				if (yych <= '@') goto yy91;
				if (yych <= 'C') goto yy95;
				goto yy96;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy95;
				if (yych >= 'a') goto yy95;
			} else {
				if (yych <= 'd') goto yy96;
				if (yych <= 'f') goto yy95;
			}
		}
yy91:
		YYCURSOR = YYMARKER;
		if (yyaccept <= 1) {
			if (yyaccept == 0) {
				goto yy78;
			} else {
				goto yy80;
			}
		} else {
			goto yy114;
		}
yy92:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy91;
		if (yych <= 0xBF) goto yy73;
		goto yy91;
yy93:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy91;
		if (yych <= 0xBF) goto yy92;
		goto yy91;
yy94:
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy91;
			if (yych <= '0') goto yy97;
			if (yych <= '7') goto yy98;
			goto yy99;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy91;
				goto yy99;
			} else {
				if (yych <= '`') goto yy91;
				if (yych <= 'f') goto yy99;
				goto yy91;
			}
		}
yy95:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy99;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy99;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy99;
			goto yy91;
		}
yy96:
		yych = *++YYCURSOR;
		if (yych <= 'B') {
			if (yych <= '7') {
				if (yych <= '/') goto yy91;
				goto yy99;
			} else {
				if (yych <= '9') goto yy100;
				if (yych <= '@') goto yy91;
				goto yy100;
			}
		} else {
			if (yych <= '`') {
				if (yych <= 'F') goto yy101;
				goto yy91;
			} else {
				if (yych <= 'b') goto yy100;
				if (yych <= 'f') goto yy101;
				goto yy91;
			}
		}
yy97:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '7') goto yy102;
			if (yych <= '9') goto yy103;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy103;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy103;
			goto yy91;
		}
yy98:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy103;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy103;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy103;
			goto yy91;
		}
yy99:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy104;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy104;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy104;
			goto yy91;
		}
yy100:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy105;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy105;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy105;
			goto yy91;
		}
yy101:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy106;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy106;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy106;
			goto yy91;
		}
yy102:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy107;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy107;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy107;
			goto yy91;
		}
yy103:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy109;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy109;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy109;
			goto yy91;
		}
yy104:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy111;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy111;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy111;
			goto yy91;
		}
yy105:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy113;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy113;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy113;
			goto yy91;
		}
yy106:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych <= '9') goto yy115;
			goto yy91;
		} else {
			if (yych <= 'F') goto yy115;
			if (yych <= '`') goto yy91;
			if (yych <= 'f') goto yy115;
			goto yy91;
		}
yy107:
		++YYCURSOR;
		{
	    // utf16_1
        int utf16 = json_ucs2_to_int(s, 2);
        s->str[s->str_len] = (char) utf16;
        s->str_len += 1;
        s->str_start = s->cursor;
		s->val->js_str.push_back((char)utf16);
        JSON_CONDITION_GOTO(STR_P1);
    }
yy109:
		++YYCURSOR;
		{
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
yy111:
		++YYCURSOR;
		{
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
yy113:
		yyaccept = 2;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych == '\\') goto yy116;
yy114:
		{
        // USC2
        //s->errcode = JSON_ERROR_UTF16;
        print_token("JSON_ERROR_UTF16_8");
        s->line_col = s->cursor - s->line_start;
        return JSON_T_ERROR;
    }
yy115:
		++YYCURSOR;
		goto yy114;
yy116:
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy91;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy118;
		if (yych != 'd') goto yy91;
yy118:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy91;
		if (yych <= 'F') goto yy119;
		if (yych <= 'b') goto yy91;
		if (yych >= 'g') goto yy91;
yy119:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych >= ':') goto yy91;
		} else {
			if (yych <= 'F') goto yy120;
			if (yych <= '`') goto yy91;
			if (yych >= 'g') goto yy91;
		}
yy120:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy91;
			if (yych >= ':') goto yy91;
		} else {
			if (yych <= 'F') goto yy121;
			if (yych <= '`') goto yy91;
			if (yych >= 'g') goto yy91;
		}
yy121:
		++YYCURSOR;
		{
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
	}


}
