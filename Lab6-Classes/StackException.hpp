/* 
 * File:   StackException.hpp
 * Author: dale
 *
 * Created on November 14, 2011, 6:40 PM
 */

#ifndef STACKEXCEPTION_HPP
#define	STACKEXCEPTION_HPP

#include <string>

class StackException {
private:
    std::string message;
public:
    inline StackException(std::string msg) {
        message = msg;
    }

    inline std::string getMessage(void) {
        return message;
    }
};


#endif	/* STACKEXCEPTION_H */

