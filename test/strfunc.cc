#include "strfunc.h"

std::string ff::quiti(const std::string &text) {
    std::string buff="";
    for(int c=0;c<(int)text.length();c++){
        if(text[c] != 'i' && text[c] != 'j' && text[c] != '*') {
            buff += text[c];
        }
    }
    return buff;
}

std::string ff::trim(const std::string &text) {
    std::string buff="";
    for(int c=0;c<(int)text.length();c++){
        if(text[c] != ' ') {
            buff += text[c];
        }
    }
    return buff;
}

