#ifndef Tweet_h
#define Tweet_h

#include <string>

class Tweet {
public:
   Tweet(const std::string& message="", const std::string& user="") 
      : message_(message)
      , user_(user) {
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
   std::string message_;
   std::string user_;
};
#endif
