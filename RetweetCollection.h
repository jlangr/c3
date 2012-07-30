#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"

// START:alternate
class RetweetCollection {
public:
   RetweetCollection() 
      : empty_(true) {
   }

   bool isEmpty() const {
      return empty_;
   }

   void add(const Tweet& tweet) {
      empty_ = false;
   }

   unsigned int size() const {
      return 0;
   }

private:
   bool empty_;
};
// END:alternate
#endif
