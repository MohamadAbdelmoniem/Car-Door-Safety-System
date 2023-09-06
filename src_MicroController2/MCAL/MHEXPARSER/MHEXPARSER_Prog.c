/*
 * MHEXPARSER_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: DELL
 */

// Function to convert an ASCII code to a hexadecimal number
uint8_t AsciiToHex(uint8_t asciiCode) {
    if ((asciiCode >= '0' && asciiCode <= '9')) {
        return asciiCode - '0';
    } else if ((asciiCode >= 'A' && asciiCode <= 'F') || (asciiCode >= 'a' && asciiCode <= 'f')) {
        asciiCode = toupper(asciiCode);
        return asciiCode - 'A' + 10;
    } else {
        // Handle invalid input or other characters as needed
        return 0xFF; // Error or invalid character, you can choose another error code if needed
    }
}
void ParseData(char* input){
	u8 Character_One;
	u8 Character_Two;
	u8 sum;

	u8 FirstDigit_Address;
	u8 SecondDigit_Address;
	u8 ThirdDigit_Address;
	u8 FourthDigit_Address;

    if (input[0] != '\0' && input[1] != '\0') {
        // Convert the characters to a hexadecimal value
        Character_One = AsciiToHex(input[1]);
        Character_Two = AsciiToHex(input[2]);

        sum = (Character_One << 4) | Character_Two;

         FirstDigit_Address = AsciiToHex(input[3]);
         SecondDigit_Address = AsciiToHex(input[4]);
         ThirdDigit_Address = AsciiToHex(input[5]);
         FourthDigit_Address=AsciiToHex(input[6]);

         u8 Sum_Address= (FirstDigit_Address << 12) | (SecondDigit_Address << 8) |
        		 		(ThirdDigit_Address << 4) | (FourthDigit_Address);

    }
}




