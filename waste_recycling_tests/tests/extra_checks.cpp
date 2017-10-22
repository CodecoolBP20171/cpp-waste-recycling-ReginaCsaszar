//
// Created by jeannie on 2017.10.22..
//

#include <gtest/gtest.h>
#include <dustbin/Dustbin9000.h>

class ExtraFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    ExtraFixture() : Test() {}
};

TEST_F(ExtraFixture, Garbage_weight_check) {
    Garbage waste = Garbage("other");
    PlasticGarbage plastic = PlasticGarbage("plastic");
    PaperGarbage paper = PaperGarbage("paper");
    MetalGarbage metal = MetalGarbage("metal");
    BottleCap pbc = BottleCap("pink");
    EXPECT_EQ(waste.getWeight(), 7);
    EXPECT_EQ(plastic.getWeight(), 10);
    EXPECT_EQ(paper.getWeight(), 5);
    EXPECT_EQ(metal.getWeight(), 25);
    EXPECT_EQ(pbc.getWeight(), 1);
}

TEST_F(ExtraFixture, Bin_weight_check) {
    Garbage waste = Garbage("other");
    PlasticGarbage plastic = PlasticGarbage("plastic");
    plastic.clean();
    PaperGarbage paper = PaperGarbage("paper");
    paper.squeeze();
    Dustbin bin = Dustbin();
    EXPECT_EQ(bin.getCurrentWeight(), 0);
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutPaperGarbage(paper));
    EXPECT_EQ(bin.getCurrentWeight(), 82);
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_THROW(bin.throwOutPlasticGarbage(plastic), DustbinIsFull);
    EXPECT_EQ(bin.getCurrentWeight(), 92);
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.emptyContents());
    EXPECT_EQ(bin.getCurrentWeight(), 0);
}

TEST_F(ExtraFixture, Bin9000_weight_check) {
    MetalGarbage metal = MetalGarbage("metal");
    BottleCap bc = BottleCap();
    Dustbin9000 bin = Dustbin9000();
    EXPECT_EQ(bin.getCurrentWeight(), 0);
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_NO_THROW(bin.throwOutMetalGarbage(metal));
    EXPECT_EQ(bin.getCurrentWeight(), 75);
    EXPECT_NO_THROW(bin.throwOutBottlecap(bc));
    EXPECT_THROW(bin.throwOutMetalGarbage(metal), DustbinIsFull);
    EXPECT_EQ(bin.getCurrentWeight(), 76);
    EXPECT_NO_THROW(bin.emptyContents());
    EXPECT_EQ(bin.getCurrentWeight(), 0);
}