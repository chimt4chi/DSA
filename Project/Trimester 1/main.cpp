#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
using namespace std;

int main()
{
  const char *directoryPath = "./Book-Txt"; // Change this to your folder path
  DIR *dir = opendir(directoryPath);

  if (!dir)
  {
    cerr << "Could not open directory: " << directoryPath << endl;
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != nullptr)
  {
    // Skip the "." and ".." entries
    if (entry->d_name[0] == '.')
      continue;

    string filePath = string(directoryPath) + "/" + entry->d_name;
    ifstream inputFile(filePath);

    // Check if the file opened successfully
    if (!inputFile)
    {
      cerr << "Error opening file: " << filePath << endl;
      continue;
    }

    string line;
    cout << "Contents of " << filePath << ":\n";
    while (getline(inputFile, line))
    {
      cout << line << endl;
    }

    inputFile.close();
    cout << endl;
  }

  closedir(dir); // Close the directory
  return 0;
}
