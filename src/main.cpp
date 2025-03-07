#include "huffman.h"

int main()
{
    Huffman huffman;
    int choice;
    string inputFile, outputFile;

    cout << "📂 Welcome to Huffman Compression Tool 📂\n";
    cout << "1. Compress a File\n";
    cout << "2. Decompress a File\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter filename to compress: ";
        cin >> inputFile;
        outputFile = inputFile + ".huff";
        huffman.compressFile(inputFile, outputFile);
    }
    else if (choice == 2)
    {
        cout << "Enter filename to decompress: ";
        cin >> inputFile;
        outputFile = "decompressed_" + inputFile;
        huffman.decompressFile(inputFile, outputFile);
    }
    else
    {
        cout << "Exiting...\n";
    }

    return 0;
}
