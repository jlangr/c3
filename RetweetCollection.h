#ifndef RetweetCollection_h
#define RetweetCollection_h

// START:add
// START_HIGHLIGHT
#include "Tweet.h"
// END_HIGHLIGHT

class RetweetCollection {
public:
// START_HIGHLIGHT
   RetweetCollection() 
      : size_(0) {
   }
// END_HIGHLIGHT

   bool isEmpty() const {
      return 0 == size();
   }

   unsigned int size() const {
      return size_;
   }

// START_HIGHLIGHT
   void add(const Tweet& tweet) {
      size_ = 1;
   }
// END_HIGHLIGHT

// START_HIGHLIGHT
private:
   unsigned int size_;
// END_HIGHLIGHT
};
// END:add
#endif
