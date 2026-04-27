#include <gtest/gtest.h>

#include "../src/binary_tree.h"

TEST(BinaryTreeTest, NewTreeIsEmpty) {
    BinaryTree<int> t;
    EXPECT_TRUE(t.empty());
    EXPECT_EQ(t.size(), 0u);
}

TEST(BinaryTreeTest, PushIncreasesSize) {
    BinaryTree<int> t;
    t.push(5);
    EXPECT_EQ(t.size(), 1u);
    t.push(3);
    EXPECT_EQ(t.size(), 2u);
}

TEST(BinaryTreeTest, PushMakesTreeNonEmpty) {
    BinaryTree<int> t;
    t.push(10);
    EXPECT_FALSE(t.empty());
}

TEST(BinaryTreeTest, SearchFindsExistingElement) {
    BinaryTree<int> t;
    t.push(5);
    t.push(3);
    t.push(7);
    EXPECT_TRUE(t.search(5));
    EXPECT_TRUE(t.search(3));
    EXPECT_TRUE(t.search(7));
}

TEST(BinaryTreeTest, SearchReturnsFalseForMissingElement) {
    BinaryTree<int> t;
    t.push(5);
    t.push(3);
    EXPECT_FALSE(t.search(99));
}

TEST(BinaryTreeTest, SearchOnEmptyTreeReturnsFalse) {
    BinaryTree<int> t;
    EXPECT_FALSE(t.search(1));
}

TEST(BinaryTreeTest, PopRemovesElement) {
    BinaryTree<int> t;
    t.push(5);
    t.push(3);
    t.push(7);
    t.pop(3);
    EXPECT_FALSE(t.search(3));
}

TEST(BinaryTreeTest, PopDecreasesSize) {
    BinaryTree<int> t;
    t.push(5);
    t.push(3);
    t.pop(3);
    EXPECT_EQ(t.size(), 1u);
}

TEST(BinaryTreeTest, PopNonExistentElementDoesNothing) {
    BinaryTree<int> t;
    t.push(5);
    t.pop(99);
    EXPECT_EQ(t.size(), 1u);
    EXPECT_TRUE(t.search(5));
}

TEST(BinaryTreeTest, PopRootWithTwoChildren) {
    BinaryTree<int> t;
    t.push(5);
    t.push(3);
    t.push(7);
    t.pop(5);
    EXPECT_FALSE(t.search(5));
    EXPECT_TRUE(t.search(3));
    EXPECT_TRUE(t.search(7));
}

TEST(BinaryTreeTest, PopLastElementMakesTreeEmpty) {
    BinaryTree<int> t;
    t.push(42);
    t.pop(42);
    EXPECT_TRUE(t.empty());
}

TEST(BinaryTreeTest, PushAndSearchMultipleElements) {
    BinaryTree<int> t;
    for (int i = 1; i <= 10; ++i) {
        t.push(i);
    }
    EXPECT_EQ(t.size(), 10u);
    for (int i = 1; i <= 10; ++i) {
        EXPECT_TRUE(t.search(i));
    }
}

TEST(BinaryTreeTest, DuplicatePushDoesNotIncreaseSizeForBST) {
    BinaryTree<int> t;
    t.push(5);
    t.push(5);
    EXPECT_EQ(t.size(), 1u);
}

TEST(BinaryTreeTest, WorksWithStrings) {
    BinaryTree<std::string> t;
    t.push("banana");
    t.push("apple");
    t.push("cherry");
    EXPECT_TRUE(t.search("apple"));
    EXPECT_FALSE(t.search("grape"));
    t.pop("apple");
    EXPECT_FALSE(t.search("apple"));
}
