/************************************************************************************
 * LED Controller
 *
 * Some effects borrowed from:
 * https://www.tweaking4all.com/hardware/arduino/arduino-all-ledstrip-effects-in-one/
 * https://www.tweaking4all.com/forum/miscellaneous-software/lego-millenium-falcon-with-all-ledstrip-effects-in-one-fastled/
 *
 * Adding a new effect:
 * - Create a new function with the prefix `effect`
 * - Add function call as switch case in main loop
 * - Increment the LED_EFFECT_COUNT define
 ************************************************************************************/

#ifndef _LED_MAPPER_
#define _LED_MAPPER_

#include <FastLED.h>

#define LED_PIN 5
#define LED_COUNT 12
#define LED_EFFECT_COUNT 9
#define COLUMN_COUNT 7
#define COLUMN_HEIGHT 2

// Button defines
#define LED_INDEX_P1      0
#define LED_INDEX_P2      1
#define LED_INDEX_P3      2
#define LED_INDEX_P4      3
#define LED_INDEX_K4      4
#define LED_INDEX_K3      5
#define LED_INDEX_K2      6
#define LED_INDEX_K1      7
#define LED_INDEX_RIGHT   8
#define LED_INDEX_DOWN    9
#define LED_INDEX_LEFT   10
#define LED_INDEX_UP     11
#define LED_INDEX_NONE   255

// Define mappings for HitBox button layout
const int ColumnMatrix[COLUMN_COUNT][COLUMN_HEIGHT] = {
	{ LED_INDEX_LEFT,  LED_INDEX_NONE },
	{ LED_INDEX_DOWN,  LED_INDEX_UP },
	{ LED_INDEX_RIGHT, LED_INDEX_NONE },
	{ LED_INDEX_P1,    LED_INDEX_K1 },
	{ LED_INDEX_P2,    LED_INDEX_K2 },
	{ LED_INDEX_P3,    LED_INDEX_K3 },
	{ LED_INDEX_P4,    LED_INDEX_K4 },
};

struct ButtonColorMap {
	ButtonColorMap(uint8_t bi, CHSV bc)
		: buttonIndex(bi), buttonColor(bc) { }
	uint8_t buttonIndex;
	CHSV buttonColor;
};

CRGB leds[LED_COUNT];

// Set colors with hue, saturation, and value
// These values should be tuned
CHSV ColorBlack     = CHSV(   0,   0,   0);
CHSV ColorWhite     = CHSV(   0,   0, 255);

CHSV ColorRed       = CHSV(   0, 255, 255);
CHSV ColorOrange    = CHSV(  20, 255, 255);
CHSV ColorYellow    = CHSV(  40, 255, 255);
CHSV ColorLimeGreen = CHSV(  60, 255, 255);
CHSV ColorGreen     = CHSV(  80, 255, 255);
CHSV ColorSeafoam   = CHSV( 100, 255, 255);
CHSV ColorAqua      = CHSV( 120, 255, 255);
CHSV ColorSkyBlue   = CHSV( 140, 255, 255);
CHSV ColorBlue      = CHSV( 160, 255, 255);
CHSV ColorPurple    = CHSV( 180, 255, 255);
CHSV ColorPink      = CHSV( 200, 255, 255);
CHSV ColorMagenta   = CHSV( 220, 255, 255);

const ButtonColorMap StaticRainbowButtonMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_LEFT, ColorRed),
	ButtonColorMap(LED_INDEX_UP, ColorOrange),
	ButtonColorMap(LED_INDEX_DOWN, ColorOrange),
	ButtonColorMap(LED_INDEX_RIGHT, ColorYellow),
	ButtonColorMap(LED_INDEX_P1, ColorGreen),
	ButtonColorMap(LED_INDEX_K1, ColorGreen),
	ButtonColorMap(LED_INDEX_P2, ColorAqua),
	ButtonColorMap(LED_INDEX_K2, ColorAqua),
	ButtonColorMap(LED_INDEX_P3, ColorBlue),
	ButtonColorMap(LED_INDEX_K3, ColorBlue),
	ButtonColorMap(LED_INDEX_K4, ColorPink),
	ButtonColorMap(LED_INDEX_P4, ColorPink),
};

const ButtonColorMap GuiltyGearCustomColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorPink),     // P
	ButtonColorMap(LED_INDEX_P2, ColorGreen),    // S
	ButtonColorMap(LED_INDEX_P3, ColorRed),      // HS
	ButtonColorMap(LED_INDEX_P4, ColorBlack),
	ButtonColorMap(LED_INDEX_K1, ColorBlue),     // K
	ButtonColorMap(LED_INDEX_K2, ColorOrange),   // D
	ButtonColorMap(LED_INDEX_K3, ColorBlack),
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap GuiltyGearTypeAColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorBlue),     // K
	ButtonColorMap(LED_INDEX_P2, ColorGreen),    // S
	ButtonColorMap(LED_INDEX_P3, ColorRed),      // HS
	ButtonColorMap(LED_INDEX_P4, ColorBlack),
	ButtonColorMap(LED_INDEX_K1, ColorPink),     // P
	ButtonColorMap(LED_INDEX_K2, ColorBlack),
	ButtonColorMap(LED_INDEX_K3, ColorOrange),   // D
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap NeoGeoCurvedColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorYellow),   // B
	ButtonColorMap(LED_INDEX_P2, ColorGreen),    // C
	ButtonColorMap(LED_INDEX_P3, ColorBlue),     // D
	ButtonColorMap(LED_INDEX_P4, ColorBlack),
	ButtonColorMap(LED_INDEX_K1, ColorRed),      // A
	ButtonColorMap(LED_INDEX_K2, ColorBlack),
	ButtonColorMap(LED_INDEX_K3, ColorBlack),
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap NeoGeoModernColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorRed),      // A
	ButtonColorMap(LED_INDEX_P2, ColorGreen),    // C
	ButtonColorMap(LED_INDEX_P3, ColorBlack),
	ButtonColorMap(LED_INDEX_P4, ColorBlack),
	ButtonColorMap(LED_INDEX_K1, ColorYellow),   // B
	ButtonColorMap(LED_INDEX_K2, ColorBlue),     // D
	ButtonColorMap(LED_INDEX_K3, ColorBlack),
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap NeoGeoStraightColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorRed),      // A
	ButtonColorMap(LED_INDEX_P2, ColorYellow),   // B
	ButtonColorMap(LED_INDEX_P3, ColorGreen),    // C
	ButtonColorMap(LED_INDEX_P4, ColorBlue),     // D
	ButtonColorMap(LED_INDEX_K1, ColorBlack),
	ButtonColorMap(LED_INDEX_K2, ColorBlack),
	ButtonColorMap(LED_INDEX_K3, ColorBlack),
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap SixButtonFighterColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorBlue),     // LP
	ButtonColorMap(LED_INDEX_P2, ColorYellow),   // MP
	ButtonColorMap(LED_INDEX_P3, ColorRed),      // HP
	ButtonColorMap(LED_INDEX_P4, ColorBlack),
	ButtonColorMap(LED_INDEX_K1, ColorBlue),     // LK
	ButtonColorMap(LED_INDEX_K2, ColorYellow),   // MK
	ButtonColorMap(LED_INDEX_K3, ColorRed),      // HK
	ButtonColorMap(LED_INDEX_K4, ColorBlack),
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap SuperFamicomColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorGreen),     // Y
	ButtonColorMap(LED_INDEX_P2, ColorBlue),      // X
	ButtonColorMap(LED_INDEX_P3, ColorOrange),    // R
	ButtonColorMap(LED_INDEX_P4, ColorMagenta),   // L
	ButtonColorMap(LED_INDEX_K4, ColorAqua),      // ZL
	ButtonColorMap(LED_INDEX_K3, ColorPurple),    // ZR
	ButtonColorMap(LED_INDEX_K2, ColorRed),       // A
	ButtonColorMap(LED_INDEX_K1, ColorYellow),    // B
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

const ButtonColorMap XboxColorMapping[LED_COUNT] = {
	ButtonColorMap(LED_INDEX_P1, ColorBlue),      // X
	ButtonColorMap(LED_INDEX_P2, ColorYellow),    // Y
	ButtonColorMap(LED_INDEX_P3, ColorOrange),    // RB
	ButtonColorMap(LED_INDEX_P4, ColorMagenta),   // LB
	ButtonColorMap(LED_INDEX_K4, ColorAqua),      // LT
	ButtonColorMap(LED_INDEX_K3, ColorPurple),    // RT
	ButtonColorMap(LED_INDEX_K2, ColorRed),       // B
	ButtonColorMap(LED_INDEX_K1, ColorGreen),     // A
	ButtonColorMap(LED_INDEX_RIGHT, ColorWhite),
	ButtonColorMap(LED_INDEX_DOWN, ColorWhite),
	ButtonColorMap(LED_INDEX_LEFT, ColorWhite),
	ButtonColorMap(LED_INDEX_UP, ColorWhite),
};

inline void applyColorMapping(const ButtonColorMap colorMapping[LED_COUNT]) __attribute__((always_inline));
inline void showLeds() __attribute__((always_inline));

void configureLeds() {
    FastLED.addLeds<SK6812, LED_PIN, RGB>(leds, LED_COUNT);
}

void applyColorMapping(const ButtonColorMap colorMapping[LED_COUNT]) {
	for (uint8_t i = 0; i < LED_COUNT; i++)
		leds[colorMapping[i].buttonIndex] = colorMapping[i].buttonColor;

	showLeds();
}

enum class LedEffectMode {
	NONE,
	XBOX,
	SFC,
	SIX_BUTTON,
	GG_TYPE_A,
	NEOGEO_STRAIGHT,
	NEOGEO_CURVED,
	NEOGEO_MODERN,
	STATIC_RAINBOW,
	GG_CUSTOM,
};

void selectEffect(LedEffectMode mode) {
	switch (mode) {
		case LedEffectMode::XBOX:            applyColorMapping(XboxColorMapping);             break;
		case LedEffectMode::SFC:             applyColorMapping(SuperFamicomColorMapping);     break;
		case LedEffectMode::SIX_BUTTON:      applyColorMapping(SixButtonFighterColorMapping); break;
		case LedEffectMode::GG_TYPE_A:       applyColorMapping(GuiltyGearTypeAColorMapping);  break;
		case LedEffectMode::NEOGEO_STRAIGHT: applyColorMapping(NeoGeoStraightColorMapping);   break;
		case LedEffectMode::NEOGEO_CURVED:   applyColorMapping(NeoGeoCurvedColorMapping);     break;
		case LedEffectMode::NEOGEO_MODERN:   applyColorMapping(NeoGeoModernColorMapping);     break;
		case LedEffectMode::STATIC_RAINBOW:  applyColorMapping(StaticRainbowButtonMapping);   break;
		case LedEffectMode::GG_CUSTOM:       applyColorMapping(GuiltyGearCustomColorMapping); break;
	}
}

void showLeds() {
	FastLED.show();
}

#endif
