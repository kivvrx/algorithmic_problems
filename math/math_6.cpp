#include <iostream>
#include <bitset>
#include <string>

// b ^ (b[i+1] на каждой позиции (подставить пример)) 
// b 1 1 0 1 
// g 1 0 1 1  это должно получится по формуле if b[i+1] = 1 then g[i] = not b[i] else g[i] = b[i]
// теперь эквивалент 
//       i 3 2 1 0
//    b[i] 1 1 0 1 
//  b[i+1] 0 1 1 0  тоесть это сдвиг вправо на 1 
//      g  1 0 1 1  num ^ (num >> 1) == b ^ (b[i+1])
unsigned int gray_encode(unsigned int const num)
{
   return num ^ (num >> 1); 
}
// по формуле g[i] = b[i] XOR b[i+1]
// добавим XOR b[i+1] к обеим частям 
// g[i] XOR b[i+1] = b[i] XOR b[i+1] XOR b[i+1] (b[i+1] XOR b[i+1] == 0, b[i] XOR 0 == b[i])
// получим 
// b[i] = g[i] XOR b[i+1] (1)
// посмотрим на b[i+1] = g[i+1] XOR b[i+2]
// подставим в (1)
// получим b[i] = g[i] XOR g[i+1] XOR b[i+2] (2)
// если это продолжать рекурсивно то получим b[i] — это XOR всех старших битов g там последний член будет b[i+...] но это уже будет 0 поэтому ничего не 
// поменяется 
// теперь мы будем увеличивать шаг на (умножить на 2) потому что 
// домножим шаг в (2) на 2  => получим b[i+2] = g[i+2] XOR g[i+3] XOR b[i+4] (3)
// далее надо найти b[i+4] опять домножим шаг на 2 в (3) => получим b[i+4] = g[i+4] XOR g[i+6] XOR b[i+8]
// и так далее тоесть мы шаг всегда домножаем на 2 в итоге прийдем с полностью декодированному числу тут надо знать только сколько 
// мы задействуем разрядов 
// теперь пример нам надо получить b[i] = g[i] XOR g[i+1] XOR b[i+2] (надо получить g[i] XOR g[i+1])
// оно получится если сдвинуть вправо число g 
// i i+4 i+3 i+2 i+1  i
// g  0   1   0   1   1  
// сдвигаем на 1 вправо получим другое g  
// i i+5 i+4 i+3 i+2 i+1
// g  0   0   1   0   1
// делаем g[i] XOR g[i+1]
// теперь у нас содержится для i g[i] XOR g[i+1] это промежуточное b[i] НЕ РЕКУРСИВНОЕ но по формуле (2) надо получить то что мы сейчас получили
// вот у нас теперь что получилось 
// i i+4 i+3 i+2 i+1  i
// b  0   1   1   1   0
// смотрим на (2) нам надо получить  g[i] XOR g[i+1] XOR b[i+2] (g[i] XOR g[i+1] это b[i]) значит сдвинем b на 2 вправо 
// потом смотрим на (3) надо получить b[i+4] шаг умножим на 2 опять и так далее умножаем до старшего разряда нужного нам 
// нам нужно 5 битное число значит до 31 
unsigned int gray_decode(unsigned int g)
{

    unsigned int b = g;
    for (unsigned int shift = 1; shift < 32; shift <<= 1)
        b ^= b >> shift;
    return b;
}


std::string to_binary(unsigned int value, int const digits)
{
   return std::bitset<32>(value).to_string().substr(32-digits);
}

int main()
{
   std::cout << "Number\tBinary\tGray\tDecoded\n";
   std::cout << "------\t------\t----\t-------\n";

   for (unsigned int n = 0; n < 32; ++n)
   {
      auto encg = gray_encode(n);
      auto decg = gray_decode(encg);

      std::cout 
         << n << "\t" << to_binary(n, 5) << "\t" 
         << to_binary(encg, 5) << "\t" << decg << "\n";
   }
}