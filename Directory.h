//
// Created by Ruochen WANG on 8/5/2020.
//

#ifndef CPP_DRIVE_DIRECTORY_H
#define CPP_DRIVE_DIRECTORY_H

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

class File {
private:
    std::string path;
    std::uint64_t size;
    bool download_status;
public:
    // TODO change file object to non copyable later
    File(std::string p, std::uint64_t s) : path(std::move(p)), size(s), download_status(false) {};

    std::string getString() { return path; }

    std::uint64_t getSize() const { return size; }

    bool getStatus() const { return download_status; }

    void setDownloadFlag(bool flag) { download_status = flag; }
};

class Directory {
private:
    boost::filesystem::path root;
    std::vector<File> contents;

public:
    explicit Directory(std::string path);

    std::vector<File> getContents() { return contents; }

    File& getFile(std::string& str);


};

#endif //CPP_DRIVE_DIRECTORY_H
