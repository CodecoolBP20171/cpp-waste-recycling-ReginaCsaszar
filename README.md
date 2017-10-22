# Waste Recycling
Simple OOP assignment in c++

Császár Regina @Codecool BP 3 (2017.1) Group C 

### The story
It's 2020. The mentors of Codecool Phnom Pen (capital of Cambodia) are fed up, that despite the strict house rules, no one cares about collecting the waste in a selective way in the school. They decided to make an automated dustbin, which can detect different types of garbage, and sounds a loud alarm if the wrong kind of garbage was thrown in it.

Mentors at Codecool usually have a whole bunch of things to do, and they aren't exceptions either, so they don't have time to implement the dustbin's software....

Have you found out yet? YES, it's your job to implement it in an Object-Oriented way! :-)

### The specification
You "only" have to implement the classes and the business logic now and make tests to prove it's working. 

Please make sure each of the classes go into it's own file.

#### Garbage
This is the class containing a regular garbage's business logic.

##### Attributes
**name**: a string, storing some custom name of the exact garbage object
 
#### PaperGarbage

This is the class containing the business logic of a garbage made of paper. PaperGarbage class inherits from the Garbage class.

##### Attributes
**name**: a string, storing the name of the garbage (should be inherited from the Garbage)

**isSqueezed**: a boolean, storing if the garbage is squeezed or not
##### Instance methods
**squeeze()**: when called, it sets the object's isSqueezed attribute to True
 
#### PlasticGarbage

This is the class containing the business logic of a garbage made of plastic. PlasticGarbage class inherits from the Garbage class.

##### Attributes
**name**: a string, storing the name of the garbage (should be inherited from the Garbage)

**isClean**: a boolean, storing if the garbage is clean or not
##### Instance methods
**clean()**: when called, it sets the object's isClean attribute to True
 
#### DustbinContentError

This class contains a custom exception, called DustbinContentError, which is raised by the Dustbin in some error cases (see below). If this exception appears the alarm switches on (but that's not something you should care about). Google for std::exception and inherit from it and/or check last week's reference codes for help.

#### Dustbin

This class should contain all the logic, what our automated dustbin can do.

##### Attributes
**color**: a string, storing the dustbin's color

**paperContent**: an array storing PaperGarbage instances

**plasticContent**: an array storing PlasticGarbage instances

**houseWasteContent**: an array storing Garbage instances

##### Intance methods
**throwOutGarbage(Garbage)**: the argument is an instance of the Garbage class. It puts that into the houseWasteContent array

**throwOutPaperGarbage(PaperGarbage)**: the argument is an instance of the PaperGarbage class. If it's squeezed, then it puts that into the paperContent array. If the PaperGarbage instance is not squeezed, it raises a DustbinContentError exception

**throwOutPlasticGarbage(PlasticGarbage)**: the argument is an instance of the PlasticGarbage class. If it's clean, then it puts that into the plasticContent array. If the PlasticGarbage instance is not clean, it raises a DustbinContentError exception

**emptyContents()**: If it's called, all the garbage containers gets emptied
 
#### Dustbin9000

The newest dustbin in the market which can do all the things Dustbin already knew and more:

- It accepts metal garbage (and therefore has a container for it)
- also has a compartment for bottle caps but only if the cap is pink. So it won't accept any other color and will raise a BottleCapException if receives a non-pink cap (and will fire back the cap to your face but that's not something you should care about)

Figure out the classes and the structure to implement this awesome new dustbin!

#### DustbinTests

This class should contain test cases for the specification above. Try to test all the cases what you can think of. Make yourself a simple Unit Test framework (like what I made for the NoSoSiCa) or figure out how to use Google Test framework. It's up to you. :)

### Hints

Take care about privacy: make the variables/functions'/etc. access modifiers so they can be accessed only by the classes which really needs them!

You can make extra functions for the classes if you feel the need :)

Make at least 10 test case. Every test should initialize it's own dustbin assuring they are not depending on each other

### Extra

1. Make a maximum capacity for the dustbin and a weight for the garbage types. The dustbin should throw a DustbinIsFull exception if it would overflow and should not accept that piece of garbage

2. Make some little console interface where you can virtually use the dustbin. Select the type of garbage, configure it (squeeze option if needed etc.) and try to put it into the dustbin. Have fun with it :)