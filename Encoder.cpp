#include "Encoder.h"
#include <vector>


using namespace std;


string encoder::encode_char(char data)
{
    vector<char> bits;
    for (int i = 0; i < 8; i++)
    {
        bits.push_back((data >> i) & 1);
    }
    string result;
    for (auto bit : bits)
    {
        if (!bit)
            result += i_0;
        else
            result += i_1;
    }
    return result;
}

string encoder::encode(const string data)
{
    string result;
    for (int i = 0; i < data.size(); i++)
    {
        char byte = data[i];
        result += encoder::encode_char(byte);
    }
    return result;
}


char encoder::decode_char(std::string data)
{
    if (data.size() != encoder::exp_size * 8)
        return 0;

    char result = 0;

    for (auto i = data.begin(); i != data.end(); i+=encoder::exp_size)
    {
        string u8char(i, i + encoder::exp_size);
        int shift = (i-data.begin())/encoder::exp_size;
        if (u8char == i_1)
        {
            result |= (1 << shift );
        }
    }
    return result;
}


std::string encoder::decode(std::string data)
{
    if (data.size() % (8*encoder::exp_size) != 0)     {
        return "";
    }
    string result;
    for (int b = 0; b < data.size(); b += 8*encoder::exp_size) {
        string byte(data.begin() + b, data.begin() + b + 8*encoder::exp_size);
        result+=encoder::decode_char(byte);
    }
    return result;
}

std::string encoder::remove_unnecessary_symbols(std::string data)
{
    std::string result;
    auto p = data.begin();
    while (p!=data.end())
    {
        std::string c(p, p + encoder::exp_size);
        if (c == encoder::i_0 || c == encoder::i_1)
        {
            result += c;
            p+=3;
        } else {
            p+=1;
        }

    }
    return result;
}

std::string encoder::create_secret(std::string secret)
{
    return encoder::encode(secret);
}

std::string encoder::extract_secret(std::string message)
{
    return encoder::decode(
        encoder::remove_unnecessary_symbols(message)
    );
}
