#include "huffman.h"
#include "utils.h"

Huffman::Huffman() { root = nullptr; }

void Huffman::buildFrequencyMap(const string &text)
{
    for (char ch : text)
        frequencyMap[ch]++;
}

Node *Huffman::buildHuffmanTree()
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto pair : frequencyMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    return pq.top();
}

void Huffman::generateCodes(Node *root, string str)
{
    if (!root)
        return;
    if (root->data != '\0')
        huffmanCodes[root->data] = str;
    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

string Huffman::encodeText(const string &text)
{
    string encodedText = "";
    for (char ch : text)
        encodedText += huffmanCodes[ch];
    return encodedText;
}

string Huffman::decodeText(const string &encodedText)
{
    string decodedText = "";
    Node *current = root;
    for (char bit : encodedText)
    {
        current = (bit == '0') ? current->left : current->right;
        if (!current->left && !current->right)
        {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}

void Huffman::compressFile(const string &inputFile, const string &outputFile)
{
    string text = readFile(inputFile);
    if (text.empty())
        return;

    buildFrequencyMap(text);
    root = buildHuffmanTree();
    generateCodes(root, "");

    string encodedText = encodeText(text);
    writeFile(outputFile, encodedText);

    logAction("Compressed", inputFile);
    showCompressionStats(inputFile, outputFile);
}

void Huffman::decompressFile(const string &inputFile, const string &outputFile)
{
    string encodedText = readFile(inputFile);
    if (encodedText.empty())
        return;

    string decodedText = decodeText(encodedText);
    writeFile(outputFile, decodedText);

    logAction("Decompressed", inputFile);
}
