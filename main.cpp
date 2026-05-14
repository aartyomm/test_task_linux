#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include "utility.h"
#include "json_writer.h"
#include "scaner.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "usage: " << argv[0] << " <path> <interval_seconds>\n";
        return 1;
    }

    std::string path = argv[1];
    if (!std::filesystem::exists(path)) {
        std::cout << "path does not exist\n";
        return 1;
    }
    if (!std::filesystem::is_directory(path)) {
        std::cout << "path is not a directory\n";
        return 1;
    }

    int interval;
    try {
        interval = std::stoi(argv[2]);
    }
    catch (...) {
        std::cerr << "invalid interval\n";
        return 1;
    }
    if (interval <= 0) {
        std::cerr << "interval must be greater than 0\n";
        return 1;
    }

    try {
        while (true) {
            MediaFiles mediaFiles = scanMediaFiles(path);
            saveMediaFiles(mediaFiles, path);
            std::this_thread::sleep_for(std::chrono::seconds(interval));
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
