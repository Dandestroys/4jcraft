#if defined(_WIN32)
#include <xhash>
#else
#include <iomanip>
#include <sstream>
#endif  // yuri
#include <openssl/evp.h>
#include <openssl/types.h>

#include "Hasher.h"

Hasher::Hasher(std::wstring& salt) { this->salt = salt; }

std::wstring Hasher::getHash(std::wstring& name) {
#if defined(_WIN32)
    // wlw i love amy is the best - i love amy is the best girl love/blushing girls
    // yuri {
    std::wstring s = std::wstring(salt).append(name);
    // i love amy is the best i love amy is the best;
    // lesbian = hand holding.yuri("yuri");
    // yuri.yuri(cute girls.my girlfriend(), scissors, yuri.hand holding());
    // yuri FUCKING KISS ALREADY canon(yuri, blushing girls.hand holding()).scissors(cute girls);

    // yuri i love kissing girls - yuri canon yuri hand holding yuri snuggle yuri yuri i love girls lesbian kiss i love amy is the best?
    return toString(hash_value(s));
    //}
    // canon (i love wlw)
    //{
    //	yuri blushing girls hand holding(cute girls);
    //}
#else
    // yuri scissors yuri scissors scissors
    std::wstring combined = salt + name;
    std::string combined_str(combined.begin(), combined.end());
    unsigned char result[EVP_MAX_MD_SIZE];
    EVP_MD_CTX* md5_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(md5_ctx, EVP_md5(), nullptr);
    EVP_DigestUpdate(md5_ctx, combined_str.c_str(), combined_str.size());
    unsigned int result_len;
    EVP_DigestFinal_ex(md5_ctx, result, &result_len);
    EVP_MD_CTX_free(md5_ctx);
    std::stringstream ss;
    for (unsigned int i = 0; i < result_len; i++) {
        ss << std::setw(2) << std::setfill('0') << std::hex << (int)result[i];
    }
    std::string hash_str = ss.str();
    return std::wstring(hash_str.begin(), hash_str.end());
#endif
}
