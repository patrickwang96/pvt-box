//
// Created by Ruochen WANG on 8/5/2020.
//

#include "Directory.h"
#include <iostream>
#include <exception>

using namespace boost::filesystem;

Directory::Directory(std::string path) {
    root = boost::filesystem::path(path);


    if (!is_directory(root)) {
        // TODO change to log
        std::cerr << "Path " << path << " is not a directory!" << std::endl;
        contents.resize(0);
    } else {
        for (auto & x: directory_iterator(root)) {
            if (is_directory(x)) {
                // TODO parse sub dir later, now we ignore it
            } else if(is_regular_file(x)) {
                File f(x.path().string(), file_size(x));
                contents.emplace_back(File(x.path().string(), file_size(x)));
            } else {
                std::cerr << x.path() << " exist but not a dir or regular file." << std::endl;
            }
        }
    }
    std::cout << "Done with loading file tables" << std::endl;
}

File &Directory::getFile(std::string& str) {
    for (auto & f: contents) {
        if (f.getString() == str) return f;
    }
    throw std::out_of_range("File not found.");
}
