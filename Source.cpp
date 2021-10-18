//
3 // SFML - Simple and Fast Multimedia Library
4 // Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
5 //
6 // This software is provided 'as-is', without any express or implied warranty.
7 // In no event will the authors be held liable for any damages arising from the use of this software.
8 //
9 // Permission is granted to anyone to use this software for any purpose,
10 // including commercial applications, and to alter it and redistribute it freely,
11 // subject to the following restrictions:
12 //
13 // 1. The origin of this software must not be misrepresented;
14 //    you must not claim that you wrote the original software.
15 //    If you use this software in a product, an acknowledgment
16 //    in the product documentation would be appreciated but is not required.
17 //
18 // 2. Altered source versions must be plainly marked as such,
19 //    and must not be misrepresented as being the original software.
20 //
21 // 3. This notice may not be removed or altered from any source distribution.
22 //
24
25 #ifndef SFML_RANDOMIZER_HPP
26 #define SFML_RANDOMIZER_HPP
27
29 // Headers
31 #include <SFML/Config.hpp>
32
33
34 namespace sf
35 {
    40 class SFML_API Randomizer
        41 {
    42 public:
        43
            51     static void SetSeed(unsigned int Seed);
        52
            59     static unsigned int GetSeed();
        60
            70     static float Random(float Begin, float End);
        71
            81     static int Random(int Begin, int End);
        82
    83 private:
        84
            86     // Static member variables
            88     static unsigned int ourSeed;
        89 };
    90
        91 } // namespace sf
92
93
94 #endif // SFML_RANDOMIZER_HPP