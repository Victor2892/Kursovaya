#include <UnitTest++/UnitTest++.h>
#include "/home/student/kursovaya_rabota/kurs/Generator.h"
#include "/home/student/kursovaya_rabota/kurs/Generator.cpp"

SUITE(setBaseRegisterTest)
{
    Generator test;
    TEST(defaultRegister) {
        string Register = "10101000111001010110111110011001";
        test.setBaseRegister(Register);
        CHECK(true);
    }
    TEST(otherSuccessfulRegister) {
        string Register = "10101001000001010110011010011000";
        test.setBaseRegister(Register);
        CHECK(true);
    }

    TEST(RegisterWithOneUnit) {
        string Register = "10000000000000000000000000000000";
        test.setBaseRegister(Register);
        CHECK(true);
    }

    TEST(RegisterFromZeros) {
        string Register = "00000000000000000000000000000000";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }

    TEST(RegisterLongerThan32Characters) {
        string Register = "0000000000000000000000000000000011111";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }
    TEST(RegisterShorterThan32Characters) {
        string Register = "100000000000011111";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }
    TEST(RegisterEmpty) {
        string Register = "";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }
    TEST(RegisterInvalidCharacterLetter) {
        string Register = "1010100011100101A110111110011001";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }
    TEST(RegisterInvalidCharacterNumber) {
        string Register = "10101000911001011110111110011001";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }
    TEST(RegisterInvalidCharacterSpecial) {
        string Register = "10101000,?1100101111011111001100";
        CHECK_THROW(test.setBaseRegister(Register),GeneratorError);
    }

}
SUITE(generationTest)
{
    Generator test;
    TEST(correctCountNumbersForGeneration) {
        const int count_numbers = 2;
        test.useDefaultRegister();
        test.generation(count_numbers);
        CHECK(true);
    }
    TEST(negativeNumberForGeneration) {
        const int count_numbers = -2;
        test.useDefaultRegister();
        CHECK_THROW(test.generation(count_numbers),GeneratorError);
    }
    TEST(theNumberZeroForGeneration) {
        const int count_numbers = 0;
        test.useDefaultRegister();
        CHECK_THROW(test.generation(count_numbers),GeneratorError);
    }
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
