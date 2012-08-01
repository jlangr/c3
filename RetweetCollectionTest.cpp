#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

// START:helper
class ARetweetCollection: public Test {
public:
   RetweetCollection collection;

// START_HIGHLIGHT
// TODO: google test might have a better way to do this...
   void ASSERT_SIZE(unsigned int expected) {
      ASSERT_THAT(collection.size(), Eq(expected));
      ASSERT_THAT(collection.isEmpty(), Eq(0 == expected));
   }
// END_HIGHLIGHT
};

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

TEST_F(ARetweetCollection, DISABLED_DecreasesSizeAfterRemovingTweet) {
   collection.add(Tweet());
   
   collection.remove(Tweet());

   ASSERT_SIZE(0);
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero) {
   ASSERT_THAT(collection.size(), Eq(0));

   ASSERT_THAT(collection.isEmpty(), Eq(true));
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNonZero) {
   collection.add(Tweet());
   ASSERT_THAT(collection.size(), Gt(0));

   ASSERT_THAT(collection.isEmpty(), Eq(false));
}

// START:IncrementsSizeWhenTweetAdded
TEST_F(ARetweetCollection, IncrementsSizeWhenTweetAdded) {
   Tweet first("msg1", "@user");
   collection.add(first);
   Tweet second("msg2", "@user");

   collection.add(second);

   ASSERT_THAT(collection.size(), Eq(2));
}
// END:IncrementsSizeWhenTweetAdded

// START:IgnoreDuplicates
TEST_F(ARetweetCollection, IgnoresDuplicateTweetAdded) {
   Tweet tweet("msg", "@user");
   Tweet duplicate(tweet);
   collection.add(tweet);

   collection.add(duplicate);

   ASSERT_THAT(collection.size(), Eq(1));
}
// END:IgnoreDuplicates

