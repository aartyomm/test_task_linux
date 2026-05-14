#pragma once

#include<vector>
#include<string>
#include"utility.h"

void writeJsonArray(std::ofstream& file, const std::vector<std::string>& files);

void saveMediaFiles(const MediaFiles& mediaFiles, const std::string& homePath);
