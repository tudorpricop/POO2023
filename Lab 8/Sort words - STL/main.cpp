#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>

struct SortCompare {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        if (a.second == b.second) {
            return a.first > b.first; //  lexicographically
        }
        return a.second < b.second; //  frequency
    }
};

void toLowerCase(std::string& str) {
    for (char& c : str) {
        c = std::tolower(c);
    }
}

int main()
{
    std::ifstream infile("in.txt");
    std::string input;

    std::getline(infile, input);

    std::string delim = " .?!,";

    std::map<std::string, int> word_count;

    int begin = 0;

    while ((begin = input.find_first_not_of(delim, begin)) != std::string::npos) {

        int end = input.find_first_of(delim, begin);
        std::string word = input.substr(begin, end - begin);

        toLowerCase(word);

        word_count[word]++;
        begin = end;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, SortCompare> word_queue(word_count.begin(), word_count.end());

    while (!word_queue.empty()) {
        std::cout << word_queue.top().first << " => " << word_queue.top().second << std::endl;
        word_queue.pop();
    }

    return 0;

}