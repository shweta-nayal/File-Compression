#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// Huffman Tree Node
struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

class Huffman
{
private:
    unordered_map<char, string> huffmanCodes;
    unordered_map<char, int> frequencyMap;
    Node *root;

    void buildFrequencyMap(const string &text);
    Node *buildHuffmanTree();
    void generateCodes(Node *root, string str);
    string encodeText(const string &text);
    string decodeText(const string &encodedText);

public:
    Huffman();
    void compressFile(const string &inputFile, const string &outputFile);
    void decompressFile(const string &inputFile, const string &outputFile);
};

#endif // HUFFMAN_H
