#include "gmock/gmock.h"
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public:
   RetweetCollection collection;
};

MATCHER_P(HasSize, expected, "") { 
   return 
      arg.size() == expected && 
      arg.isEmpty() == (0 == expected); 
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
   ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
   ASSERT_THAT(collection.size(), Eq(0));
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero) {
   ASSERT_THAT(collection.size(), Eq(0));

   ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNonZero) {
   collection.add(Tweet());
   ASSERT_THAT(collection.size(), Gt(0));

   ASSERT_FALSE(collection.isEmpty());
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
      tweet = nullptr;
   }
};
// END:OneTweetFixture

// START:OneTweetTests
TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty) {
   ASSERT_FALSE(collection.isEmpty());
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

