#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define SoLuongBanToiDa 20

typedef struct 
{
    uint8_t ID;
    char TEN[20];
    uint16_t GIA;
}ThucAn;

vector<ThucAn> DataThucAn;

typedef struct
{
    uint8_t ID;
    char THUCAN[20];
    uint8_t SO_LUONG;
    uint16_t DONGIA;
}Ban;


class QuanLy
{
public:
    void ThemThucAn();
    void SuaThucAn();
    void XoaThucAn();
    void HienThiDataThucAn();
};

class NhanVien
{
public:
    void ThemBan();
    void TinhTien();
    void ThemMon(uint8_t ID_ban);
    void HienThiDataBan();
private:
    vector<Ban> Data_ID_Ban;
    uint8_t CheckBan(uint8_t so_ban);
    uint8_t CheckThucAn(uint8_t ID);
    void sortData();
    void Used_Table();
};

void QuanLy::ThemThucAn()
{
    system("cls");
    ThucAn thuc_an;
    static uint8_t id = 1;
    thuc_an.ID = id;
    id++;
    printf("Nhap ten thuc an: \n");
    scanf("%s", thuc_an.TEN);
    
    printf("Nhap gia tien cho thuc an %s\n", thuc_an.TEN);
    scanf("%d", &thuc_an.GIA);
    
    DataThucAn.push_back(thuc_an);
}

//Sửa thông tin là nó bị nhảy lệch
void QuanLy::SuaThucAn()
{
    if (DataThucAn.empty() == 1)
    {
        printf("Chua co thong tin thuc an\n");
        return;
    }
    QuanLy ql;
    uint8_t fix , checkphim;
    char temp[20];
    ql.HienThiDataThucAn();
    printf("Nhap ID thuc an muon sua thong tin:\n");
    scanf("%d", &fix);
    int i;
    for (i = 0; i < DataThucAn.size(); i++)
    {
        if (DataThucAn[i].ID == fix)
        {   
            printf("Thong tin thuc an dang duoc sua:\n");
            printf("ID: %d \t Ten: %s \t Gia tien: %d\n ",DataThucAn[i].ID ,DataThucAn[i].TEN , DataThucAn[i].GIA);
            // do
            // {
            //     printf("Moi ban chon thong tin can duoc thay doi\n");
            //     printf("Nhap 1 de sua ten thuc an\n");
            //     printf("Nhap 2 de sua gia tien thuc an\n");
            //     printf("Nhap 0 de xac nhan va thoat\n");
            //     scanf("%d",&checkphim);
            //     if (checkphim == 1)
            //     {
                    printf("Nhap ten moi: \n");
                    scanf("%s",temp);
                    strcpy(DataThucAn[i].TEN , temp);
                // }
                // else if (checkphim == 2)
                // {
                    printf("Nhap gia tien moi: \n");
                    scanf("%d",&DataThucAn[i].GIA);

                // }
                // else if (checkphim == 0)
                // {
                    
                    printf("Thong tin thuc an dang da duoc sua thanh:\n");
                    printf("ID: %d \t Ten: %s \t Gia tien: %d\n ",DataThucAn[i].ID ,DataThucAn[i].TEN , DataThucAn[i].GIA );
                    break;
            //     }else printf("Ban da nhap sai, vui long nhap lai\n");
                
            // } while (checkphim != 0);          
        }   
    } 
}

void QuanLy::XoaThucAn()
{
    if (DataThucAn.empty() == 1)
    {
        printf("Chua co thong tin thuc an\n");
        return;
    }
    QuanLy ql;
    uint8_t fix , checkphim;
    ThucAn temp;
    ql.HienThiDataThucAn();
    printf("Nhap ID thuc an muon xoa:\n");
    scanf("%d", &fix);
    for (uint8_t i = 0; i < DataThucAn.size(); i++)
    {
        if (DataThucAn[i].ID == fix)
        {
            printf("Thong tin thuc an dang xoa:\n");
            printf("ID: %d \t, Ten: %s \t, Gia tien: %d\n ",DataThucAn[i].ID ,DataThucAn[i].TEN , DataThucAn[i].GIA );
            DataThucAn.erase(DataThucAn.begin() + i);
            printf("Da xoa thuc an thanh cong !!!\n");
        }        
    }
}

void QuanLy::HienThiDataThucAn()
{
    if (DataThucAn.empty() == 1)
    {
        printf("Chua co thong tin thuc an\n");
        return;
    }
    printf("Danh sach thuc an hien co:\n");
    printf("ID\tTen\t\t\tGia Tien\n");
    for (uint8_t i = 0; i < DataThucAn.size(); i++)
    {
        printf("%d\t%s\t\t\t%d\n",DataThucAn[i].ID,DataThucAn[i].TEN,DataThucAn[i].GIA);
    } 
}

uint8_t NhanVien::CheckBan(uint8_t so_ban)
{   
    
    for (uint8_t i = 0; i < Data_ID_Ban.size(); i++)
    {
        if (Data_ID_Ban[i].ID == so_ban)
        {
            return 1;
        }  
    }
    return 0;   
}

uint8_t NhanVien::CheckThucAn(uint8_t ID)
{
    for (uint8_t i = 0; i < DataThucAn.size() ; i++)
    {
        if (DataThucAn[i].ID == ID)
        {
            return 1;
        }     
    }
    return 0;
    
}

//Không gán được giá trị giá từ data thức ăn qua giá trị giá của data bàn
void NhanVien::ThemMon(uint8_t ID_ban)
{
    uint8_t tam = 0, NhapID;
    Ban ban;
    ban.ID = ID_ban;

    do
    {   
        if (tam > 0)
        {
            printf("ID ban vua nhap khong ton tai, vui long nhap lai !!!\n");
        }

        printf("Nhap ID mon de chon thuc an:\n");
        scanf("%d", &NhapID);
    
        tam++;
    }while (CheckThucAn(NhapID) == 0);
    
    for (uint8_t i = 0; i < DataThucAn.size(); i++)
    {
        
        if (DataThucAn[i].ID == NhapID)
        {
            strcpy(ban.THUCAN,DataThucAn[i].TEN);   //Target , source
            
            //Tại sao Không gán được giá trị ?
            ban.DONGIA  =  DataThucAn[i].GIA;
             
        }
        
    }   
    printf("Nhap so luong: \n");
    scanf("%d", &ban.SO_LUONG);
    Data_ID_Ban.push_back(ban);
}

void NhanVien::ThemBan()
{
    
    uint8_t tam = 0;
    QuanLy ql;
    Ban so_ban;
    so_ban.SO_LUONG = 0;
    //Used_Table();
    do
    {
        if (tam > 0)
        {
            printf("So %d ban vua nhap da co, vui long nhap lai\n",so_ban.ID);
        }

        printf("Nhap ID ban: \n");
        scanf("%d",&so_ban.ID);

        while (so_ban.ID > SoLuongBanToiDa)
        {
            printf("So ban vuot muc cho phep !!! vui long nhap lai !!!\n");
            printf("Nhap so ban: \n");
            scanf("%d",&so_ban.ID);
        }
        
               
        tam++;
    } while (CheckBan(so_ban.ID) == 1);


    printf("Da tao ban %d thanh cong\n",so_ban.ID);
    uint8_t temp = so_ban.ID;
    ql.HienThiDataThucAn();
    
    uint8_t checkphim = 1;
    do
    {          
        ThemMon(temp);

        printf("Nhap 1 de them mon\n");
        printf("Nhap 0 de xac nhan va thoat\n");
        scanf("%d",&checkphim);
    } while (checkphim == 1);      
}

void NhanVien::sortData()
{
    Ban temp;
    for (int i = 0; i < Data_ID_Ban.size() - 1; i++)
    {
        for (int j = i + 1; j < Data_ID_Ban.size() ; j++)
        {
            if (Data_ID_Ban[i].ID > Data_ID_Ban[j].ID)
            {
                temp = Data_ID_Ban[i];
                Data_ID_Ban[i] = Data_ID_Ban[j];
                Data_ID_Ban[j] = temp;
            }            
        }
        
    }
    
}

void NhanVien::HienThiDataBan()
{
    if (Data_ID_Ban.empty() == 1)
    {
        printf("Khong co ban nao dang duoc su dung !!!\n");
        return;
    }
    
    sortData();
    uint8_t temp = 0,i,j;
    j = Data_ID_Ban[0].ID;
    
    for ( i = 0; i < Data_ID_Ban.size(); i++)
    {   
        if (temp == 0)
        {
            printf("Thuc an cua ban so %d bao gom:\n",Data_ID_Ban[i].ID);
        }        
        printf("%s \tSo Luong: %d \tDon Gia: %d \n", Data_ID_Ban[i].THUCAN , Data_ID_Ban[i].SO_LUONG , Data_ID_Ban[i].DONGIA);
        temp = 1;

        if ( Data_ID_Ban[i+1].ID != j)
        {
            j = Data_ID_Ban[i+1].ID;
            temp = 0;
        }            
    }   
}

void NhanVien::Used_Table()
{
    sortData();
    int ID , temp = 0;
    ID = Data_ID_Ban[0].ID;
    printf("Nhung ban da duoc su dung la: \n");
    for (uint8_t i = 0; i < Data_ID_Ban.size(); i++)
    {   
        if (temp == 0)
        {
            printf("%d \t",ID);
        }
        
        temp = 1;
        
        if ( Data_ID_Ban[i+1].ID != ID)
        {
            ID = Data_ID_Ban[i+1].ID;
            temp = 0;
        }       
    }
    printf("\n");   
}

void NhanVien::TinhTien()
{
    if (Data_ID_Ban.empty() == 1)
    {
        printf("Khong co ban nao dang duoc su dung !!!\n");
        return;
    }

    uint8_t id;
    uint32_t tongtien = 0;
    printf("Nhap ID ban can tinh tien: \n");
    scanf("%d", &id);
    
    sortData();
    printf("Thong tin hoa don cua ban can duoc tinh tien:\n");
    printf("Ten thuc an: \t\t So luong: \t\t Don gia\n");
    for ( uint8_t i = 0; i < Data_ID_Ban.size(); i++)
    {
        if (Data_ID_Ban[i].ID == id)
        {           
            printf("%s \t\t %d \t\t %d\n",Data_ID_Ban[i].THUCAN , Data_ID_Ban[i].SO_LUONG , Data_ID_Ban[i].DONGIA);
            tongtien = tongtien + (Data_ID_Ban[i].DONGIA * Data_ID_Ban[i].SO_LUONG);
        }   
    }

    printf("Tong tien cua ban so %d la: %d\n",id,tongtien);
    
    uint8_t checkphim;
    do
    {
        printf("Nhan 1 de xac nhan thanh toan !!!\n");
        printf("Nhan 0 de thoat\n");
        scanf("%d",&checkphim);
        if (checkphim == 1)
        {   
            label:
            for (uint8_t i = 0; i < Data_ID_Ban.size(); i++)
            {
                if (Data_ID_Ban[i].ID == id)
                {
                    Data_ID_Ban.erase(Data_ID_Ban.begin()+i);
                    goto label;
                }
                
            }
            printf("Da thanh toan va xoa thong tin ban\n");
            
        }
        
    } while (checkphim != 0);
    
    

}
int main(int argc, char const *argv[])
{
    system("cls");
    NhanVien nv;
    QuanLy ql;
    int rank;
    do
    {
        printf("Nhan 1 neu ban la quan ly\n");
        printf("Nhan 2 neu ban la nhan vien\n");
        scanf("%d",&rank);
    } while (rank != 1 && rank != 2);
    
    
    int checkphim;
    system("cls");
    while (1)
    {   
        
        checkphim = 0;
        printf("Nhap yeu cau cua ban:\n");
        if (rank == 1)
        {
            printf("1. Them thuc an\n");
            //Sửa thông tin thức ăn bị lỗi
            printf("2. Sua thong tin thuc an:\n");
            printf("3. Xoa thuc an theo ID\n");
            printf("4. Hien thi tat ca thong tin thuc an da nhap\n");
        }
        printf("5. Them ban\n");
        printf("6. Tinh tien theo ID ban`\n");
        printf("7. Hien thi thong tin tat ca ban dang co nguoi su dung\n");
        printf("0. De thoat chuong trinh\n");
        scanf("%d",&checkphim);

        switch (checkphim)
        {
        case 1:
            if (rank == 1)
            {
                uint8_t x;
                do
                {
                    ql.ThemThucAn();
                    printf("Nhap 1 de tiep tuc them\n");
                    printf("Nhap 0 de tro ve menu chinh\n");
                    scanf("%d",&x);
                } while (x > 0);
                
                break;
            }else 
            {
                printf("Ban la nhan vien, khong the su dung chuc nang nay!!!\n"); 
                break;
            }
        case 2:
            if (rank == 1)
            {
                ql.SuaThucAn();
                break;
            }else 
            {
                printf("Ban la nhan vien, khong the su dung chuc nang nay!!!\n");
                break;
            }
        case 3:
            if (rank == 1)
            {
                ql.XoaThucAn();
                
                break;
            }else
            {
                printf("Ban la nhan vien, khong the su dung chuc nang nay!!!\n");
                break;
            }           
        case 4:
            if (rank == 1)
            {   
                ql.HienThiDataThucAn();
                break;
            }else 
            {
                printf("Ban la nhan vien, khong the su dung chuc nang nay!!!\n");
                break;
            }
            
        case 6:
            nv.TinhTien();
            break;

        case 5:
            nv.ThemBan();
            break;

        

        case 7:
            nv.HienThiDataBan();
            break;

        case 0:
            exit(0);

        default:
            break;
        }
    }
    
    
    return 0;
}

