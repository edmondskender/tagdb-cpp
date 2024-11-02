//
// Created by edmond on 01.11.24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::cout, std::endl;

void help() {
    std::ifstream ifs("help.txt");
    std::string line;
    while(std::getline(ifs, line)) {
        cout << line << endl;
    }
}

void append(const std::vector<std::string>& content_to_append) {
    std::string filename("tagdb.txt");
    std::ofstream ofs(filename, std::ios::app);
    if(!ofs.is_open()) {
        std::cerr << "File could not open!" << std::endl;
        return;
    }
    for(const auto& line : content_to_append) {
        ofs << line << endl;
    }
}

void search(const std::vector<std::vector<std::string>>& queries) {
    std::string filename("tagdb.txt");
    std::ifstream ifs(filename);
    if(!ifs.is_open()) {
        std::cerr << "File could not open!" << std::endl;
        exit(-1);
    }
    std::string line;
    while(std::getline(ifs, line)) {
        std::stringstream ss(line);
        std::string line_tags;
        std::getline(ss, line_tags, ' ');

        std::vector<std::string> tags;
        std::stringstream ss_tags(line_tags);
        std::string tag;
        while(std::getline(ss_tags, tag, ',' )) {
            tags.push_back(tag);
        }

        bool match = false;
        for(const auto& querieTokens : queries) {
            bool all_tokens_found = true;
            for(const auto& token : querieTokens) {
                if(std::find(tags.begin(), tags.end(), token) == tags.end()) {
                    all_tokens_found = false;
                    break;
                }
            }
            if(all_tokens_found) {
                match = true;
                break;
            }
        }

        if(match) {
            std::string content;
            getline(ss, content);
            cout << content << endl;
        }

    }
}


int main(int argc, char **argv) {
    if(argc == 1 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        help();
    } else if (std::string(argv[1]) == "-a") {
        std::vector<std::string> content_to_append;
        std::stringstream ss;
        for(size_t i = 2; i < argc; ++i) {
            ss << argv[i] << " ";
        }
        content_to_append.push_back(ss.str());
        append(content_to_append);
    } else if (std::string(argv[1]) == "-q") {
        std::vector<std::vector<std::string>> searchQueries;
        for(int i = 2; i < argc; i+=2) {
            std::string line(argv[i]);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            searchQueries.push_back(tokens);
        }
        search(searchQueries);
    }
    return 0;
}
