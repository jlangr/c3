#ifndef Tweet_h
#define Tweet_h

#include <string>

class Tweet {
public:
   static const std::string NULL_USER;
// START:throwAny
   Tweet(const std::string& message="", 
         const std::string& user=Tweet::NULL_USER) 
      : message_(message)
      , user_(user) {
      if (!isValid(user_)) throw 1;
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
