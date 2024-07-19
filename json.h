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
    void print_js(const JsonValue &js, int indent=0, bool skip=false) {
        std::string indent_space;
        if (indent > 0) {
            indent_space = std::string(indent * 4, ' ');
        }

        // indent space
        // std::cout << indent_space;

        if (js.type == JSON_ARRAY) {
            auto data = js.js_array;
            if (skip) {
                std::cout << "[" << "\n";
            } else {
                std::cout << indent_space << "[" << "\n";
            }
            for(auto it = data.begin(); it != data.end(); ++it) {
            // for (auto s: js.js_array) {
                print_js(*it, indent + 1);
                if (it != std::prev(data.end())) {
                    std::cout << ",";
                }
                std::cout << "\n";
            }
            // indent space
            std::cout << indent_space  << "]\n" ;
        }  else if (js.type == JSON_OBJECT){
            auto data = js.js_object;
            if (skip) {
                std::cout << "{" << "\n";
            } else {
                std::cout << indent_space << "{" << "\n";
            }
            auto item_indent_space = std::string((indent+1) * 4, ' ');
            for(auto it = data.begin(); it != data.end(); ++it) {
            // for (auto s: js.js_object) {
                std::cout << item_indent_space << '"' << it->first << '"' << ":";
                print_js(it->second, indent+1, true);

                if (it != std::prev(data.end())) {
                    std::cout << ",\n";
                }
                std::cout << "\n";
            }
            std::cout << indent_space  << "}" << "\n";
        } else {
            // indent space
            std::cout << indent_space;
            if (js.type == JSON_NULL) {
                std::cout << "null";
            } else if (js.type == JSON_TRUE) {
                std::cout << "true";
            } else if (js.type == JSON_FALSE) {
                std::cout << "false";
            } else if (js.type == JSON_INT) {
                std::cout << js.js_str;
            } else if (js.type == JSON_DOUBLE) {
                std::cout << js.js_str;
            } else if (js.type == JSON_STRING) {
                std::cout << '"' << js.js_str << '"' ;
            }
        }
    }
};


#endif //RE2C_STUDY_JSON_H
