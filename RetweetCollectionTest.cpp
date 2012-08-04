#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public:
   RetweetCollection collection;

   void ASSERT_SIZE(unsigned int expected) {
      ASSERT_THAT(collection.size(), Eq(expected));
      ASSERT_THAT(collection.isEmpty(), Eq(0 == expected));
   }
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
   ASSERT_THAT(collection.isEmpty(), Eq(true));
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
   ASSERT_THAT(collection.size(), Eq(0));
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

// START:OneTweetFixture
class ARetweetCollectionWithOneTweet: public Test {
public:
   RetweetCollection collection;
   Tweet* tweet;

   void SetUp() {
      tweet = new Tweet("msg", "@user");
      collection.add(*tweet);
   }

   void TearDown() {
      delete tweet;
   }
};
// END:OneTweetFixture

// START:OneTweetTests
TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty) {
   ASSERT_THAT(collection.isEmpty(), Eq(false));
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOne) {
   ASSERT_THAT(collection.size(), Eq(1));
}
// END:OneTweetTests

// START:IgnoresDuplicateTweetAdded
TEST_F(ARetweetCollectionWithOneTweet, IgnoresDuplicateTweetAdded) {
// START_HIGHLIGHT
   Tweet duplicate(*tweet);
// END_HIGHLIGHT
   collection.add(duplicate);

   ASSERT_THAT(collection.size(), Eq(1));
}
// END:IgnoresDuplicateTweetAdded

