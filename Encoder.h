#ifndef ENCODER_H
#define ENCODER_H

#include <string>


namespace encoder {

const std::string i_0 = u8"\u200C";
const std::string i_1 = u8"\u200D";
const int exp_size = 3; // Expected size of unicode characters in bytes. Enforced by tests.

std::string encode_char(char data);
char decode_char(std::string data);

std::string encode(std::string data);
std::string decode(std::string data);

std::string remove_unnecessary_symbols(std::string data);

std::string create_secret(std::string secret);
std::string extract_secret(std::string message);

}

#endif // ENCODER_H
