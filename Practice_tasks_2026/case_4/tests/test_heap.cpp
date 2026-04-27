#include <gtest/gtest.h>

#include "../src/heap.h"

TEST(HeapTest, NewHeapIsEmpty) {
    Heap<int> h;
    EXPECT_TRUE(h.empty());
    EXPECT_EQ(h.size(), 0u);
}

TEST(HeapTest, PushIncreasesSize) {
    Heap<int> h;
    h.push(5);
    EXPECT_EQ(h.size(), 1u);
    h.push(10);
    EXPECT_EQ(h.size(), 2u);
}

TEST(HeapTest, PushMakesHeapNonEmpty) {
    Heap<int> h;
    h.push(1);
    EXPECT_FALSE(h.empty());
}

TEST(HeapTest, TopReturnsMaxElement) {
    Heap<int> h;
    h.push(3);
    h.push(1);
    h.push(7);
    h.push(2);
    EXPECT_EQ(h.top(), 7);
}

TEST(HeapTest, PopReturnsMaxElement) {
    Heap<int> h;
    h.push(4);
    h.push(9);
    h.push(2);
    EXPECT_EQ(h.pop(), 9);
}

TEST(HeapTest, PopMaintainsMaxHeapProperty) {
    Heap<int> h;
    h.push(5);
    h.push(3);
    h.push(8);
    h.push(1);
    EXPECT_EQ(h.pop(), 8);
    EXPECT_EQ(h.pop(), 5);
    EXPECT_EQ(h.pop(), 3);
    EXPECT_EQ(h.pop(), 1);
}

TEST(HeapTest, PopDecreasesSize) {
    Heap<int> h;
    h.push(1);
    h.push(2);
    h.pop();
    EXPECT_EQ(h.size(), 1u);
}

TEST(HeapTest, PopFromEmptyHeapThrows) {
    Heap<int> h;
    EXPECT_THROW(h.pop(), std::underflow_error);
}

TEST(HeapTest, TopFromEmptyHeapThrows) {
    Heap<int> h;
    EXPECT_THROW(h.top(), std::underflow_error);
}

TEST(HeapTest, PopLastElementMakesHeapEmpty) {
    Heap<int> h;
    h.push(42);
    h.pop();
    EXPECT_TRUE(h.empty());
}

TEST(HeapTest, DuplicateValuesHandledCorrectly) {
    Heap<int> h;
    h.push(5);
    h.push(5);
    h.push(5);
    EXPECT_EQ(h.size(), 3u);
    EXPECT_EQ(h.pop(), 5);
    EXPECT_EQ(h.pop(), 5);
}

TEST(HeapTest, SingleElementPushPop) {
    Heap<int> h;
    h.push(100);
    EXPECT_EQ(h.pop(), 100);
    EXPECT_TRUE(h.empty());
}
