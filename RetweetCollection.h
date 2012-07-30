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

// START:hasSizeOne
   unsigned int size() const {
// START_HIGHLIGHT
      return isEmpty() ? 0 : 1;
// END_HIGHLIGHT
   }
// END:hasSizeOne

private:
   bool empty_;
};
// END:alternate
#endif
