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
#define ZN_KEY_SPACE                                32
#define ZN_KEY_APOSTROPHE                           39 /* ' */
#define ZN_KEY_COMMA                                44 /*  */
#define ZN_KEY_MINUS                                45 /* - */
#define ZN_KEY_PERIOD                               46 /* . */
#define ZN_KEY_SLASH                                47 /* / */
#define ZN_KEY_D0                                   48 /* 0 */
#define ZN_KEY_D1                                   49 /* 1 */
#define ZN_KEY_D2                                   50 /* 2 */
#define ZN_KEY_D3                                   51 /* 3 */
#define ZN_KEY_D4                                   52 /* 4 */
#define ZN_KEY_D5                                   53 /* 5 */
#define ZN_KEY_D6                                   54 /* 6 */
#define ZN_KEY_D7                                   55 /* 7 */
#define ZN_KEY_D8                                   56 /* 8 */
#define ZN_KEY_D9                                   57 /* 9 */
#define ZN_KEY_SEMICOLON                            59 /* ; */
#define ZN_KEY_EQUAL                                61 /*  */
#define ZN_KEY_A                                    65
#define ZN_KEY_B                                    66
#define ZN_KEY_C                                    67
#define ZN_KEY_D                                    68
#define ZN_KEY_E                                    69
#define ZN_KEY_F                                    70
#define ZN_KEY_G                                    71
#define ZN_KEY_H                                    72
#define ZN_KEY_I                                    73
#define ZN_KEY_J                                    74
#define ZN_KEY_K                                    75
#define ZN_KEY_L                                    76
#define ZN_KEY_M                                    77
#define ZN_KEY_N                                    78
#define ZN_KEY_O                                    79
#define ZN_KEY_P                                    80
#define ZN_KEY_Q                                    81
#define ZN_KEY_R                                    82
#define ZN_KEY_S                                    83
#define ZN_KEY_T                                    84
#define ZN_KEY_U                                    85
#define ZN_KEY_V                                    86
#define ZN_KEY_W                                    87
#define ZN_KEY_X                                    88
#define ZN_KEY_Y                                    89
#define ZN_KEY_Z                                    90
#define ZN_KEY_LEFTBRACKET                          91  /* [ */
#define ZN_KEY_BACKSLASH                            92  /* \ */
#define ZN_KEY_RIGHTBRACKET                         93  /* ] */
#define ZN_KEY_GRAVEACCENT                          96  /* ` */
#define ZN_KEY_WORLD1                               161 /* non-US #1 */
#define ZN_KEY_WORLD2                               162 /* non-US #2 */

/* Function keys */
#define ZN_KEY_ESCAPE                               256
#define ZN_KEY_ENTER                                257
#define ZN_KEY_TAB                                  258
#define ZN_KEY_BACKSPACE                            259
#define ZN_KEY_INSERT                               260
#define ZN_KEY_DELETE                               261
#define ZN_KEY_RIGHT                                262
#define ZN_KEY_LEFT                                 263
#define ZN_KEY_DOWN                                 264
#define ZN_KEY_UP                                   265
#define ZN_KEY_PAGEUP                               266
#define ZN_KEY_PAGEDOWN                             267
#define ZN_KEY_HOME                                 268
#define ZN_KEY_END                                  269
#define ZN_KEY_CAPSLOCK                             280
#define ZN_KEY_SCROLLLOCK                           281
#define ZN_KEY_NUMLOCK                              282
#define ZN_KEY_PRINTSCREEN                          283
#define ZN_KEY_PAUSE                                284
#define ZN_KEY_F1                                   290
#define ZN_KEY_F2                                   291
#define ZN_KEY_F3                                   292
#define ZN_KEY_F4                                   293
#define ZN_KEY_F5                                   294
#define ZN_KEY_F6                                   295
#define ZN_KEY_F7                                   296
#define ZN_KEY_F8                                   297
#define ZN_KEY_F9                                   298
#define ZN_KEY_F10                                  299
#define ZN_KEY_F11                                  300
#define ZN_KEY_F12                                  301
#define ZN_KEY_F13                                  302
#define ZN_KEY_F14                                  303
#define ZN_KEY_F15                                  304
#define ZN_KEY_F16                                  305
#define ZN_KEY_F17                                  306
#define ZN_KEY_F18                                  307
#define ZN_KEY_F19                                  308
#define ZN_KEY_F20                                  309
#define ZN_KEY_F21                                  310
#define ZN_KEY_F22                                  311
#define ZN_KEY_F23                                  312
#define ZN_KEY_F24                                  313
#define ZN_KEY_F25                                  314

/* Keypad */
#define ZN_KEY_KP0                                  320
#define ZN_KEY_KP1                                  321
#define ZN_KEY_KP2                                  322
#define ZN_KEY_KP3                                  323
#define ZN_KEY_KP4                                  324
#define ZN_KEY_KP5                                  325
#define ZN_KEY_KP6                                  326
#define ZN_KEY_KP7                                  327
#define ZN_KEY_KP8                                  328
#define ZN_KEY_KP9                                  329
#define ZN_KEY_KPDECIMAL                            330
#define ZN_KEY_KPDIVIDE                             331
#define ZN_KEY_KPMULTIPLY                           332
#define ZN_KEY_KPSUBTRACT                           333
#define ZN_KEY_KPADD                                334
#define ZN_KEY_KPENTER                              335
#define ZN_KEY_KPEQUAL                              336
#define ZN_KEY_LEFTSHIFT                            340
#define ZN_KEY_LEFTCONTROL                          341
#define ZN_KEY_LEFTALT                              342
#define ZN_KEY_LEFTSUPER                            343
#define ZN_KEY_RIGHTSHIFT                           344
#define ZN_KEY_RIGHTCONTROL                         345
#define ZN_KEY_RIGHTALT                             346
#define ZN_KEY_RIGHTSUPER                           347
#define ZN_KEY_MENU                                 348
