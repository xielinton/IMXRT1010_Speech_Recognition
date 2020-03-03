#include "oled.h"

AT_NONCACHEABLE_SECTION(uint8_t txBuff[130]);

const uint8_t font12x16[][26] = {

        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0xFF, 0x33, 0xFF, 0x33, 0xFF, 0x33, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char !
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char "
        {0x00, 0x00, 0x00, 0x02, 0x10, 0x1E, 0x90, 0x1F, 0xF0, 0x1F, 0xFE, 0x03, 0x7E, 0x1E, 0x9E, 0x1F, 0xF0, 0x1F, 0xFE, 0x03, 0x7E, 0x02, 0x1E, 0x00, 0x10, 0x00},  // Code for char #
        {0x00, 0x00, 0x00, 0x00, 0x78, 0x04, 0xFC, 0x0C, 0xFC, 0x0C, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xCC, 0x0F, 0xCC, 0x0F, 0x88, 0x07, 0x00, 0x00, 0x00, 0x00},  // Code for char $
        {0x00, 0x00, 0x00, 0x30, 0x38, 0x38, 0x38, 0x3C, 0x38, 0x1E, 0x38, 0x0F, 0x80, 0x07, 0xC0, 0x03, 0xE0, 0x39, 0xF0, 0x38, 0x78, 0x38, 0x3C, 0x38, 0x1C, 0x00},  // Code for char %
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xB8, 0x3F, 0xFC, 0x3F, 0xFE, 0x31, 0xE6, 0x37, 0xFE, 0x3F, 0x3E, 0x1E, 0x1C, 0x3E, 0x00, 0x36, 0x00, 0x22, 0x00, 0x00},  // Code for char &
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char '
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0xFF, 0x3F, 0x07, 0x38, 0x01, 0x20, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char (
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 0x01, 0x20, 0x07, 0x38, 0xFF, 0x3F, 0xFE, 0x1F, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char )
        {0x00, 0x00, 0x00, 0x00, 0x98, 0x0C, 0xB8, 0x0E, 0xF8, 0x0F, 0xF8, 0x0F, 0xF8, 0x0F, 0xF8, 0x0F, 0xF8, 0x0F, 0xB8, 0x0E, 0x98, 0x0C, 0x00, 0x00, 0x00, 0x00},  // Code for char *
        {0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xF0, 0x0F, 0xF0, 0x0F, 0xF0, 0x0F, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00},  // Code for char +
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char ,
        {0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00},  // Code for char -
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char .
        {0x00, 0x00, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x1E, 0x00, 0x0F, 0x80, 0x07, 0xC0, 0x03, 0xE0, 0x01, 0xF0, 0x00, 0x78, 0x00, 0x3C, 0x00, 0x1E, 0x00, 0x0E, 0x00},  // Code for char /
        {0x00, 0x00, 0xF8, 0x07, 0xFE, 0x1F, 0xFE, 0x1F, 0x07, 0x3F, 0x83, 0x33, 0xC3, 0x31, 0xE3, 0x30, 0x73, 0x30, 0x3F, 0x38, 0xFE, 0x1F, 0xFE, 0x1F, 0xF8, 0x07},  // Code for char 0
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x0C, 0x30, 0x0E, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00},  // Code for char 1
        {0x00, 0x00, 0x1C, 0x30, 0x1E, 0x38, 0x1F, 0x3C, 0x07, 0x3E, 0x03, 0x3F, 0x83, 0x37, 0xC3, 0x33, 0xE3, 0x31, 0xF7, 0x30, 0x7F, 0x30, 0x3E, 0x30, 0x1C, 0x30},  // Code for char 2
        {0x00, 0x00, 0x0C, 0x0C, 0x0E, 0x1C, 0x0F, 0x3C, 0xC7, 0x38, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x39, 0xFF, 0x3F, 0x7E, 0x1F, 0x3C, 0x0E},  // Code for char 3
        {0x00, 0x00, 0xC0, 0x03, 0xE0, 0x03, 0xF0, 0x03, 0x78, 0x03, 0x3C, 0x03, 0x1E, 0x03, 0x0F, 0x03, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x03, 0x00, 0x03},  // Code for char 4
        {0x00, 0x00, 0x3F, 0x0C, 0x7F, 0x1C, 0x7F, 0x3C, 0x63, 0x38, 0x63, 0x30, 0x63, 0x30, 0x63, 0x30, 0x63, 0x30, 0xE3, 0x38, 0xE3, 0x3F, 0xC3, 0x1F, 0x83, 0x0F},  // Code for char 5
        {0x00, 0x00, 0xC0, 0x0F, 0xF0, 0x1F, 0xF8, 0x3F, 0xFC, 0x39, 0xDE, 0x30, 0xCF, 0x30, 0xC7, 0x30, 0xC3, 0x30, 0xC3, 0x39, 0xC3, 0x3F, 0x80, 0x1F, 0x00, 0x0F},  // Code for char 6
        {0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x30, 0x03, 0x3C, 0x03, 0x3F, 0xC3, 0x0F, 0xF3, 0x03, 0xFF, 0x00, 0x3F, 0x00, 0x0F, 0x00, 0x03, 0x00},  // Code for char 7
        {0x00, 0x00, 0x00, 0x0F, 0xBC, 0x1F, 0xFE, 0x3F, 0xFF, 0x39, 0xE7, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x30, 0xFF, 0x39, 0xFE, 0x3F, 0xBC, 0x1F, 0x00, 0x0F},  // Code for char 8
        {0x00, 0x00, 0x3C, 0x00, 0x7E, 0x00, 0xFF, 0x30, 0xE7, 0x30, 0xC3, 0x30, 0xC3, 0x38, 0xC3, 0x3C, 0xC3, 0x1E, 0xE7, 0x0F, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x00},  // Code for char 9
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char :
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x9C, 0x70, 0xFC, 0x70, 0xFC, 0x70, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char ;
        {0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x01, 0xF0, 0x03, 0xF8, 0x07, 0x3C, 0x0F, 0x1E, 0x1E, 0x0F, 0x3C, 0x07, 0x38, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00},  // Code for char <
        {0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x00, 0x00},  // Code for char =
        {0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x07, 0x38, 0x0F, 0x3C, 0x1E, 0x1E, 0x3C, 0x0F, 0xF8, 0x07, 0xF0, 0x03, 0xE0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char >
        {0x00, 0x00, 0x1C, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x07, 0x00, 0x83, 0x37, 0xC3, 0x37, 0xE3, 0x37, 0xF7, 0x00, 0x7F, 0x00, 0x3E, 0x00, 0x1C, 0x00, 0x00, 0x00},  // Code for char ?
        {0x00, 0x00, 0xF8, 0x0F, 0xFE, 0x1F, 0xFF, 0x1F, 0xF7, 0x3B, 0xFB, 0x37, 0xFB, 0x37, 0xFB, 0x37, 0xFB, 0x37, 0xFF, 0x37, 0xFF, 0x37, 0xFE, 0x03, 0xF8, 0x01},  // Code for char @
        {0x00, 0x00, 0x00, 0x38, 0x00, 0x3F, 0xE0, 0x3F, 0xFC, 0x07, 0xFF, 0x06, 0x1F, 0x06, 0xFF, 0x06, 0xFC, 0x07, 0xE0, 0x3F, 0x00, 0x3F, 0x00, 0x38, 0x00, 0x00},  // Code for char A
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xE7, 0x30, 0xFF, 0x39, 0xFE, 0x3F, 0xBC, 0x1F, 0x00, 0x0F, 0x00, 0x00},  // Code for char B
        {0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0x0F, 0x3C, 0x07, 0x38, 0x03, 0x30, 0x03, 0x30, 0x07, 0x38, 0x0F, 0x3C, 0x0E, 0x1C, 0x0C, 0x0C, 0x00, 0x00},  // Code for char C
		{0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x07, 0x38, 0x0F, 0x3C, 0xFE, 0x1F, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00},  // Code for char D
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0x03, 0x30, 0x03, 0x30, 0x00, 0x00},  // Code for char E
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0xC3, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00},  // Code for char F
        {0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0x0F, 0x3C, 0x07, 0x38, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC7, 0x3F, 0xC7, 0x3F, 0xC6, 0x3F, 0x00, 0x00},  // Code for char G
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00},  // Code for char H
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x03, 0x30, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x30, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char I
        {0x00, 0x00, 0x00, 0x0E, 0x00, 0x1E, 0x00, 0x3E, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x38, 0xFF, 0x3F, 0xFF, 0x1F, 0xFF, 0x07, 0x00, 0x00},  // Code for char J
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xE0, 0x01, 0xF0, 0x03, 0xF8, 0x07, 0x3C, 0x0F, 0x1E, 0x1E, 0x0F, 0x3C, 0x07, 0x38, 0x03, 0x30, 0x00, 0x00},  // Code for char K
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00},  // Code for char L
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x7E, 0x00, 0xF8, 0x01, 0xE0, 0x01, 0xF8, 0x01, 0x7E, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00},  // Code for char M
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x3E, 0x00, 0xF8, 0x00, 0xF0, 0x03, 0xC0, 0x07, 0x00, 0x1F, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00},  // Code for char N
        {0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0x0F, 0x3C, 0x07, 0x38, 0x03, 0x30, 0x07, 0x38, 0x0F, 0x3C, 0xFE, 0x1F, 0xFC, 0x0F, 0xF0, 0x03, 0x00, 0x00},  // Code for char O
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x83, 0x01, 0x83, 0x01, 0x83, 0x01, 0x83, 0x01, 0xC7, 0x01, 0xFF, 0x01, 0xFE, 0x00, 0x7C, 0x00, 0x00, 0x00},  // Code for char P
        {0x00, 0x00, 0xF0, 0x03, 0xFC, 0x0F, 0xFE, 0x1F, 0x0F, 0x3C, 0x07, 0x38, 0x03, 0x36, 0x07, 0x3E, 0x0F, 0x3E, 0xFE, 0x3F, 0xFC, 0x3F, 0xF0, 0x33, 0x00, 0x00},  // Code for char Q
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x83, 0x01, 0x83, 0x03, 0x83, 0x07, 0x83, 0x0F, 0xC7, 0x1F, 0xFF, 0x3D, 0xFE, 0x38, 0x7C, 0x30, 0x00, 0x00},  // Code for char R
		{0x00, 0x00, 0x3C, 0x0C, 0x7E, 0x1C, 0xFF, 0x3C, 0xE7, 0x38, 0xC3, 0x30, 0xC3, 0x30, 0xC3, 0x30, 0xC7, 0x39, 0xCF, 0x3F, 0x8E, 0x1F, 0x0C, 0x0F, 0x00, 0x00},  // Code for char S
        {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},  // Code for char T
        {0x00, 0x00, 0xFF, 0x07, 0xFF, 0x1F, 0xFF, 0x3F, 0x00, 0x38, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x38, 0xFF, 0x3F, 0xFF, 0x1F, 0xFF, 0x07, 0x00, 0x00},  // Code for char U
        {0x00, 0x00, 0x07, 0x00, 0x3F, 0x00, 0xFF, 0x01, 0xF8, 0x0F, 0xC0, 0x3F, 0x00, 0x3E, 0xC0, 0x3F, 0xF8, 0x0F, 0xFF, 0x01, 0x3F, 0x00, 0x07, 0x00, 0x00, 0x00},  // Code for char V
        {0x00, 0x00, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x1E, 0x80, 0x07, 0x80, 0x03, 0x80, 0x07, 0x00, 0x1E, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0x00, 0x00},  // Code for char W
        {0x00, 0x00, 0x03, 0x30, 0x0F, 0x3C, 0x1F, 0x3E, 0x3C, 0x0F, 0xF0, 0x03, 0xE0, 0x01, 0xF0, 0x03, 0x3C, 0x0F, 0x1F, 0x3E, 0x0F, 0x3C, 0x03, 0x30, 0x00, 0x00},  // Code for char X
        {0x00, 0x00, 0x03, 0x00, 0x0F, 0x00, 0x3F, 0x00, 0xFC, 0x00, 0xF0, 0x3F, 0xC0, 0x3F, 0xF0, 0x3F, 0xFC, 0x00, 0x3F, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x00, 0x00},  // Code for char Y
        {0x00, 0x00, 0x03, 0x30, 0x03, 0x3C, 0x03, 0x3E, 0x03, 0x3F, 0xC3, 0x33, 0xE3, 0x31, 0xF3, 0x30, 0x3F, 0x30, 0x1F, 0x30, 0x0F, 0x30, 0x03, 0x30, 0x00, 0x00}  // Code for char Z
};

void OLED_Init(void){

	I2C_Init();

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_DISPLAYOFF;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETDISPLAYCLOCKDIV;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x80;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETMULTIPLEX;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_LCDHEIGHT-2;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);


	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETDISPLAYOFFSET;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x00;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETSTARTLINE;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_CHARGEPUMP;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x14;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_MEMORYMODE;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x00;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SEGREMAP | 0x1;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_COMSCANDEC;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETCOMPINS;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x12; //?
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETCONTRAST;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x8F; //?
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_SETPRECHARGE;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0xF1;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x40;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_DISPLAYALLON_RESUME;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_NORMALDISPLAY;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_DEACTIVATE_SCROLL;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_DISPLAYON;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_COLUMNADDR;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x00;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_LCDWIDTH-1;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = SSD1306_PAGEADDR;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x00;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

	txBuff[0] = 0x00;
	txBuff[1] = 0x07;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);



}

/*
 * Clear the OLED Screen
 */

void OLED_Clear_Screen(void){

	memset(txBuff,0,129);
	txBuff[0] = 0x40;
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
	I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,129);
}

/*
 * Print the Text on OLED Screen (font size 12x16)
 * @line (0 to 6)
 * @xpos (0 to 127)
 * @data (String data)
 */

void OLED_PrintText(uint8_t line,uint8_t xpos, const uint8_t *data){

	uint8_t i,j,k,len,cmax;

	len = strlen((const char*) data);

	if( line < 7){

		if((xpos + len*13) > 127){

			cmax=127;
		}
		else
		{
			cmax = xpos + len*13;
		}

		txBuff[0] = 0x00;
		txBuff[1] = SSD1306_COLUMNADDR;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

		txBuff[0] = 0x00;
		txBuff[1] = xpos;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

		txBuff[0] = 0x00;
		txBuff[1] = cmax;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

		txBuff[0] = 0x00;
		txBuff[1] = SSD1306_PAGEADDR;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

		txBuff[0] = 0x00;
		txBuff[1] = line;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);
		txBuff[0] = 0x00;
		txBuff[1] = line;
		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);
		txBuff[0] = 0x40;

		for(j=0;j<len;j++){
			for(i=0,k=0;i<26;i=i+2,k++){
				txBuff[j*13 + k +1] = font12x16[data[j]-32][i];
			}
		}

		I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,cmax-xpos +1);

			txBuff[0] = 0x00;
			txBuff[1] = SSD1306_COLUMNADDR;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = xpos;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = cmax;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = SSD1306_PAGEADDR;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = line+1;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = line+1;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);
			txBuff[0] = 0x40;

			for(j=0;j<len;j++){
				for(i=1,k=0;i<26;i=i+2,k++){
					txBuff[j*13 + k +1] = font12x16[data[j]-32][i];
				}
			}
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,cmax-xpos +1);
	}
}


/*
 * Draw the Image on OLED Screen (BMP 40x128)
 * @line ( 0 to 7)
 * @xpos (0 to 127)
 * @data (data array)
 */

void OLED_DrawImage(uint8_t line, uint8_t xpos, const uint8_t *data){

	uint8_t i,j;
	uint16_t k;
	uint8_t size = data[0];
	uint8_t hsize = data[1]/8;

	if(xpos + size >128){

		xpos = 128 - size;
	}

	if( line + hsize <= 8){
		k=2;
		for(j=0;j<hsize;j++){
			txBuff[0] = 0x00;
			txBuff[1] = SSD1306_COLUMNADDR;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = xpos;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = xpos + size-1;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = SSD1306_PAGEADDR;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = line+j;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x00;
			txBuff[1] = line+j;
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,2);

			txBuff[0] = 0x40;
			for(i=0;i<size;i++,k++){
				txBuff[i +1] = data[k];
			}
			I2C_Transfer(SSD1306_I2C_ADDRESS, txBuff,size + 1);
		}

	}
}
