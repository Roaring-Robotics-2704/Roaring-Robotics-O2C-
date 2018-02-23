/*
 * libc.h
 *
 *  Created on: Feb 20, 2018
 *      Author: cryog
 */

#ifndef SRC_UNREGISTEREDMODULES_LIBC_H_
#define SRC_UNREGISTEREDMODULES_LIBC_H_


#include <algorithm>
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string &s) { // Trim the left side of a string for whitespace
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {  // Trim the right side of a string for whitespace
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) { // Removes the whitespace at the beginning and end of a string
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) { // Same as `ltrim` except returns the new string without changing the original string
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) { // Same as `rtrim` except returns the new string without changing the original string
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) { // Same as `trim` except returns the new string without changing the original string
    trim(s);
    return s;
}


#endif /* SRC_UNREGISTEREDMODULES_LIBC_H_ */
