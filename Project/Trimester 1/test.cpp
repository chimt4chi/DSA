#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

// Function to load stop words into a set
set<string> loadStopWords()
{
    return {"a", "an", "and", "the", "of", "in"};
}

// Function to count words in a line, excluding stop words
void countWords(const string &line, int &totalWordCount, int &filteredWordCount, const set<string> &stopWords)
{
    stringstream ss(line);
    string word;

    while (ss >> word)
    { // Extract words from the line
        // Convert to lowercase for comparison
        string lowerWord;
        for (char c : word)
        {
            lowerWord += tolower(c);
        }

        totalWordCount++; // Increment total word count

        // Increment filtered count if the word is not a stop word
        if (stopWords.find(lowerWord) == stopWords.end())
        {
            filteredWordCount++;
        }
    }
}

// Function to process the file and count words
void processFile(const string &filename, int &totalWordCount, int &filteredWordCount)
{
    ifstream ofile(filename);
    if (!ofile)
    {
        cerr << "Error opening file";
        return; // Exit the function if file can't be opened
    }

    string line;
    while (getline(ofile, line))
    {
        countWords(line, totalWordCount, filteredWordCount, loadStopWords());
    }

    ofile.close();
}

int main()
{
    int totalWordCount = 0;
    int filteredWordCount = 0;

    processFile("todo.txt", totalWordCount, filteredWordCount);

    cout << "Total word count: " << totalWordCount << endl;
    cout << "Total word count (excluding common words): " << filteredWordCount << endl;

    return 0;
}
