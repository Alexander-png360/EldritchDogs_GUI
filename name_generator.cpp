#include "eldritchdogs.h"
#include <cstdlib>
#include <string>

std::string generateName(char firstLetter, int length) {
    const std::string vowels = "aeiou";
    const std::string consonants = "bcdfghjklmnpqrstvwxyz";

    std::string name(1, firstLetter);

    for (int i = 0; i < length / 2; i++) {
        char randomVowel = vowels[std::rand() % vowels.size()];
        char randomConsonant = consonants[std::rand() % consonants.size()];
        name += randomVowel;
        name += randomConsonant;
    }

    return name;
}
