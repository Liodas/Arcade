/*
** File.hpp for Arcade
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Mon Mar 13 16:23:03 2017 gastal_r
** Last update	Tue Mar 14 00:10:10 2017 gastal_r
*/

#ifndef         _FILE_HPP_
#define         _FILE_HPP_

#include        <dirent.h>
#include        <sys/types.h>
#include        <algorithm>
#include        <vector>
#include        <string>
#include        "Exception.hpp"

class File
{
public:
  File (const std::string);
  virtual ~File (){};

  bool          checkExtension(const std::string &str) const;
  std::vector<std::string> getLibs() const;

  static DIR    *Opendir(const char *name)
  {
    return (opendir(name));
  }

  static struct dirent *Readdir(DIR *dirp)
  {
    return (readdir(dirp));
  }

  static int Closedir(DIR *dirp) { return (closedir(dirp)); }

private:
  std::string   _path;
};

#endif          /* !_FILE_HPP_ */