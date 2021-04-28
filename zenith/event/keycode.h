/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/4/24. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

// From glfw3.h
#define ZENITH_KEY_SPACE                                32
#define ZENITH_KEY_APOSTROPHE                           39 /* ' */
#define ZENITH_KEY_COMMA                                44 /*  */
#define ZENITH_KEY_MINUS                                45 /* - */
#define ZENITH_KEY_PERIOD                               46 /* . */
#define ZENITH_KEY_SLASH                                47 /* / */
#define ZENITH_KEY_D0                                   48 /* 0 */
#define ZENITH_KEY_D1                                   49 /* 1 */
#define ZENITH_KEY_D2                                   50 /* 2 */
#define ZENITH_KEY_D3                                   51 /* 3 */
#define ZENITH_KEY_D4                                   52 /* 4 */
#define ZENITH_KEY_D5                                   53 /* 5 */
#define ZENITH_KEY_D6                                   54 /* 6 */
#define ZENITH_KEY_D7                                   55 /* 7 */
#define ZENITH_KEY_D8                                   56 /* 8 */
#define ZENITH_KEY_D9                                   57 /* 9 */
#define ZENITH_KEY_SEMICOLON                            59 /* ; */
#define ZENITH_KEY_EQUAL                                61 /*  */
#define ZENITH_KEY_A                                    65
#define ZENITH_KEY_B                                    66
#define ZENITH_KEY_C                                    67
#define ZENITH_KEY_D                                    68
#define ZENITH_KEY_E                                    69
#define ZENITH_KEY_F                                    70
#define ZENITH_KEY_G                                    71
#define ZENITH_KEY_H                                    72
#define ZENITH_KEY_I                                    73
#define ZENITH_KEY_J                                    74
#define ZENITH_KEY_K                                    75
#define ZENITH_KEY_L                                    76
#define ZENITH_KEY_M                                    77
#define ZENITH_KEY_N                                    78
#define ZENITH_KEY_O                                    79
#define ZENITH_KEY_P                                    80
#define ZENITH_KEY_Q                                    81
#define ZENITH_KEY_R                                    82
#define ZENITH_KEY_S                                    83
#define ZENITH_KEY_T                                    84
#define ZENITH_KEY_U                                    85
#define ZENITH_KEY_V                                    86
#define ZENITH_KEY_W                                    87
#define ZENITH_KEY_X                                    88
#define ZENITH_KEY_Y                                    89
#define ZENITH_KEY_Z                                    90
#define ZENITH_KEY_LEFTBRACKET                          91  /* [ */
#define ZENITH_KEY_BACKSLASH                            92  /* \ */
#define ZENITH_KEY_RIGHTBRACKET                         93  /* ] */
#define ZENITH_KEY_GRAVEACCENT                          96  /* ` */
#define ZENITH_KEY_WORLD1                               161 /* non-US #1 */
#define ZENITH_KEY_WORLD2                               162 /* non-US #2 */

/* Function keys */
#define ZENITH_KEY_ESCAPE                               256
#define ZENITH_KEY_ENTER                                257
#define ZENITH_KEY_TAB                                  258
#define ZENITH_KEY_BACKSPACE                            259
#define ZENITH_KEY_INSERT                               260
#define ZENITH_KEY_DELETE                               261
#define ZENITH_KEY_RIGHT                                262
#define ZENITH_KEY_LEFT                                 263
#define ZENITH_KEY_DOWN                                 264
#define ZENITH_KEY_UP                                   265
#define ZENITH_KEY_PAGEUP                               266
#define ZENITH_KEY_PAGEDOWN                             267
#define ZENITH_KEY_HOME                                 268
#define ZENITH_KEY_END                                  269
#define ZENITH_KEY_CAPSLOCK                             280
#define ZENITH_KEY_SCROLLLOCK                           281
#define ZENITH_KEY_NUMLOCK                              282
#define ZENITH_KEY_PRINTSCREEN                          283
#define ZENITH_KEY_PAUSE                                284
#define ZENITH_KEY_F1                                   290
#define ZENITH_KEY_F2                                   291
#define ZENITH_KEY_F3                                   292
#define ZENITH_KEY_F4                                   293
#define ZENITH_KEY_F5                                   294
#define ZENITH_KEY_F6                                   295
#define ZENITH_KEY_F7                                   296
#define ZENITH_KEY_F8                                   297
#define ZENITH_KEY_F9                                   298
#define ZENITH_KEY_F10                                  299
#define ZENITH_KEY_F11                                  300
#define ZENITH_KEY_F12                                  301
#define ZENITH_KEY_F13                                  302
#define ZENITH_KEY_F14                                  303
#define ZENITH_KEY_F15                                  304
#define ZENITH_KEY_F16                                  305
#define ZENITH_KEY_F17                                  306
#define ZENITH_KEY_F18                                  307
#define ZENITH_KEY_F19                                  308
#define ZENITH_KEY_F20                                  309
#define ZENITH_KEY_F21                                  310
#define ZENITH_KEY_F22                                  311
#define ZENITH_KEY_F23                                  312
#define ZENITH_KEY_F24                                  313
#define ZENITH_KEY_F25                                  314

/* Keypad */
#define ZENITH_KEY_KP0                                  320
#define ZENITH_KEY_KP1                                  321
#define ZENITH_KEY_KP2                                  322
#define ZENITH_KEY_KP3                                  323
#define ZENITH_KEY_KP4                                  324
#define ZENITH_KEY_KP5                                  325
#define ZENITH_KEY_KP6                                  326
#define ZENITH_KEY_KP7                                  327
#define ZENITH_KEY_KP8                                  328
#define ZENITH_KEY_KP9                                  329
#define ZENITH_KEY_KPDECIMAL                            330
#define ZENITH_KEY_KPDIVIDE                             331
#define ZENITH_KEY_KPMULTIPLY                           332
#define ZENITH_KEY_KPSUBTRACT                           333
#define ZENITH_KEY_KPADD                                334
#define ZENITH_KEY_KPENTER                              335
#define ZENITH_KEY_KPEQUAL                              336
#define ZENITH_KEY_LEFTSHIFT                            340
#define ZENITH_KEY_LEFTCONTROL                          341
#define ZENITH_KEY_LEFTALT                              342
#define ZENITH_KEY_LEFTSUPER                            343
#define ZENITH_KEY_RIGHTSHIFT                           344
#define ZENITH_KEY_RIGHTCONTROL                         345
#define ZENITH_KEY_RIGHTALT                             346
#define ZENITH_KEY_RIGHTSUPER                           347
#define ZENITH_KEY_MENU                                 348
