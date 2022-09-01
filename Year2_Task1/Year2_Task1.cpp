#include <iostream>

#include "CustomString.h"

#define AIM 3

int main()
{
    char c_str[] = "Hey, I'm from array of characters!";
    CustomString emptyString;
    CustomString fromCharPointer = CustomString(c_str);
    CustomString fromC_String = CustomString("Just another C-string...");
    CustomString copiedString = fromC_String;
    CustomString* stringPointer = new CustomString();
    std::cout << "\nEmpty string: " << emptyString <<
        "\nString from array: " << fromCharPointer <<
        "\nString from constant C-string: " << fromC_String <<
        "\nCopied string: " << copiedString <<
        "\nEmpty string from pointer: " << *stringPointer << '\n';
    delete stringPointer;
    emptyString = CustomString("Seems, now I store something");
    std::cout << "\nFilled string: " << emptyString << '\n';
#if AIM > 3
    fromCharPointer = "I'm C-string...";
    fromCharPointer += CustomString(" But now I constracted from different strings!");
    std::cout << "\nString after concatenation: " << fromCharPointer << '\n';
#endif
#if AIM > 4
    std::cout << "\nSource string: " << fromC_String <<
        "\nCharacter to be changed: " << fromC_String[13] << '\n';
    fromC_String[13] = 'A';
    std::cout << "\nChanged string: " << fromC_String << '\n';
#endif
}