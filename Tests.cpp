#include "Encoder.h"
#include <assert.h>
#include <iostream>

using namespace std;
void mytest() {
    string g = u8"Привет BRATVA";
    cout << g << endl;
    for (char c: g) {
        cout << static_cast<int>(c) << endl;
    }

    cout << "i_0=";
    for (char c : encoder::i_0)
        cout << static_cast<int>(c) << " ";
    cout << endl;
    cout << "i_1=";
    for (char c : encoder::i_1)
        cout << static_cast<int>(c) << " ";
    cout << endl;

}

void assert_correct_size() {
    assert(encoder::i_0.size() == encoder::exp_size);
    assert(encoder::i_1.size() == encoder::exp_size);
}

void test_encode_char(char c, string& result) {
    cout << "Testing encode_char" << endl;
    result = encoder::encode_char(c);
    assert(result.size() == 8 * encoder::exp_size);
    for (auto i = result.begin(); i != result.end(); i+=encoder::exp_size) {
        string u8char(i, i+encoder::exp_size);
        assert(u8char == encoder::i_0 || u8char == encoder::i_1);
    }
}

void test_decode_char(string data, char expected_result) {
    cout << "Testing decode_char" << endl;
    char result = encoder::decode_char(data);
    assert(result == expected_result);
}

void test_encode_decode_ascii()  {
    cout << "Testing encode_decode_ascii" << endl;
    string data = u8"Hello, World!";
    string encoded = encoder::encode(data);
    string decoded = encoder::decode(encoded);
    assert(data == decoded);
}

void test_encode_decode_other()  {
    cout << "Testing encode_decode_other" << endl;
    string data = u8"ДАРОВА БРАТВА!";
    string encoded = encoder::encode(data);
    string decoded = encoder::decode(encoded);
    assert(data == decoded);
}

// bool test_combined_text_and_secret(QString message, QString secret) {
//     QString encoded_message = encoder::encode(secret);
//     QString result = encoded_message + message;
//     QString decoded_message = encoder::decode(
//         encoder::remove_unnecessary_symbols(result));
//     return secret == decoded_message;
// }

// bool test_full_pipeline(QString message, QString secret) {
//     QString encoded_message = encoder::mix_text_and_secret(message, secret);
//     QString extracted_secret = encoder::extract_secret(encoded_message);
//     return secret == extracted_secret;
// }

int main(int argc, char *argv[])
{
    bool suc = true;
    // suc = suc && test_encode_decode_ascii();
    // suc = suc && test_encode_decode_other();
    // suc = suc && test_combined_text_and_secret("Hello, World!", "secret");
    // suc = suc && test_combined_text_and_secret("ДАРОВА БРАТВА!", "секрет");
    // suc = suc && test_full_pipeline("Hello, World!", "secret");
    // suc = suc && test_full_pipeline("ДАРОВА БРАТВА!", "секрет");
    mytest();
    assert_correct_size();
    string result;
    test_encode_char('a', result);
    test_decode_char(result, 'a');

    test_encode_decode_ascii();
    test_encode_decode_other();
    if (suc) return 0;
    else return 1;
}
