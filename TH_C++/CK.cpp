#include<bits/stdc++.h>
using namespace std;
typedef struct MonHoc {
    string MaMH;
    int sotinchiMH;
    double DiemQT;
    double DiemCK;
    double trongsoCK;
    double DiemMH;
    string KetQuaMH;
}MonHoc;

typedef struct SinhVien {
    string Masv;
    string HoTen;
    string GioiTinh;
    int SoMonHoc;
    double DiemCPA;
    string XepLoai;
    vector<MonHoc> mhmh;
}SinhVien;



int main() {
    int n;
    vector<SinhVien> svsv;
    cout << "Nguyen Trung Thanh - 20215482 - 727736 - 2022.2 :" << endl;
    cout << "Nhap so luong sinh vien : ";
    cin >> n;
    cin.ignore();
    while (true) {
        cout << " Nguyen Trung Thanh - 20215482 - 727736 - 2022.2"<< endl;
        cout << "**   CHUONG TRINH QUAN LY SINH VIEN   **"<<endl;
        cout << "**1. Nhap cac SINH VIEN           **\n" << "**2.In THONG TIN SV, KET QUA,.. **\n"
             <<"**0. Thoat\n"
             <<"******************************************\n"
             <<"*        Nhap lua chon cua ban             \n";
        char control;
        cin >> control;
        cin.ignore();
        switch (control)
        {
        case '1':
            cout << "Ban da chon nhap ds SINH VIEN!";
            for (int i=0; i<n; i++){
                SinhVien sv;
                cout << "Nhap thong tin cua sinh vien thu " << i+1 << " :\n" << endl;
                cout <<" Nhap ten SV: "; getline(cin, sv.HoTen); 
                cout <<" Nhap gioi  tinh: "; cin >> sv.GioiTinh; 
                cout <<" Nhap so mon hoc: "; cin >> sv.SoMonHoc; 
                cout <<"\n";
                for (int j=0; j<sv.SoMonHoc; j++){
                    MonHoc mh;
                    cout << "Nhap mon hoc thu " << j+1 << endl;
                    cout << " \tNhap ma MH: "; cin >> mh.MaMH;
                    cout << " \tNhap so tin chi: "; cin >> mh.sotinchiMH; 
                    cout << " \tNhap trong so CK:>0,<1: "; cin >> mh.trongsoCK;
                    cout << " \tNhap diem QT: "; cin >> mh.DiemQT;
                    cout << " \tNhap diem CK: "; cin >> mh.DiemCK;
                    sv.mhmh.push_back(mh);
                }
                cin.ignore();
                svsv.push_back(sv);
            }
            cout << "Ban da nhap thanh cong!"<<endl;
            cout << "Bam phim bat ky de tiep tuc!";
            cin.ignore();
            cin.get();
            break;
        case '2':
            cout << "Ban da chon xuat DS SINH VIEN !"<< endl;
            for (int i=0; i<n; i++){
                
                double sum1 = 0;
                double sum2 = 0;
                for (int j=0; j<svsv[i].SoMonHoc; j++){
                    svsv[i].mhmh[j].DiemMH = svsv[i].mhmh[j].DiemCK * svsv[i].mhmh[j].trongsoCK + svsv[i].mhmh[j].DiemQT * (1-svsv[i].mhmh[j].trongsoCK);
                    if (svsv[i].mhmh[j].DiemMH > 5) svsv[i].mhmh[j].KetQuaMH = "qua mon";
                    else if (svsv[i].mhmh[j].DiemMH < 5) svsv[i].mhmh[j].KetQuaMH = "hoc lai";
                    sum1 += (double)svsv[i].mhmh[j].DiemMH * svsv[i].mhmh[j].sotinchiMH;
                    sum2 += (double)svsv[i].mhmh[j].sotinchiMH;
                }
                svsv[i].DiemCPA = (double)sum1/sum2;
                if (svsv[i].DiemCPA >= 9) svsv[i].XepLoai = "A+";
                else if (svsv[i].DiemCPA >= 8.5) svsv[i].XepLoai = "A";
                else if (svsv[i].DiemCPA >= 7.5) svsv[i].XepLoai = "B+";
                else if (svsv[i].DiemCPA >= 6.5) svsv[i].XepLoai = "B";
                else if (svsv[i].DiemCPA >= 5) svsv[i].XepLoai = "C";
                else if (svsv[i].DiemCPA >= 4) svsv[i].XepLoai = "D";
                else if (svsv[i].DiemCPA < 4) svsv[i].XepLoai = "F";


            }
            for (int i=0; i<n; i++) {
                cout << "\tTensinhvien: " << svsv[i].HoTen << endl;
                cout << "\tGioi tinh: " << svsv[i].GioiTinh << endl;
                cout << "\tSo monhoc: " << svsv[i].SoMonHoc << endl;
                cout << "\t Ket qua hoc tap cac mon:" << endl;
                cout << "\tMamonhoc" << "\t sotinchi" << "\t trongso" << "\t diem QT" << "\t diem CK" << "\t diem MH" << "\t Ket qua MH"<<endl;
                for (int j=0; j<svsv[i].SoMonHoc; j++){
                cout <<"\t"<< svsv[i].mhmh[j].MaMH << "   \t\t" << svsv[i].mhmh[j].sotinchiMH << "\t\t"
                 << svsv[i].mhmh[j].trongsoCK << "\t\t" << svsv[i].mhmh[j].DiemQT << "\t\t" 
                 <<svsv[i].mhmh[j].DiemCK <<"\t\t"<< svsv[i].mhmh[j].DiemMH<< "\t\t"<< svsv[i].mhmh[j].KetQuaMH<<endl;
                }
                cout << "\t" <<"Diem CPA:" << svsv[i].DiemCPA << endl;
                cout << "\t" << "Xep loai:" << svsv[i].XepLoai << endl;
            }
            cout << "Bam phim bat ki de tiep tuc!";
            cin.ignore();
            cin.get();
            break;
        case '0': 
            cout <<"\n" <<"Ban da chon thoat chuong trinh!";
            return 0;
        }
    }
}