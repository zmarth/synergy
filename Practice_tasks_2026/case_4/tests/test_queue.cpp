#include <gtest/gtest.h>

#include "../src/queue.h"

TEST(QueueTest, NewQueueIsEmpty) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0u);
}

TEST(QueueTest, PushIncreasesSize) {
    Queue<int> q;
    q.push(1);
    EXPECT_EQ(q.size(), 1u);
    q.push(2);
    EXPECT_EQ(q.size(), 2u);
}

TEST(QueueTest, PushMakesQueueNonEmpty) {
    Queue<int> q;
    q.push(42);
    EXPECT_FALSE(q.empty());
}

TEST(QueueTest, PopReturnsFrontElement) {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    EXPECT_EQ(q.pop(), 10);
}

TEST(QueueTest, PopMaintainsFifoOrder) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 3);
}

TEST(QueueTest, PopDecreasesSize) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    EXPECT_EQ(q.size(), 1u);
}

TEST(QueueTest, PopLastElementMakesQueueEmpty) {
    Queue<int> q;
    q.push(99);
    q.pop();
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, PopFromEmptyQueueThrows) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::underflow_error);
}

TEST(QueueTest, FrontReturnsFirstWithoutRemoving) {
    Queue<int> q;
    q.push(5);
    q.push(10);
    EXPECT_EQ(q.front(), 5);
    EXPECT_EQ(q.size(), 2u);
}

TEST(QueueTest, FrontFromEmptyQueueThrows) {
    Queue<int> q;
    EXPECT_THROW(q.front(), std::underflow_error);
}

TEST(QueueTest, PushPopPushWorksCorrectly) {
    Queue<int> q;
    q.push(1);
    q.pop();
    q.push(2);
    EXPECT_EQ(q.front(), 2);
    EXPECT_EQ(q.size(), 1u);
}

TEST(QueueTest, WorksWithStrings) {
    Queue<std::string> q;
    q.push("hello");
    q.push("world");
    EXPECT_EQ(q.pop(), "hello");
    EXPECT_EQ(q.pop(), "world");
}

TEST(QueueTest, WorksWithDoubles) {
    Queue<double> q;
    q.push(3.14);
    q.push(2.71);
    EXPECT_DOUBLE_EQ(q.pop(), 3.14);
}
