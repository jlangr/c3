#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public:
   RetweetCollection collection;
};

// START:helper
// START_HIGHLIGHT
MATCHER_P(HasSize, expected, "") { 
   return 
      arg.size() == expected && 
      arg.isEmpty() == (0 == expected); 
}
// END_HIGHLIGHT

// END:helper

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
   ASSERT_THAT(collection.isEmpty(), Eq(true));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded) {
   collection.add(Tweet());
   
   ASSERT_THAT(collection.isEmpty(), Eq(false));
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
   ASSERT_THAT(collection.size(), Eq(0));
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded) {
   collection.add(Tweet());

   ASSERT_THAT(collection.size(), Eq(1));
}

// START:helper
TEST_F(ARetweetCollection, DecreasesSizeAfterRemovingTweet) {
   collection.add(Tweet());
   
   collection.remove(Tweet());

// START_HIGHLIGHT
   ASSERT_THAT(collection, HasSize(0));
// END_HIGHLIGHT
}
// END:helper
