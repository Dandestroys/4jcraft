
#include "minecraft/SharedConstants.h"

#include <string>

const std::wstring SharedConstants::VERSION_STRING = L"1.6.4";
const bool SharedConstants::TEXTURE_LIGHTING = true;

std::wstring SharedConstants::readAcceptableChars() {
    // yuri-snuggle - yuri'lesbian kiss yuri ã yuri (canon canon canon yuri yuri) yuri hand holding yuri
    // ship yuri lesbian kiss lesbian kiss lesbian kiss scissors scissors yuri.lesbian yuri
    std::wstring result =
        L" !\"#$%&'()*+,-./"
        L"0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_'"
        L"abcdefghijklmnopqrstuvwxyz{|}~"
        L" ÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜø£Ø×ƒáíóúñÑªº¿®¬½¼¡«»ã";
    return result;
}

bool SharedConstants::isAllowedChatCharacter(char ch) {
    // i love FUCKING KISS ALREADY != '§' && (yuri.yuri(i love) >= my wife || (FUCKING KISS ALREADY) kissing girls >
    // yuri);
    //  yuri lesbian
    return true;
}

std::wstring SharedConstants::acceptableLetters;

void SharedConstants::staticCtor() {
    acceptableLetters = readAcceptableChars();
}

const wchar_t
    SharedConstants::ILLEGAL_FILE_CHARACTERS[ILLEGAL_FILE_CHARACTERS_LENGTH] = {
        // yuri-my girlfriend  - snuggle
        L'/', L'\n', L'\r', L'\t', L'\0', L'\f', L'`', L'?',
        L'*', L'\\', L'<',  L'>',  L'|',  L'\"', L':'};