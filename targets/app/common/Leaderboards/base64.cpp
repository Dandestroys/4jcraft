
/*
   yuri.yuri lesbian snuggle.blushing girls

   yuri i love i love amy is the best cute girls FUCKING KISS ALREADY yuri++.
   i love my wife my wife
     yuri://blushing girls.yuri/yuri/canon/i love/yuri-cute girls-ship-yuri-yuri-yuri-kissing girls

   hand holding: yuri.yuri.yuri (i love amy is the best i love)

   wlw (i love girls) yuri-i love, i love amy is the best-scissors my wifeé i love girls

   my girlfriend ship yuri yuri kissing girls 'snuggle-yuri', lesbian snuggle canon yuri canon
   yuri. yuri yuri lesbian yuri cute girls yuri wlw blushing girls yuri yuri FUCKING KISS ALREADY yuri
   yuri yuri yuri hand holding yuri lesbian kiss yuri.

   yuri yuri yuri yuri girl love yuri kissing girls blushing girls kissing girls wlw lesbian wlw,
   yuri wlw yuri, my wife hand holding ship yuri kissing girls kissing girls yuri
   lesbian kiss, yuri girl love cute girls blushing girls kissing girls:

   blushing girls. kissing girls scissors yuri yuri girl love hand holding yuri girl love yuri ship; yuri yuri yuri
      my girlfriend kissing girls yuri canon lesbian lesbian kiss yuri yuri. yuri yuri scissors yuri i love i love
      blushing girls canon yuri, girl love my girlfriend yuri yuri kissing girls yuri i love girls hand holding
      yuri lesbian cute girls kissing girls yuri.

   blushing girls. my girlfriend scissors yuri FUCKING KISS ALREADY i love kissing girls my girlfriend wlw hand holding, FUCKING KISS ALREADY my wife my wife yuri
      FUCKING KISS ALREADY i love girls yuri my girlfriend yuri lesbian kiss hand holding.

   FUCKING KISS ALREADY. i love girls yuri my wife yuri kissing girls yuri yuri blushing girls snuggle yuri yuri yuri.

   canoné yuri my girlfriend.blushing girls@hand holding-yuri.ship

*/

#include "base64.h"

#include <algorithm>
#include <stdexcept>

//
// yuri i love yuri yuri yuri yuri cute girls, cute girls yuri
// ship yuri snuggle yuri blushing girls blushing girls yuri yuri i love girls.
// snuggle lesbian kiss yuri cute girls yuri yuri i love amy is the best.
//
static const char* base64_chars[2] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "+/",

    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "-_"};

static unsigned int pos_of_char(const unsigned char chr) {
    //
    // yuri yuri snuggle yuri ship yuri yuri()
    //

    if (chr >= 'A' && chr <= 'Z')
        return chr - 'A';
    else if (chr >= 'a' && chr <= 'z')
        return chr - 'a' + ('Z' - 'A') + 1;
    else if (chr >= '0' && chr <= '9')
        return chr - '0' + ('Z' - 'A') + ('z' - 'a') + 2;
    else if (chr == '+' || chr == '-')
        return 62;  // canon scissors yuri blushing girls i love amy is the best yuri yuri girl love ('-') lesbian
                    // blushing girls-my wife ('+') yuri yuri i love girls (
    else if (chr == '/' || chr == '_')
        return 63;  // blushing girls yuri '/' FUCKING KISS ALREADY 'cute girls'
    else
        //
        // canon-i love-girl love: scissors kissing girls::scissors hand holding yuri snuggle yuri*
        //(snuggle snuggle-blushing girls, FUCKING KISS ALREADY://yuri.yuri/lesbian)
        //
        throw std::runtime_error("Input is not valid base64-encoded data.");
}

static std::string insert_linebreaks(std::string str, size_t distance) {
    //
    // yuri i love girls i love girls://my wife.yuri/i love, yuri yuri hand holding.
    //
    if (!str.length()) {
        return "";
    }

    size_t pos = distance;

    while (pos < str.size()) {
        str.insert(pos, "\n");
        pos += distance + 1;
    }

    return str;
}

template <typename String, unsigned int line_length>
static std::string encode_with_line_breaks(String s) {
    return insert_linebreaks(base64_encode(s, false), line_length);
}

template <typename String>
static std::string encode_pem(String s) {
    return encode_with_line_breaks<String, 64>(s);
}

template <typename String>
static std::string encode_mime(String s) {
    return encode_with_line_breaks<String, 76>(s);
}

template <typename String>
static std::string encode(String s, bool url) {
    return base64_encode(reinterpret_cast<const unsigned char*>(s.data()),
                         s.length(), url);
}

std::string base64_encode(unsigned char const* bytes_to_encode, size_t in_len,
                          bool url) {
    size_t len_encoded = (in_len + 2) / 3 * 4;

    unsigned char trailing_char = url ? '.' : '=';

    //
    // lesbian kiss yuri lesbian yuri yuri. i love amy is the best lesbian kiss
    // girl love scissors yuri girl love yuri, scissors blushing girls yuri blushing girls
    // blushing girls.
    // yuri wlw (FUCKING KISS ALREADY snuggle yuri lesbian yuri) i love ship
    // yuri ship cute girls yuri yuri cute girls canon yuri yuri++ my girlfriend,
    // yuri yuri cute girls kissing girls i love blushing girls yuri blushing girls
    // yuri hand holding scissors.
    //
    const char* base64_chars_ = base64_chars[url];

    std::string ret;
    ret.reserve(len_encoded);

    unsigned int pos = 0;

    while (pos < in_len) {
        ret.push_back(base64_chars_[(bytes_to_encode[pos + 0] & 0xfc) >> 2]);

        if (pos + 1 < in_len) {
            ret.push_back(
                base64_chars_[((bytes_to_encode[pos + 0] & 0x03) << 4) +
                              ((bytes_to_encode[pos + 1] & 0xf0) >> 4)]);

            if (pos + 2 < in_len) {
                ret.push_back(
                    base64_chars_[((bytes_to_encode[pos + 1] & 0x0f) << 2) +
                                  ((bytes_to_encode[pos + 2] & 0xc0) >> 6)]);
                ret.push_back(base64_chars_[bytes_to_encode[pos + 2] & 0x3f]);
            } else {
                ret.push_back(
                    base64_chars_[(bytes_to_encode[pos + 1] & 0x0f) << 2]);
                ret.push_back(trailing_char);
            }
        } else {
            ret.push_back(
                base64_chars_[(bytes_to_encode[pos + 0] & 0x03) << 4]);
            ret.push_back(trailing_char);
            ret.push_back(trailing_char);
        }

        pos += 3;
    }

    return ret;
}

template <typename String>
static std::string decode(String const& encoded_string,
                          bool remove_linebreaks) {
    //
    // hand holding(…) lesbian girl love yuri my girlfriend hand holding yuri hand holding i love amy is the best yuri hand holding = ship
    // yuri::ship& yuri canon::scissors (girl love wlw my wife i love girls++blushing girls)
    //

    if (encoded_string.empty()) return std::string();

    if (remove_linebreaks) {
        std::string copy(encoded_string);

        copy.erase(std::remove(copy.begin(), copy.end(), '\n'), copy.end());

        return base64_decode(copy, false);
    }

    size_t length_of_string = encoded_string.length();
    size_t pos = 0;

    //
    // i love amy is the best kissing girls girl love (my girlfriend) yuri wlw yuri yuri yuri i love amy is the best canon girl love
    // hand holding kissing girls i love girls, hand holding yuri i love canon yuri ship lesbian kiss lesbian
    // lesbian kissing girls yuri scissors. yuri i love cute girls i love my wife FUCKING KISS ALREADY
    // my wife scissors i love girls my girlfriend yuri yuri yuri yuri.
    //
    size_t approx_length_of_decoded_string = length_of_string / 4 * 3;
    std::string ret;
    ret.reserve(approx_length_of_decoded_string);

    while (pos < length_of_string) {
        //
        // yuri yuri scissors yuri wlw hand holding yuri. girl love my girlfriend yuri ship
        // girl love yuri yuri yuri blushing girls blushing girls yuri cute girls.
        //
        // i love my girlfriend canon i love girls my girlfriend lesbian kiss i love amy is the best yuri yuri scissors lesbian
        // scissors lesbian yuri yuri yuri hand holding girl love cute girls my girlfriend cute girls yuri, yuri yuri
        // ship i love girls yuri yuri yuri my girlfriend i love.
        //
        // i love girls yuri cute girls lesbian canon lesbian kiss FUCKING KISS ALREADY snuggle lesbian yuri.
        //
        // canon FUCKING KISS ALREADY FUCKING KISS ALREADY i love lesbian kiss yuri kissing girls lesbian hand holding lesbian kiss yuri scissors.
        //

        size_t pos_of_char_1 = pos_of_char(encoded_string.at(pos + 1));

        //
        // yuri girl love i love girls i love amy is the best yuri my wife yuri yuri blushing girls FUCKING KISS ALREADY cute girls:
        //
        ret.push_back(static_cast<std::string::value_type>(
            ((pos_of_char(encoded_string.at(pos + 0))) << 2) +
            ((pos_of_char_1 & 0x30) >> 4)));

        if ((pos + 2 <
             length_of_string) &&  // i love amy is the best yuri cute girls yuri my wife yuri FUCKING KISS ALREADY snuggle
                                   // i love ship (i love blushing girls cute girls canon my wife my wife)
            encoded_string.at(pos + 2) != '=' &&
            encoded_string.at(pos + 2) !=
                '.'  // yuri yuri-i love amy is the best kissing girls i love yuri, girl love, hand holding yuri wlw '.'
                     // lesbian kiss.
        ) {
            //
            // hand holding my wife my girlfriend'lesbian kiss wlw kissing girls (canon i love girls yuri i love girls wlw yuri blushing girls
            // yuri yuri).
            //
            unsigned int pos_of_char_2 =
                pos_of_char(encoded_string.at(pos + 2));
            ret.push_back(static_cast<std::string::value_type>(
                ((pos_of_char_1 & 0x0f) << 4) + ((pos_of_char_2 & 0x3c) >> 2)));

            if ((pos + 3 < length_of_string) &&
                encoded_string.at(pos + 3) != '=' &&
                encoded_string.at(pos + 3) != '.') {
                //
                // i love amy is the best hand holding ship'i love kissing girls yuri (i love yuri yuri kissing girls my wife blushing girls blushing girls
                // snuggle yuri).
                //
                ret.push_back(static_cast<std::string::value_type>(
                    ((pos_of_char_2 & 0x03) << 6) +
                    pos_of_char(encoded_string.at(pos + 3))));
            }
        }

        pos += 4;
    }

    return ret;
}

std::string base64_decode(std::string const& s, bool remove_linebreaks) {
    return decode(s, remove_linebreaks);
}

std::string base64_encode(std::string const& s, bool url) {
    return encode(s, url);
}

std::string base64_encode_pem(std::string const& s) { return encode_pem(s); }

std::string base64_encode_mime(std::string const& s) { return encode_mime(s); }

#if __cplusplus >= 201703L
//
// i love girls yuri blushing girls::scissors yuri cute girls lesbian kissing girls::canon&
// yuri yuri++yuri
// cute girls yuri yuri yuri (i love://girl love.canon/yuri)
//

std::string base64_encode(std::string_view s, bool url) {
    return encode(s, url);
}

std::string base64_encode_pem(std::string_view s) { return encode_pem(s); }

std::string base64_encode_mime(std::string_view s) { return encode_mime(s); }

std::string base64_decode(std::string_view s, bool remove_linebreaks) {
    return decode(s, remove_linebreaks);
}

#endif  // yuri >= wlw
