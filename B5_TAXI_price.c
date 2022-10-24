#include <stdio.h>

int tinhtien(int km)
{
    int tongtien=0;
    
    if (km <= 1)
    {
        tongtien = km * 5000;
    }
    else if (km > 1 && km <=30)
    {
        tongtien = 1*5000 + (km-1)*4000;
    }
    else if (km>30)
    {
        tongtien = 1*5000 + 30*4000 + (km-31)*3000;
    }
    return tongtien;
        
}
int main(int argc, char const *argv[])
{
    int quangduong;
    do
    {
        printf("Nhap so km da di: ");
        scanf("%d",&quangduong);
    } while (quangduong < 0);
        
    printf("So tien phai tra la: %d d",tinhtien(quangduong));
    return 0;
}
