
#include <gtest/gtest.h>
#include <dustbin/Dustbin9000.h>

class BinFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    BinFixture() : Test() {}
};

TEST_F(BinFixture, Dustbin_check) {
    Dustbin bin = Dustbin();
    Dustbin bin2 = Dustbin("blue");
    EXPECT_EQ(bin.getColor(), "gray");
    EXPECT_EQ(bin2.getColor(), "blue");
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin2.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin2.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin2.getPaperGarbageAmount(), 0);
}

TEST_F(BinFixture, Dustbin9000_check) {
    Dustbin9000 bin = Dustbin9000();
    Dustbin9000 bin2 = Dustbin9000("blue");
    EXPECT_EQ(bin.getColor(), "gray");
    EXPECT_EQ(bin2.getColor(), "blue");
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getBottlecapAmount(), 0);
    EXPECT_EQ(bin.getMetalGarbageAmount(), 0);
    EXPECT_EQ(bin2.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin2.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin2.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin2.getBottlecapAmount(), 0);
    EXPECT_EQ(bin2.getMetalGarbageAmount(), 0);
}