#ifndef __KEYBOARDBUTTON_H__
#define __KEYBOARDBUTTON_H__

namespace BadEngine {
	enum KeyboardButton {
		// ASCII mapped keysyms
		// The keyboard syms have been cleverly chosen to map to ASCII
		KEYBOARD_BUTTON_UNKNOWN		= 0,
		KEYBOARD_BUTTON_FIRST		= 0,
		KEYBOARD_BUTTON_BACKSPACE		= 8,
		KEYBOARD_BUTTON_TAB		= 9,
		KEYBOARD_BUTTON_CLEAR		= 12,
		KEYBOARD_BUTTON_RETURN		= 13,
		KEYBOARD_BUTTON_PAUSE		= 19,
		KEYBOARD_BUTTON_ESCAPE		= 27,
		KEYBOARD_BUTTON_SPACE		= 32,
		KEYBOARD_BUTTON_EXCLAIM		= 33,
		KEYBOARD_BUTTON_QUOTEDBL		= 34,
		KEYBOARD_BUTTON_HASH		= 35,
		KEYBOARD_BUTTON_DOLLAR		= 36,
		KEYBOARD_BUTTON_AMPERSAND		= 38,
		KEYBOARD_BUTTON_QUOTE		= 39,
		KEYBOARD_BUTTON_LEFTPAREN		= 40,
		KEYBOARD_BUTTON_RIGHTPAREN		= 41,
		KEYBOARD_BUTTON_ASTERISK		= 42,
		KEYBOARD_BUTTON_PLUS		= 43,
		KEYBOARD_BUTTON_COMMA		= 44,
		KEYBOARD_BUTTON_MINUS		= 45,
		KEYBOARD_BUTTON_PERIOD		= 46,
		KEYBOARD_BUTTON_SLASH		= 47,
		KEYBOARD_BUTTON_0			= 48,
		KEYBOARD_BUTTON_1			= 49,
		KEYBOARD_BUTTON_2			= 50,
		KEYBOARD_BUTTON_3			= 51,
		KEYBOARD_BUTTON_4			= 52,
		KEYBOARD_BUTTON_5			= 53,
		KEYBOARD_BUTTON_6			= 54,
		KEYBOARD_BUTTON_7			= 55,
		KEYBOARD_BUTTON_8			= 56,
		KEYBOARD_BUTTON_9			= 57,
		KEYBOARD_BUTTON_COLON		= 58,
		KEYBOARD_BUTTON_SEMICOLON		= 59,
		KEYBOARD_BUTTON_LESS		= 60,
		KEYBOARD_BUTTON_EQUALS		= 61,
		KEYBOARD_BUTTON_GREATER		= 62,
		KEYBOARD_BUTTON_QUESTION		= 63,
		KEYBOARD_BUTTON_AT			= 64,
		// Skip uppercase letters
		KEYBOARD_BUTTON_LEFTBRACKET	= 91,
		KEYBOARD_BUTTON_BACKSLASH		= 92,
		KEYBOARD_BUTTON_RIGHTBRACKET	= 93,
		KEYBOARD_BUTTON_CARET		= 94,
		KEYBOARD_BUTTON_UNDERSCORE		= 95,
		KEYBOARD_BUTTON_BACKQUOTE		= 96,
		KEYBOARD_BUTTON_A			= 97,
		KEYBOARD_BUTTON_B			= 98,
		KEYBOARD_BUTTON_C			= 99,
		KEYBOARD_BUTTON_D			= 100,
		KEYBOARD_BUTTON_E			= 101,
		KEYBOARD_BUTTON_F			= 102,
		KEYBOARD_BUTTON_G			= 103,
		KEYBOARD_BUTTON_H			= 104,
		KEYBOARD_BUTTON_I			= 105,
		KEYBOARD_BUTTON_J			= 106,
		KEYBOARD_BUTTON_K			= 107,
		KEYBOARD_BUTTON_L			= 108,
		KEYBOARD_BUTTON_M			= 109,
		KEYBOARD_BUTTON_N			= 110,
		KEYBOARD_BUTTON_O			= 111,
		KEYBOARD_BUTTON_P			= 112,
		KEYBOARD_BUTTON_Q			= 113,
		KEYBOARD_BUTTON_R			= 114,
		KEYBOARD_BUTTON_S			= 115,
		KEYBOARD_BUTTON_T			= 116,
		KEYBOARD_BUTTON_U			= 117,
		KEYBOARD_BUTTON_V			= 118,
		KEYBOARD_BUTTON_W			= 119,
		KEYBOARD_BUTTON_X			= 120,
		KEYBOARD_BUTTON_Y			= 121,
		KEYBOARD_BUTTON_Z			= 122,
		KEYBOARD_BUTTON_DELETE		= 127,
		// End of ASCII mapped keysyms
		
		// International keyboard syms
		KEYBOARD_BUTTON_WORLD_0		= 160, // 0xA0
		KEYBOARD_BUTTON_WORLD_1		= 161,
		KEYBOARD_BUTTON_WORLD_2		= 162,
		KEYBOARD_BUTTON_WORLD_3		= 163,
		KEYBOARD_BUTTON_WORLD_4		= 164,
		KEYBOARD_BUTTON_WORLD_5		= 165,
		KEYBOARD_BUTTON_WORLD_6		= 166,
		KEYBOARD_BUTTON_WORLD_7		= 167,
		KEYBOARD_BUTTON_WORLD_8		= 168,
		KEYBOARD_BUTTON_WORLD_9		= 169,
		KEYBOARD_BUTTON_WORLD_10		= 170,
		KEYBOARD_BUTTON_WORLD_11		= 171,
		KEYBOARD_BUTTON_WORLD_12		= 172,
		KEYBOARD_BUTTON_WORLD_13		= 173,
		KEYBOARD_BUTTON_WORLD_14		= 174,
		KEYBOARD_BUTTON_WORLD_15		= 175,
		KEYBOARD_BUTTON_WORLD_16		= 176,
		KEYBOARD_BUTTON_WORLD_17		= 177,
		KEYBOARD_BUTTON_WORLD_18		= 178,
		KEYBOARD_BUTTON_WORLD_19		= 179,
		KEYBOARD_BUTTON_WORLD_20		= 180,
		KEYBOARD_BUTTON_WORLD_21		= 181,
		KEYBOARD_BUTTON_WORLD_22		= 182,
		KEYBOARD_BUTTON_WORLD_23		= 183,
		KEYBOARD_BUTTON_WORLD_24		= 184,
		KEYBOARD_BUTTON_WORLD_25		= 185,
		KEYBOARD_BUTTON_WORLD_26		= 186,
		KEYBOARD_BUTTON_WORLD_27		= 187,
		KEYBOARD_BUTTON_WORLD_28		= 188,
		KEYBOARD_BUTTON_WORLD_29		= 189,
		KEYBOARD_BUTTON_WORLD_30		= 190,
		KEYBOARD_BUTTON_WORLD_31		= 191,
		KEYBOARD_BUTTON_WORLD_32		= 192,
		KEYBOARD_BUTTON_WORLD_33		= 193,
		KEYBOARD_BUTTON_WORLD_34		= 194,
		KEYBOARD_BUTTON_WORLD_35		= 195,
		KEYBOARD_BUTTON_WORLD_36		= 196,
		KEYBOARD_BUTTON_WORLD_37		= 197,
		KEYBOARD_BUTTON_WORLD_38		= 198,
		KEYBOARD_BUTTON_WORLD_39		= 199,
		KEYBOARD_BUTTON_WORLD_40		= 200,
		KEYBOARD_BUTTON_WORLD_41		= 201,
		KEYBOARD_BUTTON_WORLD_42		= 202,
		KEYBOARD_BUTTON_WORLD_43		= 203,
		KEYBOARD_BUTTON_WORLD_44		= 204,
		KEYBOARD_BUTTON_WORLD_45		= 205,
		KEYBOARD_BUTTON_WORLD_46		= 206,
		KEYBOARD_BUTTON_WORLD_47		= 207,
		KEYBOARD_BUTTON_WORLD_48		= 208,
		KEYBOARD_BUTTON_WORLD_49		= 209,
		KEYBOARD_BUTTON_WORLD_50		= 210,
		KEYBOARD_BUTTON_WORLD_51		= 211,
		KEYBOARD_BUTTON_WORLD_52		= 212,
		KEYBOARD_BUTTON_WORLD_53		= 213,
		KEYBOARD_BUTTON_WORLD_54		= 214,
		KEYBOARD_BUTTON_WORLD_55		= 215,
		KEYBOARD_BUTTON_WORLD_56		= 216,
		KEYBOARD_BUTTON_WORLD_57		= 217,
		KEYBOARD_BUTTON_WORLD_58		= 218,
		KEYBOARD_BUTTON_WORLD_59		= 219,
		KEYBOARD_BUTTON_WORLD_60		= 220,
		KEYBOARD_BUTTON_WORLD_61		= 221,
		KEYBOARD_BUTTON_WORLD_62		= 222,
		KEYBOARD_BUTTON_WORLD_63		= 223,
		KEYBOARD_BUTTON_WORLD_64		= 224,
		KEYBOARD_BUTTON_WORLD_65		= 225,
		KEYBOARD_BUTTON_WORLD_66		= 226,
		KEYBOARD_BUTTON_WORLD_67		= 227,
		KEYBOARD_BUTTON_WORLD_68		= 228,
		KEYBOARD_BUTTON_WORLD_69		= 229,
		KEYBOARD_BUTTON_WORLD_70		= 230,
		KEYBOARD_BUTTON_WORLD_71		= 231,
		KEYBOARD_BUTTON_WORLD_72		= 232,
		KEYBOARD_BUTTON_WORLD_73		= 233,
		KEYBOARD_BUTTON_WORLD_74		= 234,
		KEYBOARD_BUTTON_WORLD_75		= 235,
		KEYBOARD_BUTTON_WORLD_76		= 236,
		KEYBOARD_BUTTON_WORLD_77		= 237,
		KEYBOARD_BUTTON_WORLD_78		= 238,
		KEYBOARD_BUTTON_WORLD_79		= 239,
		KEYBOARD_BUTTON_WORLD_80		= 240,
		KEYBOARD_BUTTON_WORLD_81		= 241,
		KEYBOARD_BUTTON_WORLD_82		= 242,
		KEYBOARD_BUTTON_WORLD_83		= 243,
		KEYBOARD_BUTTON_WORLD_84		= 244,
		KEYBOARD_BUTTON_WORLD_85		= 245,
		KEYBOARD_BUTTON_WORLD_86		= 246,
		KEYBOARD_BUTTON_WORLD_87		= 247,
		KEYBOARD_BUTTON_WORLD_88		= 248,
		KEYBOARD_BUTTON_WORLD_89		= 249,
		KEYBOARD_BUTTON_WORLD_90		= 250,
		KEYBOARD_BUTTON_WORLD_91		= 251,
		KEYBOARD_BUTTON_WORLD_92		= 252,
		KEYBOARD_BUTTON_WORLD_93		= 253,
		KEYBOARD_BUTTON_WORLD_94		= 254,
		KEYBOARD_BUTTON_WORLD_95		= 255, // 0xFF
		
		// Numeric keypad
		KEYBOARD_BUTTON_KP0		= 256,
		KEYBOARD_BUTTON_KP1		= 257,
		KEYBOARD_BUTTON_KP2		= 258,
		KEYBOARD_BUTTON_KP3		= 259,
		KEYBOARD_BUTTON_KP4		= 260,
		KEYBOARD_BUTTON_KP5		= 261,
		KEYBOARD_BUTTON_KP6		= 262,
		KEYBOARD_BUTTON_KP7		= 263,
		KEYBOARD_BUTTON_KP8		= 264,
		KEYBOARD_BUTTON_KP9		= 265,
		KEYBOARD_BUTTON_KP_PERIOD		= 266,
		KEYBOARD_BUTTON_KP_DIVIDE		= 267,
		KEYBOARD_BUTTON_KP_MULTIPLY	= 268,
		KEYBOARD_BUTTON_KP_MINUS		= 269,
		KEYBOARD_BUTTON_KP_PLUS		= 270,
		KEYBOARD_BUTTON_KP_ENTER		= 271,
		KEYBOARD_BUTTON_KP_EQUALS		= 272,
		
		// Arrows + Home/End pad
		KEYBOARD_BUTTON_UP			= 273,
		KEYBOARD_BUTTON_DOWN		= 274,
		KEYBOARD_BUTTON_RIGHT		= 275,
		KEYBOARD_BUTTON_LEFT		= 276,
		KEYBOARD_BUTTON_INSERT		= 277,
		KEYBOARD_BUTTON_HOME		= 278,
		KEYBOARD_BUTTON_END		= 279,
		KEYBOARD_BUTTON_PAGEUP		= 280,
		KEYBOARD_BUTTON_PAGEDOWN		= 281,
		
		// Function keys
		KEYBOARD_BUTTON_F1			= 282,
		KEYBOARD_BUTTON_F2			= 283,
		KEYBOARD_BUTTON_F3			= 284,
		KEYBOARD_BUTTON_F4			= 285,
		KEYBOARD_BUTTON_F5			= 286,
		KEYBOARD_BUTTON_F6			= 287,
		KEYBOARD_BUTTON_F7			= 288,
		KEYBOARD_BUTTON_F8			= 289,
		KEYBOARD_BUTTON_F9			= 290,
		KEYBOARD_BUTTON_F10		= 291,
		KEYBOARD_BUTTON_F11		= 292,
		KEYBOARD_BUTTON_F12		= 293,
		KEYBOARD_BUTTON_F13		= 294,
		KEYBOARD_BUTTON_F14		= 295,
		KEYBOARD_BUTTON_F15		= 296,
		
		// Key state modifier keys
		KEYBOARD_BUTTON_NUMLOCK		= 300,
		KEYBOARD_BUTTON_CAPSLOCK		= 301,
		KEYBOARD_BUTTON_SCROLLOCK		= 302,
		KEYBOARD_BUTTON_RSHIFT		= 303,
		KEYBOARD_BUTTON_LSHIFT		= 304,
		KEYBOARD_BUTTON_RCTRL		= 305,
		KEYBOARD_BUTTON_LCTRL		= 306,
		KEYBOARD_BUTTON_RALT		= 307,
		KEYBOARD_BUTTON_LALT		= 308,
		KEYBOARD_BUTTON_RMETA		= 309,
		KEYBOARD_BUTTON_LMETA		= 310,
		KEYBOARD_BUTTON_LSUPER		= 311, // Left "Windows" key
		KEYBOARD_BUTTON_RSUPER		= 312, // Right "Windows" key
		KEYBOARD_BUTTON_MODE		= 313, // "Alt Gr" key */
		KEYBOARD_BUTTON_COMPOSE		= 314, // Multi-key compose key
		
		// Miscellaneous function keys
		KEYBOARD_BUTTON_HELP		= 315,
		KEYBOARD_BUTTON_PRINT		= 316,
		KEYBOARD_BUTTON_SYSREQ		= 317,
		KEYBOARD_BUTTON_BREAK		= 318,
		KEYBOARD_BUTTON_MENU		= 319,
		KEYBOARD_BUTTON_POWER		= 320, // Power Macintosh power key */
		KEYBOARD_BUTTON_EURO		= 321, // Some european keyboards */
		KEYBOARD_BUTTON_UNDO		= 322, // Atari keyboard has Undo */
		
		// Add any other keys here
		
		KEYBOARD_BUTTON_LAST
	};
};

#endif // __KEYBOARDBUTTON_H__
