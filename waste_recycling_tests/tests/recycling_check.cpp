#include <gtest/gtest.h>
#include <dustbin/Dustbin9000.h>
#include <garbage/MetalGarbage.hpp>

class RecycleFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    RecycleFixture() : Test() {}
};

TEST_F(RecycleFixture, Dustbin_container_check) {
    Dustbin bin = Dustbin();
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    Garbage waste = Garbage("waste");
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_EQ(bin.getHouseWasteAmount(), 5);
    EXPECT_NO_THROW(bin.emptyContents());
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
}

TEST_F(RecycleFixture, Dustbin9000_container_check) {
    Dustbin9000 bin = Dustbin9000();
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getBottlecapAmount(), 0);
    EXPECT_EQ(bin.getMetalGarbageAmount(), 0);
    MetalGarbage metal = MetalGarbage("metal");
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_EQ(bin.getMetalGarbageAmount(), 4);
    EXPECT_NO_THROW(bin.emptyContents());
    EXPECT_EQ(bin.getMetalGarbageAmount(), 0);
}

TEST_F(RecycleFixture, Dustbin_PlasticGarbage_check) {
    Dustbin bin = Dustbin();
    PlasticGarbage p = PlasticGarbage("p");
    EXPECT_THROW(bin.throwOutPlasticGarbage(p), DustbinContentError);
    EXPECT_NO_THROW(p.clean());
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(p));
}

TEST_F(RecycleFixture, Dustbin_PaperGarbage_check) {
    Dustbin bin = Dustbin();
    PaperGarbage p = PaperGarbage("p");
    EXPECT_THROW(bin.throwOutPaperGarbage(p), DustbinContentError);
    EXPECT_NO_THROW(p.squeeze());
    EXPECT_NO_THROW(bin.throwOutPaperGarbage(p));
}


TEST_F(RecycleFixture, Dustbin9000_BottleCap_check) {
    Dustbin9000 bin = Dustbin9000();
    BottleCap p = BottleCap();
    BottleCap k = BottleCap("kék");
    EXPECT_NO_THROW(bin.throwOutBottlecap(p));
    EXPECT_THROW(bin.throwOutBottlecap(k), BottleCapException);
}
