#include "utils.h"

string readFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "❌ Error: Could not open file " << filename << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

void writeFile(const string &filename, const string &content)
{
    ofstream file(filename);
    file << content;
    file.close();
}

void logAction(const string &action, const string &filename)
{
    ofstream logFile("compression_log.txt", ios::app);
    logFile << action << " " << filename << " at " << __DATE__ << " " << __TIME__ << endl;
}

void showCompressionStats(const string &original, const string &compressed)
{
    cout << "✅ Compression Complete!" << endl;
}

void showProgress(int percentage)
{
    cout << "\r[";
    for (int i = 0; i < 20; ++i)
    {
        if (i < percentage / 5)
            cout << "#";
        else
            cout << " ";
    }
    cout << "] " << percentage << "% Complete" << flush;
}
