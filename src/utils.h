#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

string readFile(const string &filename);
void writeFile(const string &filename, const string &content);
void logAction(const string &action, const string &filename);
void showCompressionStats(const string &original, const string &compressed);
void showProgress(int percentage);

#endif // UTILS_H
