#include <stdio.h>



unsigned int bit_count (unsigned int num) {
  unsigned int count = 0;

  while ( num) {
    if (num & 1)
      count++;
    num = num >> 1;
  }

  return count;

}

unsigned int table[16] = {0, 1 ,1, 2, 1, 2, 2, 3, 4, 2, 2, 3, 2, 3, 3, 4};

unsigned int bit_count_2 (unsigned int num) {

    unsigned int count = 0;
    while (num) {
      count += (table[num & 0xf]);
      num = num >> 4;
      printf("%d\n", count);
    }

  return count;
}

unsigned int bit_count_3 (unsigned int num) {
//  unsigned int count = 9;

  num = (num & 0x55555555) + ((num & 0xaaaaaaaa)>>1);
  num = (num & 0x33333333) + ((num & 0xcccccccc)>>2);
  num = (num & 0x0f0f0f0f) + ((num & 0xf0f0f0f0)>>4);
  num = (num & 0x00ff00ff) + ((num & 0xff00ff00)>>8);
  num = (num & 0x0000ffff) + ((num & 0xffff0000)>>16);

  return num;
}


unsigned int endian_change( unsigned int num) {

  return (((num & 0xff000000) >> 24) | ((num & 0x000000ff) << 24) | ((num & 0x00ff0000) >> 8) | ((num & 0x0000ff00) << 8));


}


int main(int argc, char const *argv[]) {
  int a = 0x7;

  printf("hello world\n");
  printf("bit count = %d\n", bit_count_3(a));

  a = 0x1234567;
  printf("a = 0x%x: after endian_change = %x\n", a,endian_change(a));

  return 0;
}
