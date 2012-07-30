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
      return isEmpty() ? 0 : 1;
   }

// START:hasSizeOne
   void remove(const Tweet& tweet) {
      empty_ = true;
   }
// END:hasSizeOne

private:
   bool empty_;
};
// END:alternate
#endif
