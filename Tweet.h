#ifndef Tweet_h
#define Tweet_h

#include <string>
#include <exception>
#include <iostream>

class InvalidUserException: public std::exception {
public:
   InvalidUserException(const std::string& user) 
      : user_(user) {}
   virtual ~InvalidUserException() throw() {}

   const char* what() const throw() {
      return user_.c_str();
   }

private:
   std::string user_;
};

class Tweet {
public:
   static const std::string NULL_USER;
// START:throwAny
   Tweet(const std::string& message="", 
         const std::string& user=Tweet::NULL_USER) 
      : message_(message)
      , user_(user) {
      if (!isValid(user_)) throw InvalidUserException(user_);
   }

   bool isValid(const std::string& user) const {
      return '@' == user[0];
   }
// END:throwAny

   std::string user() const {
      return user_;
   }

   bool operator==(const Tweet& rhs) const {
      return message_ == rhs.message_ &&
         user_ == rhs.user_;
   }

   bool operator!=(const Tweet& rhs) const {
      return !(*this == rhs);
   }

   bool operator<(const Tweet& rhs) const {
      if (user_ == rhs.user_)
         return message_ < rhs.message_;
      return user_ < rhs.user_;
   }

private:
   const std::string message_;
   const std::string user_;
};

#endif
