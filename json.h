//
// Created by admin on 2024/7/5.
//

#ifndef RE2C_STUDY_JSON_H
#define RE2C_STUDY_JSON_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

enum JsonTypeEnum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_INT,
    JSON_DOUBLE,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
};

struct JsonValue {
    int type;
    double js_double;
    int js_int;
    std::string js_str;
    std::vector<JsonValue> js_array;
    std::map<std::string, JsonValue> js_object;

    // JsonValue &operator=(const JsonValue &right) {
    //     type = right.type;
    //     js_str = right.js_str;
    // }
    JsonValue() {
        type = JSON_STRING;
    }

    JsonValue(JsonTypeEnum p_type): JsonValue() {
        type = p_type;
    }

    JsonValue(const JsonValue& old) {
        type = old.type;
        js_int = old.js_int;
        js_double = old.js_double;
        js_str = old.js_str;
        js_array = old.js_array;
        js_object = old.js_object;
    }

    JsonValue(const JsonValue& old, JsonTypeEnum p_type): JsonValue(old) {
        type = p_type;
    }



    void print() {
        print_js(*this);
    }

private:
    void print_js(const JsonValue &js, int indent=0) {
        std::string indent_space;
        if (indent > 0) {
            std::cout << std::string(indent * 4, ' ');
        }

        // indent space
        std::cout << indent_space;

        if (js.type == JSON_NULL) {
            std::cout << "null" << "\n";
        } else if (js.type == JSON_TRUE) {
            std::cout << "true" << "\n";
        } else if (js.type == JSON_FALSE) {
            std::cout << "false" << "\n";
        } else if (js.type == JSON_INT) {
            std::cout << js.js_str;
        } else if (js.type == JSON_DOUBLE) {
            std::cout << js.js_str;
        } else if (js.type == JSON_ARRAY) {
            std::cout << "array: [" << "\n";
            for (auto s: js.js_array) {
                print_js(s, indent + 1);
                std::cout << ", ";
            }
            // indent space
            std::cout << indent_space  << "]" ;
        } else if (js.type == JSON_STRING) {
            std::cout << '"' << js.js_str << '"' ;
        } else {
            std::cout << "object: {" << "\n";
            for (auto s: js.js_object) {
                std::cout << indent_space << '"' << s.first << '"' << ":";
                print_js(s.second, indent);
                std::cout << "\n";
            }
            std::cout << indent_space  << "}" << "\n";
        }
    }
};


#endif //RE2C_STUDY_JSON_H
