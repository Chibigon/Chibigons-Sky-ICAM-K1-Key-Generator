#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <string>

// Define ANSI escape codes for color
#define ANSI_FG_GREEN "\x1B[32m"
#define ANSI_FG_BLUE "\x1B[34m"
#define ANSI_RESET "\x1B[0m"

std::string generateRandomAESKey(int keySize) {
    if (keySize != 128 && keySize != 256) {
        std::cerr << "Invalid key size. Only 128 and 256 bits are supported." << std::endl;
        return ""; // Return empty string for invalid key size
    }

    int keyBytes = keySize / 8;
    std::string aesKey;
    aesKey.reserve(keyBytes);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> distribution(0, 255);

    for (int i = 0; i < keyBytes; ++i) {
        aesKey.push_back(static_cast<char>(distribution(gen)));
    }

    return aesKey;
}

void printAnimeGirlASCIIArt() {
    std::string animeGirlArt = R"(
      ___           ___                        ___                        ___           ___           ___     
     /  /\         /  /\           ___        /  /\           ___        /  /\         /  /\         /  /\    
    /  /::\       /  /:/          /__/\      /  /::\         /__/\      /  /::\       /  /::\       /  /::|   
   /  /:/\:\     /  /:/           \__\:\    /  /:/\:\        \__\:\    /  /:/\:\     /  /:/\:\     /  /:|:|   
  /  /:/  \:\   /  /::\ ___       /  /::\  /  /::\ \:\       /  /::\  /  /:/  \:\   /  /:/  \:\   /  /:/|:|__ 
 /__/:/ \  \:\ /__/:/\:\  /\   __/  /:/\/ /__/:/\:\_\:|   __/  /:/\/ /__/:/_\_ \:\ /__/:/ \__\:\ /__/:/ |:| /\
 \  \:\  \__\/ \__\/  \:\/:/  /__/\/:/~~  \  \:\ \:\/:/  /__/\/:/~~  \  \:\__/\_\/ \  \:\ /  /:/ \__\/  |:|/:/
  \  \:\            \__\::/   \  \::/      \  \:\_\::/   \  \::/      \  \:\ \:\    \  \:\  /:/      |  |:/:/ 
   \  \:\           /  /:/     \  \:\       \  \:\/:/     \  \:\       \  \:\/:/     \  \:\/:/       |__|::/  
    \  \:\         /__/:/       \__\/        \__\::/       \__\/        \  \::/       \  \::/        /__/:/   
     \__\/         \__\/                         ~~                      \__\/         \__\/         \__\/    

)";

    std::cout << ANSI_FG_BLUE << animeGirlArt << ANSI_RESET;
    std::cout << ANSI_FG_GREEN << "Chibigon's Sky ICAM K1 Key Generator" << std::endl;
    std::cout << "Btw I love you nshout <3" << ANSI_RESET << std::endl;
}

int main() {
    while (true) {
        printAnimeGirlASCIIArt();
        std::cout << ANSI_FG_GREEN << "Choose the key size (128 or 256), or press Enter to exit: ";

        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            break; // Exit the loop if the user presses Enter
        }

        int keySize = std::stoi(input);

        std::string aesKey = generateRandomAESKey(keySize);
        if (!aesKey.empty()) {
            std::cout << "Generated AES-" << keySize << " Key: ";
            std::cout << std::hex << std::setfill('0'); // Set std::hex and setfill once before the loop
            for (unsigned char c : aesKey) {
                std::cout << std::setw(2) << static_cast<int>(c);
            }
            std::cout << std::dec << std::endl; // Reset to std::dec after printing the key
        }

        // Wait for the user to press Enter before displaying the ASCII art again
        std::cout << "Press Enter to continue...";
        std::getline(std::cin, input);
    }

    return 0;
}
