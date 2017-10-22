
#include "gtest/gtest.h"
#include <garbage/PlasticGarbage.hpp>
#include <garbage/PaperGarbage.hpp>
#include <garbage/MetalGarbage.hpp>
#include <garbage/BottleCap.hpp>

class GarbageFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    GarbageFixture() : Test() {}
};

TEST_F(GarbageFixture, PlasticGarbage_check) {
    PlasticGarbage plastic = PlasticGarbage("plastic");
    EXPECT_EQ(plastic.getName(), "plastic");
    EXPECT_EQ(plastic.cleanState(), false);
    EXPECT_NO_THROW(plastic.clean());
    EXPECT_EQ(plastic.cleanState(), true);
}

TEST_F(GarbageFixture, PaperGarbage_check) {
    PaperGarbage paper = PaperGarbage("paper");
    EXPECT_EQ(paper.getName(), "paper");
    EXPECT_EQ(paper.squeezeState(), false);
    EXPECT_NO_THROW(paper.squeeze());
    EXPECT_EQ(paper.squeezeState(), true);
}

TEST_F(GarbageFixture, MetalGarbage_check) {
    MetalGarbage metal = MetalGarbage("metal");
    EXPECT_EQ(metal.getName(), "metal");
}

TEST_F(GarbageFixture, Garbage_check) {
    Garbage waste = Garbage("other");
    EXPECT_EQ(waste.getName(), "other");
}


TEST_F(GarbageFixture, BottleCap_check) {
    BottleCap pbc = BottleCap();
    BottleCap bbc = BottleCap("blue");
    EXPECT_EQ(pbc.getName(), "bottlecap");
    EXPECT_EQ(pbc.getName(), "bottlecap");
    EXPECT_EQ(pbc.getColor(), "pink");
    EXPECT_EQ(bbc.getColor(), "blue");
}
