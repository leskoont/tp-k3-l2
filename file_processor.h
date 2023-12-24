#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <fstream>

class FileProcessor {
private:
    char* text;
    int length;

    void setText(const char* newText);

public:
    FileProcessor();
    FileProcessor(const char* filename);
    FileProcessor(const FileProcessor& other);
    ~FileProcessor();

    int getLength() const;
    const char* getText() const;

    FileProcessor& operator=(const FileProcessor& other);

    int countPunctuation() const;
    void displayMaxPunctuationSentence() const;
};

#endif // FILE_PROCESSOR_H