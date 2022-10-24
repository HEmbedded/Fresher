// Xuất giá trị xuất hiện nhiều lần nhất trong mảng, in ra giá trị và vị trí
// Xuất số lần xuất hiện của mỗi giá trị khác nhau trong mảng

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Kiểu dữ liệu của mảng
typedef struct{
    int *ptr;
    int size;
}Array;

// xuất giá trị của mảng
void xuatmang (Array mang)
{
    for (int i = 0; i < mang.size; i++)
    {  
        printf(" %d ", mang.ptr[i]);
    }
}

// Tạo mảng random
void CreateArray(Array *value){

    srand(time(NULL));
    value->size = 6 + rand() % (30 +1 - 20);
    int temp;
    printf("Kich thuoc cua array: %d\n", value->size);

    value->ptr = (int *)malloc(value->size * sizeof(int));

    for(int i = 0; i < value->size; i++){
        temp = rand() %9;
        value->ptr[i] = temp;
    }
}


// Hàm tính số lần xuất hiện của mỗi số trong mảng random
void count (Array mang, Array *dem)
{ 
    for (int i = 0; i < mang.size; i++)
    {
        for (int j = i+1; j < mang.size; j++)
        {
            if (mang.ptr[i] == mang.ptr[j])
            {
                dem->ptr[j] = dem->ptr[j] + 1;               
            }          
        }             
    }  
}

// Hàm xuất giá trị xuất hiện nhiều nhất và vị trí của nó trong hàm random
void XuatHienNhieuNhat(Array mang, Array dem)
{
    int max=0;
    for (int i = 0; i < dem.size; i++)
    {
        if (dem.ptr[i] > max)
        {
            max = dem.ptr[i];
        }
    }

    int temp=0;
    for (int j = 0 + temp; j < mang.size; j++)
    {
        if (dem.ptr[j] == max)
        {
            printf("\nSo %d xuat hien nhieu nhat\nSo lan xuat hien la: %d\n", mang.ptr[j], dem.ptr[j]);
            printf("Nam o vi tri:             ");
            for (int k = 0; k < dem.size; k++)
            {
                if (mang.ptr[j] ==  mang.ptr[k])
                {
                    printf(" x ");
                }else
                {
                    printf("   ");
                }
            }
        }       
    }         
}

// Hàm xuất số lần xuất hiện của mỗi giá trị trong mảng random
void SoLanXuatHien (Array mang, Array dem)
{
    int temp=1;
    for (int i = 0; i < mang.size; i++)
    {
        if (dem.ptr[i] == 1)
        {
            for (int j = i+1; j < mang.size; j++)
            {
                if (mang.ptr[i] == mang.ptr[j])
                {
                    temp++;       
                }
            }           
        printf("\nGia tri %d xuat hien %d lan", mang.ptr[i],temp);   
        temp=1;            
        }              
    }   
}


int main(int argc, char const *argv[])
{
    // Khai báo tên mảng random và mảng phụ
    Array mang, dem;

    // Tạo giá trị random cho mảng
    CreateArray(&mang);

    // Tạo địa chỉ cho mảng đếm
    dem.ptr = (int*)malloc(mang.size * sizeof(int));
    dem.size = mang.size;

    // Gán giá trị 1 cho toàn bộ giá trị mảng đếm
    for (int i = 0; i < dem.size; i++)
    {
        dem.ptr[i] = 1;
    }

    // Kiểm tra giá trị mảng đã được random hay chưa ?
    printf("\nMang random =             ");
    xuatmang(mang);

    // Đếm giá trị trùng cho mảng dem và in ra
    count(mang,&dem);
    printf("\nMang dem da count:        ");
    xuatmang(dem);
    
    // In ra giá trị xuất hiện nhiều nhất và vị trí của nó trong mảng random
    XuatHienNhieuNhat(mang,dem);

    // In ra số lần xuất hiện của mỗi giá trị có trong mảng random
    SoLanXuatHien(mang,dem);
    
    return 0;
}
