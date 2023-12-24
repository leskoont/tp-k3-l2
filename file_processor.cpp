#include "file_processor.h"
#include <cctype>
#include <cstring>
#include <stdexcept>

FileProcessor::FileProcessor() : text(nullptr), length(0) {
    std::cout << "FileProcessor Default constructor called." << std::endl;
}

FileProcessor::FileProcessor(const char* filename) : text(nullptr), length(0) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Cannot open file.");
    }

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    setText(fileContent.c_str());
    std::cout << "FileProcessor Parametrized constructor called." << std::endl;
    std::cout << "Read text from file: " << fileContent << std::endl;
}

FileProcessor::FileProcessor(const FileProcessor& other) : text(nullptr), length(0) {
    setText(other.text);
    std::cout << "FileProcessor Copy constructor called." << std::endl;
}

FileProcessor::~FileProcessor() {
    delete[] text;
    std::cout << "FileProcessor Destructor called." << std::endl;
}

void FileProcessor::setText(const char* newText) {
    if (newText == nullptr) {
        throw std::invalid_argument("Text cannot be null.");
    }

    length = std::strlen(newText);
    text = new char[length + 1];
    if (strcpy_s(text, length + 1, newText) != 0) {
        // Обработка ошибки, если копирование не удалось
        throw std::runtime_error("Error copying string.");
    }
}

int FileProcessor::getLength() const {
    return length;
}

const char* FileProcessor::getText() const {
    return text;
}

FileProcessor& FileProcessor::operator=(const FileProcessor& other) {
    if (this != &other) {
        delete[] text;
        setText(other.text);
    }
    std::cout << "FileProcessor Assignment operator called." << std::endl;
    return *this;
}

int FileProcessor::countPunctuation() const {
    int punctuationCount = 0;
    for (int i = 0; i < getLength(); ++i) {
        if (ispunct(getText()[i])) {
            ++punctuationCount;
        }
    }
    return punctuationCount;
}

void FileProcessor::displayMaxPunctuationSentence() const {
    const char* text = getText();
    int maxLength = 0;
    int currentLength = 0;
    const char* maxPunctuationSentenceStart = nullptr;

    for (int i = 0; i <= getLength(); ++i) {
        if (ispunct(text[i]) || text[i] == '\0') {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxPunctuationSentenceStart = text + i - currentLength;
            }
            currentLength = 0;
        }
        else {
            ++currentLength;
        }
    }

    if (maxPunctuationSentenceStart != nullptr) {
        std::cout << "Sentence with max punctuation: ";
        for (int i = 0; i < maxLength; ++i) {
            std::cout << maxPunctuationSentenceStart[i];
        }
        std::cout << std::endl;
    }
}