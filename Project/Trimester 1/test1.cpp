#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

using namespace std;

// Function to load stop words into a set
set<string> loadStopWords()
{
  return {"a", "an", "and", "the", "of", "in"};
}

// Function to count words in a line, excluding stop words
void countWords(const string &line, map<string, int> &wordCount, const set<string> &stopWords)
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

    // Increment word count if not a stop word
    if (stopWords.find(lowerWord) == stopWords.end())
    {
      wordCount[lowerWord]++;
    }
  }
}

// Function to process a file and return the word count map
map<string, int> processFile(const string &filename)
{
  ifstream file(filename);
  map<string, int> wordCount;
  if (!file)
  {
    cerr << "Error opening file: " << filename << endl;
    return wordCount; // Return empty map on failure
  }

  string line;
  set<string> stopWords = loadStopWords();
  while (getline(file, line))
  {
    countWords(line, wordCount, stopWords);
  }

  file.close();
  return wordCount;
}

// Function to compare two files based on their word counts
int calculateSimilarity(const map<string, int> &count1, const map<string, int> &count2)
{
  int commonWordCount = 0;
  for (const auto &entry : count1)
  {
    if (count2.find(entry.first) != count2.end())
    {
      commonWordCount += min(entry.second, count2.at(entry.first));
    }
  }
  return commonWordCount;
}

// Function to compare multiple files and find the top N similar files
void findTopSimilarFiles(const vector<string> &filenames, int topN)
{
  vector<pair<string, map<string, int>>> fileWordCounts;

  // Process each file and store the word counts
  for (const string &filename : filenames)
  {
    fileWordCounts.push_back({filename, processFile(filename)});
  }

  // Create a vector to store similarities
  vector<pair<string, int>> similarityResults;

  // Compare each file with every other file
  for (size_t i = 0; i < fileWordCounts.size(); ++i)
  {
    for (size_t j = i + 1; j < fileWordCounts.size(); ++j)
    {
      int commonWords = calculateSimilarity(fileWordCounts[i].second, fileWordCounts[j].second);
      similarityResults.push_back({fileWordCounts[i].first + " & " + fileWordCounts[j].first, commonWords});
    }
  }

  // Sort by common words in descending order
  sort(similarityResults.begin(), similarityResults.end(), [](const pair<string, int> &a, const pair<string, int> &b)
       { return a.second > b.second; });

  // Output top N results
  cout << "Top " << topN << " similar file pairs based on common words:" << endl;
  for (int i = 0; i < min(topN, (int)similarityResults.size()); ++i)
  {
    cout << similarityResults[i].first << " - Common Words: " << similarityResults[i].second << endl;
  }
}

// Function to get all .txt files from a directory
void getTextFiles(const string &directoryPath, vector<string> &filenames)
{
#ifdef _WIN32
  WIN32_FIND_DATA findFileData;
  HANDLE hFind = FindFirstFile((directoryPath + "\\*.txt").c_str(), &findFileData);
  if (hFind != INVALID_HANDLE_VALUE)
  {
    do
    {
      filenames.push_back(directoryPath + "\\" + findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);
    FindClose(hFind);
  }
#else
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(directoryPath.c_str())) != nullptr)
  {
    while ((ent = readdir(dir)) != nullptr)
    {
      string filename = ent->d_name;
      if (filename.find(".txt") != string::npos)
      {
        filenames.push_back(directoryPath + "/" + filename);
      }
    }
    closedir(dir);
  }
  else
  {
    cerr << "Could not open directory: " << directoryPath << endl;
  }
#endif
}

int main()
{
  string directoryPath = "./Book-Txt"; // Set your directory path here
  vector<string> filenames;

  // Get all .txt files from the specified directory
  getTextFiles(directoryPath, filenames);

  // Find top 10 similar files
  findTopSimilarFiles(filenames, 10);

  return 0;
}
