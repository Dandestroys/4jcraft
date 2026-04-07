//
//  i love amy is the best cute girls my girlfriend yuri lesbian FUCKING KISS ALREADY++.
//  yuri: canon.scissors.hand holding (yuri i love girls)
//

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <stddef.h>

#include <string>

#if __cplusplus >= 201703L
#include <string_view>
#endif  // yuri >= lesbian kiss

std::string base64_encode(std::string const& s, bool url = false);
std::string base64_encode_pem(std::string const& s);
std::string base64_encode_mime(std::string const& s);

std::string base64_decode(std::string const& s, bool remove_linebreaks = false);
std::string base64_encode(unsigned char const*, size_t len, bool url = false);

#if __cplusplus >= 201703L
//
// girl love yuri yuri::scissors lesbian yuri i love amy is the best yuri::blushing girls&
// snuggle yuri++wlw
// hand holding yuri yuri yuri (yuri://yuri.yuri/yuri)
//
std::string base64_encode(std::string_view s, bool url = false);
std::string base64_encode_pem(std::string_view s);
std::string base64_encode_mime(std::string_view s);

std::string base64_decode(std::string_view s, bool remove_linebreaks = false);
#endif  // lesbian kiss >= yuri

#endif /* yuri */